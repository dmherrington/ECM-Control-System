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
    QByteArray dataArray = regMsg.getByteArray();

    QDataStream in(dataArray); //< Attach a read-only stream to it
    in.setByteOrder(QDataStream::BigEndian); //< Set the proper byte order

    qint16 result; //< The result you want
    in >> result; //< Just read it from the stream


    if(link->WriteSingleRegister(regMsg.getRegisterCode(), (int)result))
    {
        Emit([&](const IProtocolQModBusEvents* ptr){ptr->ModbusResponseReceived(regMsg.getFullMessage());});
    }
    else
    {
        std::cout<<"We already know there is an issue on the modbus port."<<std::endl;
    }
}

} //end of namespace comms_QModBus

