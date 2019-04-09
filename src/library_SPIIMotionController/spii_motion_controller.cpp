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

void SPIIMotionController::uploadOperationalVariables(const Operation_VariableList &variableList)
{

}

BufferData SPIIMotionController::retrieveBufferData(const unsigned int &bufferIndex)
{
    BufferData bufferData;
    m_StateInterface->m_BufferManager->getBufferData(bufferIndex, bufferData);
    return bufferData;
}

void SPIIMotionController::executeCommand(const AbstractCommandPtr command)
{
    ECM::SPII::AbstractStateSPII* currentState = static_cast<ECM::SPII::AbstractStateSPII*>(stateMachine->getCurrentState());
    currentState->handleCommand(command);
    ProgressStateMachineStates();
}

void SPIIMotionController::executeCustomCommands(const std::vector<std::string> &stringCommands)
{
    char* cmd = "enable X\r";

    //acsc_Command(handle,cmd,strlen(cmd),NULL);
}


void SPIIMotionController::ConnectToSimulation()
{
    if(m_CommsMarshaler->ConnectToSimulation(m_SPIIDevice))
    {
        m_StateInterface->m_BufferManager->setMaxBufferSize(m_SPIIDevice.getBufferCount() + 1);
        m_StateInterface->m_BufferManager->setDBufferIndex(m_SPIIDevice.getDBufferIndex());

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
    if(m_CommsMarshaler->ConnectToEthernetPort(linkConfig, m_SPIIDevice))
    {
        m_StateInterface->m_BufferManager->setMaxBufferSize(m_SPIIDevice.getBufferCount() + 1);
        m_StateInterface->m_BufferManager->setDBufferIndex(m_SPIIDevice.getDBufferIndex());

        initializeMotionController();

        //Now we can notify the remaining parties that the
        common::comms::CommunicationUpdate commsUpdate("Motion Controller Link");
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCCommunicationUpdate(commsUpdate);
    }}

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
    requestTP->addAxis(MotorAxis::X); requestTP->addAxis(MotorAxis::Y); requestTP->addAxis(MotorAxis::Z);
    requestTP->setTupleDescription(common::TupleECMData(tuplePos));
    m_DevicePolling->addRequest(requestTP,20);

    // 1: Request the axis status of the ACS unit
    RequestAxisStatusPtr requestAS = std::make_shared<RequestAxisStatus>();
    common::TupleGeneralDescriptorString tupleAxis("AxisStatus");
    requestAS->setTupleDescription(common::TupleECMData(tupleAxis));
    requestAS->addAxis(MotorAxis::X); requestAS->addAxis(MotorAxis::Y); requestAS->addAxis(MotorAxis::Z);
    m_DevicePolling->addRequest(requestAS,100);

    // 1: Request the motor status of the ACS unit
    RequestMotorStatusPtr requestMS = std::make_shared<RequestMotorStatus>();
    common::TupleGeneralDescriptorString tupleMotor("MotorStatus");
    requestMS->setTupleDescription(common::TupleECMData(tupleMotor));
    requestMS->addAxis(MotorAxis::X); requestMS->addAxis(MotorAxis::Y); requestMS->addAxis(MotorAxis::Z);
    m_DevicePolling->addRequest(requestMS,500);

    // 1: Request the motor faults of the ACS unit
    Request_MotorFaultPtr requestMF = std::make_shared<Request_MotorFault>();
    common::TupleGeneralDescriptorString tupleMotorFaults("MotorFaults");
    requestMF->setTupleDescription(common::TupleECMData(tupleMotorFaults));
    requestMF->addAxis(MotorAxis::X); requestMF->addAxis(MotorAxis::Y); requestMF->addAxis(MotorAxis::Z);
    m_DevicePolling->addRequest(requestMF,500);

    // 1: Request the system faults of the ACS unit
    Request_SystemFaultsPtr requestSF = std::make_shared<Request_SystemFaults>();
    common::TupleGeneralDescriptorString tupleSystemFaults("SystemFaults");
    requestSF->setTupleDescription(common::TupleECMData(tupleSystemFaults));
    m_DevicePolling->addRequest(requestMF,500);

    //Retrieve the current contents aboard the device
    m_CommsMarshaler->initializeBufferContents();

    m_DevicePolling->beginPolling();
}

void SPIIMotionController::cbi_AbstractSPIICommand(const AbstractCommandPtr command)
{
    m_CommsMarshaler->sendAbstractSPIICommand(command);
}

void SPIIMotionController::cbi_AbstractSPIIMotionCommand(const AbstractCommandPtr command)
{
    m_CommsMarshaler->sendAbstractSPIIMotionCommand(command);
}

void SPIIMotionController::cbi_AbstractSPIIRequest(const AbstractRequestPtr request)
{
    UNUSED(request);
}

void SPIIMotionController::cbi_AbstractSPIIAddPolled(const AbstractRequestPtr request, const int &period)
{
    m_DevicePolling->addRequest(request,period);
}

void SPIIMotionController::cbi_AbstractSPIIRemovePolled(const common::TupleECMData &tuple)
{
    m_DevicePolling->removeRequest(tuple);
}

void SPIIMotionController::cbi_SPIIControllerGains(const CommandControllerGain &gains)
{
    UNUSED(gains);
}

void SPIIMotionController::cbi_SPIIHomeIndicated(const bool &indicated)
{
    emit signal_MCHomeIndicated(indicated);
}

void SPIIMotionController::cbi_SPIITouchoffIndicated(const bool &indicated)
{
    emit signal_MCTouchoffIndicated(indicated);
}

void SPIIMotionController::cbi_SPIIMotionProfileState(const MotionProfileState &state, const bool &processTransitions)
{
    if(processTransitions)
        ProgressStateMachineStates();

    emit signal_MCUpdatedProfileState(state);
    this->onNewMotionProfileState(state);
}

void SPIIMotionController::cbi_SPIINewMachineState(const ECM::SPII::SPIIState &state)
{
    emit signal_MCNewMotionState(state, QString::fromStdString(ECM::SPII::ECMStateToString(state)));
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
    if(axis.empty())
        return;

    m_StateInterface->m_AxisStatus->updateAxisStatus(axis);
    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_MotorUpdate(const std::vector<Status_MotorPerAxis> &motor)
{
    if(motor.empty())
        return;

    m_StateInterface->m_MotorStatus->updateMotorStatus(motor);
    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_VariableUpdate(const std::vector<Status_VariableValue> &variable)
{
    if(variable.empty())
        return;

    for(size_t index = 0; index < variable.size(); index++)
        m_StateInterface->m_MasterVariableValues->updateVariable(variable.at(index));

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_MotorFaultUpdate(const std::vector<Status_MotorAxisFault> &motor)
{
    if(motor.empty())
        return;

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_SystemFaultUpdate(const Status_SystemFault &status)
{
    if(!status.isStatusValid())
        return;

    ProgressStateMachineStates();
}


void SPIIMotionController::SPIIPolling_PositionUpdate(const std::vector<Status_PositionPerAxis> &position)
{
    if(position.empty())
        return;

    common::TuplePositionalString tuple;
    tuple.axisName = QString::fromStdString(AxisToString(MotorAxis::Z));

    common_data::PositionalStatePtr positionalState = std::make_shared<common_data::PositionalState>();
    for(size_t index = 0; index < position.size(); index++)
        positionalState->setAxisPosition(position.at(index).getAxis(), position.at(index).getPosition());

    common_data::MachinePositionalState state;
    state.setObservationTime(position.at(0).getTime());
    state.setPositionalState(positionalState);

    if(m_StateInterface->m_AxisPosition->updatePositionStatus(position))
        emit signal_MCNewPosition(tuple, state, true);
    else
        emit signal_MCNewPosition(tuple, state, false);

    ProgressStateMachineStates();
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

void SPIIMotionController::NewBuffer_AvailableData(const BufferData &bufferData)
{
    m_StateInterface->m_BufferManager->updateBufferData(bufferData.getBufferIndex(),bufferData);

    Status_BufferState newBufferState;
    newBufferState.setBufferIndex(bufferData.getBufferIndex());
    newBufferState.setProgramString(bufferData.getProgramString());
    if(bufferData.isBufferCompiled())
        newBufferState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::COMPILED);
    else
        newBufferState.setBufferState(Status_BufferState::ENUM_BUFFERSTATE::CURRENT);
    emit signal_MCBufferUpdate(newBufferState);
}

void SPIIMotionController::NewStatus_OperationalLabels(const Operation_LabelList &labelList)
{
    m_StateInterface->m_BufferManager->updateOperationalLabels(labelList);

    emit signal_MCNewProgramLabelList(labelList);
}

void SPIIMotionController::NewStatus_PrivateOperationalVariables(const bool &success, const Operation_VariableList &variableList)
{
    if(success)
    {
        m_StateInterface->m_MasterVariableValues->fromVariableList(variableList);

        m_StateInterface->m_BufferManager->updatePrivateVariables(variableList);

        this->onFinishedUploadingVariables(success,variableList);

        emit signal_MCNewProgramVariableList(variableList);
    }
}

void SPIIMotionController::NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList)
{
    if(success)
    {
        m_StateInterface->m_MasterVariableValues->fromVariableList(variableList);

        m_StateInterface->m_BufferManager->updateUserVariables(variableList);

        this->onFinishedUploadingVariables(success,variableList);

        emit signal_MCNewProgramVariableList(variableList);
    }
}

void SPIIMotionController::NewStatus_CustomCommandReceived(const std::string &command, const std::string &response)
{
  emit signal_CustomUserRequestReceived(command,response);
}



