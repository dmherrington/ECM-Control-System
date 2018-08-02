#include "protocol_qmodbus.h"

namespace comms_QModBus{

QModBusProtocol::QModBusProtocol()
{

}

void QModBusProtocol::AddListner(const IProtocolQModBusEvents *listener)
{
    m_Listners.push_back(listener);
}

void QModBusProtocol::setSlaveAddress(ILink* link, const unsigned int &slaveAddress)
{
    link->SetSlaveAddress(slaveAddress);
}

void QModBusProtocol::writeDataToSingleRegister(const ILink *link, const ModbusRegister &regMsg)
{
    unsigned int data = regMsg.getByteArray().toInt();
    if(link->WriteSingleRegister(data))
    {
        Emit([&](const IProtocolQModBusEvents* ptr){ptr->ResponseReceived(regMsg.getFullMessage());});
    }
    else
    {

    }
}

} //end of namespace comms_QModBus

