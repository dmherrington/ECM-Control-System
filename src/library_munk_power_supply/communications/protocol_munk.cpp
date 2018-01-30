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

/////////////////////////////////////////////////////////////////////
/// Methods issuing general fault & status requests
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendFaultStateRequest(const ILink *link, const DataParameter::RegisterFaultState &request)
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
            if(completeMessage.isException() == Data::ExceptionType::EXCEPTION)
                parseForException(link, completeMessage);
            else if(completeMessage.isReadWriteType() == Data::ReadWriteType::READ)
                parseForReadMessage(link, completeMessage);
            else if(completeMessage.isReadWriteType() == Data::ReadWriteType::WRITE)
                parseForAck(link, completeMessage);
        }
    }
}

void MunkProtocol::parseForReadMessage(const ILink *link, const MunkMessage &msg)
{
    DataParameter::AbstractParameter* currentRead = readVector.front();
    if(currentRead->getParameterType() == DataParameter::ParameterType::FAULT_STATE)
    {
        parseForFaultStateCode(link,currentRead,msg);
    }
}


void MunkProtocol::parseForException(const ILink *link, const MunkMessage &msg)
{
    Emit([&](const IProtocolMunkEvents* ptr){ptr->ExceptionResponseReceived(link,msg.isReadWriteType(),msg.getDataByte(2));});
}

void MunkProtocol::parseForFaultStateCode(const ILink *link, const DataParameter::AbstractParameter* parameter, const MunkMessage &msg)
{
    const DataParameter::RegisterFaultState* faultState = parameter->as<DataParameter::RegisterFaultState>();
    Data::FaultRegisterType type = static_cast<Data::FaultRegisterType>(faultState->getParameterCode());
    uint8_t dataHi = msg.getDataByte(3);
    uint8_t dataLo = msg.getDataByte(4);
    int faultCode = dataLo | (dataHi<<8);

    switch (type) {
    case Data::FaultRegisterType::FAULT_REGISTER_1:
    {
        Data::FaultCodesRegister1 castCode = static_cast<Data::FaultCodesRegister1>(faultCode);
        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister1Received(link,castCode);});
        break;
    }
    case Data::FaultRegisterType::FAULT_REGISTER_2:
    {
        Data::FaultCodesRegister2 castCode = static_cast<Data::FaultCodesRegister2>(faultCode);
        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeRegister2Received(link,castCode);});
        break;
    }
    case Data::FaultRegisterType::FAULT_REGISTER_3:
    {
        Data::FaultCodesRegister3 castCode = static_cast<Data::FaultCodesRegister3>(faultCode);
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
    else if(parameterCode == DataParameter::ParameterTypeToInt(DataParameter::ParameterType::MEMORYWRITE))
    {
        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCommittedToMemory(link);});
    }
    else
    {
        std::cout<<"We have received an ack for a type that I am not currently aware of."<<std::endl;
    }
}



} //end of namespace comms
} //end of namespace munk
