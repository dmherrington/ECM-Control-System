#include "register_supply_identifier.h"

namespace registers_Munk {

//!
//! \brief Register_SupplyIdentifier::Register_SupplyIdentifier
//! \param type
//!
Register_SupplyIdentifier::Register_SupplyIdentifier():
    AbstractParameter()
{
    this->parameterCode = 10;
    this->parameterType = ParameterType::SUPPLY_IDENTIFIER;
    this->setReadorWrite(data_Munk::MunkRWType::READ);
}

//!
//! \brief RegisterStandardFaults::RegisterStandardFaults
//! \param copy
//!
Register_SupplyIdentifier::Register_SupplyIdentifier(const Register_SupplyIdentifier &copy):
    AbstractParameter(copy)
{

}


ParameterType Register_SupplyIdentifier::getParameterType() const
{
    return ParameterType::SUPPLY_IDENTIFIER;
}

std::string Register_SupplyIdentifier::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray Register_SupplyIdentifier::getByteArray() const
{
    QByteArray ba;

    uint8_t HIGHSeqType = (uint8_t)((01 & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(01 & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

QByteArray Register_SupplyIdentifier::getExpectedResponse() const
{
    QByteArray ba;
    return ba;
}

} //end of namespace registers_Munk
