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

    //ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());

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

void ECM_API::initializeECMLogs(const ECMCommand_ExecuteCollection &executionCollection,
                                const bool &clearContents,
                                const std::string &descriptor)
{
    //gets the file and directory structure ready for us
    m_Log->initializeLogging(executionCollection.getPartNumber(),
                             executionCollection.getSerialNumber(),
                             clearContents);

    /* This no longer made sense with the new profile configuration
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
    */

    std::string operationsString;
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "PUMP OPERATIONAL SETTTINGS: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Pump->getLogOfOperationalSettings();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "POWER SUPPLY OPERATIONAL SETTTINGS: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Munk->getLogOfOperationalSettings();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL SCRIPT: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Galil->stateInterface->galilProgram->getProgram();
    operationsString += "\r\n";

    this->writeHeaderBreaker(operationsString, 100);
    operationsString += "MOTION CONTROLLER OPERATIONAL VARIABLES: \n";
    this->writeHeaderBreaker(operationsString, 100);
    operationsString += m_Galil->stateInterface->galilProgram->getVariableList().getLoggingString();
    operationsString += "\r\n";

    m_Log->writeExecutionCollection(executionCollection);
    ECMCommand_ProfileConfiguration profileConfig = executionCollection.getActiveConfiguration();
    m_Log->writeLoggingHeader(executionCollection.getPartNumber(),executionCollection.getSerialNumber(),profileConfig.getOperationName(),
                              profileConfig.getProfileName(),operationsString,descriptor,
                              profileConfig.execProperties.getStartTime());
}

void ECM_API::executeMachiningProcess(const ECMCommand_ProfileConfiguration &profileConfig)
{
    m_Log->enableLogging(true);

    emit signal_ExecutingProfile(profileConfig.getOperationName(),profileConfig.execProperties.getStartTime());

    CommandExecuteProfilePtr command = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::PROFILE,
                                                                               profileConfig.getProfileName());
    m_Galil->executeCommand(command);
}

void ECM_API::concludeMachiningProcess(const ECMCommand_ProfileConfiguration &profileConfig)
{
    //conclude writing to the logs with any wrap up data that we need
    m_Log->CloseMachiningLog(profileConfig.execProperties.getEndTime(),
                             profileConfig.execProperties.getProfileCode());
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


            break;
        }
        case ProfileState_Machining::MACHININGProfileCodes::ABORTED:
        {
            m_Pump->ceasePumpOperations();

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

void ECM_API::writeHeaderBreaker(std::string &logString, const unsigned int &size) const
{
    //Write header breaker line at the top
    for(size_t i = 0; i < size; i++)
    {
        logString = logString + "*";
    }
    //bump the header to the next line
    logString = logString + "\n";
}
