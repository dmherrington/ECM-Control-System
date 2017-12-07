#include "command_execute_program.h"

CommandExecuteProgram::CommandExecuteProgram():
    AbstractCommand(CommandType::EXECUTE_PROGRAM)
{

}

void CommandExecuteProgram::setScript(const std::string &name)
{
    this->scriptName = name;
}

std::string CommandExecuteProgram::getScriptName() const
{
    return this->scriptName;
}

void CommandExecuteProgram::clearScriptName()
{
    this->scriptName = "";
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
