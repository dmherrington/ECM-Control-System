#include "command_motor_enable.h"

CommandMotorEnable::CommandMotorEnable():
    AbstractCommand(CommandType::MOTOR_ON)
{

}

void CommandMotorEnable::setEnableAxis(const MotorAxis &axis)
{
    this->enableAxis = axis;
}

MotorAxis CommandMotorEnable::getEnableAxis()
{
    return this->enableAxis;
}

std::string CommandMotorEnable::getCommandString() const
{
    std::string str = "";
    if(enableAxis == MotorAxis::ALL)
    {
        //for now we are going to throw an exception here as this should create a multi-message
        //or the mask should reflect all layers which I dont know how galil would handle yet
    }
    else
    {
        str.append(CommandToString(this->getCommandType()));
        str.append(" ");
        str.append(AxisToString(enableAxis));
    }
    return str;
}
