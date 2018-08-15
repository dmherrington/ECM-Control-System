#include "ecm_logging.h"

ECMLogging::ECMLogging():
    masterLog(nullptr), loggingInitialized(false), loggingEnabled(false)
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

bool ECMLogging::isComponentLogging() const
{
    return loggingEnabled && loggingInitialized;
}
