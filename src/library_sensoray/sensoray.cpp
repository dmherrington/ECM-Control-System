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

//////////////////////////////////////////////////////////////
/// Virtual methods allowed from comms::CommsEvents
//////////////////////////////////////////////////////////////
void Sensoray::ConnectionOpened() const
{
    std::cout<<"A connection has been opened to the sensoray device."<<std::endl;
    this->initializeSensoray();
}

void Sensoray::ConnectionClosed() const
{
    std::cout<<"A connection has been closed to the sensoray device."<<std::endl;
}

void Sensoray::NewDataReceived(const QByteArray &buffer) const
{
    emit ReceivedSerialMessage(buffer);
}

void Sensoray::initializeSensoray() const
{
    commsMarshaler->resetSensorayIO();
}
