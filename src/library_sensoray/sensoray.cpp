#include "sensoray.h"

Sensoray::Sensoray(const std::string &name, QObject *parent):
    QObject(parent),
    ICommunication(),
    commsMarshaler(nullptr),
    deviceName(name)
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

    deviceName = name;

    commsMarshaler = std::make_shared<comms_Sensoray::CommsMarshaler>();
    commsMarshaler->AddSubscriber(this);

    m_PollingObj = new SensorayPollMachine();
    m_PollingObj->updateCommsProtocol(commsMarshaler);
    m_PollingObj->beginPolling();
}


///////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from Sensoray device
///////////////////////////////////////////////////////////////////////////

void Sensoray::openConnection(const comms_Sensoray::SensorayTCPConfiguration &config)
{
    commsMarshaler->ConnectToLink(config);
}

void Sensoray::closeConnection()
{
    commsMarshaler->DisconnetFromLink();
}

bool Sensoray::isDeviceConnected() const
{
    return commsMarshaler->isLinkConnected();
}

///////////////////////////////////////////////////////////////////////////
/// Methods supporting the Connect/Disconnect from accompanying RS485 port
///////////////////////////////////////////////////////////////////////////

bool Sensoray::isSerialDeviceReadyToConnect() const
{
    return commsMarshaler->isLinkConnected();
}

void Sensoray::openSerialPortConnection(const common::comms::SerialConfiguration &config) const
{
    commsMarshaler->ConnectToSerialPort(config);
}

void Sensoray::openEthernetPortConnection(const common::comms::TCPConfiguration &config) const
{
    UNUSED(config);
}

void Sensoray::closePortConnection() const
{
    commsMarshaler->DisconnetFromSerialPort();
}

void Sensoray::readModbusDataPort(const ModbusRegister &regMsg) const
{
    UNUSED(regMsg);
}
void Sensoray::writeModbusDataPort(const ModbusRegister &regMsg) const
{
    UNUSED(regMsg);
    //commsMarshaler->WriteToSerialPort(msg);
}

bool Sensoray::isModbusPortOpen() const
{
    return false;
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////

//!
//! \brief Sensoray::ConnectionStatusUpdated
//! \param update
//!
void Sensoray::ConnectionStatusUpdated(const common::comms::CommunicationUpdate &update) const
{
    if(update.getUpdateType() == common::comms::CommunicationUpdate::UpdateTypes::CONNECTED)
    {
        this->initializeSensoray();
        emit signal_SensorayCommunicationUpdate(update);

        common::NotificationUpdate newUpdate(deviceName,ECMDevice::DEVICE_SENSORAY,common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
        newUpdate.setPeripheralMessage("Sensoray Device connected.");
        emit signal_SensoryNotificationUpdate(newUpdate);
    }
    else
    {
        emit signal_SensorayCommunicationUpdate(update);

        common::NotificationUpdate newUpdate(deviceName,ECMDevice::DEVICE_SENSORAY,common::NotificationUpdate::NotificationTypes::NOTIFICATION_ALERT);
        newUpdate.setPeripheralMessage("Sensoray Device unable to connect.");
        emit signal_SensoryNotificationUpdate(newUpdate);
    }
}

void Sensoray::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    emit signal_PortUpdate(update);
}

void Sensoray::NewDataReceived(const QByteArray &buffer) const
{
    emit signal_RXNewPortData(buffer);
}

void Sensoray::ReceivedUpdatedADC(const std::vector<S2426_ADC_SAMPLE> data) const
{
    for(size_t i = 0; i < data.size(); i++)
    {
        std::string sensorName = "Channel " + std::to_string(i);
        //First let us construct the tuple describing the measurement
        common::TupleSensorString sensorTuple(QString::fromStdString(this->deviceName),
                                              "Temperature Probe",
                                              QString::fromStdString(sensorName));
        //Pull out the correct value corresponding to the temperature sensor
        double cTemperature = (data.at(i).volts - 1.258693)/0.094; //Function provided from Mike via Excel chart
        //Convert the value into the appropriate temperature
        double fTemperature = (cTemperature * (9.0/5.0)) + 32.0;
        //Notify whoever is listening of a sensor update

        common::EnvironmentTime currentTime;
        common::EnvironmentTime::CurrentTime(common::Devices::SYSTEMCLOCK,currentTime);

        common_data::SensorState newSensorMeasurement;
        newSensorMeasurement.setObservationTime(currentTime);

        newSensorMeasurement.ConstructSensor(common_data::SENSOR_TEMPERATURE,"Temperature Coolant");
        ((common_data::SensorTemperature*)newSensorMeasurement.getSensorData().get())->setTemperature(fTemperature,common_data::TemperatureUnit::UNIT_FAHRENHEIT);
        emit signal_SensorayNewSensorValue(sensorTuple,newSensorMeasurement);
    }
}

void Sensoray::initializeSensoray() const
{
    //commsMarshaler->resetSensorayIO();
}
