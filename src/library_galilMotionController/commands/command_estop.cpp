#include "command_estop.h"

CommandEStop::CommandEStop():
    AbstractCommand(CommandType::EXECUTE_PROGRAM)
{

}

CommandEStop::CommandEStop(const CommandEStop &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandEStop::getClone() const
{
    return (new CommandEStop(*this));
}

void CommandEStop::getClone(AbstractCommand** state) const
{
    *state = new CommandEStop(*this);
}

std::string CommandEStop::getCommandString() const
{
    std::string str;
    return str;
}
