#ifndef PLC_DATA_FRAMING_H
#define PLC_DATA_FRAMING_H

#include <QByteArray>

#include "common/common.h"
#include "common/class_forward.h"

#include "../data/type_read_write.h"
#include "../data/type_plc_exception.h"

#include "plc_message.h"
#include "plc_message_framing.h"

namespace comms_PLC{

class PLCDataFraming
{
public:
    PLCDataFraming(const int &address);
    PLCMessageFramingState additionalByteRecevied(const uint8_t &byte);
    PLCMessage getCurrentMessage() const;
private:
    unsigned int CRC16(const QByteArray &array) const;

private:
    int pumpAddress;
    PLCMessageFramingState currentMSGState;
    PLCMessage currentMessge;
};

} //end of namespace comms_PLC


#endif // PLC_DATA_FRAMING_H
