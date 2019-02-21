#include "spii_motion_controller.h"


SPIIMotionController::SPIIMotionController()
{

    std::vector<MotorAxis> availableAxis;
    availableAxis.push_back(MotorAxis::Z);

    m_CommsMarshaler = new Comms::CommsMarshaler();
    m_CommsMarshaler->AddSubscriber(this);

    m_StateInterface = new SPIIStateInterface(availableAxis);
    //m_StateInterface->connectCallback(this);

    stateMachine = new hsm::StateMachine();
    //stateMachine->Initialize<ECM::SPII::State_Idle>(m_StateInterface);
    //if we begin issuing text commands we have to be careful how the state machine progresses
    //ProgressStateMachineStates();

    //Instantiating the galil state polling object. This is only needed to be done once within the program
    m_DevicePolling = new SPIIPollMachine();
    m_DevicePolling->connectCallback(this);
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
    m_DevicePolling->updateCommsHandle(m_SPIIDevice);

    // 1: Stop all motion that may exist on the controller
    //CommandStopPtr commandStop = std::make_shared<CommandStop>();
    //int rtnCode = acsc_KillAll(this->SPIIDevice,ACSC_SYNCHRONOUS);


    //Add items to the ASC polling queue so that we can stay up to date
    // 1: Request the position of the galil unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    common::TuplePositionalString tuplePos;
    tuplePos.axisName = "All Axis";
    requestTP->setTupleDescription(common::TupleECMData(tuplePos));

    m_DevicePolling->addRequest(requestTP,20);
    // 2: Request the stop codes
//    RequestStopCodePtr requestSC = std::make_shared<RequestStopCode>();
//    common::TupleGeneralDescriptorString tupleSC("StopCodes");
//    requestSC->setTupleDescription(common::TupleECMData(tupleSC));
//    m_DevicePolling->addRequest(requestSC,200);
    // 3: Request the tell switches
//    RequestTellSwitchesPtr requestTS = std::make_shared<RequestTellSwitches>();
//    common::TupleGeneralDescriptorString tupleTS("TellSwitches");
//    requestTS->setTupleDescription(common::TupleECMData(tupleTS));
//    m_DevicePolling->addRequest(requestTS,200);
    // 4: Request the current inputs
//    RequestTellInputsPtr requestTI = std::make_shared<RequestTellInputs>();
//    common::TupleGeneralDescriptorString tupleTI("TellInputs");
//    requestTI->setTupleDescription(common::TupleECMData(tupleTI));
//    m_DevicePolling->addRequest(requestTI,1000);

    m_DevicePolling->beginPolling();

}

void SPIIMotionController::cbi_SPIIStatusRequest()
{
    m_CommsMarshaler->requestPosition();
}
