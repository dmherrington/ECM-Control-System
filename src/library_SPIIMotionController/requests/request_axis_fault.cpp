#include "request_motor_fault.h"

Request_MotorFault::Request_MotorFault(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_MOTOR_FAULTS,500)
{
    addAxis(axis);
}

Request_MotorFault::Request_MotorFault(const Request_MotorFault &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
}

AbstractRequest* Request_MotorFault::getClone() const
{
    return (new Request_MotorFault(*this));
}

void Request_MotorFault::getClone(AbstractRequest** state) const
{
    *state = new Request_MotorFault(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void Request_MotorFault::addAxis(const MotorAxis &axis)
{
    tellAxis.push_back(axis);
    tellAxis.sort();
    tellAxis.unique();
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> Request_MotorFault::getAxis() const
{
    return tellAxis;
}

void Request_MotorFault::setRequestAllAxes(const bool &requestAll)
{
    this->requestAllAxis = requestAll;
}

bool Request_MotorFault::shouldRequestAllAxes() const
{
    return this->requestAllAxis;
}
