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
        MunkMessage receivedMSG;
        if(link->WriteBytes(setpoint.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(setpoint.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD,numberOfRegisters);});
                    }
                }
            }
        }
    }
}

void MunkProtocol::sendReverseVoltageSetpoint(const ILink *link, const registers_Munk::SegmentVoltageSetpoint &setpoint)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(setpoint.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(setpoint.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE,numberOfRegisters);});
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing current setpoints relevant to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendForwardCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(setpoint.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(setpoint.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD,numberOfRegisters);});
                    }
                }
            }
        }
    }
}

void MunkProtocol::sendReverseCurrentSetpoint(const ILink *link, const registers_Munk::SegmentCurrentSetpoint &setpoint)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(setpoint.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(setpoint.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE,numberOfRegisters);});
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general segment data to the munk program
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendSegmentTime(const ILink *link, const registers_Munk::SegmentTimeGeneral &segment)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(segment.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(segment.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD,numberOfRegisters);});
                    }
                }
            }
        }
    }
}

void MunkProtocol::sendCommitToEEPROM(const ILink *link, const registers_Munk::ParameterMemoryWrite &command)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(command.getFullMessage()))
        {
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(command.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCommittedToMemory(link);});
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general fault & status requests
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendFaultStateRequest(const ILink *link, const registers_Munk::RegisterFaultState &request)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
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
bool MunkProtocol::ReceiveData(const ILink *link, MunkMessage &returnMessage)
{
    while(dataParse.getCurrentMessageState() != FramingState::RECEIVED_ENTIRE_MESSAGE)
    {
        std::vector<uint8_t> buffer = link->ReadBytes();
        //This is where data from the munk power supply serial buffer is seen
        for(uint8_t c: buffer)
        {
            //we should create a structure to succesfully parse it here
            std::cout<<"We have received data from the serial buffer and the message thus far is: "<<dataParse.getCurrentMessage().getDataArray().toHex().toStdString()<<std::endl;
            if(dataParse.additionalByteRecevied(c) == FramingState::RECEIVED_ENTIRE_MESSAGE)
            {
                break;
            }
        }
    }
    returnMessage = dataParse.getCurrentMessage();
    return true;
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

} //end of namespace comms_Munk

