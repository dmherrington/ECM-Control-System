#include "ecm_logging.h"

ECMLogging::ECMLogging(const std::map<string, string> &softwareVersions):
    masterLog(nullptr), loggingInitialized(false), loggingEnabled(false), softwareVersioningMap(softwareVersions)
{

}

std::string ECMLogging::getLoggingPath() const
{
    return this->loggingPath;
}

bool ECMLogging::checkLoggingPath(const string &partNumber, const string &serialNumber) const
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

void ECMLogging::writeExecutionCollection(const ECMCommand_ExecuteCollection &collection)
{
    if (!configurationFile->open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonObject saveObject;
    QJsonArray segmentDataArray;

    std::map<unsigned int, ECMCommand_AbstractProfileConfigPtr> profileMap = collection.getCollection();
    std::map<unsigned int, ECMCommand_AbstractProfileConfigPtr>::iterator it = profileMap.begin();

    for (; it!=profileMap.end(); ++it)
    {
            ECMCommand_AbstractProfileConfigPtr operationConfiguration = it->second;
            QJsonObject operationObject;
            operationConfiguration->writeToJSON(operationObject);
            segmentDataArray.append(operationObject);
    }

    saveObject["configData"] = segmentDataArray;
    QJsonDocument saveDoc(saveObject);
    configurationFile->write(saveDoc.toJson());
    configurationFile->close();
}

void ECMLogging::enableLogging(const bool &enable)
{
    this->loggingEnabled = enable;
}

void ECMLogging::initializeLogging(const std::string &partNumber, const std::string &serialNumber, bool clearContents)
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
    QString fileNameConfig = QString::fromStdString(loggingPath) + "configuration" + ".json";

    masterLog = new QFile(fileName);
    configurationFile = new QFile(fileNameConfig);

    if(clearContents)
    {
        masterLog->open(QFile::WriteOnly | QIODevice::Text);
        masterLog->resize(0);
    }
    else{
        masterLog->open(QFile::WriteOnly | QFile::Append | QIODevice::Text);
    }


    loggingInitialized = true;
}

void ECMLogging::writeCurrentOperationalSettings(const std::string &operationalSettings)
{
    if(!loggingInitialized)
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter << QString::fromStdString(operationalSettings);

    stringWriter <<"\r\n";

    stringWriter.flush();
    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::beginLoggingOperationalData()
{
    if(!loggingInitialized)
        return;

    //Enable logging of any current machining information that comes through
    this->enableLogging(true);

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter<<"OPERATIONAL DATA: \n";
    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));

    stringWriter <<"\r\n";

    stringWriter.flush();
    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::writeProfileLoggingHeader(const std::string &partNumber, const std::string &serialNumber, const std::string &operationName,
                                    const std::string &profileName, const std::string &descriptor,
                                    const common::EnvironmentTime &time)
{
    if(!loggingInitialized)
        return;

    this->setLoggingStartTime(time);

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter << "Part Number #: " << QString::fromStdString(partNumber) << "\t" << "Serial Number #: " << QString::fromStdString(serialNumber) <<"\n";
    stringWriter << "Operation Name: " << QString::fromStdString(operationName) << "\t" <<"Machining Profile : " << QString::fromStdString(profileName) <<"\n";
    stringWriter << "Operation Time : " << time <<"\n";
    stringWriter << "Descriptor (Optional): " << QString::fromStdString(descriptor) <<"\r\n" <<"\r\n";

    this->WriteLogSoftwareVersions(stringWriter);

    stringWriter <<"\r\n";

    stringWriter.flush();
    QTextStream out(masterLog);
    out << str;

}

void ECMLogging::writePauseLoggingHeader(const std::string &partNumber, const std::string &serialNumber, const std::string &operationName,
                                    const std::string &descriptor,const common::EnvironmentTime &time)
{
    if(!loggingInitialized)
        return;

    this->setLoggingStartTime(time);

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter << "Part Number #: " << QString::fromStdString(partNumber) << "\t" << "Serial Number #: " << QString::fromStdString(serialNumber) <<"\n";
    stringWriter << "Operation Name: " << QString::fromStdString(operationName) << "\t" << "Operation Time : " << time <<"\n";
    stringWriter << "Descriptor (Optional): " << QString::fromStdString(descriptor) <<"\r\n" <<"\r\n";

    this->WriteLogSoftwareVersions(stringWriter);

    stringWriter <<"\r\n";

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter<<"THERE IS NO OPERATIONAL DATA OR SETTINGS FOR THIS TYPE OF OPERATION \n";
    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));

    stringWriter <<"\r\n";

    stringWriter.flush();
    QTextStream out(masterLog);
    out << str;

}

void ECMLogging::WriteLogSoftwareVersions(QTextStream &stringWriter)
{
    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter<<"SOFTWARE VERSION INFORMATION: \n";
    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));

    std::map<std::string,std::string>::iterator it = this->softwareVersioningMap.begin();

    for(; it != this->softwareVersioningMap.end(); ++it)
    {
        stringWriter<<QString::fromStdString(it->first)<<":"<<QString::fromStdString(it->second)<<"\n";
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
    if(!isComponentLogging())
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);
    uint64_t elapsedTime = (state.getObservationTime() - this->startLogTime)/1000.0; // this value is in milliseconds
    stringWriter << "POS|";
    stringWriter << state.getObservationTime().ToString() << "\t" << QString::number(elapsedTime) << "\t" << key.axisName << "|";
    stringWriter << state;
    stringWriter << "\n";
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
    stringWriter << "\n";
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
    stringWriter << "\n";
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

void ECMLogging::WriteConcludingOperationStats(const double &duration, const ProfileState_Machining::MACHININGProfileCodes &completionCode)
{
    if(!isComponentLogging())
        return;

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    stringWriter<<QString::fromStdString(ProfileState_Machining::MACHININGCodesToString(completionCode)) << "\n";
    stringWriter<<"Elapsed Seconds: " << QString::number(duration);
    stringWriter << "\n";
    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;
}

void ECMLogging::CloseMachiningLog(const double &duration)
{
    this->enableLogging(false);

    QString str;
    QTextStream stringWriter(&str, QIODevice::WriteOnly);

    stringWriter<<QString::fromStdString(this->WriteHeaderBreaker(100));
    //stringWriter<<QString::fromStdString(ProfileState_Machining::MACHININGCodesToString(completionCode)) << "\n";
    stringWriter<<"Collection Elapsed Time: " << QString::number(duration);
    stringWriter << "\n";
    stringWriter.flush();

    QTextStream out(masterLog);
    out << str;

    masterLog->close();
}

std::string ECMLogging::WriteHeaderBreaker(const unsigned int &size)
{
    std::string str;

    //Write header breaker line at the top
    for(size_t i = 0; i < size; i++)
    {
        str += "*";
    }

    //bump the header to the next line
    str += "\n";
    return str;
}

bool ECMLogging::isComponentLogging() const
{
    return loggingEnabled && loggingInitialized;
}


