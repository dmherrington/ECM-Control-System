#include "request_motor_status.h"

RequestMotorStatus::RequestMotorStatus(const MotorAxis &axis):
    AbstractAxisRequest(RequestTypes::TELL_MOTOR, axis, 20)
{

}

RequestMotorStatus::RequestMotorStatus(const RequestMotorStatus &copy):
    AbstractAxisRequest(copy)
{

}

AbstractRequest* RequestMotorStatus::getClone() const
{
    return (new RequestMotorStatus(*this));
}

void RequestMotorStatus::getClone(AbstractRequest** state) const
{
    *state = new RequestMotorStatus(*this);
}
