#include "command_set_bit.h"

CommandSetBit::CommandSetBit():
    AbstractCommand()
{

}

void CommandSetBit::appendAddress(const unsigned int &address)
{
    this->digitalAddr.push_back(address);
}

std::vector<unsigned int> CommandSetBit::getDigitalAddress()
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
        str.append(digitalAddr.at(i));
        if(i < (length-1))
            str.append(",");
    }
    return str;
}

