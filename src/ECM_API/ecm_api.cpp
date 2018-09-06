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

void ECM_API::initializeECMLogs()
{
    m_Log->writeLoggingHeader();
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
            //conclude writing to the logs with any wrap up data that we need
            m_Log->enableLogging(false); //let us stop the logs

            break;
        case ProfileState_Machining::MACHININGProfileCodes::ABORTED:
            //conclude writing to the logs with any wrap up data that we need
            m_Log->enableLogging(false); //let us stop the logs

            break;
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

