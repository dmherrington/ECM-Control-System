#include "galil_motion_controller.h"


GalilMotionController::GalilMotionController(const std::string &name):
    deviceName(name)
{
    qRegisterMetaType<common::TuplePositionalString>("TuplePositionalString");
    qRegisterMetaType<common_data::MachinePositionalState>("MachinePositionalState");

    qRegisterMetaType<MotionProfileState>("MotionProfileState");

    std::vector<MotorAxis> availableAxis;
    availableAxis.push_back(MotorAxis::Z);

    commsMarshaler = new Comms::CommsMarshaler();
    commsMarshaler->AddSubscriber(this);

    stateInterface = new GalilStateInterface(availableAxis);
    stateInterface->connectCallback(this);

    stateMachine = new hsm::StateMachine();
    stateMachine->Initialize<ECM::Galil::State_Idle>(stateInterface);
    //if we begin issuing text commands we have to be careful how the state machine progresses
    ProgressStateMachineStates();

    //Instantiating the galil state polling object. This is only needed to be done once within the program
    galilPolling = new GalilPollState();
    galilPolling->connectCallback(this);

    //    GReturn rtnCode = GOpen("169.254.78.101",&mConnection);

    //Setting up the proper directory paths for all of the stuff
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir profilesDirectory(QString::fromStdString(rootPath + "/Galil/profiles"));
        QDir programsDirectory(QString::fromStdString(rootPath + "/Galil/programs"));
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Galil/settings"));

        profilesDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/profiles"));
        programsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/programs"));
        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/settings"));

        profilesPath = profilesDirectory.absolutePath() + "/";
        programPath = programsDirectory.absolutePath() + "/";
        settingsPath = settingsDirectory.absolutePath() + "/generalSettings.json";
    }

    programPath += "DefaultGalilScript.txt";
    QFile openFile(programPath);

    if (!openFile.open(QIODevice::ReadOnly | QFile::Text)) {
        qWarning("Couldn't open default galil script file.");
    }
    QTextStream in(&openFile);
    defaultProgram.setProgramString(in.readAll().toStdString());
    openFile.close();
}

GalilMotionController::~GalilMotionController()
{
    if(stateMachine)
    {
        delete stateMachine;
        stateMachine = nullptr;
    }

    if(stateInterface)
    {
        delete stateMachine;
        stateMachine = nullptr;
    }

    if(galilPolling)
    {
        galilPolling->stop();
        delete galilPolling;
        galilPolling = nullptr;
    }
}

std::vector<common::TupleECMData> GalilMotionController::getPlottables() const
{
    std::vector<common::TupleECMData> rtn;

    common::TuplePositionalString tpString;
    tpString.axisName = QString::fromStdString(AxisToString(MotorAxis::Z));
    rtn.push_back(tpString);

    common::TupleProfileVariableString varString("","","ppos");
    rtn.push_back(varString);

    return rtn;
}

GalilCurrentProgram GalilMotionController::getCurrentMCProgram() const
{
    return *stateInterface->galilProgram;
}

void GalilMotionController::initializeMotionController()
{

    // 1: Stop all motion that may exist
    CommandStopPtr commandStop = std::make_shared<CommandStop>();
    this->commsMarshaler->sendAbstractGalilCommand(commandStop);
    //this->executeCommand(commandStop);

    // 2: Enable the air brake
    CommandMotorDisablePtr commandMotorDisable = std::make_shared<CommandMotorDisable>();
    //this->executeCommand(commandMotorDisable);
    this->commsMarshaler->sendAbstractGalilCommand(commandMotorDisable);

    // 3: Write the default galil script to the Galil

    //Add the appropriate lambda function to see the progress of the initialization upload
    this->AddLambda_FinishedUploadingScript(this,[this](const bool &success, const GalilCurrentProgram &program){
        if(success)
        {
            emit signal_MCNewProgramReceived(program);
        }else
        {

        }
    });

    CommandUploadProgramPtr commandUploadDefault = std::make_shared<CommandUploadProgram>();
    commandUploadDefault->setCurrentScript(defaultProgram.getProgramString());
    this->executeCommand(commandUploadDefault);


    //This is no longer needed here as it is performed in the protocol
    // 4: Execute the initial setup routine within the default script to establish variables etc
    // CommandExecuteProfilePtr commandExecuteSetup = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::SETUP,"setup");
    // this->executeCommand(commandExecuteSetup);

    //Add items to the galil polling queue so that we can stay up to date
    // 1: Request the position of the galil unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    common::TuplePositionalString tuplePos;
    tuplePos.axisName = "XAxis";
    requestTP->setTupleDescription(common::TupleECMData(tuplePos));
    galilPolling->addRequest(requestTP,100);
    // 2: Request the stop codes
    RequestStopCodePtr requestSC = std::make_shared<RequestStopCode>();
    common::TupleGeneralDescriptorString tupleSC("StopCodes");
    requestSC->setTupleDescription(common::TupleECMData(tupleSC));
    galilPolling->addRequest(requestSC,1000);
    // 3: Request the tell switches
    RequestTellSwitchesPtr requestTS = std::make_shared<RequestTellSwitches>();
    common::TupleGeneralDescriptorString tupleTS("TellSwitches");
    requestTS->setTupleDescription(common::TupleECMData(tupleTS));
    galilPolling->addRequest(requestTS,200);
    // 4: Request the current inputs
    RequestTellInputsPtr requestTI = std::make_shared<RequestTellInputs>();
    common::TupleGeneralDescriptorString tupleTI("TellInputs");
    requestTI->setTupleDescription(common::TupleECMData(tupleTI));
    galilPolling->addRequest(requestTI,1000);

    galilPolling->beginPolling();

}

void GalilMotionController::openConnection(const std::string &address)
{
    commsMarshaler->ConnectToLink(address); //if true this means we have connected to the galil unit
}

void GalilMotionController::closeConnection()
{
    CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();
    command->setDisableAxis(MotorAxis::Z);
    this->executeCommand(command);

    commsMarshaler->DisconnetLink();
}

bool GalilMotionController::isDeviceConnected() const
{
    return commsMarshaler->isDeviceConnected();
}

std::string GalilMotionController::getCurrentMCState() const
{
    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
    ECM::Galil::GalilState stateEnum = currentState->getCurrentState();
    return ECM::Galil::ECMStateToString(stateEnum);
}

StatusInputs GalilMotionController::getCurrent_MCDIO() const
{
    return this->stateInterface->statusInputs.get();
}

std::vector<common::TupleECMData> GalilMotionController::getAvailablePlottables() const
{
    std::vector<common::TupleECMData> rtn;
    common::TupleECMData bottomPositionECM(common::TupleProfileVariableString("","","ppos"));
    rtn.push_back(bottomPositionECM);
    return rtn;
}

void GalilMotionController::LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    emit signal_MotionControllerCommunicationUpdate(update);
}

void GalilMotionController::LinkConnected()
{
    //initialize the device
    this->initializeMotionController();

    //notify all listeners that we have connected
    common::comms::CommunicationUpdate connection;
    connection.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::CONNECTED);
    emit signal_MotionControllerCommunicationUpdate(connection);
}

void GalilMotionController::LinkDisconnected() const
{
    if(galilPolling)
    {
        galilPolling->pausePolling();
        galilPolling->stop();
    }

    common::comms::CommunicationUpdate connection;
    connection.setUpdateType(common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED);
    emit signal_MotionControllerCommunicationUpdate(connection);
}

void GalilMotionController::CustomUserRequestReceived(const string &request, const string &response)
{
    emit signal_CustomUserRequestReceived(request, response);
}

void GalilMotionController::StatusMessage(const std::string &msg) const
{
    UNUSED(msg);
}

void GalilMotionController::ErrorBadCommand(const CommandType &type, const std::string &description)
{
    //std::cout<<"There was a bad command when issuing: "<<type<<" and the response was: "<<description<<std::endl;
    emit signal_ErrorCommandCode(type, description);
}

void GalilMotionController::ErrorBadRequest(const RequestTypes &type, const std::string &description)
{
    //std::cout<<"There was a bad request when issuing: "<<requestType<<" and the response was: "<<description<<std::endl;
    emit signal_ErrorRequestCode(type, description);
}

void GalilMotionController::NewProgramUploaded(const bool &success, const GalilCurrentProgram &program)
{
    //Ken this should be updated to reflect the latest conditions of the program not just the script
    stateInterface->galilProgram->fromProgram(program);
    this->onFinishedUploadingScript(success,program);
}

void GalilMotionController::NewVariableListUploaded(const bool &success, const ProgramVariableList &list)
{
    //Ken this should be updated to reflect the latest conditions of the program not just the script
    stateInterface->galilProgram->setVariableList(list);
    this->onFinishedUploadingVariables(success,list);
}

void GalilMotionController::NewProgramDownloaded(const ProgramGeneric &program)
{
    stateInterface->galilProgram->setProgram(program.getProgramString());
    //emit signal_MCNewProgramReceived(program);

    //This process is actually automated in the comms marshaler
//    //We now have a new program, let us query for the available labels and variables
//    RequestListVariablesPtr requestVariables = std::make_shared<RequestListVariables>();
//    commsMarshaler->sendAbstractGalilRequest(requestVariables);
}

void GalilMotionController::NewStatusInputs(const StatusInputs &status)
{
    if(stateInterface->statusInputs.set(status))
    {
        ProgressStateMachineStates();

        emit signal_MCNewDigitalInput(status);
    }
}

void GalilMotionController::NewStatusPosition(const Status_Position &status)
{
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

}

void GalilMotionController::NewStatusMotorEnabled(const Status_MotorEnabled &status)
{
    if(stateInterface->getAxisStatus(status.getAxis())->setMotorEnabled(status.isMotorEnabled()))
    {
        ProgressStateMachineStates();
    }
}
void GalilMotionController::NewStatusMotorStopCode(const Status_StopCode &status)
{
    if(stateInterface->getAxisStatus(status.getAxis())->stopCode.set(status))
    {
        ProgressStateMachineStates();
    }
}

void GalilMotionController::NewStatusMotorInMotion(const Status_AxisInMotion &status)
{
    if(stateInterface->getAxisStatus(status.getAxis())->setMotorMoving(status.isMotorMoving()))
    {
        if(status.isMotorMoving()==false)
        {
            RequestStopCodePtr request = std::make_shared<RequestStopCode>();
            commsMarshaler->sendAbstractGalilRequest(request);
        }
        ProgressStateMachineStates();
    }
}

void GalilMotionController::NewStatusVariableValue(const Status_VariableValue &status)
{
    stateInterface->galilProgram->updateVariableValue(status.getVariableName(), status.getVariableValue());

    if(stateInterface->statusVariableValues->updateVariable(status))
    {

        //ProgressStateMachineStates();

        common::TupleProfileVariableString varTuple(QString::fromStdString(status.getProgramName()),
                                                    QString::fromStdString(status.getProfileName()),
                                                    QString::fromStdString(status.getVariableName()));
        emit signal_MCNewProfileVariableValue(varTuple,status.getVariableState());
    }
}

void GalilMotionController::NewStatusLabelList(const Status_LabelList &status)
{
    stateInterface->galilProgram->setLabelList(status.getLabelList());
    emit signal_MCNewProgramLabelList(status.getLabelList());
}

void GalilMotionController::NewStatusVariableList(const Status_VariableList &status)
{
    stateInterface->galilProgram->setVariableList(status.getVariableList());
    stateInterface->statusVariableValues->fromVariableList(status.getVariableList());

    emit signal_MCNewProgramVariableList(status.getVariableList());
}

void GalilMotionController::executeCommand(const AbstractCommandPtr command)
{
    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
    currentState->handleCommand(command);
    ProgressStateMachineStates();
}

void GalilMotionController::executeCustomCommands(const std::vector<std::string> &stringCommands)
{
    this->commsMarshaler->sendCustomGalilCommands(stringCommands);
}

void GalilMotionController::uploadProgramVariableList(const ProgramVariableList &varList)
{
    this->commsMarshaler->uploadGalilProfileVariables(varList);
}

void GalilMotionController::cbi_GalilStatusRequest(const AbstractRequestPtr request)
{
    commsMarshaler->sendAbstractGalilRequest(request);
}

void GalilMotionController::cbi_AbstractGalilCommand(const AbstractCommandPtr command)
{
    commsMarshaler->sendAbstractGalilCommand(command);
}

void GalilMotionController::cbi_AbstractGalilMotionCommand(const AbstractCommandPtr command)
{
    commsMarshaler->sendAbstractGalilMotionCommand(command);
}

void GalilMotionController::cbi_AbstractGalilRequest(const AbstractRequestPtr request)
{
    commsMarshaler->sendAbstractGalilRequest(request);
}

void GalilMotionController::cbi_AbstractGalilAddPolled(const AbstractRequestPtr request, const int &period)
{
    galilPolling->addRequest(request, period);
}

void GalilMotionController::cbi_AbstractGalilRemovePolled(const common::TupleECMData &tuple)
{
    galilPolling->removeRequest(tuple);
}

void GalilMotionController::cbi_GalilControllerGains(const CommandControllerGain &gains)
{
    commsMarshaler->sendGalilControllerGains(gains);
}

void GalilMotionController::cbi_GalilHomeIndicated(const bool &indicated)
{
    emit signal_GalilHomeIndicated(indicated);
}

void GalilMotionController::cbi_GalilTouchoffIndicated(const bool &indicated)
{
    emit signal_GalilTouchoffIndicated(indicated);
}

void GalilMotionController::cbi_NewMotionProfileState(const MotionProfileState &state)
{
    ProgressStateMachineStates();
    emit signal_GalilUpdatedProfileState(state);
    this->onNewMotionProfileState(state);
}

void GalilMotionController::cbi_GalilNewMachineState(const ECM::Galil::GalilState &state)
{
    emit signal_MCNewMotionState(QString::fromStdString(ECM::Galil::ECMStateToString(state)));
}

void GalilMotionController::cbi_GalilUploadProgram(const AbstractCommandPtr command)
{
    commsMarshaler->uploadProgram(command);
}

void GalilMotionController::cbi_GalilDownloadProgram(const AbstractCommandPtr command)
{
    commsMarshaler->downloadProgram(command);
}

void GalilMotionController::getProgramPath(std::string &filePath) const
{
    QFile file(programPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

bool GalilMotionController::saveProgram()
{
    QFile file(programPath);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream outStream(&file);
    outStream << QString::fromStdString(stateInterface->galilProgram->getProgram());
    file.close();
    return true;
}

bool GalilMotionController::saveProgramAs(const std::string &filePath)
{
    //this sets the current program file path
    programPath = QString::fromStdString(filePath);
    bool saved = this->saveProgram();
    return saved;
}

bool GalilMotionController::loadProgram(const std::string &filePath, std::string &programText)
{
    //this sets the current program file path
    programPath = QString::fromStdString(filePath);

    QFile file(programPath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream inStream(&file);
    programText = inStream.readAll().toStdString();
    file.close();
    return true;
}

void GalilMotionController::getSettingsPath(std::string &filePath) const
{
    QFile file(settingsPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

bool GalilMotionController::saveSettings()
{
    m_Settings.saveSettings(settingsPath);
}

bool GalilMotionController::saveSettingsAs(const std::string &filePath)
{
    settingsPath = QString::fromStdString(filePath);
    m_Settings.saveSettings(settingsPath);
}

bool GalilMotionController::loadSettings(const std::string &filePath)
{
    settingsPath = QString::fromStdString(filePath);
    m_Settings.loadSettings(settingsPath);
}

std::string GalilMotionController::getLogOfOperationalSettings() const
{
    std::string str;
    str += "GALIL MOTION CONTROL PROGRAM: \n";
    str += stateInterface->galilProgram->getProgram();
    str += "GALIL MOTION CONTROL VARIABLE SETTINGS: \n";
    str += stateInterface->galilProgram->getVariableList().getLoggingString();
    return str;
}

//!
//! \brief Cause the state machine to update it's states
//!
void GalilMotionController::ProgressStateMachineStates()
{
//    m_Mutex_StateMachine.lock();
    stateMachine->ProcessStateTransitions();
    stateMachine->UpdateStates();
//    m_Mutex_StateMachine.unlock();
}
