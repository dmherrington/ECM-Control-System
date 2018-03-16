#ifndef MUNK_MESSAGE_FRAMING_STATE_H
#define MUNK_MESSAGE_FRAMING_STATE_H

enum class FramingState{
    WAITING,
    RECIEVED_MUNK_ADDRESS,
    RECEIVED_EXCEPTION_FUNCTION_CODE,
    RECEIVED_STD_FUNCTION_CODE_READ,
    RECEIVED_STD_FUNCTION_CODE_WRITE,
    RECEIVED_EXCEPTION_CODE,
    RECEIVED_PAYLOAD,
    RECEIVED_LAST_PAYLOAD,
    RECEIVED_CRC_LOW,
    RECEIVED_CRC_HIGH,
    RECEIVED_ENTIRE_MESSAGE
};

#endif // MUNK_MESSAGE_FRAMING_STATE_H
