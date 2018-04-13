#include "munk_data_framing.h"


namespace comms_Munk{

MunkDataFraming::MunkDataFraming(const int &munkAddress):
    munkAddress(munkAddress), currentMSGState(FramingState::WAITING)
{

}

FramingState MunkDataFraming::additionalByteRecevied(const uint8_t &byte)
{
    switch (currentMSGState) {
    case FramingState::WAITING:
    case FramingState::RECEIVED_ENTIRE_MESSAGE:
    {
        std::cout<<"We are in the state of waiting and/or had previously received an entire message"<<std::endl;
        //we should be looking for a byte equal to the address
        if(byte == munkAddress)
        {
            currentMSGState = FramingState::RECIEVED_MUNK_ADDRESS;
            currentMessge.resetData();
            currentMessge.appendArray(byte);
        }
        break;
    }
    case FramingState::RECIEVED_MUNK_ADDRESS:
    {
        std::cout<<"We are in the state of munk address"<<std::endl;

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
            currentMSGState = FramingState::RECEIVED_EXCEPTION_FUNCTION_CODE;
            currentMessge.setExceptionType(data_Munk::MunkExceptionType::EXCEPTION);
        }
        else
        {
            currentMSGState = currentMessge.setReadWriteType(RWValue);
            currentMessge.setExceptionType(data_Munk::MunkExceptionType::NO_EXCEPTION);
        }
        break;
    }
    case FramingState::RECEIVED_EXCEPTION_FUNCTION_CODE:
    {
        std::cout<<"We are in the state of exception function code"<<std::endl;

        currentMSGState = FramingState::RECEIVED_EXCEPTION_CODE;
        currentMessge.appendArray(byte);
        break;
    }
    case FramingState::RECEIVED_EXCEPTION_CODE:
    {
        std::cout<<"We are in the exception code"<<std::endl;

        currentMSGState = FramingState::RECEIVED_CRC_LOW;
        currentMessge.appendArray(byte);
        break;
    }
    case FramingState::RECEIVED_STD_FUNCTION_CODE_READ:
    {
        std::cout<<"We are in the state of function code read"<<std::endl;

        //this byte tells us how many bytes are following the message
        currentMSGState = FramingState::RECEIVED_PAYLOAD;
        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(byte);
        break;
    }
    case FramingState::RECEIVED_STD_FUNCTION_CODE_WRITE:
    {
        std::cout<<"We are in the state of function code write"<<std::endl;

        currentMSGState = FramingState::RECEIVED_LAST_PAYLOAD;
        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(0);
        break;
    }
    case FramingState::RECEIVED_PAYLOAD:
    {
        std::cout<<"We are in the state of receiving payload"<<std::endl;

        currentMessge.appendArray(byte);
        currentMessge.setRemainingPayload(currentMessge.remainingPayloadSize() - 1);
        if(currentMessge.remainingPayloadSize() < 1)
        {
            currentMSGState = FramingState::RECEIVED_LAST_PAYLOAD;
        }
        break;
    }
    case FramingState::RECEIVED_LAST_PAYLOAD:
    {
        std::cout<<"We are in the state of receiving last payload"<<std::endl;

        currentMSGState = FramingState::RECEIVED_CRC_LOW;
        currentMessge.appendArray(byte);
        break;
    }
    case FramingState::RECEIVED_CRC_LOW:
    {
        std::cout<<"We are in the state of receiving crc low"<<std::endl;

        //we already had the low byte and therefore we must have received the high byte
        currentMSGState = FramingState::RECEIVED_CRC_HIGH;
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
            currentMSGState = FramingState::RECEIVED_ENTIRE_MESSAGE;
        }
        else
        {
            currentMessge.resetData();
            currentMSGState = FramingState::WAITING;
        }
        break;
    }
    default:
        break;
    }
    return currentMSGState;
}

MunkMessage MunkDataFraming::getCurrentMessage() const
{
    return this->currentMessge;
}

FramingState MunkDataFraming::getCurrentMessageState() const
{
    return this->currentMSGState;
}

unsigned int MunkDataFraming::CRC16(const QByteArray &array) const
{
char j;
WORD Temp = 0xFFFF;
int size = array.size();
for (int i=0;i<size;i++){
unsigned char charTemp = (unsigned char)array.at(i);
Temp ^= (WORD)charTemp;
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

} //end of namespace comms_Munk

