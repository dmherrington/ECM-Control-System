#include "register_operation_signal.h"


namespace registers_WestinghousePump{

Register_OperationSignal::Register_OperationSignal():
    AbstractWestinghouseRegister(RegisterTypeToInt(WestinhouseRegisterTypes::OPERATION_SIGNAL))
{

}
Register_OperationSignal::Register_OperationSignal(const Register_OperationSignal &copy):
    AbstractWestinghouseRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_OperationSignal::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
WestinhouseRegisterTypes Register_OperationSignal::getRegisterType() const
{
    return WestinhouseRegisterTypes::OPERATION_SIGNAL;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_OperationSignal::getByteArray() const
{
    QByteArray data;

    uint32_t bitArray = 0;
    uint32_t mask = 1<<0;
    bitArray = (bitArray & (~mask)) | (_run<<0);

    mask = 1<<1;
    bitArray = (bitArray & (~mask)) | (_reverse<<1);

    mask = 1<<2;
    bitArray = (bitArray & (~mask)) | (_fault<<2);

    uint8_t HIGHBType = (uint8_t)((bitArray & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(bitArray & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);


    return data;
}

void Register_OperationSignal::parseFromArray(const QByteArray &msg)
{
    this->setSlaveAddress(msg.at(0));
    //parse if it is read/write
    if(msg.at(1) == static_cast<int>(data_WestinghousePump::RWType::READ))
        this->setReadorWrite(data_WestinghousePump::RWType::READ);
    else
        this->setReadorWrite(data_WestinghousePump::RWType::WRITE);

    uint8_t dataHi = msg.at(4);
    uint8_t dataLo = msg.at(5);
    uint32_t value = dataLo | (dataHi<<8);

    unsigned int mask = 2;
    //check 2nd bit
    this->shouldReverse(this->checkMask(value,mask));
    //check 1st bit
    mask = 1;
    this->shouldRun(this->checkMask(value,mask));

}

bool Register_OperationSignal::checkMask(const uint16_t &value, const unsigned int &mask) const
{
    if((value & mask) == 0)
        return false;
    else
        return true;
}


void Register_OperationSignal::shouldRun(const bool &value)
{
    this->_run = value;
}

void Register_OperationSignal::shouldReverse(const bool &value)
{
    this->_reverse = value;
}

void Register_OperationSignal::shouldFault(const bool &value)
{
    this->_fault = value;
}

void Register_OperationSignal::shouldReset(const bool &value)
{
    this->_reset = value;
}

bool Register_OperationSignal::isRun() const
{
    return _run;
}

bool Register_OperationSignal::isReverse() const
{
    return _reverse;
}

bool Register_OperationSignal::isFault() const
{
    return _fault;
}

bool Register_OperationSignal::isReset() const
{
    return _reset;
}

} //end of namespace registers_WestinghousePump 

