#include "protocol_rigol.h"

namespace rigol {
namespace comms{

RigolProtocol::RigolProtocol()
{

}

void RigolProtocol::AddListner(const IProtocolRigolEvents* listener)
{
    m_Listners.push_back(listener);
}

void RigolProtocol::sendSetAcquisitionCommand(const ILink *link, const commands::AbstractAcquireCommandPtr command)
{
    std::string commandString = command->getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    link->WriteBytes(byteArray);
}


void RigolProtocol::sendSetMeasurementCommand(const ILink *link, const commands::MeasureCommand_Item &command)
{
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    link->WriteBytes(byteArray);
}

void RigolProtocol::sendMeasurementRequest(const ILink *link, const commands::MeasureCommand_Item &command)
{
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    std::vector<uint8_t> rcvBuffer = link->WriteBytesRequest(byteArray);
    Emit([&](const IProtocolRigolEvents* ptr){ptr->ResponseReceived(link,rcvBuffer);});
}

//!
//! \brief Read data incoming from some link
//!
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
void RigolProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    Emit([&](const IProtocolRigolEvents* ptr){ptr->ResponseReceived(link,buffer);});
}





} //end of namespace comms
} //end of namespace rigol
