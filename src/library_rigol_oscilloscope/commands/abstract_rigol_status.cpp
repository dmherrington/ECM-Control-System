#include "abstract_rigol_status.h"

namespace rigol {
namespace commands {


AbstractRigolStatus::AbstractRigolStatus(const CommandTypes &type):
    commandType(type)
{
    this->requestTime.CurrentTime(Devices::SYSTEMCLOCK,this->requestTime);
}

AbstractRigolStatus::AbstractRigolStatus(const AbstractRigolStatus &copy)
{
    this->commandType = copy.commandType;
    this->receivedTime = copy.receivedTime;
    this->requestTime = copy.requestTime;
}

void AbstractRigolStatus::setCommandType(const CommandTypes &type)
{
    this->commandType = type;
}

CommandTypes AbstractRigolStatus::getCommandType() const
{
    return this->commandType;
}

void AbstractRigolStatus::updateReceivedTime()
{
    this->receivedTime.CurrentTime(Devices::SYSTEMCLOCK,this->receivedTime);
}

EnvironmentTime AbstractRigolStatus::getReceivedTime() const
{
    return this->receivedTime;
}

EnvironmentTime AbstractRigolStatus::getRequestTime() const
{
    return this->requestTime;
}

} //end of namespace commands
} //end of namespace rigol
