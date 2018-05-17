#include "register_fault_reset.h"

namespace registers_Munk {


Register_FaultReset::Register_FaultReset():
    AbstractParameter()
{
    this->parameterCode = 201;
    this->setReadorWrite(data_Munk::MunkRWType::WRITE);
}

Register_FaultReset::Register_FaultReset(const Register_FaultReset &copy):
    AbstractParameter(copy)
{

}

std::string Register_FaultReset::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray Register_FaultReset::getByteArray() const
{
    QByteArray ba;
    uint8_t numBytes = 1;
    if(numBytes > 0)
    {
        uint8_t HIGHSeqType = (uint8_t)((numBytes & 0xFF00) >> 8);
        uint8_t LOWSeqType = (uint8_t)(numBytes & 0x00FF);
        ba.append(HIGHSeqType);
        ba.append(LOWSeqType);

        ba.append((uint8_t)numBytes * 2);

        uint8_t HIGHBType = (uint8_t)((01 & 0xFF00) >> 8); //01 signals a value of true
        uint8_t LOWBType = (uint8_t)(01 & 0x00FF);

        ba.append(HIGHBType);
        ba.append(LOWBType);
    }

    return ba;
}

QByteArray Register_FaultReset::getExpectedResponse() const
{
    QByteArray ba;
    uint8_t HIGHSeqType = (uint8_t)((1 & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(1 & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

} //end of namespace registers_Munk
