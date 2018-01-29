#ifndef MUNK_DATA_FRAMING_H
#define MUNK_DATA_FRAMING_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "munk_message.h"
#include "message_framing_state.h"

class MunkDataFraming
{
    typedef unsigned int WORD;

public:
    MunkDataFraming(const int &munkAddress);
    FramingState additionalByteRecevied(const uint8_t &byte);
    MunkMessage getCurrentMessage() const;
private:
    unsigned int CRC16(const QByteArray &array) const;

private:
    int munkAddress;
    FramingState currentMSGState;
    MunkMessage currentMessge;
};

#endif // MUNK_DATA_FRAMING_H
