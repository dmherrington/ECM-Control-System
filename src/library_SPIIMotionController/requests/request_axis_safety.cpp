#include "request_axis_safety.h"

Request_AxisSafety::Request_AxisSafety(const MotorAxis &axis):
    AbstractAxisRequest(RequestTypes::TELL_AXIS_SAFETY, axis, 500)
{

}

Request_AxisSafety::Request_AxisSafety(const Request_AxisSafety &copy):
    AbstractAxisRequest(copy)
{

}

AbstractRequest* Request_AxisSafety::getClone() const
{
    return (new Request_AxisSafety(*this));
}

void Request_AxisSafety::getClone(AbstractRequest** state) const
{
    *state = new Request_AxisSafety(*this);
}
