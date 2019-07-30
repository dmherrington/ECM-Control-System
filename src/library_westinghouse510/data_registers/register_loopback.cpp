#include "register_loopback.h"

namespace registers_WestinghousePump {

Register_Loopback::Register_Loopback():
    AbstractWestinghouseRegister(RegisterTypeToInt(WestinhouseRegisterTypes::LOOPBACK))
{

}

Register_Loopback::Register_Loopback(const Register_Loopback &copy):
    AbstractWestinghouseRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_Loopback::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
WestinhouseRegisterTypes Register_Loopback::getRegisterType() const
{
    return WestinhouseRegisterTypes::LOOPBACK;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_Loopback::getByteArray() const
{
    QByteArray data;

    data.append(static_cast<char>(dataHi));
    data.append(static_cast<char>(dataLo));

    return data;
}

void Register_Loopback::parseFromArray(const QByteArray &msg)
{
    this->setSlaveAddress(static_cast<uint8_t>(msg.at(0)));
    //parse if it is read/write
    if(msg.at(1) == static_cast<int>(data_WestinghousePump::RWType::READ))
        this->setReadorWrite(data_WestinghousePump::RWType::READ);
    else if(msg.at(1) == static_cast<int>(data_WestinghousePump::RWType::WRITE))
        this->setReadorWrite(data_WestinghousePump::RWType::WRITE);
    else
        this->setReadorWrite(data_WestinghousePump::RWType::LOOP);
}

} //end of namespace registers_WestinghousePump
