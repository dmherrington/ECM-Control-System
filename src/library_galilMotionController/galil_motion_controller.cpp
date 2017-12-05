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
    GReturn rtnCode = GClose(&mConnection);
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
    //1) Stop the motion of the machine

    //2) Turn off the power supply

    //3) Read the program

    GReturn rtnCode = GProgramDownload(&mConnection,programText.c_str(),nullptr);
}

void galilMotionController::downloadProgram(std::string &programText)
{
    //1) Stop the motion of the machine
    CommandStop stopMachine;
    //2) Turn off the power supply

    //3)

    //4) Read the program

    GBufOut onboardProgram;
    GSize programSize = 0;

    GReturn rtnCode = GProgramUpload(&mConnection,onboardProgram,programSize);
    programText = std::string(onboardProgram);
}

