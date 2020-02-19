#include "request_axis_status.h"

RequestAxisStatus::RequestAxisStatus(const MotorAxis &axis):
    AbstractAxisRequest(RequestTypes::TELL_AXIS, axis, 20)
{

}

RequestAxisStatus::RequestAxisStatus(const RequestAxisStatus &copy):
    AbstractAxisRequest(copy)
{

}

AbstractRequest* RequestAxisStatus::getClone() const
{
    return (new RequestAxisStatus(*this));
}

void RequestAxisStatus::getClone(AbstractRequest** state) const
{
    *state = new RequestAxisStatus(*this);
}
