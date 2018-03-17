#ifndef WESTINGHOUSE_MESSAGE_H
#define WESTINGHOUSE_MESSAGE_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "../data/type_read_write.h"
#include "data/westinghouse_exception_message.h"

#include "westinghouse_510_message_framing.h"


namespace comms_WestinghousePump {

class WestinghouseMessage
{
public:
    WestinghouseMessage() = default;

    WestinghouseMessage(const WestinghouseMessage &copy);

    void resetData();
    void appendArray(const uint8_t &byte);

    QByteArray getDataArray() const;
    uint8_t getDataByte(const int &index) const;
    int getDataSize() const;

    WestinghouseFramingState setReadWriteType(const uint8_t &RWType);

    void setExceptionType(const data_WestinghousePump::WestinghouseExceptionTypes &EXType);

    data_WestinghousePump::RWType isReadWriteType() const;

    data_WestinghousePump::WestinghouseExceptionTypes isException() const;

    void setRemainingPayload(const int &size);

    int remainingPayloadSize() const;

public:
    WestinghouseMessage& operator = (const WestinghouseMessage &rhs)
    {
        currentArray = rhs.currentArray;
        rwType = rhs.rwType;
        exType = rhs.exType;
        remainingPayload = rhs.remainingPayload;
        return *this;
    }
private:
    QByteArray currentArray;
    data_WestinghousePump::RWType rwType = data_WestinghousePump::RWType::WRITE;
    data_WestinghousePump::WestinghouseExceptionTypes exType = data_WestinghousePump::WestinghouseExceptionTypes::NO_EXCEPTION;
    int remainingPayload = 0;
};

} //end of namespace comms_WestinghousePump


#endif //WESTINGHOUSE_MESSAGE_H
