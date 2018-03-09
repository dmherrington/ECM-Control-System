#include "sensoray.h"

Sensoray::Sensoray(const std::string &name, QObject *parent):
    QObject(parent)
{
    commsMarshaler = new comms::CommsMarshaler();
    commsMarshaler->AddSubscriber(this);
}


void Sensoray::openConnection(const std::string &ipAddress, const int &portNumber)
{
    comms::SensorayTCPConfiguration linkConfig(ipAddress,portNumber,2426);
    commsMarshaler->ConnectToLink(linkConfig);
}

void Sensoray::closeConnection()
{
    commsMarshaler->DisconnetFromLink();
}

void Sensoray::transmitSerialMessage(const QByteArray &data)
{
    commsMarshaler->WriteToSerialPort(data);
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
    emit ReceivedSerialMessage(buffer);
}

void Sensoray::initializeSensoray() const
{
    commsMarshaler->resetSensorayIO();
}
