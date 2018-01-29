#ifndef MUNK_DATA_FRAMING_H
#define MUNK_DATA_FRAMING_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

enum class FramingState{
    WAITING,
    RECIEVED_MUNK_ADDRESS,
    RECEIVED_FUNCTION_CODE,
    RECEIVED_EXCEPTION_CODE,
    RECEIVED_PAYLOAD,
    RECEIVED_CRC_LOW,
    RECEIVED_CRC_HIGH
};

enum class MunkMessageType
{
    VALID,
    EXCEPTION,
    FAULT
};


class munk_message
{
public:
    munk_message() = default;

    void appendArray(const uint8_t &byte)
    {
        this->currentArray.append(byte);
    }

    QByteArray getDataArray() const
    {
        return currentArray;
    }

    void setMessageType(const MunkMessageType &msgType)
    {
        this->type = msgType;
    }

    MunkMessageType getMessageType() const
    {
        return type;
    }

private:
    QByteArray currentArray;
    MunkMessageType type = MunkMessageType::VALID;
};

class MunkDataFraming
{
public:
    MunkDataFraming(const int &munkAddress);
    void additionalByteRecevied(const uint8_t &byte);

private:
    unsigned int CRC16(const QByteArray &array) const;

private:
    int munkAddress;
    FramingState currentMSGState;
    QByteArray currentArray;
};

#endif // MUNK_DATA_FRAMING_H
