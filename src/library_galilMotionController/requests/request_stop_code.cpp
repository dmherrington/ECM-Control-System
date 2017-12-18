#include "request_stop_code.h"

RequestStopCode::RequestStopCode(const MotorAxis &axis):
    AbstractCommand(CommandType::STOP_CODE), stopAxis(axis)
{

}

RequestStopCode::RequestStopCode(const RequestStopCode &copy):
    AbstractCommand(copy)
{

}

AbstractCommand* RequestStopCode::getClone() const
{
    return (new RequestStopCode(*this));
}

void RequestStopCode::getClone(AbstractCommand** state) const
{
    *state = new CommandStop(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestStopCode::setAxis(const MotorAxis &axis)
{
    stopAxis = axis;
}

//!
//! \brief getAxis
//! \return
//!
MotorAxis RequestStopCode::getAxis() const
{
    return stopAxis;
}

std::string RequestStopCode::getCommandString() const
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
        str.append(" ");
        str.append(AxisToString(stopAxis));
    }
    return str;
}
