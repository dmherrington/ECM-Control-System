#include "spii_motion_controller.h"


SPIIMotionController::SPIIMotionController(const AxisSettings &settings)
{
    m_CommsMarshaler = std::make_shared<Comms::CommsMarshaler>();
    m_CommsMarshaler->AddSubscriber(this);

    m_StateInterface = new SPIIStateInterface(settings);
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

void SPIIMotionController::setAxesSettings(const AxisSettings &settings)
{
    m_StateInterface->updateAxisSettings(settings);
}

void SPIIMotionController::enableAvailableAxes()
{
    CommandMotorEnablePtr command = std::make_shared<CommandMotorEnable>();
    command->addAxis(MotorAxis::X); command->addAxis(MotorAxis::Y); command->addAxis(MotorAxis::Z);
    this->executeCommand(command);
}

void SPIIMotionController::disableAvailableAxes()
{
    CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();

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
    m_CommsMarshaler->sendCustomSPIICommands(stringCommands);
}

void SPIIMotionController::executeSynchronizationRequest()
{
    m_CommsMarshaler->initializeBufferContents();
}

void SPIIMotionController::ConnectToSimulation()
{
    if(m_CommsMarshaler->ConnectToSimulation(m_SPIIDevice))
    {
        m_StateInterface->m_BufferManager->setMaxBufferSize(m_SPIIDevice.getBufferCount() + 1);
        m_StateInterface->m_BufferManager->setDBufferIndex(m_SPIIDevice.getDBufferIndex());

        initializeMotionController();

        //Now we can notify the remaining parties that the
        common::comms::CommunicationUpdate commsUpdate("Motion Controller Link", ECMDevice::DEVICE_MOTIONCONTROL);
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCCommunicationUpdate(commsUpdate);

        common::NotificationUpdate newUpdate("ACS Controller",ECMDevice::DEVICE_MOTIONCONTROL,common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
        newUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCNotification(newUpdate);
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
        common::comms::CommunicationUpdate commsUpdate("Motion Controller Link", ECMDevice::DEVICE_MOTIONCONTROL);
        commsUpdate.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
        commsUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCCommunicationUpdate(commsUpdate);

        common::NotificationUpdate newUpdate("ACS Controller",ECMDevice::DEVICE_MOTIONCONTROL,common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
        newUpdate.setPeripheralMessage("SPII Motor Controller Connected.");
        emit signal_MCNotification(newUpdate);
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

    setupRequestQueue();

    //Retrieve the current contents aboard the device
    m_CommsMarshaler->initializeBufferContents();

    m_DevicePolling->beginPolling();
}

void SPIIMotionController::setupRequestQueue()
{
    std::vector<MotorAxis> currentAxes = m_StateInterface->getAvailableAxes();

    //Add items to the ACS polling queue so that we can stay up to date
    // 1: Request the position of the ACS unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    common::TupleGeneralDescriptorString tuplePos("PositionStatus");
    requestTP->addAxes(currentAxes);
    requestTP->setTupleDescription(common::TupleECMData(tuplePos));
    m_DevicePolling->addRequest(requestTP,20);

    // 1: Request the axis status of the ACS unit
    RequestAxisStatusPtr requestAS = std::make_shared<RequestAxisStatus>();
    common::TupleGeneralDescriptorString tupleAxis("AxisStatus");
    requestAS->setTupleDescription(common::TupleECMData(tupleAxis));
    requestAS->addAxes(currentAxes);
    m_DevicePolling->addRequest(requestAS,100);

    // 1: Request the axis safety of the ACS unit
    Request_AxisSafetyPtr requestASafety = std::make_shared<Request_AxisSafety>();
    common::TupleGeneralDescriptorString tupleSafety("SafetyStatus");
    requestASafety->setTupleDescription(common::TupleECMData(tupleSafety));
    requestASafety->addAxes(currentAxes);
    m_DevicePolling->addRequest(requestASafety,100);

    // 1: Request the motor status of the ACS unit
    RequestMotorStatusPtr requestMS = std::make_shared<RequestMotorStatus>();
    common::TupleGeneralDescriptorString tupleMotor("MotorStatus");
    requestMS->setTupleDescription(common::TupleECMData(tupleMotor));
    requestMS->addAxes(currentAxes);
    m_DevicePolling->addRequest(requestMS,500);

    // 1: Request the motor faults of the ACS unit
    Request_MotorFaultPtr requestMF = std::make_shared<Request_MotorFault>();
    common::TupleGeneralDescriptorString tupleMotorFaults("MotorFaults");
    requestMF->setTupleDescription(common::TupleECMData(tupleMotorFaults));
    requestMF->addAxes(currentAxes);
    m_DevicePolling->addRequest(requestMF,500);

    // 1: Request the system faults of the ACS unit
    Request_SystemFaultsPtr requestSF = std::make_shared<Request_SystemFaults>();
    common::TupleGeneralDescriptorString tupleSystemFaults("SystemFaults");
    requestSF->setTupleDescription(common::TupleECMData(tupleSystemFaults));
    m_DevicePolling->addRequest(requestSF,500);

    // 1: Request the system faults of the ACS unit
    Request_UnsolicitedMsgsPtr requestUNM = std::make_shared<Request_UnsolicitedMsgs>();
    common::TupleGeneralDescriptorString tupleUnsolicitedMsgs("UnsolicitedMsgs");
    requestUNM->setTupleDescription(common::TupleECMData(tupleUnsolicitedMsgs));
    m_DevicePolling->addRequest(requestUNM,100);
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

void SPIIMotionController::cbi_SPIINotificationUpdate(const common::NotificationUpdate &update)
{
    emit signal_MCNotification(update);
}

void SPIIMotionController::cbi_SPIIUploadProgram(const AbstractCommandPtr command)
{
    m_CommsMarshaler->sendAbstractSPIICommand(command);
}

void SPIIMotionController::cbi_SPIIDownloadProgram(const AbstractCommandPtr command)
{

}

void SPIIMotionController::SPIIPolling_VariableUpdate(const std::vector<Status_VariableValue> &variable)
{
    if(variable.empty())
        return;

    for(size_t index = 0; index < variable.size(); index++)
        m_StateInterface->m_MasterVariableValues->updateVariable(variable.at(index));

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_PositionUpdate(const std::vector<Status_PositionPerAxis> &position)
{
    bool newPosition = false;
    common::TuplePositionalString tuple;
    tuple.axisName = QString::fromStdString(AxisToString(MotorAxis::Z));
    common_data::MachinePositionalState state;
    common_data::PositionalStatePtr positionalState = std::make_shared<common_data::PositionalState>();

    std::map<MotorAxis,Status_AxisState>::iterator it;

    for(size_t index = 0; index < position.size(); index++)
    {
        Status_PositionPerAxis currentStatus = position.at(index);
        MotorAxis currentAxis = currentStatus.getAxis();
        if(currentStatus.isStatusValid())
        {
            newPosition = m_StateInterface->m_AxisState.at(currentAxis).m_AxisPosition.set(currentStatus);
            positionalState->setAxisPosition(currentAxis, position.at(index).getPosition());
        }

    }
    state.setObservationTime(position.at(0).getTime());
    state.setPositionalState(positionalState);

    emit signal_MCNewPosition(tuple, state, newPosition);

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_AxisUpdate(const std::vector<Status_PerAxis> &axis)
{

    std::map<MotorAxis,Status_AxisState>::iterator it;

    for(size_t index = 0; index < axis.size(); index++)
    {
        Status_PerAxis currentStatus = axis.at(index);
        MotorAxis currentAxis = currentStatus.getAxis();
        if(currentStatus.isStatusValid())
            m_StateInterface->m_AxisState.at(currentAxis).m_AxisStatus.set(currentStatus);
    }
    ProgressStateMachineStates();
}


void SPIIMotionController::SPIIPolling_MotorUpdate(const std::vector<Status_MotorPerAxis> &motor)
{
    std::map<MotorAxis,Status_AxisState>::iterator it;

    for(size_t index = 0; index < motor.size(); index++)
    {
        Status_MotorPerAxis currentStatus = motor.at(index);
        MotorAxis currentAxis = currentStatus.getAxis();
        if(currentStatus.isStatusValid())
            m_StateInterface->m_AxisState.at(currentAxis).m_MotorStatus.set(currentStatus);
    }
    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_AxisSafetyUpdate(const std::vector<Status_AxisSafety> &axis)
{

    bool errorExists = false;

    std::map<MotorAxis,Status_AxisState>::iterator it;

    for(size_t index = 0; index < axis.size(); index++)
    {
        Status_AxisSafety currentStatus = axis.at(index);
        MotorAxis currentAxis = currentStatus.getAxis();
        if(currentStatus.isStatusValid())
        {

            if(!m_StateInterface->m_AxisState.at(currentAxis).m_AxisSafety.set(currentStatus))
                continue;

            if(currentStatus.doesSafetyFaultExist() && (currentStatus.getErrorCode() > 5005))
            {
                errorExists = true;
                std::string notificationMessage = "Safety Fault " + AxisToString(currentStatus.getAxis()) +
                        ":" + currentStatus.getErrorString();
                common::NotificationUpdate newUpdate("ACS",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR,
                                                     notificationMessage);
                emit signal_MCNotification(newUpdate);
            }
        }
    }

    if(errorExists)
        this->onAbortExecution();

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_MotorFaultUpdate(const std::vector<Status_MotorAxisFault> &motor)
{


    bool errorExists = false;

    std::map<MotorAxis,Status_AxisState>::iterator it;

    for(size_t index = 0; index < motor.size(); index++)
    {
        Status_MotorAxisFault currentStatus = motor.at(index);
        MotorAxis currentAxis = currentStatus.getAxis();
        if(currentStatus.isStatusValid())
        {

            if(!m_StateInterface->m_AxisState.at(currentAxis).m_MotorFault.set(currentStatus))
                continue;

            if(currentStatus.doesMotorFaultExist())
            {
                errorExists = true;
                std::string notificationMessage = "Motor Fault " + AxisToString(currentStatus.getAxis()) +
                        ":" + currentStatus.getErrorString();

                common::NotificationUpdate newUpdate("ACS",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR,
                                                     notificationMessage);
                emit signal_MCNotification(newUpdate);
            }
        }
    }

    if(errorExists)
        this->onAbortExecution();

    ProgressStateMachineStates();
}

void SPIIMotionController::SPIIPolling_SystemFaultUpdate(const Status_SystemFault &status)
{
    if(!status.isStatusValid())
        return;

    if(m_StateInterface->m_SystemFaults.set(status)) //this implies that something has indeed changed
    {
        if(status.doesSystemFaultExist())
        {
            common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                                 common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR,
                                                 "System Fault:");
            emit signal_MCNotification(newUpdate);

            this->onAbortExecution();
        }
        emit signal_ESTOPTriggered(status.isHardwareEmergencyStop());
    }

    ProgressStateMachineStates();
}


void SPIIMotionController::SPIIPolling_UnsolicitedMsgs(const std::vector<std::string> &msgs)
{
    for(size_t msgIndex = 0; msgIndex < msgs.size(); msgIndex++)
    {
        common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                             common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL,
                                             msgs.at(msgIndex));
        emit signal_MCNotification(newUpdate);
    }
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

    switch (state.getBufferStatus()) {
        case Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD:
        case Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING:

    {
        std::string msg = "Buffer: " + std::to_string(state.getBufferIndex()) + " Line Number: " + std::to_string(state.getErrorLine()) ;
        msg+=" " + state.getErrorString();
        common::NotificationUpdate newUpdate("ACS",ECMDevice::DEVICE_MOTIONCONTROL,
                                             common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR,
                                             msg);
        break;
    }
     default:
    {
        break;
    }
    }
}

void SPIIMotionController::NewBuffer_ProgramSuite(const bool &success, const SPII_CurrentProgram &program)
{
    this->onFinishedUploadingScript(success,program);
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

void SPIIMotionController::NewStatus_UploadedOperationalVariables(const bool &success, const Operation_VariableList &variableList)
{
    if(success)
    {
        m_StateInterface->m_MasterVariableValues->fromVariableList(variableList);

        m_StateInterface->m_BufferManager->updateUserVariables(variableList);

        this->onFinishedUploadingVariables(success,variableList);
    }
}

void SPIIMotionController::NewStatus_UserOperationalVariables(const bool &success, const Operation_VariableList &variableList)
{
    if(success)
    {
        m_StateInterface->m_MasterVariableValues->fromVariableList(variableList);

        m_StateInterface->m_BufferManager->updateUserVariables(variableList);

        emit signal_MCNewUserVariableList(variableList);
    }
}

void SPIIMotionController::NewStatus_CustomCommandReceived(const std::string &command, const std::string &response)
{
  emit signal_CustomUserRequestReceived(command,response);
}



