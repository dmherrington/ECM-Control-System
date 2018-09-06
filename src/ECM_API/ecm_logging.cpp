#include "ecm_logging.h"

ECMLogging::ECMLogging(const std::map<string, string> &softwareVersions):
    masterLog(nullptr), loggingInitialized(false), loggingEnabled(false), softwareVersioningMap(softwareVersions)
{

}

bool ECMLogging::checkLoggingPath(const string &partNumber, const string &serialNumber)
{
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        //set up the root folder directory based on the part number

        QDir partDirectory(QString::fromStdString(rootPath + "/logs/PartNumber_" + partNumber + "/"));
        if(!partDirectory.exists() || partDirectory.isEmpty())
            return true;

        std::string newPath = "SerialNumber_";
        std::string finalPath = newPath + serialNumber;

        QDir serialDirectory(QString::fromStdString(rootPath + "/logs/PartNumber_" + partNumber + "/" + finalPath));
        if(!serialDirectory.exists() || serialDirectory.isEmpty())
            return true;
    }
    return false;
}

void ECMLogging::enableLogging(const bool &enable)
{
    this->loggingEnabled = enable;
}

void ECMLogging::initializeLogging(const string &partNumber, const string &serialNumber, const common::EnvironmentTime &time, bool clearContents)
{
    std::string logName = "machiningLogs";
    loggingPath = "";
    char* ECMPath = getenv("ECM_ROOT");

    if(ECMPath){
        std::string rootPath(ECMPath);
        //set up the root folder directory based on the part number

        QDir loggingDirectory(QString::fromStdString(rootPath + "/logs/PartNumber_" + partNumber + "/"));

        std::string newPath = "SerialNumber_";
        std::string finalPath = newPath + serialNumber;

        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/logs/PartNumber_" + partNumber + "/"));

        if(!loggingDirectory.mkdir(QString::fromStdString(finalPath)))
            std::cout<<"The folder already exists."<<std::endl;

        loggingPath = loggingDirectory.absolutePath().toStdString() + "/" + finalPath + "/";
    }

    QString fileName = QString::fromStdString(loggingPath) + QString::fromStdString(logName) + ".out";
    masterLog = new QFile(fileName);
    masterLog->open(QIODevice::WriteOnly);
    masterLog->resize(0);

    this->setLoggingStartTime(time);

    loggingInitialized = true;
}

void ECMLogging::writeLoggingHeader(std::string &munkText, std::string &pumpText, std::string &mtnCtrlText)
{
    if(!loggingInitialized)
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    //Let us write the header contents

    //Let us write the software versions here
    this->WriteHeaderBreaker(100);
    stringWriter<<"SOFTWARE VERSIONS \r\n";
    this->WriteLogSoftwareVersions(stringWriter);
    this->WriteHeaderBreaker(100);

    //Let us write the power supply settings here
    this->WriteHeaderBreaker(100);
    stringWriter<<"POWER SUPPLY SETTINGS \r\n";
    stringWriter<<QString::fromStdString(munkText);
    this->WriteHeaderBreaker(100);

    //Let us write the pump settings here
    this->WriteHeaderBreaker(100);
    stringWriter<<"PUMP SETTINGS \r\n";
    stringWriter<<QString::fromStdString(pumpText);
    this->WriteHeaderBreaker(100);

    //Let us write the motion controller settings here
    this->WriteHeaderBreaker(100);
    stringWriter<<"MOTION CONTROL SETTINGS \r\n";
    stringWriter<<QString::fromStdString(mtnCtrlText);
    this->WriteHeaderBreaker(100);

    stringWriter.flush();

    QTextStream outFile(masterLog);
    outFile << str;

}

void ECMLogging::setLoggingRelativeTime(const bool &value)
{
    this->logReglativeTime = value;
}

bool ECMLogging::isLoggingRelativeTime() const
{
    return this->logReglativeTime;
}

void ECMLogging::setLoggingStartTime(const common::EnvironmentTime &time)
{
    this->startLogTime = time;
}

void ECMLogging::WriteLogMachinePositionalState(const common::TuplePositionalString &key, const common_data::MachinePositionalState &state)
{
    if(!isComponentLogging())
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "POS|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.axisName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::WriteLogProfileVariableState(const common::TupleProfileVariableString &key, const common_data::MotionProfileVariableState &state)
{
    if(!isComponentLogging())
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "PVS|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.programName << "\t" << key.profileName << "\t" << key.variableName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::WriteLogSensorState(const common::TupleSensorString &key, const common_data::SensorState &state)
{

    if(!isComponentLogging())
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "S|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.sourceName << "\t" << key.sensorName << "\t" << key.measurementName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::SetSensorLogFile(const common::TupleSensorString &key)
{
    QString fileName = QString::fromStdString(loggingPath) + key.HumanName()+ ".out";
    QFile* outFile = new QFile(fileName);
    outFile->open(QIODevice::WriteOnly);
    outFile->resize(0);
    m_LogSensorStates[key] = outFile;
}

void ECMLogging::WriteLogSoftwareVersions(QTextStream &stringWriter)
{
    std::map<std::string,std::string>::iterator it = this->softwareVersioningMap.begin();

    for(; it != this->softwareVersioningMap.end(); ++it)
    {
        stringWriter<<QString::fromStdString(it->first)<<":"<<QString::fromStdString(it->second)<<"\r\n";
    }

    stringWriter<<"\r\n";
}

void ECMLogging::WriteHeaderBreaker(const unsigned int &size)
{
    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    //Write header breaker line at the top
    for(size_t i = 0; i < size; i++)
    {
        stringWriter << "*";
    }
    //bump the header to the next line
    stringWriter << "\r\n";

    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;
}

bool ECMLogging::isComponentLogging() const
{
    return loggingEnabled && loggingInitialized;
}


