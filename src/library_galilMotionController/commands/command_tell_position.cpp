#include "command_tell_position.h"

CommandTellPosition::CommandTellPosition(const MotorAxis &axis):
    AbstractCommand(CommandType::TELL_POSITION), tellAxis(axis)
{

}

CommandTellPosition::CommandTellPosition(const CommandTellPosition &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* CommandTellPosition::getClone() const
{
    return (new CommandTellPosition(*this));
}

void CommandTellPosition::getClone(AbstractCommand** state) const
{
    *state = new CommandTellPosition(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void CommandTellPosition::setAxis(const MotorAxis &axis)
{
    tellAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis CommandTellPosition::getAxis() const
{
    return tellAxis;
}

std::string CommandTellPosition::getCommandString() const
{
    std::string str = "";
    if(tellAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append("");
        str.append(AxisToString(tellAxis));
    }
    return str;
}
