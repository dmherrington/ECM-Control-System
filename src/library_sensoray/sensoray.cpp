#include "sensoray.h"

Sensoray::Sensoray(const std::string &name, QObject *parent):
    QObject(parent)
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
    std::cout<<"A connection has been opened to the sensoray device."<<std::endl;
    this->initializeSensoray();
    emit ConnectionStatus();
}

//!
//! \brief Sensoray::ConnectionClosed
//!
void Sensoray::ConnectionClosed() const
{
    std::cout<<"A connection has been closed to the sensoray device."<<std::endl;
    emit ConnectionStatus();
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

}

void Sensoray::SerialPortStatusUpdate(const common::comms::CommunicationUpdate &update) const
{
    emit signal_SerialPortUpdate(update);
}

void Sensoray::SerialPortConnection(const common::comms::CommunicationConnection &connection) const
{
    emit signal_SerialPortConnection(connection);
}

void Sensoray::initializeSensoray() const
{
    commsMarshaler->resetSensorayIO();
}
