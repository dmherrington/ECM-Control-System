#include "request_tell_position.h"

RequestTellPosition::RequestTellPosition(const MotorAxis &axis):
    AbstractRequest(RequestTypes::TELL_POSITION,20)
{
    addAxis(axis);
}

RequestTellPosition::RequestTellPosition(const RequestTellPosition &copy):
    AbstractRequest(copy)
{
    this->tellAxis = copy.tellAxis;
}

AbstractRequest* RequestTellPosition::getClone() const
{
    return (new RequestTellPosition(*this));
}

void RequestTellPosition::getClone(AbstractRequest** state) const
{
    *state = new RequestTellPosition(*this);
}

//!
//! \brief setAxis
//! \param axis
//!
void RequestTellPosition::addAxis(const MotorAxis &axis)
{
    tellAxis.push_back(axis);
    tellAxis.unique();
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> RequestTellPosition::getAxis() const
{
    return tellAxis;
}

