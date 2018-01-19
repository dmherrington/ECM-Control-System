#include "command_clear_bit.h"

CommandClearBit::CommandClearBit():
    AbstractCommand(CommandType::CLEAR_BIT)
{

}
CommandClearBit::CommandClearBit(const CommandClearBit &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandClearBit::getClone() const
{
    return (new CommandClearBit(*this));
}

void CommandClearBit::getClone(AbstractCommand** state) const
{
    *state = new CommandClearBit(*this);
}

void CommandClearBit::appendAddress(const unsigned int &address)
{
    this->digitalAddr.push_back(address);
}

std::vector<unsigned int> CommandClearBit::getDigitalAddress() const
{
    return this->digitalAddr;
}

std::string CommandClearBit::getCommandString() const
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
