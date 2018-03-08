#include "protocol_sensoray.h"

namespace sensoray {
namespace comms{

SensorayProtocol::SensorayProtocol()
{

}

void SensorayProtocol::AddListner(const IProtocolSensorayEvents *listener)
{
    m_Listners.push_back(listener);
}

void SensorayProtocol::resetSensorayIO(SensorayLink *link)
{
    if(link->isConnected())
    {
        link->resetSensorayIO();
    }
}

bool SensorayProtocol::openSerialPort(SensorayLink *link, const SerialConfiguration &config)
{
    if(!link->isSerialPortConnected())
        link->OpenSerialPort(config);
}

bool SensorayProtocol::closeSerialPort (SensorayLink *link)
{
    if(link->isSerialPortConnected())
        link->CloseSerialPort();
}

void SensorayProtocol::transmitDataToSerialPort(SensorayLink *link, const QByteArray &msg)
{
    if(link->isSerialPortConnected())
    {
        QByteArray response = link->WriteToSerialPort(msg);
    }
}

//!
//! \brief Read data incoming from some link
//!
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
void SensorayProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    Emit([&](const IProtocolSensorayEvents* ptr){ptr->ResponseReceived(link,buffer);});
}





} //end of namespace comms
} //end of namespace sensoray
