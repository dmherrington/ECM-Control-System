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

void CommandSetBit::appendAddress(const unsigned int &address)
{
    this->digitalAddr.push_back(address);
}

std::vector<unsigned int> CommandSetBit::getDigitalAddress() const
{
    return this->digitalAddr;
}

std::string CommandSetBit::getCommandString() const
{
    std::string str;
    str.append(CommandToString(this->getCommandType()));
    str.append(" ");
    int length = digitalAddr.size();
    for(int i = 0; i < length; i++)
    {
        str.append(std::to_string(digitalAddr.at(i)));
        if(i < (length-1))
            str.append(",");
    }
    return str;
}

