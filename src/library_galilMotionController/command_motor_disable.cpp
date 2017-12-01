#include "command_motor_disable.h"

CommandMotorDisable::CommandMotorDisable()
{
    this->commandType = CommandType::MOTOR_OFF;
}

void CommandMotorDisable::setDisableAxis(const MotorAxis &axis)
{
    this->disableAxis = axis;
}

MotorAxis CommandMotorDisable::getDisableAxis() const
{
    return this->disableAxis;
}

std::string CommandMotorDisable::getCommandString() const
{
    std::string str = "";
    if(disableAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");
        str.append(AxisToString(disableAxis));
    }
    return str;
}
