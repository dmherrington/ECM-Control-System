#include "command_motion_start.h"

CommandMotionStart::CommandMotionStart(const MotorAxis &axis):
    AbstractCommand(CommandType::MOTION_START)
{
    addAxis(axis);
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
void CommandMotionStart::addAxis(const MotorAxis &axis)
{
    std::pair<std::map<MotorAxis,MotionValue>::iterator,bool> ret;
    ret = m_AxisValue.insert ( std::pair<MotorAxis,MotionValue>(axis,MotionValue::CHANGE));
    //the element already exists
    if (ret.second==false) {
        m_AxisValue.at(axis) = MotionValue::CHANGE;
    }
}

//!
//! \brief getAxis
//! \return
//!
std::map<MotorAxis,CommandMotionStart::MotionValue> CommandMotionStart::getAxis() const
{
    return m_AxisValue;
}

