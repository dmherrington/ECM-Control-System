#include "spii_motion_controller.h"


SPIIMotionController::SPIIMotionController()
{

    std::vector<MotorAxis> availableAxis;
    availableAxis.push_back(MotorAxis::X);

    m_CommsMarshaler = std::make_shared<Comms::CommsMarshaler>();
    m_CommsMarshaler->AddSubscriber(this);

    m_StateInterface = new SPIIStateInterface(availableAxis);
    //m_StateInterface->connectCallback(this);

    stateMachine = new hsm::StateMachine();
    //stateMachine->Initialize<ECM::SPII::State_Idle>(m_StateInterface);
    //if we begin issuing text commands we have to be careful how the state machine progresses
    //ProgressStateMachineStates();

    //Instantiating the galil state polling object. This is only needed to be done once within the program
    m_DevicePolling = new SPIIPollMachine();
    m_DevicePolling->updateCommsProtocol(m_CommsMarshaler);
}

SPIIMotionController::~SPIIMotionController()
{

}


void SPIIMotionController::ConnectToSimulation()
{
    m_SPIIDevice = m_CommsMarshaler->ConnectToSimulation();
    if(m_CommsMarshaler->isDeviceConnected())
    {
        initializeMotionController();
    }
}

void SPIIMotionController::ConnectToSerialPort(const common::comms::SerialConfiguration &linkConfig)
{

}

void SPIIMotionController::ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig)
{

}

void SPIIMotionController::ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig)
{

}

void SPIIMotionController::closeConnection()
{

}

bool SPIIMotionController::isDeviceConnected() const
{
    return m_CommsMarshaler->isDeviceConnected();
}



//!
//! \brief Cause the state machine to update it's states
//!
void SPIIMotionController::ProgressStateMachineStates()
{
    std::lock_guard<std::mutex> lock(m_Mutex_StateMachine);
    stateMachine->ProcessStateTransitions();
    stateMachine->UpdateStates();
}

void SPIIMotionController::LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    switch (update.getUpdateType()) {
    case common::comms::CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        break;
    }
    default:
    {
        break;
    }
    }
}

void SPIIMotionController::initializeMotionController()
{

    // 1: Stop all motion that may exist on the controller
    //CommandStopPtr commandStop = std::make_shared<CommandStop>();
    //int rtnCode = acsc_KillAll(this->SPIIDevice,ACSC_SYNCHRONOUS);


    //Add items to the ACS polling queue so that we can stay up to date
    // 1: Request the position of the ACS unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    m_DevicePolling->addRequest(requestTP,20);

    // 1: Request the axis status of the ACS unit
    RequestAxisStatusPtr requestAS = std::make_shared<RequestAxisStatus>();
    m_DevicePolling->addRequest(requestAS,100);

    // 1: Request the motor status of the ACS unit
    RequestMotorStatusPtr requestMS = std::make_shared<RequestMotorStatus>();
    m_DevicePolling->addRequest(requestMS,500);

    m_DevicePolling->beginPolling();
}

void SPIIMotionController::SPIIPolling_PositionUpdate(const std::vector<SPII::Status_PositionPerAxis> &position)
{
    m_StateInterface->
}

void SPIIMotionController::cbi_SPIIStatusRequest()
{

}
