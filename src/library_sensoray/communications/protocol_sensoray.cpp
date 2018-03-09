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
        return link->OpenSerialPort(config);
    return true;
}

bool SensorayProtocol::closeSerialPort (SensorayLink *link)
{
    if(link->isSerialPortConnected())
        return link->CloseSerialPort();
    return true;
}

void SensorayProtocol::transmitDataToSerialPort(SensorayLink *link, const QByteArray &msg)
{
    if(link->isSerialPortConnected())
    {
        QByteArray buffer = link->WriteToSerialPort(msg);
        Emit([&](const IProtocolSensorayEvents* ptr){ptr->ResponseReceived(link,buffer);});
    }
}

} //end of namespace comms
} //end of namespace sensoray
