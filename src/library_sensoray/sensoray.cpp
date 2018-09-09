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

    commsMarshaler = new comms_Sensoray::CommsMarshaler();
    commsMarshaler->AddSubscriber(this);
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

void Sensoray::closeSerialPortConnection() const
{
    commsMarshaler->DisconnetFromSerialPort();
}

void Sensoray::writeToSerialPort(const ModbusRegister &regMsg) const
{
    //commsMarshaler->WriteToSerialPort(msg);
}

bool Sensoray::isSerialPortOpen() const
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
        emit signal_SerialPortReadyToConnect();
    }
    else
    {
        emit signal_SensorayCommunicationUpdate(update);
    }
}

void Sensoray::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    emit signal_SerialPortUpdate(update);
}

void Sensoray::NewDataReceived(const QByteArray &buffer) const
{
    emit signal_RXNewSerialData(buffer);
}

void Sensoray::initializeSensoray() const
{
    //commsMarshaler->resetSensorayIO();
}
