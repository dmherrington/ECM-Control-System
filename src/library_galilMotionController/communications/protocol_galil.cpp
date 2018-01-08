#include "protocol_galil.h"

#include <iostream>

#include <algorithm>

namespace Comms
{

GalilProtocol::GalilProtocol()
{

}

void GalilProtocol::AddListner(const IProtocolGalilEvents* listener)
{
    m_Listners.push_back(listener);
}

void GalilProtocol::UploadNewProgram(const ILink *link, const std::string &programString)
{
    std::cout<<"I am trying to upload a new program"<<std::endl;
    GReturn rtn = link->UploadProgram(programString);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil command
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolCommand(const ILink *link, const AbstractCommandPtr command)
{
    std::cout<<"I am in here"<<std::endl;
    //link->WriteCommand(command);
}

void GalilProtocol::handleBadCommandResponse(const ILink* link, const CommandType &type) const
{
    char error[100];
    link->WriteTellErrorCode(error);
}

void GalilProtocol::handleCommandResponse(const ILink *link, const AbstractCommandPtr command, const GReturn &response)
{
        switch (response) {
        case G_NO_ERROR:
        {
            break;
        }
        case G_BAD_RESPONSE_QUESTION_MARK:
        {
            handleBadCommandResponse(link, command->getCommandType());
            break;
        }
        default:
            break;
        }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods issuing an explicit galil information request
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GalilProtocol::SendProtocolRequest(const ILink *link, const AbstractRequestPtr request)
{
    std::cout<<"I am trying to send a protocol request of type: "<<RequestToString(request->getRequestType())<<std::endl;
    link->WriteRequest(request);
}

void GalilProtocol::handleRequestResponse(const ILink *link, const AbstractRequestPtr request, const GReturn &response)
{
        switch (response) {
        case G_NO_ERROR:
        {
            break;
        }
        case G_BAD_LOST_DATA:
        {
            break;
        }
        case G_BAD_RESPONSE_QUESTION_MARK:
        {
            handleBadRequestResponse(link, request->getRequestType());
            break;
        }
        default:
            break;
        }
}

void GalilProtocol::handleBadRequestResponse(const ILink* link, const RequestTypes &type) const
{
    char error[100];
    link->WriteTellErrorCode(error);
}

//void GalilProtocol::SendProtocolMessage(const ILink *link, const double &message)
//{
//    // Create buffer
//    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
//    // Write message into buffer, prepending start sign
//    int len = mavlink_msg_to_send_buffer(buffer, &message);
//    // If link is connected
//    if (link->isConnected())
//    {
//        // Send the portion of the buffer now occupied by the message
//        link->WriteBytes((const char*)buffer, len);
//    }
//    Emit([&](const IProtocolGalilEvents* ptr){ptr->MessageReceived(2.5);});
//}



//!
//! \brief Read data incoming from some link
//!
//! This code is largely a copy from MAVLinkProtocol::receiveBytes in qgroundcontrol
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
void GalilProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    //where the response is seen
}

} //END MAVLINKComms
