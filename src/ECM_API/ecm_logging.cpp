#include "ecm_logging.h"

ECMLogging::ECMLogging()
{
    loggingPath = "";
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir loggingDirectory(QString::fromStdString(rootPath + "/logs/PartNumber/"));

        std::string newPath = "SerialNumber_";
        int testIndex = 0;
        std::string finalPath = newPath + std::to_string(testIndex);

        loggingDirectory.mkpath(QString::fromStdString(rootPath + "/logs/PartNumber/"));
        if(!loggingDirectory.mkdir(QString::fromStdString(finalPath)))
            std::cout<<"The file already exists."<<std::endl;

        loggingPath = loggingDirectory.absolutePath().toStdString() + "/" + finalPath;
    }
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
    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "POS|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.axisName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    //QTextStream out(m_LogProfileVariableStates[key]);
    //out << str;
}

void ECMLogging::WriteLogProfileVariableState(const common::TupleProfileVariableString &key, const common_data::MotionProfileVariableState &state)
{
    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "PVS|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.programName << "\t" << key.profileName << "\t" << key.variableName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    QTextStream out(m_LogProfileVariableStates[key]);
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

void ECMLogging::WriteLogSensorState(const common::TupleSensorString &key, const common_data::SensorState &state)
{
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    stringWriter << "S|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.sourceName << "\t" << key.sensorName << "\t" << key.measurementName << "|";
    stringWriter << state;
    stringWriter << "\r\n";
    stringWriter.flush();

    QTextStream out(m_LogSensorStates[key]);
    out << str;
}
