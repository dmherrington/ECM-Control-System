#include "register_conductivity.h"

namespace registers_PLC{

Register_Conductivity::Register_Conductivity():
    AbstractPLCRegister(RegisterTypeToInt(PLCRegisterTypes::CONDUCTIVITY))
{
    this->setReadorWrite(data_PLC::RWType::READ);
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
    //const int count = qFromLittleEndian<qint16>(info.data());

    QByteArray data;
    uint8_t HIGHBType = (uint8_t)((0 & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(2 & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);
    return data;
}

void Register_Conductivity::parseFromArray(const QByteArray &msg)
{

}

} //end of namespace registers_PLC
