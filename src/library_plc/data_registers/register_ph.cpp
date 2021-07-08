#include "register_ph.h"

namespace registers_PLC{

Register_pH::Register_pH():
    AbstractPLCRegister(RegisterTypeToInt(PLCRegisterTypes::PH))
{
    this->setReadorWrite(data_PLC::RWType::READ);
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
    //const int count = qFromLittleEndian<qint16>(info.data());

    QByteArray data;
    uint8_t HIGHBType = (uint8_t)((0 & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(2 & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);
    return data;
}

void Register_pH::parseFromArray(const QByteArray &msg)
{

}

} //end of namespace registers_PLC
