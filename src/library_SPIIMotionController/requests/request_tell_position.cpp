#include "request_tell_position.h"

RequestTellPosition::RequestTellPosition():
    AbstractRequest(RequestTypes::TELL_POSITION,20)
{

}

RequestTellPosition::RequestTellPosition(const RequestTellPosition &copy):
    AbstractRequest(copy)
{
    this->requestAllAxis = copy.requestAllAxis;
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
    requestAllAxis = false;
}

//!
//! \brief getAxis
//! \return
//!
std::list<MotorAxis> RequestTellPosition::getAxis() const
{
    return tellAxis;
}

void RequestTellPosition::setRequestAllAxes(const bool &requestAll)
{
    this->requestAllAxis = requestAll;
}

bool RequestTellPosition::shouldRequestAllAxes() const
{
    return this->requestAllAxis;
}

