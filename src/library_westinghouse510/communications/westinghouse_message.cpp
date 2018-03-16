#include "westinghouse_message.h"

namespace comms_WestinghousePump {

WestinghouseMessage::WestinghouseMessage(const WestinghouseMessage &copy)
{
    currentArray = copy.getDataArray();
    rwType = copy.isReadWriteType();
    exType = copy.isException();
    remainingPayload = copy.remainingPayloadSize();
}

void WestinghouseMessage::resetData()
{
    currentArray.clear();
    rwType = data_WestinghousePump::ReadWriteType::WRITE;
    exType = data_WestinghousePump::ExceptionType::NO_EXCEPTION;
    remainingPayload = 0;
}

void WestinghouseMessage::appendArray(const uint8_t &byte)
{
    this->currentArray.append(byte);
}

QByteArray WestinghouseMessage::getDataArray() const
{
    return this->currentArray;
}

uint8_t WestinghouseMessage::getDataByte(const int &index) const
{
    return this->currentArray.at(index);
}

int WestinghouseMessage::getDataSize() const
{
    return this->currentArray.size();
}

FramingState WestinghouseMessage::setReadWriteType(const uint8_t &RWType)
{
    if(RWType == static_cast<uint8_t>(data_WestinghousePump::ReadWriteType::WRITE))
    {
        this->rwType = data_WestinghousePump::ReadWriteType::WRITE;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_WRITE;
        remainingPayload = 4;
    }
    else
    {
        this->rwType = data_WestinghousePump::ReadWriteType::READ;
        return FramingState::RECEIVED_STD_FUNCTION_CODE_READ;
    }
}

void WestinghouseMessage::setExceptionType(const data_WestinghousePump::ExceptionType &EXType)
{
    if(EXType == data_WestinghousePump::ExceptionType::NO_EXCEPTION)
        this->exType = data_WestinghousePump::ExceptionType::NO_EXCEPTION;
    else
        this->exType = data_WestinghousePump::ExceptionType::EXCEPTION;
}

data_WestinghousePump::ReadWriteType WestinghouseMessage::isReadWriteType() const
{
    return rwType;
}

data_WestinghousePump::ExceptionType WestinghouseMessage::isException() const
{
    return exType;
}

void WestinghouseMessage::setRemainingPayload(const int &size)
{
    remainingPayload = size;
}

int WestinghouseMessage::remainingPayloadSize() const
{
    return this->remainingPayload;
}

} //end of namespace comms_WestinghousePump

