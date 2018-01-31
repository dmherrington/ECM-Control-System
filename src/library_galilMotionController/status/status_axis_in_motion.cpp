#include "status_axis_in_motion.h"

Status_AxisInMotion::Status_AxisInMotion():
    AbstractStatus(StatusTypes::STATUS_MOTOREN)
{
    this->currentAxis = MotorAxis::Z;
    this->moving = 0;
}

Status_AxisInMotion::Status_AxisInMotion(const Status_AxisInMotion &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->moving = copy.moving;
}

void Status_AxisInMotion::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis Status_AxisInMotion::getAxis() const
{
    return this->currentAxis;
}

void Status_AxisInMotion::setMotorMoving(const bool &moving)
{
    this->moving = moving;
}

bool Status_AxisInMotion::isMotorMoving() const
{
    return this->moving;
}
