#include "galil_motion_controller.h"


galilMotionController::galilMotionController()
{
    std::vector<MotorAxis> availableAxis;
    availableAxis.push_back(MotorAxis::Z);

    stateInterface = new GalilStateInterface(availableAxis);
    stateMachine = new hsm::StateMachine();
    stateMachine->Initialize<ECM::Galil::State_Idle>(stateInterface);
    //if we begin issuing text commands we have to be careful how the state machine progresses
    stateMachine->UpdateStates();
    stateMachine->ProcessStateTransitions();

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
}

galilMotionController::~galilMotionController()
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

void galilMotionController::openConnection(const std::string &address)
{
    if(stateInterface->commsMarshaler->ConnectToLink(address)) //if true this means we have connected to the galil unit
    {
        //since we have now connected to the galil we can begin collecting information
        stateInterface->setConnected(true);
    }
}

void galilMotionController::closeConnection()
{
    if(stateInterface->commsMarshaler->DisconnetLink()) //if true this means we have disconnected from the galil unit
    {
        //since we have now disconnected from the galil we should stop collecting information
        stateInterface->setConnected(false);
    }
}

bool galilMotionController::saveSettings()
{
    m_Settings.saveSettings(settingsPath);
}

bool galilMotionController::saveSettingsAs(const std::string &filePath)
{
    settingsPath = QString::fromStdString(filePath);
    m_Settings.saveSettings(settingsPath);
}

bool galilMotionController::loadSettings(const std::string &filePath)
{
    settingsPath = QString::fromStdString(filePath);
    m_Settings.loadSettings(settingsPath);
}



void galilMotionController::LinkConnected() const
{
    galilPolling->beginPolling();
}


void galilMotionController::LinkDisconnected() const
{
    if(galilPolling)
    {
        galilPolling->pausePolling();
        galilPolling->stop();

    }
}

void galilMotionController::getProgramPath(std::string &filePath) const
{
    QFile file(programPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

void galilMotionController::getSettingsPath(std::string &filePath) const
{
    QFile file(settingsPath);
    QFileInfo fileInfo(file);
    filePath = fileInfo.absolutePath().toStdString();
}

bool galilMotionController::saveProgram(const std::string &text)
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

void galilMotionController::executeCommand(const AbstractCommand *command)
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

void galilMotionController::executeStringCommand(const std::string &stringCommand)
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

//    QString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);

//    std::string testString(buf);
//    size_t index = testString.find("\r\n");
//    if(index != std::string::npos)
//    {
//        //this means that it was found
//        std::string response = testString.substr (0,index);
//        std::cout<<"The string seen here is: "<<response<<std::endl;
//    }
//    std::cout<<"Command Executed."<<std::endl;
//    std::cout<<ParseGReturn::getGReturnString(rtn);
//    std::cout<<"Returned: "<<std::string(returnOut)<<std::endl;
}

bool galilMotionController::saveProgramAs(const std::string &filePath, const std::string &text)
{
    //this sets the current program file path
    programPath = QString::fromStdString(filePath);
    bool saved = this->saveProgram(text);
    return saved;
}

bool galilMotionController::loadProgram(const std::string &filePath, std::string &programText)
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


void galilMotionController::uploadProgram(const ProgramGeneric &program) const
{
    stateInterface->commsMarshaler->uploadProgram(program);
//    ECM::Galil::AbstractStateGalil* currentState = static_cast<ECM::Galil::AbstractStateGalil*>(stateMachine->getCurrentState());
//    //currentState->handleCommand();

//    //1) Stop the motion of the machine
//    CommandStop stop;
//    GCmd(galil,stop.getCommandString().c_str());
//    //GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
//    //2) Turn off the power supply
//    CommandSetBit setBit;
//    setBit.appendAddress(2);
//    GCmd(galil,setBit.getCommandString().c_str());

//    //3) Write the program
//    GReturn rtnCode = GProgramDownload(galil,programText.c_str(),0);
//    std::cout<<"The return code here is "<<std::endl;
}

void galilMotionController::downloadProgram() const
{
    stateInterface->commsMarshaler->downloadProgram();
//    GBufOut returnOut;
//    GSize read_bytes = 0; //bytes read in GCommand

//    //1) Stop the motion of the machine
//    CommandStop stop;
//    GCmd(galil,stop.getCommandString().c_str());
//    //GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
//    //2) Turn off the power supply
//    CommandSetBit setBit;
//    setBit.appendAddress(2);
//    GCmd(galil,setBit.getCommandString().c_str());

//    //rtn = GCommand(mConnection,setBit.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
//    //3) Read the program
//    char* buf = new char[10]();
//    GReturn rtnCode = GProgramUpload(galil,buf,10);


//    programText = std::string(buf);
//    delete[] buf;
}

void galilMotionController::cbi_GalilStatusRequestCommand(const AbstractRequest *request)
{
    stateInterface->transmitRequest(request);
}

