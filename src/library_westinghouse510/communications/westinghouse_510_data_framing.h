#ifndef MUNK_DATA_FRAMING_H
#define MUNK_DATA_FRAMING_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "westinghouse_message.h"
#include "westinghouse_510_message_framing.h"

namespace comms_WestinghousePump{

class WestinghouseDataFraming
{
public:
    WestinghouseDataFraming(const int &address);
    FramingState additionalByteRecevied(const uint8_t &byte);
    WestinghouseMessage getCurrentMessage() const;
private:
    unsigned int CRC16(const QByteArray &array) const;

private:
    int pumpAddress;
    FramingState currentMSGState;
    WestinghouseMessage currentMessge;
};

} //end of namespace comms_WestinghousePump


#endif // MUNK_DATA_FRAMING_H
