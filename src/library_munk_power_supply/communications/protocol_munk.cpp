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

void MunkProtocol::updateCompleteMunkParameters(const ILink *link, const std::vector<registers_Munk::AbstractParameterPtr> parameters)
{
    for(unsigned int i = 0; i < parameters.size(); i++)
    {
        bool validParameter = true;
        switch (parameters.at(i)->getParameterType()) {
        case registers_Munk::ParameterType::CURRENTSETPOINT_FORWARD:
        {
            std::cout<<"Uploading current setpoint forward...."<<std::endl;
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
            break;
        }
        case registers_Munk::ParameterType::CURRENTSETPOINT_REVERSE:
        {
            std::cout<<"Uploading current setpoint reverse...."<<std::endl;
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentCurrentSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
            break;
        }
        case registers_Munk::ParameterType::VOLTAGESETPOINT_FORWARD:
        {
            std::cout<<"Uploading voltage setpoint forward...."<<std::endl;
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::FORWARD);});
            break;
        }
        case registers_Munk::ParameterType::VOLTAGESETPOINT_REVERSE:
        {
            std::cout<<"Uploading voltage setpoint reverse...."<<std::endl;
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentVoltageSetpointAcknowledged(link,data_Munk::SegmentMode::REVERSE);});
            break;
        }
        case registers_Munk::ParameterType::PATTERNWRITECOMMAND:
        {
            std::cout<<"Uploading segment setpoint times...."<<std::endl;
            if(parameters.at(i)->getFullMessage().size() > 0)
                validParameter = sendAbstractSetpoint(link,parameters.at(i));
            if(validParameter)
                Emit([&](const IProtocolMunkEvents* ptr){ptr->SegmentTimeSetpointAcknowledged(link);});
            break;
        }
        case registers_Munk::ParameterType::MEMORYWRITE:
        {
            std::cout<<"Uploading commit to memory...."<<std::endl;
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
    std::cout<<"We have uploaded a complete set of munk parameters."<<std::endl;
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
            std::cout<<"We have finished transmitting info"<<std::endl;
            if(this->ReceiveData(link,receivedMSG))
            {
                std::cout<<"We have finished receiving info"<<std::endl;
                if(receivedMSG.isException() == data_Munk::MunkExceptionType::EXCEPTION)
                    parseForException(link, receivedMSG);
                else if(receivedMSG.isReadWriteType() == data_Munk::MunkRWType::READ)
                {
                    std::cout<<"We have read the fault state request."<<std::endl;
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
            if(dataParse.additionalByteRecevied(c) == FramingState::RECEIVED_ENTIRE_MESSAGE)
            {
                break;
            }
        }
    }
    std::cout<<"We have received data from the serial buffer and the message is: "<<dataParse.getCurrentMessage().getDataArray().toHex().toStdString()<<std::endl;
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

