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

//!
//! \brief Send message onto some link
//!
//! This code is largely a copy from MAVLinkProtocol::sendMessage in qgroundcontrol
//! \param link Link to put message onto
//! \param message Message to send
//!
void GalilProtocol::SendProtocolMessage(const ILink *link, const mavlink_message_t &message)
{
    // Create buffer
    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    // Write message into buffer, prepending start sign
    int len = mavlink_msg_to_send_buffer(buffer, &message);
    // If link is connected
    if (link->isConnected())
    {
        // Send the portion of the buffer now occupied by the message
        link->WriteBytes((const char*)buffer, len);
    }
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
