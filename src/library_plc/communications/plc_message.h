#ifndef PLC_MESSAGE_H
#define PLC_MESSAGE_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "../data/type_read_write.h"
#include "../data/type_plc_exception.h"

#include "plc_message_framing.h"


namespace comms_PLC {

class PLCMessage
{
public:
    PLCMessage() = default;

    PLCMessage(const PLCMessage &copy);

    void resetData();
    void appendArray(const uint8_t &byte);

    QByteArray getDataArray() const;
    uint8_t getDataByte(const int &index) const;
    int getDataSize() const;

    PLCMessageFramingState setReadWriteType(const uint8_t &RWType);

    void setExceptionType(const data_PLC::PLCExceptionTypes &EXType);

    data_PLC::RWType isReadWriteType() const;

    data_PLC::PLCExceptionTypes isException() const;

    void setRemainingPayload(const int &size);

    int remainingPayloadSize() const;

public:
    PLCMessage& operator = (const PLCMessage &rhs)
    {
        currentArray = rhs.currentArray;
        rwType = rhs.rwType;
        exType = rhs.exType;
        remainingPayload = rhs.remainingPayload;
        return *this;
    }
private:
    QByteArray currentArray;
    data_PLC::RWType rwType = data_PLC::RWType::WRITE;
    data_PLC::PLCExceptionTypes exType = data_PLC::PLCExceptionTypes::NO_EXCEPTION;
    int remainingPayload = 0;
};

} //end of namespace comms_PLCPump


#endif //PLC_MESSAGE_H
