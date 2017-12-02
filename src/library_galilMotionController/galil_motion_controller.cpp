#include "galil_motion_controller.h"


galilMotionController::galilMotionController():
    mConnection(nullptr)
{
    //GReturn rtnCode = GOpen("",&mConnection);
    //GCon g, GCStringIn command, GBufOut buffer, GSize buffer_len, GSize* bytes_returned)
    std::string command = "_TPA";

//    Data::EnvironmentTime currentTime;
//    Data::EnvironmentTime::CurrentTime(Data::Devices::SYSTEMCLOCK, currentTime);

//    char* MACEPath = getenv("ECM_ROOT");
//    std::string loggingPath = "";
//    if(MACEPath){
//        std::string rootPath(MACEPath);
//        //rootPath += "/logs/";
//        QDir loggingDirectory(QString::fromStdString(rootPath + "/logs/"));

//        std::string newPath = currentTime.dateString() + "_Test_";
//        int testIndex = 0;
//        std::string finalPath = newPath + std::to_string(testIndex);

//        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/logs/"));
//        while(!loggingDirectory.mkdir(QString::fromStdString(finalPath)))
//        {
//            testIndex++;
//            finalPath = newPath + std::to_string(testIndex);
//        }
//        loggingPath = loggingDirectory.absolutePath().toStdString() + "/" + finalPath;

//        std::cout << "The current MACE_ROOT path is: " << rootPath << std::endl;
//        filename = rootPath + kPathSeparator + "MaceSetup.xml";
//    }else{
//        filename = "MaceSetup2.xml";
//    }

}

bool galilMotionController::saveProgram(const std::string &text)
{
//    QFile file(QString::fromStdString(filePath));
//    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
//        QTextStream outStream(&file);
//        outStream << QString::fromStdString(text);
//        file.close();
//    }
}


bool galilMotionController::saveProgramAs(const std::string &filePath, const std::string &text)
{
    QFile file(QString::fromStdString(filePath));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream outStream(&file);
    outStream << QString::fromStdString(text);
    file.close();
    return true;
}

bool galilMotionController::loadProgram(const std::string &filePath, std::string &programText)
{
    QFile file(QString::fromStdString(filePath));
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

}

void galilMotionController::downloadProgram(std::string &programText)
{

}
