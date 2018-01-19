#include "status_stop_code.h"

Status_StopCode::Status_StopCode():
    AbstractStatus(StatusTypes::STATUS_STOPCODE)
{

}

Status_StopCode::Status_StopCode(const MotorAxis &axis, const int &code):
    AbstractStatus(StatusTypes::STATUS_STOPCODE)
{
    this->setStopCode(code); //this will also set the time
    this->setAxis(axis);
}

Status_StopCode::Status_StopCode(const Status_StopCode &copy):
    AbstractStatus(StatusTypes::STATUS_STOPCODE)
{
    this->currentAxis = copy.currentAxis;
    this->stopCode = copy.stopCode;
}

void Status_StopCode::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_StopCode::setStopCode(const int &code)
{
    this->stopCode = code;
}

MotorAxis Status_StopCode::getAxis() const
{
    return this->currentAxis;
}
int Status_StopCode::getCode() const
{
    return this->stopCode;
}
