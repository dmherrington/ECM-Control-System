#include "status_axis.h"

Statusy::status_axis():
    AbstractStatus(StatusTypes::STATUS_MOTOREN)
{
    this->currentAxis = MotorAxis::Z;
    this->moving = 0;
}

status_axis::status_axis(const status_axis &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->moving = copy.moving;
}

void status_axis::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

MotorAxis status_axis::getAxis() const
{
    return this->currentAxis;
}

void status_axis::setMotorMoving(const bool &moving)
{
    this->moving = moving;
}

bool status_axis::isMotorMoving() const
{
    return this->moving;
}
