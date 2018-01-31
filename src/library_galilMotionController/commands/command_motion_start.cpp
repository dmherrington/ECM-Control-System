#include "command_motion_start.h"

CommandMotionStart::CommandMotionStart(const MotorAxis &axis):
    AbstractCommand(CommandType::MOTION_START), startAxis(axis)
{

}

CommandMotionStart::CommandMotionStart(const CommandMotionStart &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandMotionStart::getClone() const
{
    return (new CommandMotionStart(*this));
}

void CommandMotionStart::getClone(AbstractCommand** state) const
{
    *state = new CommandMotionStart(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void CommandMotionStart::setAxis(const MotorAxis &axis)
{
    startAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis CommandMotionStart::getAxis() const
{
    return startAxis;
}

std::string CommandMotionStart::getCommandString() const
{
    std::string str = "";
    if(startAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");
        str.append(AxisToString(startAxis));
    }
    return str;
}
