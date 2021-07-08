#include "plc_data_framing.h"

namespace comms_PLC{

PLCDataFraming::PLCDataFraming(const int &address):
    pumpAddress(address), currentMSGState(PLCMessageFramingState::WAITING)
{

}

PLCMessageFramingState PLCDataFraming::additionalByteRecevied(const uint8_t &byte)
{
    switch (currentMSGState) {
    case PLCMessageFramingState::WAITING:
    case PLCMessageFramingState::RECEIVED_ENTIRE_MESSAGE:
    {
        //we should be looking for a byte equal to the address
        if(byte == pumpAddress)
        {
            currentMSGState = PLCMessageFramingState::RECIEVED_PUMP_ADDRESS;
            currentMessge.resetData();
            currentMessge.appendArray(byte);
        }
        break;
    }
    case PLCMessageFramingState::RECIEVED_PUMP_ADDRESS:
    {
        //once we have first received the munk address, the next byte will be the function code
        currentMessge.appendArray(byte);

        uint8_t exceptionMask = 127<<0;
        uint8_t exceptionValue = (byte & (~exceptionMask));

        uint8_t RWMask = 240<<0;
        uint8_t RWValue = (byte & (~RWMask));

        if(exceptionValue == 128)
        {
            // this means that we have received an exception message and there is only
            // one byte to follow telling us of the exception code and concluding with
            // the checksum
            currentMSGState = PLCMessageFramingState::RECEIVED_EXCEPTION_FUNCTION_CODE;
            currentMessge.setExceptionType(data_PLC::PLCExceptionTypes::EXCEPTION);
        }
        else
        {
            currentMSGState = currentMessge.setReadWriteType(RWValue);
            currentMessge.setExceptionType(data_PLC::PLCExceptionTypes::NO_EXCEPTION);
        }
        break;
    }
    case PLCMessageFramingState::RECEIVED_EXCEPTION_FUNCTION_CODE:
    {
        currentMSGState = PLCMessageFramingState::RECEIVED_EXCEPTION_CODE;
        currentMessge.appendArray(byte);
        break;
    }
    case PLCMessageFramingState::RECEIVED_EXCEPTION_CODE:
    {
        currentMSGState = PLCMessageFramingState::RECEIVED_CRC_HIGH;
        currentMessge.appendArray(byte);
        break;
    }
    case PLCMessageFramingState::RECEIVED_STD_FUNCTION_CODE_READ:
    {
        //this byte tells us how many bytes are following the message
        currentMSGState = PLCMessageFramingState::RECEIVED_PAYLOAD;
        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(byte);
        break;
    }
    case PLCMessageFramingState::RECEIVED_STD_FUNCTION_CODE_WRITE:
    {
        currentMSGState = PLCMessageFramingState::RECEIVED_PAYLOAD;
        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(3);
        break;
    }
    case PLCMessageFramingState::RECEIVED_PAYLOAD:
    {
        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(currentMessge.remainingPayloadSize() - 1);
        if(currentMessge.remainingPayloadSize() < 1)
        {
            currentMSGState = PLCMessageFramingState::RECEIVED_LAST_PAYLOAD;
        }
        break;
    }
    case PLCMessageFramingState::RECEIVED_LAST_PAYLOAD:
    {
        currentMSGState = PLCMessageFramingState::RECEIVED_CRC_HIGH;
        currentMessge.appendArray(byte);
        break;
    }
    case PLCMessageFramingState::RECEIVED_CRC_HIGH:
    {
        //we already had the low byte and therefore we must have received the high byte
        currentMSGState = PLCMessageFramingState::RECEIVED_CRC_LOW;
        currentMessge.appendArray(byte);

        uint8_t highByte = currentMessge.getDataByte(currentMessge.getDataSize() - 1);
        uint8_t lowByte = currentMessge.getDataByte(currentMessge.getDataSize() - 2);

        QByteArray currentArray = currentMessge.getDataArray();
        currentArray.remove(currentArray.size()-2,2);

        unsigned int checkSum = CRC16(currentArray);
        uint8_t highChecksum = (uint8_t)((checkSum & 0xFF00) >> 8);
        uint8_t lowChecksum = (uint8_t)(checkSum & 0x00FF);

        if((highByte == highChecksum) && (lowByte == lowChecksum))
        {
            //the message we received is complete
            currentMSGState = PLCMessageFramingState::RECEIVED_ENTIRE_MESSAGE;
        }
        else
        {
            currentMessge.resetData();
            currentMSGState = PLCMessageFramingState::WAITING;
        }
        break;
    }
    default:
        break;
    }
    return currentMSGState;
}

PLCMessage PLCDataFraming::getCurrentMessage() const
{
    return this->currentMessge;
}


unsigned int PLCDataFraming::CRC16(const QByteArray &array) const
{
char j;
unsigned int Temp = 0xFFFF;
int size = array.size();
for (int i=0;i<size;i++){
unsigned char charTemp = (unsigned char)array.at(i);
Temp ^= (unsigned int)charTemp;
for (j=8;j!=0;j--){

    if ((Temp & 0x0001) != 0) {      // If the LSB is set
        Temp >>= 1;                    // Shift right and XOR 0xA001
        Temp ^= 0xA001;
    }
    else                            // Else LSB is not set
        Temp >>= 1;                    // Just shift right
}
}
return Temp;
}

} //end of namespace comms_WestinghousePump

