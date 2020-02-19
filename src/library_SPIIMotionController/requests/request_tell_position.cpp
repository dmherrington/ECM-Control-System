#include "request_tell_position.h"

RequestTellPosition::RequestTellPosition(const MotorAxis &axis):
    AbstractAxisRequest(RequestTypes::TELL_POSITION, axis, 20)
{

}

RequestTellPosition::RequestTellPosition(const RequestTellPosition &copy):
    AbstractAxisRequest(copy)
{

}

AbstractRequest* RequestTellPosition::getClone() const
{
    return (new RequestTellPosition(*this));
}

void RequestTellPosition::getClone(AbstractRequest** state) const
{
    *state = new RequestTellPosition(*this);
}

