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
    rwType = data_Munk::MunkRWType::WRITE;
    exType = data_Munk::MunkExceptionType::NO_EXCEPTION;
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

void MunkMessage::setReadWriteType(const uint8_t &RWType)
{
    if(RWType == static_cast<uint8_t>(data_Munk::MunkRWType::WRITE))
    {
        this->rwType = data_Munk::MunkRWType::WRITE;
        remainingPayload = 4;
    }
    else
    {
        this->rwType = data_Munk::MunkRWType::READ;
    }
}

void MunkMessage::setExceptionType(const data_Munk::MunkExceptionType &EXType)
{
    if(EXType == data_Munk::MunkExceptionType::NO_EXCEPTION)
        this->exType = data_Munk::MunkExceptionType::NO_EXCEPTION;
    else
        this->exType = data_Munk::MunkExceptionType::EXCEPTION;
}

data_Munk::MunkRWType MunkMessage::isReadWriteType() const
{
    return rwType;
}

data_Munk::MunkExceptionType MunkMessage::isException() const
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

