#include "munk_message.h"

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
    rwType = Data::ReadWriteType::WRITE;
    exType = Data::ExceptionType::NO_EXCEPTION;
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
    if(RWType == static_cast<uint8_t>(Data::ReadWriteType::WRITE))
    {
        this->rwType = Data::ReadWriteType::WRITE;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_WRITE;
        remainingPayload = 4;
    }
    else
    {
        this->rwType = Data::ReadWriteType::READ;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_READ;
    }
}

void MunkMessage::setExceptionType(const Data::ExceptionType &EXType)
{
    if(EXType == Data::ExceptionType::NO_EXCEPTION)
        this->exType = Data::ExceptionType::NO_EXCEPTION;
    else
        this->exType = Data::ExceptionType::EXCEPTION;
}

Data::ReadWriteType MunkMessage::isReadWriteType() const
{
    return rwType;
}

Data::ExceptionType MunkMessage::isException() const
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

