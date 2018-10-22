#include "register_tb_temperature.h"

namespace registers_Munk {

Register_TBTemperature::Register_TBTemperature():
    AbstractParameter()
{
    this->parameterCode = 801;
    this->parameterType = ParameterType::TB_TEMPERATURE;
    this->setReadorWrite(data_Munk::MunkRWType::READ);
}

//!
//! \brief RegisterStandardFaults::RegisterStandardFaults
//! \param copy
//!
Register_TBTemperature::Register_TBTemperature(const Register_TBTemperature &copy):
    AbstractParameter(copy)
{

}

std::string Register_TBTemperature::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray Register_TBTemperature::getByteArray() const
{
    QByteArray ba;

    uint8_t HIGHSeqType = (uint8_t)((01 & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(01 & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

QByteArray Register_TBTemperature::getExpectedResponse() const
{
    QByteArray ba;
    return ba;
}

} //end of namespace registers_Munk

