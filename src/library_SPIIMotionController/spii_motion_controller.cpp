#include "spii_motion_controller.h"


SPIIMotionController::SPIIMotionController()
{
    std::vector<MotorAxis> availableAxis;
    availableAxis.push_back(MotorAxis::X);

    m_CommsMarshaler = std::make_shared<Comms::CommsMarshaler>();
    m_CommsMarshaler->AddSubscriber(this);

    m_StateInterface = new SPIIStateInterface(availableAxis);
    m_StateInterface->connectCallback(this);

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
    ECM::SPII::AbstractStateSPII* currentState = static_cast<ECM::SPII::AbstractStateSPII*>(stateMachine->getCurrentState());
    currentState->handleCommand(command);
    ProgressStateMachineStates();
}

void SPIIMotionController::executeCustomCommands(const std::vector<std::string> &stringCommands)
{

}


void SPIIMotionController::ConnectToSimulation()
{
    if(m_CommsMarshaler->ConnectToSimulation(m_SPIIDevice))
    {
        initializeMotionController();

        //Now we can notify the remaining parties that the
        common::comms::CommunicationUpdate commsUpdate("Motion Controller Link");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCCommunicationUpdate(commsUpdate);
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

void SPIIMotionController::getSPIIProperties(unsigned int &numAxis, unsigned int &numBuffers, unsigned int &dBufferIndex) const
{
    numAxis = this->m_SPIIDevice.getAxisCount();
    numBuffers = this->m_SPIIDevice.getBufferCount();
    dBufferIndex = this->m_SPIIDevice.getDBufferIndex();
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

void SPIIMotionController::cbi_AbstractSPIICommand(const AbstractCommandPtr command)
{

}
void SPIIMotionController::cbi_AbstractSPIIMotionCommand(const AbstractCommandPtr command)
{

}
void SPIIMotionController::cbi_AbstractSPIIRequest(const AbstractRequestPtr request)
{

}
void SPIIMotionController::cbi_AbstractSPIIAddPolled(const AbstractRequestPtr request, const int &period)
{

}
void SPIIMotionController::cbi_AbstractSPIIRemovePolled(const common::TupleECMData &tuple)
{

}
void SPIIMotionController::cbi_SPIIControllerGains(const CommandControllerGain &gains)
{

}

void SPIIMotionController::cbi_SPIIHomeIndicated(const bool &indicated)
{
    emit signal_MCHomeIndicated(indicated);
}

void SPIIMotionController::cbi_SPIITouchoffIndicated(const bool &indicated)
{

}
void SPIIMotionController::cbi_SPIIMotionProfileState(const MotionProfileState &state, const bool &processTransitions)
{

}

void SPIIMotionController::cbi_SPIINewMachineState(const ECM::SPII::SPIIState &state)
{

}

void SPIIMotionController::cbi_SPIIUploadProgram(const AbstractCommandPtr command)
{
    m_CommsMarshaler->sendAbstractSPIICommand(command);
}

void SPIIMotionController::cbi_SPIIDownloadProgram(const AbstractCommandPtr command)
{

}


void SPIIMotionController::SPIIPolling_AxisUpdate(const std::vector<Status_PerAxis> &axis)
{
    m_StateInterface->m_AxisStatus->updateAxisStatus(axis);

    /*
    GalilStatus* ptr = stateInterface->getAxisStatus(status.getAxis());

    common::TuplePositionalString tuple;
    tuple.axisName = QString::fromStdString(AxisToString(status.getAxis()));
    common_data::PositionalStatePtr position = std::make_shared<common_data::PositionalState>();
    position->setStateAxis(status.getAxis());
    position->setAxisPosition(status.getPosition());
    common_data::MachinePositionalState state;
    state.setObservationTime(status.getTime());
    state.setPositionalState(position);

    if(ptr->setPosition(status))
    {
        emit signal_MCNewPosition(tuple,state, true);
    }
    else
    {
        emit signal_MCNewPosition(tuple,state, false);
    }
    ProgressStateMachineStates();
    */
}

void SPIIMotionController::SPIIPolling_MotorUpdate(const std::vector<Status_MotorPerAxis> &motor)
{
    m_StateInterface->m_MotorStatus->updateMotorStatus(motor);
}

void SPIIMotionController::SPIIPolling_PositionUpdate(const std::vector<Status_PositionPerAxis> &position)
{
    m_StateInterface->m_AxisPosition->updatePositionStatus(position);
}

ECM::SPII::SPIIState SPIIMotionController::getCurrentMCState() const
{
    ECM::SPII::AbstractStateSPII* currentState = static_cast<ECM::SPII::AbstractStateSPII*>(stateMachine->getCurrentState());
    ECM::SPII::SPIIState stateEnum = currentState->getCurrentState();
    return stateEnum;
}

std::vector<common::TupleECMData> SPIIMotionController::getPlottables() const
{
    std::vector<common::TupleECMData> rtn;

    common::TuplePositionalString tpString;
    tpString.axisName = QString::fromStdString(AxisToString(MotorAxis::Z));
    rtn.push_back(tpString);

    common::TupleProfileVariableString varString("","","ppos");
    rtn.push_back(varString);

    return rtn;
}


void SPIIMotionController::NewBufferState(const Status_BufferState &state)
{
    m_StateInterface->m_BufferManager->statusBufferUpdate(state);
    emit signal_MCBufferUpdate(state);
}


