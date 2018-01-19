#include "command_execute_profile.h"

CommandExecuteProfile::CommandExecuteProfile(const std::string &name, const ProgramGeneric &program):
    AbstractCommand(CommandType::EXECUTE_PROGRAM)
{
    this->profileName = name;
    this->executeProgram = program;
}

CommandExecuteProfile::CommandExecuteProfile(const CommandExecuteProfile &copy):
    AbstractCommand(copy)
{
    this->profileName = copy.profileName;
    this->executeProgram = copy.executeProgram;
}

AbstractCommand* CommandExecuteProfile::getClone() const
{
    return (new CommandExecuteProfile(*this));
}

void CommandExecuteProfile::getClone(AbstractCommand** state) const
{
    *state = new CommandExecuteProfile(*this);
}

std::string CommandExecuteProfile::getCommandString() const
{
    std::string str;
    std::string profileLabel = "";

    if(executeProgram.getProfileLabel(this->profileName, profileLabel))
    {
        str.append("XQ");
        //this means there is a specific locaiton to start
        str.append(" #");
        str.append(profileLabel);
    }
    return str;
}
