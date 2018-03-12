#ifndef WESTINGHOUSE_MESSAGE_H
#define WESTINGHOUSE_MESSAGE_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "data/type_read_write.h"
#include "data/type_exception_message.h"

#include "westinghouse_510_message_framing.h"

namespace westinghousePump {
namespace comms {

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

    FramingState setReadWriteType(const uint8_t &RWType);

    void setExceptionType(const data::ExceptionType &EXType);

    data::ReadWriteType isReadWriteType() const;

    data::ExceptionType isException() const;

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
    data::ReadWriteType rwType = data::ReadWriteType::WRITE;
    data::ExceptionType exType = data::ExceptionType::NO_EXCEPTION;
    int remainingPayload = 0;
};

} //end of namespace comms
} //end of namespace westinghousePump

#endif //WESTINGHOUSE_MESSAGE_H
