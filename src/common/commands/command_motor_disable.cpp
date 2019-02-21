#include "command_motor_disable.h"

CommandMotorDisable::CommandMotorDisable():
    AbstractCommand(CommandType::MOTOR_OFF)
{

}

CommandMotorDisable::CommandMotorDisable(const CommandMotorDisable &copy):
    AbstractCommand(copy.getCommandType())
{

}

AbstractCommand* CommandMotorDisable::getClone() const
{
    return (new CommandMotorDisable(*this));
}

void CommandMotorDisable::getClone(AbstractCommand** state) const
{
    *state = new CommandMotorDisable(*this);
}

void CommandMotorDisable::addAxis(const MotorAxis &axis)
{
    std::pair<std::map<MotorAxis,DisableValue>::iterator,bool> ret;
    ret = m_AxisValue.insert ( std::pair<MotorAxis,DisableValue>(axis,DisableValue::CHANGE));
    //the element already exists
    if (ret.second==false) {
        m_AxisValue.at(axis) = DisableValue::CHANGE;
    }
}

std::map<MotorAxis, CommandMotorDisable::DisableValue> CommandMotorDisable::getDisableAxis() const
{
    return this->m_AxisValue;
}
