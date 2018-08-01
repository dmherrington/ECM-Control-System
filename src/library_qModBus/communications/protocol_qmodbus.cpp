#include "protocol_qmodbus.h"

namespace comms_QModBus{

QModBusProtocol::QModBusProtocol()
{

}

void QModBusProtocol::AddListner(const IProtocolQModBusEvents *listener)
{
    m_Listners.push_back(listener);
}

unsigned int QModBusProtocol::getSlaveID() const
{
    return this->slaveID;
}

void QModBusProtocol::setSlaveAddress(const unsigned int &slaveAddress)
{
    this->slaveID = slaveAddress;
}

void QModBusProtocol::writeDataToRegister()
{

}

} //end of namespace comms_QModBus

