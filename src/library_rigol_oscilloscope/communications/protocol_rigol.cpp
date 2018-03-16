#include "protocol_rigol.h"


namespace comms_Rigol{

RigolProtocol::RigolProtocol()
{

}

void RigolProtocol::AddListner(const IProtocolRigolEvents* listener)
{
    m_Listners.push_back(listener);
}

void RigolProtocol::sendSetAcquisitionCommand(const ILink *link, const commands_Rigol::AbstractAcquireCommandPtr command)
{
    std::string commandString = command->getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    link->WriteBytes(byteArray);
}


void RigolProtocol::sendSetMeasurementCommand(const ILink *link, const commands_Rigol::MeasureCommand_Item &command)
{
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    link->WriteBytes(byteArray);
}

void RigolProtocol::sendMeasurementRequest(const ILink *link, const commands_Rigol::MeasureCommand_Item &command)
{
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    commands_Rigol::RigolMeasurementStatus measurementStatus(command.getChannel(),command.getMeasurementType());
    std::vector<uint8_t> rcvBuffer = link->WriteBytesRequest(byteArray);
    measurementStatus.updateReceivedTime();
    measurementStatus.setMeasurementString(std::string(rcvBuffer.begin(), rcvBuffer.end()));
    Emit([&](const IProtocolRigolEvents* ptr){ptr->NewMeaurementReceived(link,measurementStatus);});
    //Emit([&](const IProtocolRigolEvents* ptr){ptr->ResponseReceived(link,rcvBuffer);});
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

} //end of namespace comms_Rigol

