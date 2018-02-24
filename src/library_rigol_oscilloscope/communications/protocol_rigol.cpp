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

void RigolProtocol::sendSetMeasurementCommand(const ILink *link, const commands::MeasureCommand_Item &command)
{
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
    link->WriteBytes(byteArray);
}

void RigolProtocol::sendMeasurementRequest(const ILink *link, const commands::MeasureCommand_Item &command)
{
    std::cout<<"I am executing another request."<<std::endl;
    std::string commandString = command.getCommandString();
    QByteArray byteArray(commandString.c_str(), commandString.length());
//    commands::AbstractRigolStatus* response = command.getExpectedResponse(); //this also establishes the time of request
//    this->responseQueue.push_back(response);
    link->WriteBytesRequest(byteArray);
//    link->WriteBytes(byteArray);
//    std::vector<uint8_t> response = link->ProcessResponse(command);
//    if(response.size() > 0)
//    {
//        commands::RigolMeasurementStatus newStatus(command.getChannel(),command.getMeasurementType());
//        std::string responseString = std::string(response.begin(), response.end());
//        double responseValue = atof(responseString.c_str());
//        newStatus.setMeasurementValue(responseValue);
//        Emit([&](const IProtocolRigolEvents* ptr){ptr->NewMeaurementReceived(link,newStatus);});
//    }
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
