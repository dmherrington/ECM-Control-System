#include "request_motor_fault.h"

Request_MotorFault::Request_MotorFault(const MotorAxis &axis):
    AbstractAxisRequest(RequestTypes::TELL_MOTOR_FAULTS, axis, 500)
{

}

Request_MotorFault::Request_MotorFault(const Request_MotorFault &copy):
    AbstractAxisRequest(copy)
{

}

AbstractRequest* Request_MotorFault::getClone() const
{
    return (new Request_MotorFault(*this));
}

void Request_MotorFault::getClone(AbstractRequest** state) const
{
    *state = new Request_MotorFault(*this);
}
