#include "ecm_api.h"

ECM_API::ECM_API()
{    
    m_Log = new ECMLogging(this->getSoftwareVersions());

    m_Rigol = new RigolOscilliscope();

    m_Munk = new MunkPowerSupply();

    m_Galil = new GalilMotionController();
    connect(m_Galil,SIGNAL(signal_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)),
            this,SLOT(slot_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)));

    connect(m_Galil, SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),
            this, SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

    connect(m_Galil, SIGNAL(signal_MCNewMotionState(ECM::Galil::GalilState,std::string)),
            this, SLOT(slot_MCNewMotionState(ECM::Galil::GalilState,std::string)));


    connect(m_Munk, SIGNAL(signal_FaultCodeRecieved()),
            this, SLOT(slot_FaultCodeReceived()));

    m_Sensoray = new Sensoray();

    m_Modbus485 = new Library_QModBus();

    m_Pump = new Westinghouse510(m_Modbus485,03);

}

std::map<std::string, std::string> ECM_API::getSoftwareVersions() const
{
    std::map<std::string, std::string> softwareVersionMap;

    softwareVersionMap.insert(std::pair<std::string,std::string>("ECM API",ECMAPI_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("GALIL Library",LIBGALIL_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("MUNK Library",LIBMUNK_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("WESTINGHOUSE  Library",LIBWESTINGHOUSE_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("SENSORAY Library",LIBSENSORAY_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("RIGOL Library",LIBRIGOL_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("MODBUS Library",LIBMODBUS_VERSION_STRING));

    softwareVersionMap.insert(std::pair<std::string,std::string>("COMMON Library",LIBCOMMON_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("DATA Library",LIBDATA_VERSION_STRING));
    softwareVersionMap.insert(std::pair<std::string,std::string>("GRAPHING Library",LIBGRAPHING_VERSION_STRING));

    return softwareVersionMap;
}

bool ECM_API::checkLoggingPathValidity(const string &partNumber, const string &serialNumber) const
{
    return m_Log->checkLoggingPath(partNumber, serialNumber);
}

void ECM_API::initializeECMLogs(const std::string &partNumber, const std::string &serialNumber, const std::string &profile,
                                const common::EnvironmentTime &time, const std::string &descriptor, const bool &clearContents)
{
    m_Log->initializeLogging(partNumber, serialNumber, clearContents); //gets the file and directory structure ready for us

    if(clearContents) //if its true means we have new stuff to write
    {
        std::string loggingPath = m_Log->getLoggingPath();

        //Write the Munk Profile Parameters
        std::string munkPath = loggingPath + "PowerSupplySettings.json";
        m_Munk->saveToFile(QString::fromStdString(munkPath));

        std::string galilPath = loggingPath + "MotionControllerSettings.txt";
        m_Galil->saveProgramAs(galilPath);

        std::string pumpPath = loggingPath + "PumpSettings.json";
        m_Pump->saveToFile(QString::fromStdString(pumpPath));
    }

    std::string operationsString;
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "PUMP OPERATIONAL SETTTINGS: \r\n";
    operationsString += m_Pump->getLogOfOperationalSettings();
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "POWER SUPPLY OPERATIONAL SETTTINGS: \r\n";
    operationsString += m_Munk->getLogOfOperationalSettings();
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL SETTTINGS: \r\n";
    operationsString += m_Galil->getLogOfOperationalSettings();
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "\r\n";

    m_Log->writeLoggingHeader(partNumber, serialNumber, profile,
                              operationsString, descriptor, time);
}

void ECM_API::action_StopMachine()
{
    CommandStopPtr commandGalilStop = std::make_shared<CommandStop>();
    m_Galil->executeCommand(commandGalilStop);

    m_Pump->ceasePumpOperations();
}

void ECM_API::slot_MotionControllerCommunicationUpdate(const common::comms::CommunicationUpdate &update)
{
    //    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    //        m_Galil->initializeMotionController();
}

void ECM_API::slot_UpdateMotionProfileState(const MotionProfileState &state)
{
    switch (state.getProfileState()->getType()) {
    case MotionProfile::ProfileType::SETUP:
        break;
    case MotionProfile::ProfileType::HOMING:
        break;
    case MotionProfile::ProfileType::TOUCHOFF:
        break;
    case MotionProfile::ProfileType::PROFILE:
    {
        //implement a better way to cast the state in this condition
        ProfileState_Machining* castState = (ProfileState_Machining*)state.getProfileState().get();
        ProfileState_Machining::MACHININGProfileCodes currentCode = castState->getCurrentCode();
        switch (currentCode) {
        case ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE:

            break;
        case ProfileState_Machining::MACHININGProfileCodes::COMPLETE:
        {
            //grab the current time and update all of the sources
            common::EnvironmentTime endTime;
            common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,endTime);

            //conclude writing to the logs with any wrap up data that we need
            m_Log->CloseMachiningLog(endTime, currentCode);
            break;
        }
        case ProfileState_Machining::MACHININGProfileCodes::ABORTED:
        {
            //grab the current time and update all of the sources
            common::EnvironmentTime endTime;
            common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,endTime);

            //conclude writing to the logs with any wrap up data that we need
            m_Log->CloseMachiningLog(endTime, currentCode);

            //m_Rigol->executeMeasurementPolling(false);
            break;
        }
        default:
            break;
        }
    }
    default:
        break;
    }
}

void ECM_API::slot_MCNewMotionState(const ECM::Galil::GalilState &state, const string &stateString)
{
    switch (state) {
    case ECM::Galil::GalilState::STATE_ESTOP:
    case ECM::Galil::GalilState::STATE_HOME_POSITIONING:
    case ECM::Galil::GalilState::STATE_MOTION_STOP:
    case ECM::Galil::GalilState::STATE_READY_STOP:
    case ECM::Galil::GalilState::STATE_SCRIPT_EXECUTION:
    case ECM::Galil::GalilState::STATE_TOUCHOFF:
    case ECM::Galil::GalilState::STATE_UNKNOWN:
    {
        //In all of the above cases we want to disable the buttons that could potentially have adverse conditions
        //Although all of the checks are handled in the state machine of the galil library, it is preferred to have
        //a secondary check within the API. This was primarily noted when the user could potentially double click.
        emit signal_LockMotionButtons(true);
        break;
    }
    case ECM::Galil::GalilState::STATE_IDLE:
    case ECM::Galil::GalilState::STATE_READY:
    {
        emit signal_LockMotionButtons(false);
        break;
    }
    case ECM::Galil::GalilState::STATE_JOGGING:
    case ECM::Galil::GalilState::STATE_MANUAL_POSITIONING:
    {
        //We do not want to change the state condition of the button in this state
        //This is because if we go to lock the buttons the release event will either
        //trigger immediately or never be emitted.

        break;
    }
    default:
        break;
    }

    emit signal_MCNewMotionState(stateString);
}

void ECM_API::slot_FaultCodeReceived()
{
    //First stop the machine to the best of our ability
    this->action_StopMachine();

    emit signal_FaultCodeRecieved();
}

void ECM_API::writeHeaderBreaker(std::string &logString, const unsigned int &size) const
{
    //Write header breaker line at the top
    for(size_t i = 0; i < size; i++)
    {
        logString = logString + "*";
    }
    //bump the header to the next line
    logString = logString + "\r\n";
}
