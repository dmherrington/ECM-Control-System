#include "rigol_oscilliscope.h"

RigolOscilliscope::RigolOscilliscope(const std::string &name, QObject *parent):
    QObject(parent),
    deviceName(name)
{
    qRegisterMetaType<common::TupleSensorString>("TupleSensorString");
    qRegisterMetaType<common_data::SensorState>("SensorState");

    pollStatus = new RigolPollMeasurement();
    pollStatus->connectCallback(this);

    commsMarshaler = new comms_Rigol::RigolCommsMarshaler();
    commsMarshaler->AddSubscriber(this);
}

RigolOscilliscope::~RigolOscilliscope()
{

}

void RigolOscilliscope::openConnection(const std::string &ipAddress, const int &port)
{
    comms_Rigol::TCPConfiguration newConfig;
    newConfig.setListenAddress(ipAddress);
    newConfig.setListenPortNumber(port);
    commsMarshaler->ConnectToLink(newConfig);
}

void RigolOscilliscope::closeConnection()
{
    commsMarshaler->DisconnetFromLink();
}

bool RigolOscilliscope::isDeviceConnected() const
{
    return this->commsMarshaler->isDeviceConnected();
}

bool RigolOscilliscope::addPollingMeasurement(const commands_Rigol::MeasureCommand_Item &command)
{
    /*
     *  First we need to check if this type of measurement already exists
     */
    bool unique = this->queue.insertIntoQueue(command); //this function will return false if it already existed
    /*
     * Second we should transmit this new polling measurement to the comms marshaler
     * the marshaler should handle this write command to setup the rigol to measure
     * such a command.
     */
    if(unique)
    {
        //alert the plotting interface that new information will be available for plotting
        common::TupleSensorString sensorTuple(QString::fromStdString(command.getDeviceName()),
                                              QString::fromStdString(AvailableChannelsToDisplayString(command.getChannel())),
                                              QString::fromStdString(MeasurementTypeEnumToString(command.getMeasurementType())));

        emit signal_RigolPlottable(sensorTuple, true);

        commsMarshaler->sendSetMeasurementCommand(command);
        //next we should copy this write command as a read command for the polling object
        commands_Rigol::MeasureCommand_Item copyCommand(command);
        copyCommand.setReadOrWrite(data_Rigol::RigolRWType::READ);
        pollStatus->addPollingMeasurement(copyCommand);
        //executeMeasurementPolling(true); //we are not going to start polling until explicitly connected
    }
    return unique;
}

void RigolOscilliscope::removePollingMeasurement(const MeasureCommand_Item &command)
{
    this->queue.removeFromQueue(command.getCommandKey());

    //alert the plotting interface that this type of information will no longer be available for plotting
    common::TupleSensorString sensorTuple(QString::fromStdString(command.getDeviceName()),
                                          QString::fromStdString(AvailableChannelsToDisplayString(command.getChannel())),
                                          QString::fromStdString(MeasurementTypeEnumToString(command.getMeasurementType())));

    emit signal_RigolPlottable(sensorTuple, false);

    pollStatus->removePollingMeasurement(command.getCommandKey());
}

void RigolOscilliscope::executeMeasurementPolling(const bool &execute)
{
    if(!pollStatus->isThreadActive() && execute)
        pollStatus->beginPolling();
    else if(pollStatus->isThreadActive() && !execute)
        pollStatus->pausePolling();
}

commands_Rigol::RigolMeasurementQueue RigolOscilliscope::getCurrentPollingMeasurements() const
{
    return this->queue;
}

void RigolOscilliscope::cbi_RigolMeasurementRequests(const commands_Rigol::MeasureCommand_Item &request)
{
    commsMarshaler->sendMeasurementRequest(request);
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////

void RigolOscilliscope::LinkConnectionUpdate(const common::comms::CommunicationUpdate &update)
{
    switch (update.getUpdateType()) {
    case common::comms::CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        this->initializeRigol();
        break;
    }
    case common::comms::CommunicationUpdate::UpdateTypes::DISCONNECTED:
    {
        break;
    }
    default:
        break;
    }

    emit signal_RigolCommunicationUpdate(update);
}

void RigolOscilliscope::ConnectionOpened()
{

}

void RigolOscilliscope::ConnectionClosed() const
{

}

void RigolOscilliscope::initializeRigol()
{
    //In this case we need to initialize the oscilliscope to the desired settings
    commands_Rigol::AcquireCommand_TypePtr acquisitionType = std::make_shared<commands_Rigol::AcquireCommand_Type>();
    acquisitionType->setAcquisitionMode(data_Rigol::AcquireCommand_TypeMode::AVERAGE);
    commsMarshaler->sendAbstractAcquireCommand(acquisitionType);

    commands_Rigol::AcquireCommand_AveragePtr acquisitionAve = std::make_shared<commands_Rigol::AcquireCommand_Average>();
    acquisitionAve->setSampleNumbers(8);
    commsMarshaler->sendAbstractAcquireCommand(acquisitionAve);

    /*
     * There is a note in the trello card for two commands that seem to uncessary or not supported.
     * ACQ:MODE:RTIM  Labview is apparently sending this to set the acquisition mode to real time
     * vs equivalent time, but I cannot find this as a command in the manual
     *
     * The following command seems to be uncessary as we are never explicitly downloading the entire
     * waveform from the oscilloscope
     * :WAVeform:FORMat BYTE - setting the format to bytes currently, not necessary and up to you
     * on which data type you want to handle
     */

    //Next, we need to tell the Rigol which ones from the load to expect to read from
    std::vector<MeasureCommand_Item> writeQueue = this->queue.getMeasurementItems();
    for(size_t i = 0; i < this->queue.getQueueSize(); i++)
    {
        MeasureCommand_Item writeCommand = writeQueue.at(i);
        writeCommand.setReadOrWrite(data_Rigol::RigolRWType::WRITE);
        commsMarshaler->sendSetMeasurementCommand(writeCommand);
    }

    //Ken: This may no longer be needed on the initialization as it is now controlled through the API
    //executeMeasurementPolling(true);
}

void RigolOscilliscope::loadFromQueue(const commands_Rigol::RigolMeasurementQueue &updatedQueue)
{
    this->queue.clearQueue();
    this->pollStatus->pausePolling();
    this->pollStatus->clearQueue();

    std::vector<commands_Rigol::MeasureCommand_Item> measurementItems = updatedQueue.getMeasurementItems();
    for(int i = 0; i < measurementItems.size(); i++)
    {
        this->addPollingMeasurement(measurementItems.at(i));
    }
    emit signal_RigolLoadComplete();
}

void RigolOscilliscope::NewDataReceived(const std::vector<uint8_t> &buffer) const
{
    for(size_t i = 0; i < buffer.size(); i++)
    {
        std::cout<<buffer.at(i);
    }
}

void RigolOscilliscope::NewMeaurementReceived(const commands_Rigol::RigolMeasurementStatus &status) const
{
    //First check if the status is actually valid or garbage
    if(!status.isStatusValid())
        return;

    //First let us construct the tuple describing the measurement
    common::TupleSensorString sensorTuple(QString::fromStdString(status.getDeviceName()),
                                          QString::fromStdString(AvailableChannelsToDisplayString(status.getChannel())),
                                          QString::fromStdString(MeasurementTypeEnumToString(status.getMeasurementType())));
    common_data::SensorState newSensorMeasurement;
    newSensorMeasurement.setObservationTime(status.getMeasurementTime());

    switch (status.getMeasurementType()) {
    case data_Rigol::MeasurementTypes::MEASURE_VTOP:
    {
            newSensorMeasurement.ConstructSensor(common_data::SENSOR_VOLTAGE,"Voltage Top");
            ((common_data::SensorVoltage*)newSensorMeasurement.getSensorData().get())->SetVoltage(status.getMeasurementValue(),common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
            emit signal_RigolNewSensorValue(sensorTuple,newSensorMeasurement);
        break;
    }
    case data_Rigol::MeasurementTypes::MEASURE_MAREA:
    {
        newSensorMeasurement.ConstructSensor(common_data::SENSOR_MAREA,"Current Area");
        ((common_data::SensorMAREA*)newSensorMeasurement.getSensorData().get())->SetCurrentArea(status.getMeasurementValue(),common_data::MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS);
        emit signal_RigolNewSensorValue(sensorTuple,newSensorMeasurement);
        break;
    }
    default:
        break;
    }
}



