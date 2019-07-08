#include "request_axis_status.h"

RequestAxisStatus::RequestAxisStatus(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_AXIS,20)
{
    addAxis(axis);
}

RequestAxisStatus::RequestAxisStatus(const RequestAxisStatus &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
}

AbstractRequest* RequestAxisStatus::getClone() const
{
    return (new RequestAxisStatus(*this));
}

void RequestAxisStatus::getClone(AbstractRequest** state) const
{
    *state = new RequestAxisStatus(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestAxisStatus::addAxis(const MotorAxis &axis)
{
    tellAxis.push_back(axis);
    tellAxis.unique();
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> RequestAxisStatus::getAxis() const
{
    return tellAxis;
}

void RequestAxisStatus::setRequestAllAxes(const bool &requestAll)
{
    this->requestAllAxis = requestAll;
}

bool RequestAxisStatus::shouldRequestAllAxes() const
{
    return this->requestAllAxis;
}
