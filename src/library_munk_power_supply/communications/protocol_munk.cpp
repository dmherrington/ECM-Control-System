#include "protocol_munk.h"

#include <iostream>

#include <algorithm>

namespace munk {
namespace comms{

MunkProtocol::MunkProtocol():
    dataParse(1)
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
        if(dataParse.additionalByteRecevied(c) == FramingState::RECEIVED_ENTIRE_MESSAGE)
        {
            MunkMessage completeMessage = dataParse.getCurrentMessage();
            if(completeMessage.isException() == Data::ExceptionType::EXCEPTION)
                parseForException(link, completeMessage);
            else if(completeMessage.isReadWriteType() == Data::ReadWriteType::READ)
                parseForFaultCode(link, completeMessage);
            else if(completeMessage.isReadWriteType() == Data::ReadWriteType::WRITE)
                parseForAck(link, completeMessage);
        }
    }
}


void MunkProtocol::parseForException(const ILink *link, const MunkMessage &msg)
{
    Emit([&](const IProtocolMunkEvents* ptr){ptr->ExceptionResponseReceived(link,msg.isReadWriteType(),msg.getDataByte(2));});
}

void MunkProtocol::parseForFaultCode(const ILink *link, const MunkMessage &msg)
{
//    uint8_t highPC = msg.getDataByte();
//    uint8_t lowPC = msg.getDataByte();
//    int parameterCode = lowPC | (highPC<<8);
}

void MunkProtocol::parseForAck(const ILink *link, const MunkMessage &msg)
{
    uint8_t highPC = msg.getDataByte(2);
    uint8_t lowPC = msg.getDataByte(3);
    int parameterCode = lowPC | (highPC<<8);

    uint8_t highREG = msg.getDataByte(4);
    uint8_t lowREG = msg.getDataByte(5);
    int numberOfRegisters = lowREG | (highREG<<8);

    if(Data::isOfVoltageSegmentType(parameterCode))
    {
        if(Data::isForwardVoltageType(parameterCode))
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,Data::SegmentMode::FORWARD,numberOfRegisters);});
        else
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,Data::SegmentMode::REVERSE,numberOfRegisters);});
    }
    else if(Data::isOfCurrentSegmentType(parameterCode))
    {
        if(Data::isForwardCurrentType(parameterCode))
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,Data::SegmentMode::FORWARD,numberOfRegisters);});
        else
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,Data::SegmentMode::REVERSE,numberOfRegisters);});
    }
    else if(Data::isOfTimeSegmentType(parameterCode))
    {
        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentTimeSetpointAcknowledged(link,numberOfRegisters);});
    }
    else
    {
        std::cout<<"We have received an ack for a type that I am not currently aware of."<<std::endl;
    }
}



} //end of namespace comms
} //end of namespace munk
