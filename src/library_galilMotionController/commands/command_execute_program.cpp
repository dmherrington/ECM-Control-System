#include "command_execute_program.h"

CommandExecuteProgram::CommandExecuteProgram():
    AbstractCommand(CommandType::EXECUTE_PROGRAM)
{

}

CommandExecuteProgram::CommandExecuteProgram(const CommandExecuteProgram &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandExecuteProgram::getClone() const
{
    return (new CommandExecuteProgram(*this));
}

void CommandExecuteProgram::getClone(AbstractCommand** state) const
{
    *state = new CommandExecuteProgram(*this);
}

std::string CommandExecuteProgram::getCommandString() const
{
    std::string str;
    str.append("XQ");

    if(this->scriptName != "")
    {
        //this means there is a specific locaiton to start
        str.append(" #");
        str.append(this->scriptName);
    }
    return str;
}
