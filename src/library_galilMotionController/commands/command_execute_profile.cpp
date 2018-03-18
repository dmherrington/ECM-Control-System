#include "command_execute_profile.h"

CommandExecuteProfile::CommandExecuteProfile(const ProfileType &type, const std::string &name):
    AbstractCommand(CommandType::EXECUTE_PROGRAM)
{
    this->profileType = type;
    this->profileName = name;
}

CommandExecuteProfile::CommandExecuteProfile(const CommandExecuteProfile &copy):
    AbstractCommand(copy)
{
    this->profileType = copy.profileType;
    this->profileName = copy.profileName;
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

    str.append("XQ");
    //this means there is a specific locaiton to start
    str.append(" #");
    str.append(profileName);

    return str;
}

//!
//! \brief getProfileLabel
//! \return
//!
ProfileType CommandExecuteProfile::getProfileType() const
{
    return this->profileType;
}

//!
//! \brief getProfileLabel
//! \return
//!
std::string CommandExecuteProfile::getProfileName() const
{
    return this->profileName;
}
