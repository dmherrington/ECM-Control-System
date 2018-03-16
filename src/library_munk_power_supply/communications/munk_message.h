#ifndef MUNK_MESSAGE_H
#define MUNK_MESSAGE_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "data/type_read_write.h"
#include "data/type_exception_message.h"

#include "message_framing_state.h"


namespace comms_Munk{

class MunkMessage {
public:
    MunkMessage() = default;

    MunkMessage(const MunkMessage &copy);

    void resetData();
    void appendArray(const uint8_t &byte);

    QByteArray getDataArray() const;
    uint8_t getDataByte(const int &index) const;
    int getDataSize() const;

    FramingState setReadWriteType(const uint8_t &RWType);

    void setExceptionType(const data_Munk::ExceptionType &EXType);

    data_Munk::ReadWriteType isReadWriteType() const;

    data_Munk::ExceptionType isException() const;

    void setRemainingPayload(const int &size);

    int remainingPayloadSize() const;

public:
    MunkMessage& operator = (const MunkMessage &rhs)
    {
        currentArray = rhs.currentArray;
        rwType = rhs.rwType;
        exType = rhs.exType;
        remainingPayload = rhs.remainingPayload;
        return *this;
    }
private:
    QByteArray currentArray;
    data_Munk::ReadWriteType rwType = data_Munk::ReadWriteType::WRITE;
    data_Munk::ExceptionType exType = data_Munk::ExceptionType::NO_EXCEPTION;
    int remainingPayload = 0;
};

} //end of namespace comms_Munk


#endif // MUNK_MESSAGE_H
