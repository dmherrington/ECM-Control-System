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

void MunkProtocol::updateCompleteMunkParameters(const ILink *link, const registers_Munk::SegmentTimeDetailed &segmentData, const std::vector<registers_Munk::AbstractParameterPtr> parameters)
{
    bool validParameter = true;

    for(unsigned int i = 0; i < parameters.size(); i++)
    {
        switch (parameters.at(i)->getParameterType()) {
        case registers_Munk::ParameterType::CURRENTSETPOINT_FORWARD:
        {
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
            break;
        }
        case registers_Munk::ParameterType::CURRENTSETPOINT_REVERSE:
        {
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
            break;
        }
        case registers_Munk::ParameterType::VOLTAGESETPOINT_FORWARD:
        {
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
            break;
        }
        case registers_Munk::ParameterType::VOLTAGESETPOINT_REVERSE:
        {
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
            break;
        }
        case registers_Munk::ParameterType::PATTERNWRITECOMMAND:
        {
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentTimeSetpointAcknowledged(link);});
            break;
        }
        case registers_Munk::ParameterType::MEMORYWRITE:
        {
            validParameter = sendCommitToEEPROM(link,*parameters.at(i)->as<registers_Munk::ParameterMemoryWrite>());
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCommittedToMemory(link);});
            break;
        }
        default:
            break;
        }
        if(validParameter == false)
            break;
    }
    Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentUploadComplete(validParameter, segmentData);});
}

bool MunkProtocol::sendAbstractSetpoint(const ILink *link, const registers_Munk::AbstractParameterPtr parameter)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(parameter->getFullMessage()))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout<<"We have finished transmitting info"<<std::endl;
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving info"<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(parameter->getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        std::cout<<"We have received and confirmed the message."<<std::endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
            std::cout<<"We have finished transmitting info"<<std::endl;
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving info"<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(setpoint.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        std::cout<<"We have received and confirmed the message."<<std::endl;
                        uint8_t highREG = receivedMSG.getDataByte(4);
                        uint8_t lowREG = receivedMSG.getDataByte(5);
                        int numberOfRegisters = lowREG | (highREG<<8);
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
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
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
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
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
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
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
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
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
                    }
                }
            }
        }
    }
}

bool MunkProtocol::sendCommitToEEPROM(const ILink *link, const registers_Munk::ParameterMemoryWrite &command)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(command.getFullMessage()))
        {
            std::cout<<"We have finished transmitting info"<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving info"<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(command.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCommittedToMemory(link);});
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////
/// Methods issuing general fault & status requests
/////////////////////////////////////////////////////////////////////

void MunkProtocol::sendFaultStateRequest(const ILink *link, const registers_Munk::RegisterFaultState &request)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(request.getFullMessage()))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            if(this->ReceiveData(link,receivedMSG))
            {
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::READ)
                {
                    parseForFaultStateCode(link,&request,receivedMSG);
                }
            }
        }
    }
}

void MunkProtocol::sendFaultStateReset(const ILink *link, const registers_Munk::Register_FaultReset &request)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(request.getFullMessage()))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout<<"We have finished transmitting info"<<std::endl;
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving info"<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(request.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultStateCleared(link);});
                    }
                }
            }
        }
    }
}

void MunkProtocol::sendPulseMode(const ILink *link, const registers_Munk::Register_PulseMode &mode)
{
    if(link->isConnected())
    {
        MunkMessage receivedMSG;
        if(link->WriteBytes(mode.getFullMessage()))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout<<"We have finished transmitting the pulse mode."<<std::endl;
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving the info on the response of the pulse mode."<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::WRITE)
                {
                    if(mode.getFullExpectedResonse() == receivedMSG.getDataArray())
                    {
                        Emit([&](const IProtocolMunkEvents* ptr){ptr->RegisterPulseModeUpdated(true, mode);});
                        return;
                    }
                }
            }
        }
    }
    Emit([&](const IProtocolMunkEvents* ptr){ptr->RegisterPulseModeUpdated(false);});
}


//!
//! \brief Read data incoming from some link
//!
//! \param link Link which data was read from
//! \param buffer data that was read.
//!
bool MunkProtocol::ReceiveData(const ILink *link, MunkMessage &returnMessage)
{
    std::vector<uint8_t> buffer = link->ReadBytes();

    while((dataParse.getCurrentMessageState() != FramingState::RECEIVED_ENTIRE_MESSAGE) && (buffer.size() > 0))
    {
        //This is where data from the munk power supply serial buffer is seen
        for(uint8_t c: buffer)
        {
            //we should create a structure to succesfully parse it here
            if(dataParse.additionalByteRecevied(c) == FramingState::RECEIVED_ENTIRE_MESSAGE)
            {
                break;
            }
        }
        buffer = link->ReadBytes();
    }
    returnMessage = dataParse.getCurrentMessage();
    dataParse.resetMessageState();
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

    Emit([&](const IProtocolMunkEvents* ptr){ptr->FaultCodeReceived(link,type,faultCode);});
}

} //end of namespace comms_Munk

