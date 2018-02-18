#include "abstract_rigol_status.h"

namespace rigol {
namespace commands {


AbstractRigolStatus::AbstractRigolStatus(const CommandTypes &type):
    commandType(type)
{
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
}

AbstractRigolStatus::AbstractRigolStatus(const AbstractRigolStatus &copy)
{
    this->commandType = copy.commandType;
    this->latestUpdate = copy.latestUpdate;
}

void AbstractRigolStatus::setCommandType(const CommandTypes &type)
{
    this->commandType = type;
}

CommandTypes AbstractRigolStatus::getCommandType() const
{
    return this->commandType;
}

void AbstractRigolStatus::setTime(const Data::EnvironmentTime &time)
{
    this->latestUpdate = time;
}

Data::EnvironmentTime AbstractRigolStatus::getTime() const
{
    return this->latestUpdate;
}

} //end of namespace commands
} //end of namespace rigol
