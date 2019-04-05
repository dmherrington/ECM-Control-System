#include "request_motor_status.h"

RequestMotorStatus::RequestMotorStatus(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_MOTOR,20)
{
    addAxis(axis);
}

RequestMotorStatus::RequestMotorStatus(const RequestMotorStatus &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
}

AbstractRequest* RequestMotorStatus::getClone() const
{
    return (new RequestMotorStatus(*this));
}

void RequestMotorStatus::getClone(AbstractRequest** state) const
{
    *state = new RequestMotorStatus(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestMotorStatus::addAxis(const MotorAxis &axis)
{
    tellAxis.push_back(axis);
    tellAxis.unique();
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> RequestMotorStatus::getAxis() const
{
    return tellAxis;
}

void RequestMotorStatus::setRequestAllAxes(const bool &requestAll)
{
    this->requestAllAxis = requestAll;
}

bool RequestMotorStatus::shouldRequestAllAxes() const
{
    return this->requestAllAxis;
}
