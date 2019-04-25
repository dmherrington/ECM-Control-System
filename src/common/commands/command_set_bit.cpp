#include "command_set_bit.h"

CommandSetBit::CommandSetBit():
    AbstractCommand(CommandType::SET_BIT)
{

}

CommandSetBit::CommandSetBit(const CommandSetBit &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandSetBit::getClone() const
{
    return (new CommandSetBit(*this));
}

void CommandSetBit::getClone(AbstractCommand** state) const
{
    *state = new CommandSetBit(*this);
}

void CommandSetBit::setValue(const unsigned int &port, const unsigned int &bit, const bool &value)
{
    this->digitalPort = port;
    this->digitalBit = bit;
    this->value = value;
}

void CommandSetBit::getValue(unsigned int &port, unsigned int &bit, bool &value) const
{
    port = this->digitalPort;
    bit = this->digitalBit;
    value = this->value;
}


std::string CommandSetBit::getCommandString() const
{
    std::string str;
//    str.append(CommandToString(this->getCommandType()));
//    str.append(" ");
//    int length = digitalAddr.size();
//    for(int i = 0; i < length; i++)
//    {
//        str.append(std::to_string(digitalAddr.at(i)));
//        if(i < (length-1))
//            str.append(",");
//    }
    return str;
}

