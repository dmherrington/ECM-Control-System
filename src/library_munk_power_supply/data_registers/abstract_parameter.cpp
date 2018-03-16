#include "abstract_parameter.h"


namespace registers_Munk {

AbstractParameter::AbstractParameter():
    parameterCode(0),slaveAddress(0),readOrwrite(data_Munk::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractParameter::AbstractParameter(const int &code):
    parameterCode(code),slaveAddress(0),readOrwrite(data_Munk::ReadWriteType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractParameter::AbstractParameter(const AbstractParameter &copy)
{
    this->parameterCode = copy.parameterCode;
    this->slaveAddress = copy.slaveAddress;
    this->readOrwrite = copy.readOrwrite;
    this->highChecksum = copy.highChecksum;
    this->lowChecksum = copy.lowChecksum;
}

void AbstractParameter::setSlaveAddress(const uint8_t &address)
{
    this->slaveAddress = address;
}

void AbstractParameter::setReadorWrite(const data_Munk::ReadWriteType &type)
{
    this->readOrwrite = type;
}

QByteArray AbstractParameter::getPrefixByteArray() const
{
    QByteArray ba;

    ba.append(slaveAddress);
    ba.append((uint8_t)readOrwrite);

    uint8_t HIGHPType = (uint8_t)((parameterCode & 0xFF00) >> 8);
    uint8_t LOWPType = (uint8_t)(parameterCode & 0x00FF);
    ba.append(HIGHPType);
    ba.append(LOWPType);

    return ba;
}

QByteArray AbstractParameter::getFullMessage() const
{
    QByteArray dataSum;

    QByteArray prefix = getPrefixByteArray();
    QByteArray data = getByteArray();

    if(data.size() > 0)
    {
        dataSum.append(prefix);
        dataSum.append(data);

        unsigned int checkSum = CRC16(dataSum);
        highChecksum = (uint8_t)((checkSum & 0xFF00) >> 8);
        lowChecksum = (uint8_t)(checkSum & 0x00FF);
        dataSum.append(lowChecksum);
        dataSum.append(highChecksum);
    }

    return dataSum;
}

QByteArray AbstractParameter::getFullExpectedResonse() const
{
    QByteArray dataSum;

    QByteArray prefix = getPrefixByteArray();
    QByteArray data = getExpectedResponse();

    if(data.size() > 0)
    {
        dataSum.append(prefix);
        dataSum.append(data);

        unsigned int checkSum = CRC16(dataSum);
        highChecksum = (uint8_t)((checkSum & 0xFF00) >> 8);
        lowChecksum = (uint8_t)(checkSum & 0x00FF);
        dataSum.append(lowChecksum);
        dataSum.append(highChecksum);
    }

    return dataSum;
}


unsigned int AbstractParameter::CRC16(const QByteArray &array) const
{
    //redefining word so its not so bad
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

} //end of namespace registers_Munk

