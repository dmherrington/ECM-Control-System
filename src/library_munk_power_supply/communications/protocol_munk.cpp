#include "protocol_munk.h"

#include <iostream>

#include <algorithm>

namespace munk {
namespace comms{

MunkProtocol::MunkProtocol()
{

}

void MunkProtocol::AddListner(const IProtocolMunkEvents* listener)
{
    m_Listners.push_back(listener);
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing voltage setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendForwardVoltageSetpoint(const ILink *link, const DataParameter::SegmentVoltageSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

void MunkProtocol::sendReverseVoltageSetpoint(const ILink *link, const DataParameter::SegmentVoltageSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing current setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendForwardCurrentSetpoint(const ILink *link, const DataParameter::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

void MunkProtocol::sendReverseCurrentSetpoint(const ILink *link, const DataParameter::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general segment data to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendSegmentTime(const ILink *link, const DataParameter::SegmentTimeGeneral &segment)
{
    if(link->isConnected())
    {
        link->WriteBytes(segment.getFullMessage());
    }
}

void MunkProtocol::sendCommitToEEPROM(const ILink *link, const DataParameter::ParameterMemoryWrite &command)
{
    if(link->isConnected())
    {
        link->WriteBytes(command.getFullMessage());
    }
}

//!
//! \brief Read data incoming from some link
//!
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
void MunkProtocol::ReceiveData(ILink *link, const std::vector<uint8_t> &buffer)
{
    UNUSED(link);

    //This is where data from the munk power supply serial buffer is seen
    for(uint8_t c: buffer)
    {
        //we should create a structure to succesfully parse it here
        std::cout<<"We have received data from the serial buffer: "<<c<<std::endl;

        //In this function is where we should emit the events related to the munk protocol
//        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister1Received(link);});
//        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister2Received(link);});
//        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister3Received(link);});
//        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentSetpointAcknowledged(link);});
//        Emit([&](const IProtocolMunkEvents* ptr){ptr->ExceptionResponseReceived(link);});
    }
}

} //end of namespace comms
} //end of namespace munk
