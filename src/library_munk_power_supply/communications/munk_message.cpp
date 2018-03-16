#include "munk_message.h"


namespace comms_Munk{

MunkMessage::MunkMessage(const MunkMessage &copy)
{
    currentArray = copy.getDataArray();
    rwType = copy.isReadWriteType();
    exType = copy.isException();
    remainingPayload = copy.remainingPayloadSize();
}

void MunkMessage::resetData()
{
    currentArray.clear();
    rwType = data_Munk::ReadWriteType::WRITE;
    exType = data_Munk::ExceptionType::NO_EXCEPTION;
    remainingPayload = 0;
}

void MunkMessage::appendArray(const uint8_t &byte)
{
    this->currentArray.append(byte);
}

QByteArray MunkMessage::getDataArray() const
{
    return this->currentArray;
}

uint8_t MunkMessage::getDataByte(const int &index) const
{
    return this->currentArray.at(index);
}

int MunkMessage::getDataSize() const
{
    return this->currentArray.size();
}

FramingState MunkMessage::setReadWriteType(const uint8_t &RWType)
{
    if(RWType == static_cast<uint8_t>(data_Munk::ReadWriteType::WRITE))
    {
        this->rwType = data_Munk::ReadWriteType::WRITE;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_WRITE;
        remainingPayload = 4;
    }
    else
    {
        this->rwType = data_Munk::ReadWriteType::READ;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_READ;
    }
}

void MunkMessage::setExceptionType(const data_Munk::ExceptionType &EXType)
{
    if(EXType == data_Munk::ExceptionType::NO_EXCEPTION)
        this->exType = data_Munk::ExceptionType::NO_EXCEPTION;
    else
        this->exType = data_Munk::ExceptionType::EXCEPTION;
}

data_Munk::ReadWriteType MunkMessage::isReadWriteType() const
{
    return rwType;
}

data_Munk::ExceptionType MunkMessage::isException() const
{
    return exType;
}

void MunkMessage::setRemainingPayload(const int &size)
{
    remainingPayload = size;
}

int MunkMessage::remainingPayloadSize() const
{
    return this->remainingPayload;
}

} //end of namespace comms_Munk

