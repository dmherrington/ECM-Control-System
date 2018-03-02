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

void SensorayProtocol::resetSensorayIO(ILink *link)
{
    link->resetSensorayIO();
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
