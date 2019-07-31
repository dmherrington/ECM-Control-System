#include "register_ph.h"

namespace registers_PLC{

Register_pH::Register_pH():
    AbstractPLCRegister(RegisterTypeToInt(PLCRegisterTypes::PH))
{

}
Register_pH::Register_pH(const Register_pH &copy):
    AbstractPLCRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_pH::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
PLCRegisterTypes Register_pH::getRegisterType() const
{
    return PLCRegisterTypes::PH;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_pH::getByteArray() const
{
    QByteArray data;
    return data;
}

void Register_pH::parseFromArray(const QByteArray &msg)
{

}

} //end of namespace registers_PLC
