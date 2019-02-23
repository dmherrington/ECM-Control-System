#include "command_stop.h"

CommandStop::CommandStop(const MotorAxis &axis):
    AbstractCommand(CommandType::STOP)
{

}

CommandStop::CommandStop(const CommandStop &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandStop::getClone() const
{
    return (new CommandStop(*this));
}

void CommandStop::getClone(AbstractCommand** state) const
{
    *state = new CommandStop(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void CommandStop::setAxis(const MotorAxis &axis)
{

}

bool CommandStop::shouldStopAllMotion() const
{
    return this->stopAll;
}

std::map<MotorAxis,bool> CommandStop::getStopAction() const
{
    return this->stopAxis;
}

std::string CommandStop::getCommandString() const
{

}
