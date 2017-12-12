#include "galil_motion_controller.h"


galilMotionController::galilMotionController()
{
//    GReturn rtnCode = GOpen("169.254.78.101",&mConnection);

    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir settingsDirectory(QString::fromStdString(rootPath + "/Galil/settings"));
        QDir programsDirectory(QString::fromStdString(rootPath + "/Galil/programs"));

        settingsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/settings"));
        programsDirectory.mkpath(QString::fromStdString(rootPath + "/Galil/programs"));

        settingsPath = settingsDirectory.absolutePath() + "/generalSettings.json";
        programPath = programsDirectory.absolutePath() + "/";
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

void galilMotionController::openConnection(const std::string &address)
{
    GReturn rtnCode = GOpen(address.c_str(),&mConnection);
    if(rtnCode == G_NO_ERROR) //this means the port was opened successfully
        emit commsStatus(true);

    //in this case we do not emit a change as we don't necessarily know the previous state

//    std::string errorString = ParseGReturn::getGReturnString(rtnCode);
//    emit currentErrorCode(errorString);
}

void galilMotionController::closeConnection()
{
    GReturn rtnCode = GClose(mConnection);
    if(rtnCode == G_NO_ERROR) //this means the port was closed successfully
        emit commsStatus(false);

    //in this case we do not emit a change as we don't necessarily know the previous state

//    std::string errorString = ParseGReturn::getGReturnString(rtnCode);
//    emit currentErrorCode(errorString);
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
    std::string commandString = command->getCommandString();
    std::cout<<"The command string seen here is: "<<commandString<<std::endl;
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand
    //We should be checking that the connection is defined
    GReturn rtn = GCmd(mConnection,commandString.c_str());
    //GReturn rtn = GCommand(mConnection,commandString.c_str(),returnOut,sizeof(returnOut),&read_bytes);
    std::cout<<"Command Executed: "<<CommandToString(command->getCommandType())<<std::endl;
    std::cout<<ParseGReturn::getGReturnString(rtn)<<std::endl;
    //std::cout<<"Returned: "<<std::string(returnOut)<<std::endl;
    if((command->getCommandType() == CommandType::JOG_MOVE) || (command->getCommandType() == CommandType::RELATIVE_MOVE))
    {
        GCmd(mConnection,"BG A");
        //we need to begin the command in these cases
        //GCommand(mConnection,"BG A",returnOut,sizeof(returnOut),&read_bytes);
    }
}

void galilMotionController::executeStringCommand(const std::string &stringCommand)
{
    std::cout<<"The command string seen here is: "<<stringCommand<<std::endl;
    char buf[1024];
    GSize read_bytes = 0; //bytes read in GCommand
    //GCmd(mConnection,stringCommand.c_str());
    GReturn rtn = GCommand(mConnection,stringCommand.c_str(),buf,sizeof(buf),&read_bytes);
    if(rtn == G_BAD_RESPONSE_QUESTION_MARK)
    {
        std::string newCommand = "TC 1";
        GReturn rtn = GCommand(mConnection,newCommand.c_str(),buf,sizeof(buf),&read_bytes);
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

void galilMotionController::uploadProgram(const std::string &programText)
{
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand

    //1) Stop the motion of the machine
    CommandStop stop;
    GCmd(mConnection,stop.getCommandString().c_str());
    //GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //2) Turn off the power supply
    CommandSetBit setBit;
    setBit.appendAddress(2);
    GCmd(mConnection,setBit.getCommandString().c_str());

    //3) Write the program
    GReturn rtnCode = GProgramDownload(mConnection,programText.c_str(),0);
    std::cout<<"The return code here is "<<std::endl;
}

void galilMotionController::downloadProgram(std::string &programText)
{
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand

    //1) Stop the motion of the machine
    CommandStop stop;
    GCmd(mConnection,stop.getCommandString().c_str());
    //GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //2) Turn off the power supply
    CommandSetBit setBit;
    setBit.appendAddress(2);
    GCmd(mConnection,setBit.getCommandString().c_str());

    //rtn = GCommand(mConnection,setBit.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //3) Read the program
    char* buf = new char[10]();
    GReturn rtnCode = GProgramUpload(mConnection,buf,10);


    programText = std::string(buf);
    delete[] buf;
}

