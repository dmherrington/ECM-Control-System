#ifndef WESTINGHOUSE_DATA_FRAMING_H
#define WESTINGHOUSE_DATA_FRAMING_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "../data/type_read_write.h"
#include "data/westinghouse_exception_message.h"

#include "westinghouse_message.h"
#include "westinghouse_510_message_framing.h"

namespace comms_WestinghousePump{

class WestinghouseDataFraming
{
public:
    WestinghouseDataFraming(const int &address);
    WestinghouseFramingState additionalByteRecevied(const uint8_t &byte);
    WestinghouseMessage getCurrentMessage() const;
private:
    unsigned int CRC16(const QByteArray &array) const;

private:
    int pumpAddress;
    WestinghouseFramingState currentMSGState;
    WestinghouseMessage currentMessge;
};

} //end of namespace comms_WestinghousePump


#endif // WESTINGHOUSE_DATA_FRAMING_H
