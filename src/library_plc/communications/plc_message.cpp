#include "plc_message.h"

namespace comms_PLC {

PLCMessage::PLCMessage(const PLCMessage &copy)
{
    currentArray = copy.getDataArray();
    rwType = copy.isReadWriteType();
    exType = copy.isException();
    remainingPayload = copy.remainingPayloadSize();
}

void PLCMessage::resetData()
{
    currentArray.clear();
    rwType = data_PLC::RWType::WRITE;
    exType = data_PLC::PLCExceptionTypes::NO_EXCEPTION;
    remainingPayload = 0;
}

void PLCMessage::appendArray(const uint8_t &byte)
{
    this->currentArray.append(byte);
}

QByteArray PLCMessage::getDataArray() const
{
    return this->currentArray;
}

uint8_t PLCMessage::getDataByte(const int &index) const
{
    return this->currentArray.at(index);
}

int PLCMessage::getDataSize() const
{
    return this->currentArray.size();
}

PLCMessageFramingState PLCMessage::setReadWriteType(const uint8_t &RWType)
{
    if(RWType == static_cast<uint8_t>(data_PLC::RWType::WRITE))
    {
        this->rwType = data_PLC::RWType::WRITE;
        return PLCMessageFramingState::RECEIVED_STD_FUNCTION_CODE_WRITE;
        remainingPayload = 4;
    }
    else
    {
        this->rwType = data_PLC::RWType::READ;
        return PLCMessageFramingState::RECEIVED_STD_FUNCTION_CODE_READ;
    }
}

void PLCMessage::setExceptionType(const data_PLC::PLCExceptionTypes &EXType)
{
    if(EXType == data_PLC::PLCExceptionTypes::NO_EXCEPTION)
        this->exType = data_PLC::PLCExceptionTypes::NO_EXCEPTION;
    else
        this->exType = data_PLC::PLCExceptionTypes::EXCEPTION;
}

data_PLC::RWType PLCMessage::isReadWriteType() const
{
    return rwType;
}

data_PLC::PLCExceptionTypes PLCMessage::isException() const
{
    return exType;
}

void PLCMessage::setRemainingPayload(const int &size)
{
    remainingPayload = size;
}

int PLCMessage::remainingPayloadSize() const
{
    return this->remainingPayload;
}

} //end of namespace comms_WestinghousePump

