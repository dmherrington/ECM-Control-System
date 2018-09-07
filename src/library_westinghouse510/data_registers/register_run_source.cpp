#include "register_run_source.h"

namespace registers_WestinghousePump {

Register_RunSource::Register_RunSource(const SourceSetting &runSource):
    AbstractWestinghouseRegister(RegisterTypeToInt(WestinhouseRegisterTypes::RUN_SOURCE))
{
    this->source = runSource;
}

Register_RunSource::Register_RunSource(const Register_RunSource &copy):
    AbstractWestinghouseRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_RunSource::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
WestinhouseRegisterTypes Register_RunSource::getRegisterType() const
{
    return WestinhouseRegisterTypes::RUN_SOURCE;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_RunSource::getByteArray() const
{
    uint8_t castSource = static_cast<uint8_t>(this->source);

    QByteArray data;
    uint8_t HIGHBType = (uint8_t)((castSource & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(castSource & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);

    return data;
}

void Register_RunSource::parseFromArray(const QByteArray &msg)
{
    this->setSlaveAddress(msg.at(0));
    //parse if it is read/write
    if(msg.at(1) == static_cast<int>(data_WestinghousePump::RWType::READ))
        this->setReadorWrite(data_WestinghousePump::RWType::READ);
    else
        this->setReadorWrite(data_WestinghousePump::RWType::WRITE);

    uint8_t dataHi = msg.at(4);
    uint8_t dataLo = msg.at(5);
    uint32_t setFlow = dataLo | (dataHi<<8);
//    double GPM = setFlow / 1000.0;
//    this->source = GPM/0.264172;
}

void Register_RunSource::setRunSource(const SourceSetting &runSource)
{
    this->source = runSource;
}

Register_RunSource::SourceSetting Register_RunSource::getRunSource() const
{
    return this->source;
}

} //end of namespace registers_WestinghousePump


