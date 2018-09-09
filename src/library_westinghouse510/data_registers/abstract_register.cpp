#include "abstract_register.h"


namespace registers_WestinghousePump{

AbstractWestinghouseRegister::AbstractWestinghouseRegister():
    parameterCode(0),slaveAddress(3),readOrwrite(data_WestinghousePump::RWType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractWestinghouseRegister::AbstractWestinghouseRegister(const int &code):
    parameterCode(code),slaveAddress(3),readOrwrite(data_WestinghousePump::RWType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractWestinghouseRegister::AbstractWestinghouseRegister(const AbstractWestinghouseRegister &copy)
{
    this->parameterCode = copy.parameterCode;
    this->slaveAddress = copy.slaveAddress;
    this->readOrwrite = copy.readOrwrite;
    this->highChecksum = copy.highChecksum;
    this->lowChecksum = copy.lowChecksum;
}

void AbstractWestinghouseRegister::setSlaveAddress(const uint8_t &address)
{
    this->slaveAddress = address;
}

void AbstractWestinghouseRegister::setReadorWrite(const data_WestinghousePump::RWType &type)
{
    this->readOrwrite = type;
}

QByteArray AbstractWestinghouseRegister::getPrefixByteArray() const
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

QByteArray AbstractWestinghouseRegister::getFullMessage() const
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

ModbusRegister AbstractWestinghouseRegister::getModbusRegister() const
{
    ModbusRegister modbusRegister;

    modbusRegister.setSlaveAddress(this->slaveAddress);

    modbusRegister.setRegisterAddress(this->getRegisterCode());

    if(this->readOrwrite == data_WestinghousePump::RWType::READ)
        modbusRegister.setReadorWrite(ModbusRegister_RWType::READ);
    else
        modbusRegister.setReadorWrite(ModbusRegister_RWType::WRITE);

    modbusRegister.setData(this->getByteArray());

    return modbusRegister;
}

unsigned int AbstractWestinghouseRegister::CRC16(const QByteArray &array) const
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

} //end of namespace registers_WestinghousePump 

