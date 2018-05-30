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
    stateMachine->UpdateStates();
    stateMachine->ProcessStateTransitions();

    //Instantiating the galil state polling object. This is only needed to be done once within the program
    galilPolling = new GalilPollState();
    galilPolling->connectCallback(this);

    // 1: Request the position of the galil unit
    RequestTellPositionPtr requestTP = std::make_shared<RequestTellPosition>();
    galilPolling->addRequest(requestTP,20);
    // 2: Request the stop codes
    RequestStopCodePtr requestSC = std::make_shared<RequestStopCode>();
    galilPolling->addRequest(requestTP,200);
    // 3: Request the tell switches
    RequestTellSwitchesPtr requestTS = std::make_shared<RequestTellSwitches>();
    galilPolling->addRequest(requestTP,200);
    // 4: Request the current inputs
    RequestTellInputsPtr requestTI = std::make_shared<RequestTellInputs>();
    galilPolling->addRequest(requestTP,50);

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

void GalilMotionController::openConnection(const std::string &address)
{
    commsMarshaler->ConnectToLink(address); //if true this means we have connected to the galil unit
}

void GalilMotionController::closeConnection()
{
    if(commsMarshaler->DisconnetLink()) //if true this means we have disconnected from the galil unit
    {
        //since we have now disconnected from the galil we should stop collecting information
        stateInterface->setConnected(false);
    }
}

std::string GalilMotionController::getCurrentMCState() const
{
    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
    ECM::Galil::ECMState stateEnum = currentState->getCurrentState();
    return ECM::Galil::ECMStateToString(stateEnum);
}

std::vector<common::TupleECMData> GalilMotionController::getAvailablePlottables() const
{
    std::vector<common::TupleECMData> rtn;
    common::TupleECMData bottomPositionECM(common::TupleProfileVariableString("","","ppos"));
    rtn.push_back(bottomPositionECM);
    return rtn;
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

void GalilMotionController::LinkConnected() const
{
    stateInterface->setConnected(true);
    galilPolling->beginPolling();

    common::comms::CommunicationConnection connectionUpdate(deviceName,true);
    emit signal_MotionControllerConnectionUpdate(connectionUpdate);
}

void GalilMotionController::LinkDisconnected() const
{
    if(galilPolling)
    {
        galilPolling->pausePolling();
        galilPolling->stop();
    }
    common::comms::CommunicationConnection connectionUpdate(deviceName,true);
    emit signal_MotionControllerConnectionUpdate(connectionUpdate);
}

void GalilMotionController::ErrorBadCommand(const std::string &commandType, const std::string &description)
{
    UNUSED(commandType);
    UNUSED(description);
}

void GalilMotionController::NewProgramUploaded(const ProgramGeneric &program)
{
    UNUSED(program);
}

void GalilMotionController::NewProgramDownloaded(const ProgramGeneric &program)
{
    UNUSED(program);
}

void GalilMotionController::NewStatusInputs(const StatusInputs &status)
{
    if(stateInterface->statusInputs.set(status))
    {
        stateMachine->UpdateStates();
        stateMachine->ProcessStateTransitions();
    }
}

void GalilMotionController::NewStatusPosition(const Status_Position &status)
{
    common::TuplePositionalString tuple;
    tuple.axisName = QString::fromStdString(AxisToString(status.getAxis()));
    common_data::PositionalStatePtr position = std::make_shared<common_data::PositionalState>();
    position->setStateAxis(status.getAxis());
    position->setAxisPosition(status.getPosition());
    common_data::MachinePositionalState state;
    state.setObservationTime(status.getTime());
    state.setPositionalState(position);

    emit signal_MCNewPosition(tuple,state);
}

void GalilMotionController::NewStatusMotorEnabled(const Status_MotorEnabled &status)
{
    if(stateInterface->getAxisStatus(status.getAxis())->setMotorEnabled(status.isMotorEnabled()))
    {
        stateMachine->UpdateStates();
        stateMachine->ProcessStateTransitions();
    }
}
void GalilMotionController::NewStatusMotorStopCode(const Status_StopCode &status)
{
    if(stateInterface->getAxisStatus(status.getAxis())->stopCode.set(status))
    {
        stateMachine->UpdateStates();
        stateMachine->ProcessStateTransitions();
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
        stateMachine->UpdateStates();
        stateMachine->ProcessStateTransitions();
    }
}

void GalilMotionController::NewStatusVariableValue(const Status_VariableValue &status)
{
    if(stateInterface->statusVariableValues->updateVariable(status))
    {
        stateMachine->UpdateStates();
        stateMachine->ProcessStateTransitions();
    }
}

void GalilMotionController::NewStatusVariableList(const Status_VariableList &status)
{
    stateInterface->galilProgram->setVariableList(status.getVariableList());
}

void GalilMotionController::getProgramPath(std::string &filePath) const
{
    QFile file(programPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

void GalilMotionController::getSettingsPath(std::string &filePath) const
{
    QFile file(settingsPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

bool GalilMotionController::saveProgram(const std::string &text)
{
    QFile file(programPath);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream outStream(&file);
    outStream << QString::fromStdString(text);
    file.close();
    return true;
}

void GalilMotionController::executeCommand(const AbstractCommand *command)
{
    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
    currentState->handleCommand(command);
    stateMachine->ProcessStateTransitions();
    /*
    std::string commandString = command->getCommandString();
    std::cout<<"The command string seen here is: "<<commandString<<std::endl;
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand
    //We should be checking that the connection is defined
    GReturn rtn = GCmd(galil,commandString.c_str());
    //GReturn rtn = GCommand(mConnection,commandString.c_str(),returnOut,sizeof(returnOut),&read_bytes);
    std::cout<<"Command Executed: "<<CommandToString(command->getCommandType())<<std::endl;
    std::cout<<ParseGReturn::getGReturnString(rtn)<<std::endl;
    //std::cout<<"Returned: "<<std::string(returnOut)<<std::endl;
    if((command->getCommandType() == CommandType::JOG_MOVE) || (command->getCommandType() == CommandType::RELATIVE_MOVE))
    {
        GCmd(galil,"BG A");
        //we need to begin the command in these cases
        //GCommand(mConnection,"BG A",returnOut,sizeof(returnOut),&read_bytes);
    }
    */
}

void GalilMotionController::executeStringCommand(const std::string &stringCommand)
{
    std::cout<<"The command string seen here is: "<<stringCommand<<std::endl;
    char buf[1024];
    GSize read_bytes = 0; //bytes read in GCommand
    //GCmd(mConnection,stringCommand.c_str());
    GReturn rtn = GCommand(galil,stringCommand.c_str(),buf,sizeof(buf),&read_bytes);
    if(rtn == G_BAD_RESPONSE_QUESTION_MARK)
    {
        std::string newCommand = "TC 1";
        GReturn rtn = GCommand(galil,newCommand.c_str(),buf,sizeof(buf),&read_bytes);
        std::cout<<"Trying to figure out why there is an error"<<std::endl;
    }
    else{
        QString result = QString::fromUtf8(buf);
        QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
        result = list.at(0);
        result = result.trimmed();
        std::string testString = result.toStdString();
        std::cout<<"The string seen here is: "<<testString<<std::endl;
    }
}

bool GalilMotionController::saveProgramAs(const std::string &filePath, const std::string &text)
{
    //this sets the current program file path
    programPath = QString::fromStdString(filePath);
    bool saved = this->saveProgram(text);
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

void GalilMotionController::cbi_AbstractGalilAddPolled(const AbstractRequestPtr request)
{
    galilPolling->addRequest(request);
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

void GalilMotionController::cbi_NewMotionProfileState(const MotionProfileState &state)
{
    emit signal_GalilUpdatedProfileState(state);
}

void GalilMotionController::cbi_GalilNewMachineState(const std::string &state)
{
    emit signal_MCNewMotionState(state);
}

void GalilMotionController::cbi_GalilUploadProgram(const AbstractCommandPtr command)
{
    commsMarshaler->uploadProgram(command);
}

void GalilMotionController::cbi_GalilDownloadProgram(const AbstractCommandPtr command)
{
    commsMarshaler->downloadProgram(command);
}
