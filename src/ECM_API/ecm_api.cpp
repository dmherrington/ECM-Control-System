#include "ecm_api.h"

ECM_API::ECM_API()
{    
    m_Log = new ECMLogging();

    m_Rigol = new RigolOscilliscope();

    m_Munk = new MunkPowerSupply();

    m_Galil = new GalilMotionController();
    connect(m_Galil,SIGNAL(signal_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)),
            this,SLOT(slot_MotionControllerCommunicationUpdate(common::comms::CommunicationUpdate)));

    connect(m_Galil, SIGNAL(signal_GalilUpdatedProfileState(MotionProfileState)),
            this, SLOT(slot_UpdateMotionProfileState(MotionProfileState)));

    m_Sensoray = new Sensoray();

    m_Modbus485 = new Library_QModBus();

    m_Pump = new Westinghouse510(m_Modbus485,03);

}

void ECM_API::initializeECMLogs(const string &partNumber, const string &serialNumber, const common::EnvironmentTime &time, bool clearContents)
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
    //softwareVersionMap.insert(std::pair<std::string,std::string>("GRAPHING Library",LIBGRAPHING_VERSION_STRING));


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
        break;
    default:
        break;
    }
}

