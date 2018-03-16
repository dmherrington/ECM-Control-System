#include "protocol_munk.h"

#include <iostream>

#include <algorithm>


namespace comms_Munk{

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

void MunkProtocol::sendForwardVoltageSetpoint(const ILink *link, const registers_Munk::SegmentVoltageSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

void MunkProtocol::sendReverseVoltageSetpoint(const ILink *link, const registers_Munk::SegmentVoltageSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing current setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendForwardCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

void MunkProtocol::sendReverseCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        link->WriteBytes(setpoint.getFullMessage());
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general segment data to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendSegmentTime(const ILink *link, const registers_Munk::SegmentTimeGeneral &segment)
{
    if(link->isConnected())
    {
        link->WriteBytes(segment.getFullMessage());
    }
}

void MunkProtocol::sendCommitToEEPROM(const ILink *link, const registers_Munk::ParameterMemoryWrite &command)
{
    if(link->isConnected())
    {
        link->WriteBytes(command.getFullMessage());
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general fault & status requests
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendFaultStateRequest(const ILink *link, const registers_Munk::RegisterFaultState &request)
{
    if(link->isConnected())
    {
        link->WriteBytes(request.getFullMessage());
        this->readVector.push_back(request.getClone());
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
            if(completeMessage.isException() == data_Munk::ExceptionType::EXCEPTION)
                parseForException(link, completeMessage);
            else if(completeMessage.isReadWriteType() == data_Munk::ReadWriteType::READ)
                parseForReadMessage(link, completeMessage);
            else if(completeMessage.isReadWriteType() == data_Munk::ReadWriteType::WRITE)
                parseForAck(link, completeMessage);
        }
    }
}

void MunkProtocol::parseForReadMessage(const ILink *link, const MunkMessage &msg)
{
    registers_Munk::AbstractParameter* currentRead = readVector.front();
    if(currentRead->getParameterType() == registers_Munk::ParameterType::FAULT_STATE)
    {
        parseForFaultStateCode(link,currentRead,msg);
    }
}


void MunkProtocol::parseForException(const ILink *link, const MunkMessage &msg)
{
    Emit([&](const IProtocolMunkEvents* ptr){ptr->ExceptionResponseReceived(link,msg.isReadWriteType(),msg.getDataByte(2));});
}

void MunkProtocol::parseForFaultStateCode(const ILink *link, const registers_Munk::AbstractParameter* parameter, const MunkMessage &msg)
{
    const registers_Munk::RegisterFaultState* faultState = parameter->as<registers_Munk::RegisterFaultState>();
    data_Munk::FaultRegisterType type = static_cast<data_Munk::FaultRegisterType>(faultState->getParameterCode());
    uint8_t dataHi = msg.getDataByte(3);
    uint8_t dataLo = msg.getDataByte(4);
    int faultCode = dataLo | (dataHi<<8);

    switch (type) {
    case data_Munk::FaultRegisterType::FAULT_REGISTER_1:
    {
        data_Munk::FaultCodesRegister1 castCode = static_cast<data_Munk::FaultCodesRegister1>(faultCode);
        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister1Received(link,castCode);});
        break;
    }
    case data_Munk::FaultRegisterType::FAULT_REGISTER_2:
    {
        data_Munk::FaultCodesRegister2 castCode = static_cast<data_Munk::FaultCodesRegister2>(faultCode);
        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister2Received(link,castCode);});
        break;
    }
    case data_Munk::FaultRegisterType::FAULT_REGISTER_3:
    {
        data_Munk::FaultCodesRegister3 castCode = static_cast<data_Munk::FaultCodesRegister3>(faultCode);
        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister3Received(link,castCode);});
        break;
    }
    default:
        break;
    }
    delete parameter;
    parameter = nullptr;
}

void MunkProtocol::parseForAck(const ILink *link, const MunkMessage &msg)
{
    uint8_t highPC = msg.getDataByte(2);
    uint8_t lowPC = msg.getDataByte(3);
    int parameterCode = lowPC | (highPC<<8);

    uint8_t highREG = msg.getDataByte(4);
    uint8_t lowREG = msg.getDataByte(5);
    int numberOfRegisters = lowREG | (highREG<<8);

    if(data_Munk::isOfVoltageSegmentType(parameterCode))
    {
        if(data_Munk::isForwardVoltageType(parameterCode))
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD,numberOfRegisters);});
        else
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE,numberOfRegisters);});
    }
    else if(data_Munk::isOfCurrentSegmentType(parameterCode))
    {
        if(data_Munk::isForwardCurrentType(parameterCode))
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD,numberOfRegisters);});
        else
            Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE,numberOfRegisters);});
    }
    else if(data_Munk::isOfTimeSegmentType(parameterCode))
    {
        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentTimeSetpointAcknowledged(link,numberOfRegisters);});
    }
    else if(parameterCode == registers_Munk::ParameterTypeToInt(registers_Munk::ParameterType::MEMORYWRITE))
    {
        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCommittedToMemory(link);});
    }
    else
    {
        std::cout<<"We have received an ack for a type that I am not currently aware of."<<std::endl;
    }
}

} //end of namespace comms_Munk

