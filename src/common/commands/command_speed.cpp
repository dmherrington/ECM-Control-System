#include "command_speed.h"

CommandSpeed::CommandSpeed():
    AbstractCommand(CommandType::SPEED)
{
    axisSpeed[MotorAxis::X] = 0.0;
    axisSpeed[MotorAxis::Y] = 0.0;
    axisSpeed[MotorAxis::Z] = 0.0;
}

CommandSpeed::CommandSpeed(const MotorAxis &axis, const unsigned int &speed):
    AbstractCommand(CommandType::SPEED)
{
    this->setAxisSpeed(axis, speed);
}

CommandSpeed::CommandSpeed(const CommandSpeed &copy):
    AbstractCommand(copy)
{
    this->axisSpeed = copy.axisSpeed;
}

AbstractCommand* CommandSpeed::getClone() const
{
    return (new CommandSpeed(*this));
}

void CommandSpeed::getClone(AbstractCommand** state) const
{
    *state = new CommandSpeed(*this);
}

void CommandSpeed::setAxisSpeed(const MotorAxis &axis, const unsigned int &speed)
{
    if(axis == MotorAxis::ALL)
    {
        axisSpeed[MotorAxis::X] = speed;
        axisSpeed[MotorAxis::Y] = speed;
        axisSpeed[MotorAxis::Z] = speed;
    }
    else
    {
        axisSpeed[axis] = speed;
    }
}

std::map<MotorAxis, unsigned int> CommandSpeed::getAxisSpeedMap() const
{
    return this->axisSpeed;
}

std::string CommandSpeed::getCommandString() const
{
    std::string str = "";

    //Ken Fix: For now we know there is only going to exist one axis in motion

    str.append(CommandToString(this->getCommandType()));
    str.append("");
    str.append(AxisToString(MotorAxis::Z));
    str.append("=");
    str.append(std::to_string(axisSpeed.at(MotorAxis::Z) * 10));

    return str;
}
