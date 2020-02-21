#include "command_motor_enable.h"

CommandMotorEnable::CommandMotorEnable():
    AbstractCommand(CommandType::MOTOR_ON)
{

}

CommandMotorEnable::CommandMotorEnable(const CommandMotorEnable &copy):
    AbstractCommand(copy.getCommandType())
{
    this->m_AxisValue = copy.m_AxisValue;
}

AbstractCommand* CommandMotorEnable::getClone() const
{
    return (new CommandMotorEnable(*this));
}

void CommandMotorEnable::getClone(AbstractCommand** state) const
{
    *state = new CommandMotorEnable(*this);
}

void CommandMotorEnable::addAxis(const MotorAxis &axis)
{
    std::pair<std::map<MotorAxis,EnableValue>::iterator,bool> ret;
    ret = m_AxisValue.insert ( std::pair<MotorAxis,EnableValue>(axis,EnableValue::CHANGE));
    //the element already exists
    if (ret.second==false) {
        m_AxisValue.at(axis) = EnableValue::CHANGE;
    }
}

void CommandMotorEnable::addAxes(const std::vector<MotorAxis> &axes)
{
    for(size_t index = 0; index < axes.size(); index++)
    {
        addAxis(axes.at(index));
    }
}

std::map<MotorAxis,CommandMotorEnable::EnableValue> CommandMotorEnable::getEnableAction() const
{
    return this->m_AxisValue;
}

