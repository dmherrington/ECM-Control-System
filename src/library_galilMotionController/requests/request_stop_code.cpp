#include "request_stop_code.h"

RequestStopCode::RequestStopCode(const MotorAxis &axis):
    AbstractRequest(RequestTypes::STOP_CODE), stopAxis(axis)
{

}

RequestStopCode::RequestStopCode(const RequestStopCode &copy):
    AbstractRequest(copy)
{

}

AbstractRequest* RequestStopCode::getClone() const
{
    return (new RequestStopCode(*this));
}

void RequestStopCode::getClone(AbstractRequest** state) const
{
    *state = new RequestStopCode(*this);
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

std::string RequestStopCode::getRequestString() const
{
    std::string str = "";
    return str;
}
