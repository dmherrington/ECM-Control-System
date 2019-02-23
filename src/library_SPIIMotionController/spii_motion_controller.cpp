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
    stateMachine->Initialize<ECM::SPII::State_Idle>(m_StateInterface);
    //if we begin issuing text commands we have to be careful how the state machine progresses
    ProgressStateMachineStates();

    //Instantiating the galil state polling object. This is only needed to be done once within the program
    m_DevicePolling = new SPIIPollMachine();
    m_DevicePolling->updateCommsProtocol(m_CommsMarshaler);
    m_DevicePolling->AddSubscriber(this);
}

SPIIMotionController::~SPIIMotionController()
{

}

void SPIIMotionController::executeCommand(const AbstractCommandPtr command)
{
    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
    currentState->handleCommand(command);
    ProgressStateMachineStates();
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
    UNUSED(linkConfig);
}

void SPIIMotionController::ConnectToEthernetPort(const common::comms::TCPConfiguration &linkConfig)
{
    UNUSED(linkConfig);
}

void SPIIMotionController::ConnectToPCIPort(const ACSC_PCI_SLOT &linkConfig)
{
    UNUSED(linkConfig);
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

    // 1: Stop all motion that may exist within the device
    CommandStopPtr commandStop = std::make_shared<CommandStop>();
    m_CommsMarshaler->commandMotionStop(*commandStop.get());

    // 2: Disable all of the motors so we can later deal with the device
    CommandMotorDisablePtr commandMotorDisable = std::make_shared<CommandMotorDisable>();
    m_CommsMarshaler->commandMotorDisable(*commandMotorDisable.get());

    //Add items to the ACS polling queue so that we can stay up to date
    // 1: Request the position of the ACS unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    common::TupleGeneralDescriptorString tuplePos("PositionStatus");
    requestTP->setTupleDescription(common::TupleECMData(tuplePos));
    m_DevicePolling->addRequest(requestTP,20);

    // 1: Request the axis status of the ACS unit
    RequestAxisStatusPtr requestAS = std::make_shared<RequestAxisStatus>();
    common::TupleGeneralDescriptorString tupleAxis("AxisStatus");
    requestAS->setTupleDescription(common::TupleECMData(tupleAxis));
    m_DevicePolling->addRequest(requestAS,100);

    // 1: Request the motor status of the ACS unit
    RequestMotorStatusPtr requestMS = std::make_shared<RequestMotorStatus>();
    common::TupleGeneralDescriptorString tupleMotor("MotorStatus");
    requestMS->setTupleDescription(common::TupleECMData(tupleMotor));
    m_DevicePolling->addRequest(requestMS,500);

    m_DevicePolling->beginPolling();
}

void SPIIMotionController::SPIIPolling_AxisUpdate(const std::vector<SPII::Status_PerAxis> &axis)
{
    m_StateInterface->m_AxisStatus->updateAxisStatus(axis);
}

void SPIIMotionController::SPIIPolling_MotorUpdate(const std::vector<SPII::Status_MotorPerAxis> &motor)
{
    m_StateInterface->m_MotorStatus->updateMotorStatus(motor);
}

void SPIIMotionController::SPIIPolling_PositionUpdate(const std::vector<SPII::Status_PositionPerAxis> &position)
{
    m_StateInterface->m_AxisPosition->updatePositionStatus(position);
}
