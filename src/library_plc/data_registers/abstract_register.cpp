#include "abstract_register.h"

namespace registers_PLC{

AbstractPLCRegister::AbstractPLCRegister():
    parameterCode(0),slaveAddress(1),readOrwrite(data_PLC::RWType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractPLCRegister::AbstractPLCRegister(const unsigned int &code):
    parameterCode(code),slaveAddress(1),readOrwrite(data_PLC::RWType::WRITE),highChecksum(0),lowChecksum(0)
{

}

AbstractPLCRegister::AbstractPLCRegister(const AbstractPLCRegister &copy)
{
    this->parameterCode = copy.parameterCode;
    this->slaveAddress = copy.slaveAddress;
    this->readOrwrite = copy.readOrwrite;
    this->highChecksum = copy.highChecksum;
    this->lowChecksum = copy.lowChecksum;
}

void AbstractPLCRegister::setSlaveAddress(const uint8_t &address)
{
    this->slaveAddress = address;
}

void AbstractPLCRegister::setReadorWrite(const data_PLC::RWType &type)
{
    this->readOrwrite = type;
}

QByteArray AbstractPLCRegister::getPrefixByteArray() const
{
    QByteArray ba;

    ba.append(static_cast<char>(slaveAddress));
    ba.append(static_cast<char>(readOrwrite));

    uint8_t HIGHPType = static_cast<uint8_t>((parameterCode & 0xFF00) >> 8);
    uint8_t LOWPType = static_cast<uint8_t>(parameterCode & 0x00FF);
    ba.append(static_cast<char>(HIGHPType));
    ba.append(static_cast<char>(LOWPType));

    return ba;
}

QByteArray AbstractPLCRegister::getFullMessage() const
{
    QByteArray dataSum;

    QByteArray prefix = getPrefixByteArray();
    QByteArray data = getByteArray();

    if(data.size() > 0)
    {
        dataSum.append(prefix);
        dataSum.append(data);

        unsigned int checkSum = CRC16(dataSum);
        highChecksum = static_cast<uint8_t>((checkSum & 0xFF00) >> 8);
        lowChecksum = static_cast<uint8_t>(checkSum & 0x00FF);
        dataSum.append(static_cast<char>(lowChecksum));
        dataSum.append(static_cast<char>(highChecksum));
    }

    return dataSum;
}

ModbusRegister AbstractPLCRegister::getModbusRegister() const
{
    ModbusRegister modbusRegister;

    modbusRegister.setSlaveAddress(this->slaveAddress);

    modbusRegister.setRegisterAddress(this->getRegisterCode());

    if(this->readOrwrite == data_PLC::RWType::READ)
        modbusRegister.setReadorWrite(ModbusRegister_RWType::READ);
    else
        modbusRegister.setReadorWrite(ModbusRegister_RWType::WRITE);

    modbusRegister.setData(this->getByteArray());

    return modbusRegister;
}

unsigned int AbstractPLCRegister::CRC16(const QByteArray &array) const
{
    char j;
    unsigned int Temp = 0xFFFF;
    int size = array.size();
    for (int i=0;i<size;i++){
        unsigned char charTemp = static_cast<unsigned char>(array.at(i));
        Temp ^= static_cast<unsigned int>(charTemp);
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

} //end of namespace registers_PLC

