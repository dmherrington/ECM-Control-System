#include "register_tb_count.h"

namespace registers_Munk {


Register_TBCount::Register_TBCount():
    AbstractParameter()
{
    this->parameterCode = 801;
    this->parameterType = ParameterType::TB_COUNT;
    this->setReadorWrite(data_Munk::MunkRWType::READ);
}

Register_TBCount::Register_TBCount(const Register_TBCount &copy):
    AbstractParameter(copy)
{

}

std::string Register_TBCount::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray Register_TBCount::getByteArray() const
{
    QByteArray ba;

    uint8_t HIGHSeqType = (uint8_t)((01 & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(01 & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

QByteArray Register_TBCount::getExpectedResponse() const
{
    QByteArray ba;
    return ba;
}

} //end of namespace registers_Munk
