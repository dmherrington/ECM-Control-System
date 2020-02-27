#include "command_execute_touchoff.h"

CommandExecuteTouchoff::CommandExecuteTouchoff(const MotionProfile::ProfileType &type, const std::string &name, const MotorAxis &axis):
    CommandExecuteProfile(type, name)
{

}

CommandExecuteTouchoff::CommandExecuteTouchoff(const CommandExecuteTouchoff &copy):
    CommandExecuteProfile(copy)
{
    this->executeOnAxis = copy.executeOnAxis;
}

AbstractCommand* CommandExecuteTouchoff::getClone() const
{
    return (new CommandExecuteProfile(*this));
}

void CommandExecuteTouchoff::getClone(AbstractCommand** state) const
{
    *state = new CommandExecuteProfile(*this);
}

void CommandExecuteTouchoff::setExecutionAxis(const MotorAxis &axis)
{
    executeOnAxis = axis;
}

MotorAxis CommandExecuteTouchoff::getExecutionAxis() const
{
    return executeOnAxis;
}
