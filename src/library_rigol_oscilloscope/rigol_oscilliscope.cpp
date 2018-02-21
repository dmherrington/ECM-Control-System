#include "rigol_oscilliscope.h"

RigolOscilliscope::RigolOscilliscope(QObject *parent) : QObject(parent)
{
    pollStatus = new RigolPollMeasurement();
    pollStatus->connectCallback(this);
    commsMarshaler = new comms::RigolCommsMarshaler();

    //Setting up the proper directory paths for all of the stuff
    char* ECMPath = getenv("ECM_ROOT");
    if(ECMPath){
        std::string rootPath(ECMPath);
        QDir measurmentDirectory(QString::fromStdString(rootPath + "/Rigol"));
        measurmentDirectory.mkpath(QString::fromStdString(rootPath + "/Rigol"));
        measurementPath = measurmentDirectory.absolutePath() + "/previousMeasurements.json";
    }

}

void RigolOscilliscope::openConnection(const std::string &ipAddress, const std::string &port)
{
    rigol::comms::TCPConfiguration newConfig;
    newConfig.setListenAddress(ipAddress);
    newConfig.setListenPortNumber(port);
    commsMarshaler->ConnectToLink(newConfig);
}

void RigolOscilliscope::closeConnection()
{
    commsMarshaler->DisconnetFromLink();
}

void RigolOscilliscope::addPollingMeasurement(const rigol::commands::MeasureCommand_Item &command)
{
    /*
     * First we should transmit this new polling measurement to the comms marshaler
     * the marshaler should handle this write command to setup the rigol to measure
     * such a command.
     */
    commsMarshaler->sendSetMeasurementCommand(command);
    //next we should copy this write command as a read command for the polling object
    rigol::commands::MeasureCommand_Item copyCommand(command);
    copyCommand.setReadOrWrite(data::ReadWriteType::READ);
    pollStatus->addPollingMeasurement(copyCommand);
}

void RigolOscilliscope::removePollingMeasurement(const std::string &key)
{
    pollStatus->removePollingMeasurement(key);
}

rigol::commands::RigolMeasurementQueue RigolOscilliscope::getCurrentPollingMeasurements() const
{
    return pollStatus->getCurrentPollingMeasurements();
}

void RigolOscilliscope::cbi_RigolMeasurementRequests(const commands::MeasureCommand_Item &request)
{
    commsMarshaler->sendMeasurementRequest(request);
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////
void RigolOscilliscope::ConnectionOpened() const
{
    std::cout<<"A connection has been opened to the rigol."<<std::endl;
    //In this case we need to initialize the oscilliscope to the desired settings
}
void RigolOscilliscope::ConnectionClosed() const
{
    std::cout<<"A connection has been closed to the rigol."<<std::endl;

}

void RigolOscilliscope::saveMeasurements()
{
    QFile saveFile(measurementPath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    rigol::commands::RigolMeasurementQueue currentQueue = pollStatus->getCurrentPollingMeasurements();
    currentQueue.write(saveObject);
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}

