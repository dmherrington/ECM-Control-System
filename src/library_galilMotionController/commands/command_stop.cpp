#include "command_stop.h"

CommandStop::CommandStop(const MotorAxis &axis):
    stopAxis(axis)
{

}

//!
//! \brief setAxis
//! \param axis
//!
void CommandStop::setAxis(const MotorAxis &axis)
{
    stopAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis CommandStop::getAxis() const
{
    return stopAxis;
}

std::string CommandStop::getCommandString() const
{
    std::string str = "";
    if(stopAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append("");
        str.append(AxisToString(stopAxis));
    }
    return str;
}
