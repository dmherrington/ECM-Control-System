#include "register_tb_select.h"

namespace registers_Munk {


Register_TBSelect::Register_TBSelect(const unsigned int &board):
    AbstractParameter()
{
    this->parameterCode = 800;
    this->parameterType = ParameterType::TB_SELECT;
    this->setReadorWrite(data_Munk::MunkRWType::WRITE);

    this->setBoardNumber(board);
}

Register_TBSelect::Register_TBSelect(const Register_TBSelect &copy):
    AbstractParameter(copy)
{

}

std::string Register_TBSelect::getDescription() const
{
    std::string str = "";
    return str;
}

void Register_TBSelect::setBoardNumber(const unsigned int &board)
{
    this->boardNumber = board;
}

unsigned int Register_TBSelect::getBoardNumber() const
{
    return this->boardNumber;
}

QByteArray Register_TBSelect::getByteArray() const
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

        uint8_t HIGHBType = (uint8_t)((this->boardNumber & 0xFF00) >> 8);
        uint8_t LOWBType = (uint8_t)(this->boardNumber & 0x00FF);

        ba.append(HIGHBType);
        ba.append(LOWBType);
    }

    return ba;
}

QByteArray Register_TBSelect::getExpectedResponse() const
{
    QByteArray ba;
    uint8_t HIGHSeqType = (uint8_t)((1 & 0xFF00) >> 8);
    uint8_t LOWSeqType = (uint8_t)(1 & 0x00FF);
    ba.append(HIGHSeqType);
    ba.append(LOWSeqType);

    return ba;
}

} //end of namespace registers_Munk
