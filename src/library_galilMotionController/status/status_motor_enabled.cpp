#include "status_motor_enabled.h"

Status_MotorEnabled::Status_MotorEnabled():
    AbstractStatus(StatusTypes::STATUS_MOTOREN)
{
    this->currentAxis = MotorAxis::Z;
    this->isEnabled = false;
}

Status_MotorEnabled::Status_MotorEnabled(const Status_MotorEnabled &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->isEnabled = copy.isEnabled;
}

void Status_MotorEnabled::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis Status_MotorEnabled::getAxis() const
{
    return this->currentAxis;
}

void Status_MotorEnabled::setMotorEnabled(const bool &enabled)
{
    this->isEnabled = enabled;
}

bool Status_MotorEnabled::isMotorEnabled() const
{
    return this->isEnabled;
}
