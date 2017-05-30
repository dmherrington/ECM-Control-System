#include "abstract_parameter.h"

namespace DataParameter {

AbstractParameter::AbstractParameter():
    parameterCode(0),slaveAddress(0),readOrwrite(Data::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractParameter::AbstractParameter(const int &code):
    parameterCode(code),slaveAddress(0),readOrwrite(Data::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

QByteArray AbstractParameter::getFullMessage()
{
    QByteArray data = getByteArray();
    unsigned int checkSum = CRC16(data);
    highChecksum = (uint8_t)((checkSum & 0xFF00) >> 8);
    lowChecksum = (uint8_t)(checkSum & 0x00FF);

}

unsigned int AbstractParameter::CRC16(const QByteArray &array)
{
    char j;
    unsigned int Temp = 0xFFFF;

    for (int i=0;i<array.size();i++){
        Temp ^= (unsigned int)array.at(i);
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

} //end of namespace DataParameter
