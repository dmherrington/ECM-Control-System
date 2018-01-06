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

void GalilProtocol::SendProtocolCommand(const ILink *link, CommandMotorEnable &command)
{
    std::cout<<"I am trying to send a protocol command"<<std::endl;
    link->WriteCommand(&command);
}

void GalilProtocol::SendProtocolRequest(const ILink *link, RequestTellPosition &request)
{
    std::cout<<"I am trying to send a protocol request"<<std::endl;
    link->WriteRequest(&request);
    if(request.getRequestReturn() == G_NO_ERROR)
    {
        //let us parse this for a status position
        Status_Position status;
        status.parseGalilString(request.getRequestString());
        Emit([&](const IProtocolGalilEvents* ptr){ptr->NewPositionReceived(status);});
    }
}

//!
//! \brief Send message onto some link
//!
//! This code is largely a copy from MAVLinkProtocol::sendMessage in qgroundcontrol
//! \param link Link to put message onto
//! \param message Message to send
//!
void GalilProtocol::SendProtocolMessage(const ILink *link, const double &message)
{
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
    Emit([&](const IProtocolGalilEvents* ptr){ptr->MessageReceived(2.5);});
}



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
