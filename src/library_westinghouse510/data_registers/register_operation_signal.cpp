#include "register_operation_signal.h"

namespace westinghousePump{
namespace registers{

Register_OperationSignal::Register_OperationSignal():
    AbstractRegister(RegisterTypeToInt(RegisterType::OPERATION_SIGNAL))
{

}
Register_OperationSignal::Register_OperationSignal(const Register_OperationSignal &copy):
    AbstractRegister(copy)
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
RegisterType Register_OperationSignal::getRegisterType() const
{
    return RegisterType::OPERATION_SIGNAL;
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

} //end of namespace registers
} //end of namespace westinghousePump
