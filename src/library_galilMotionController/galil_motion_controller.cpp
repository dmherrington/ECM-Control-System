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
    GReturn rtn = GCommand(mConnection,commandString.c_str(),returnOut,sizeof(returnOut),&read_bytes);
    std::cout<<"Command Executed: "<<CommandToString(command->getCommandType());
    std::cout<<ParseGReturn::getGReturnString(rtn);
    std::cout<<"Returned: "<<std::string(returnOut)<<std::endl;
    if((command->getCommandType() == CommandType::JOG_MOVE) || (command->getCommandType() == CommandType::RELATIVE_MOVE))
    {
        //we need to begin the command in these cases
        GCommand(mConnection,"BG A",returnOut,sizeof(returnOut),&read_bytes);
    }
}

void galilMotionController::executeStringCommand(const std::string &stringCommand)
{
    std::cout<<"The command string seen here is: "<<stringCommand<<std::endl;
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand
    GReturn rtn = GCommand(mConnection,stringCommand.c_str(),returnOut,sizeof(returnOut),&read_bytes);
    std::cout<<"Command Executed."<<std::endl;
    std::cout<<ParseGReturn::getGReturnString(rtn);
    std::cout<<"Returned: "<<std::string(returnOut)<<std::endl;
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
    GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //2) Turn off the power supply
    CommandSetBit setBit;
    setBit.appendAddress(2);
    rtn = GCommand(mConnection,setBit.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //3) Write the program
    GReturn rtnCode = GProgramDownload(&mConnection,programText.c_str(),nullptr);
}

void galilMotionController::downloadProgram(std::string &programText)
{
    GBufOut returnOut;
    GSize read_bytes = 0; //bytes read in GCommand

    //1) Stop the motion of the machine
    CommandStop stop;
    GReturn rtn = GCommand(mConnection,stop.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //2) Turn off the power supply
    CommandSetBit setBit;
    setBit.appendAddress(2);
    rtn = GCommand(mConnection,setBit.getCommandString().c_str(),returnOut,sizeof(returnOut),&read_bytes);
    //3) Read the program

    GBufOut onboardProgram;
    GSize programSize = 0;

    GReturn rtnCode = GProgramUpload(&mConnection,onboardProgram,programSize);
    programText = std::string(onboardProgram);
}

