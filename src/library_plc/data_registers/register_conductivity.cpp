#include "register_conductivity.h"

namespace registers_PLC{

Register_Conductivity::Register_Conductivity():
    AbstractPLCRegister(RegisterTypeToInt(PLCRegisterTypes::CONDUCTIVITY))
{

}
Register_Conductivity::Register_Conductivity(const Register_Conductivity &copy):
    AbstractPLCRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_Conductivity::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
PLCRegisterTypes Register_Conductivity::getRegisterType() const
{
    return PLCRegisterTypes::CONDUCTIVITY;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_Conductivity::getByteArray() const
{
    QByteArray data;
    return data;
}

void Register_Conductivity::parseFromArray(const QByteArray &msg)
{

}

} //end of namespace registers_PLC
