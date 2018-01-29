#include "munk_data_framing.h"

MunkDataFraming::MunkDataFraming(const int &munkAddress):
    munkAddress(munkAddress), currentMSGState(FramingState::WAITING)
{

}

void MunkDataFraming::additionalByteRecevied(const uint8_t &byte)
{
    switch (currentMSGState) {
    case FramingState::WAITING:
    {
        //we should be looking for a byte equal to the address
        if(byte == munkAddress)
        {
            currentMSGState = FramingState::RECIEVED_MUNK_ADDRESS;
            currentArray.clear();
            currentArray.append(byte);
        }
        break;
    }
    case FramingState::RECIEVED_MUNK_ADDRESS:
    {
        //once we have first received the munk address, the next byte will be the function code
        currentMSGState = FramingState::RECEIVED_FUNCTION_CODE;
        currentArray.append(byte);
        break;
    }
    case FramingState::RECEIVED_CRC_LOW:
    {
        //we already had the low byte and therefore we must have received the high byte
        currentMSGState = FramingState::RECEIVED_CRC_HIGH;
        currentArray.append(byte);

        uint8_t highByte = currentArray.at(currentArray.size() - 1);
        uint8_t lowByte = currentArray.at(currentArray.size() - 2);

        unsigned int checkSum = CRC16(dataSum);
        uint8_t highChecksum = (uint8_t)((checkSum & 0xFF00) >> 8);
        uint8_t lowChecksum = (uint8_t)(checkSum & 0x00FF);

        if((highByte == highChecksum) && (lowByte == lowChecksum))
        {
            //the message we received is complete
        }
        break;
    }
    default:
        break;
    }
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
