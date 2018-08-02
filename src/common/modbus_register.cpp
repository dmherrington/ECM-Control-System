#include "modbus_register.h"

ModbusRegister::ModbusRegister():
    registerAddress(0),slaveAddress(0),readOrwrite(ModbusRegister_RWType::WRITE),highChecksum(0),lowChecksum(0)
{

}

ModbusRegister::ModbusRegister(const ModbusRegister &copy)
{
    this->registerAddress = copy.registerAddress;
    this->slaveAddress = copy.slaveAddress;
    this->readOrwrite = copy.readOrwrite;
    this->data = copy.data;
    this->highChecksum = copy.highChecksum;
    this->lowChecksum = copy.lowChecksum;
}

void ModbusRegister::setRegisterAddress(const unsigned int &registerAddress)
{
    this->registerAddress = registerAddress;
}

QByteArray ModbusRegister::getByteArray() const
{
    return this->data;
}

void ModbusRegister::setSlaveAddress(const uint8_t &address)
{
    this->slaveAddress = address;
}

void ModbusRegister::setReadorWrite(const ModbusRegister_RWType &type)
{
    this->readOrwrite = type;
}

void ModbusRegister::setData(const QByteArray &dataArray)
{
    this->data = dataArray;
}

QByteArray ModbusRegister::getPrefixByteArray() const
{
    QByteArray ba;

    ba.append(slaveAddress);
    ba.append((uint8_t)readOrwrite);

    uint8_t HIGHPType = (uint8_t)((registerAddress & 0xFF00) >> 8);
    uint8_t LOWPType = (uint8_t)(registerAddress & 0x00FF);
    ba.append(HIGHPType);
    ba.append(LOWPType);

    return ba;
}

QByteArray ModbusRegister::getFullMessage() const
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

unsigned int ModbusRegister::CRC16(const QByteArray &array) const
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
