#include "sensoray.h"

Sensoray::Sensoray(const std::string &name, QObject *parent):
    deviceName(name),
    QObject(parent),
    ICommunication()
{
    qRegisterMetaType<common::comms::CommunicationConnection>("CommunicationConnection");
    qRegisterMetaType<common::comms::CommunicationUpdate>("CommunicationUpdate");

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
void Sensoray::writeToSerialPort(const QByteArray &msg) const
{
    commsMarshaler->WriteToSerialPort(msg);
}
bool Sensoray::isSerialPortOpen() const
{
    return false;
}

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////

//!
//! \brief Sensoray::ConnectionOpened
//!
void Sensoray::ConnectionOpened() const
{
    this->initializeSensoray();
    common::comms::CommunicationConnection connection(deviceName,true);
    emit signal_SensorayConnectionUpdate(connection);
    emit signal_SerialPortReadyToConnect();
}

//!
//! \brief Sensoray::ConnectionClosed
//!
void Sensoray::ConnectionClosed() const
{
    common::comms::CommunicationConnection connection(deviceName,false);
    emit signal_SensorayConnectionUpdate(connection);
}

//!
//! \brief CommunicationError
//! \param type
//! \param msg
//!
void Sensoray::CommunicationError(const std::string &type, const std::string &msg) const
{

}

//!
//! \brief CommunicationUpdate
//! \param name
//! \param msg
//!
void Sensoray::CommunicationUpdate(const std::string &name, const std::string &msg) const
{

}

void Sensoray::NewDataReceived(const QByteArray &buffer) const
{
    emit signal_RXNewSerialData(buffer);
}

void Sensoray::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    common::comms::CommunicationUpdate commsUpdate(update);
    commsUpdate.setSourceName(this->deviceName);
    emit signal_SerialPortUpdate(commsUpdate);
}

void Sensoray::SerialPortConnection(const common::comms::CommunicationConnection &connection) const
{
    common::comms::CommunicationConnection connectionUpdate(connection);
    connectionUpdate.setSourceName(this->deviceName);
    emit signal_SerialPortConnection(connectionUpdate);
}

void Sensoray::initializeSensoray() const
{
    //commsMarshaler->resetSensorayIO();
}
