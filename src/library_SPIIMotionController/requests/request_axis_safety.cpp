#include "request_axis_safety.h"

Request_AxisSafety::Request_AxisSafety(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_AXIS_SAFETY,500)
{
    addAxis(axis);
}

Request_AxisSafety::Request_AxisSafety(const Request_AxisSafety &copy):
    AbstractRequest(copy)
{
    this->requestAllAxis = copy.requestAllAxis;
    this->tellAxis = copy.tellAxis;
}

AbstractRequest* Request_AxisSafety::getClone() const
{
    return (new Request_AxisSafety(*this));
}

void Request_AxisSafety::getClone(AbstractRequest** state) const
{
    *state = new Request_AxisSafety(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void Request_AxisSafety::addAxis(const MotorAxis &axis)
{
    tellAxis.push_back(axis);
    tellAxis.unique();
    requestAllAxis = false;
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> Request_AxisSafety::getAxis() const
{
    return tellAxis;
}

void Request_AxisSafety::setRequestAllAxes(const bool &requestAll)
{
    this->requestAllAxis = requestAll;
}

bool Request_AxisSafety::shouldRequestAllAxes() const
{
    return this->requestAllAxis;
}

