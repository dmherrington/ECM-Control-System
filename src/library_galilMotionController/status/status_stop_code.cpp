#include "status_stop_code.h"

Status_StopCode::Status_StopCode():
    currentAxis(MotorAxis::Z), stopCode(0)
{
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
}

Status_StopCode::Status_StopCode(const MotorAxis &axis, const int &code)
{
    this->setStopCode(code); //this will also set the time
    this->setAxis(axis);
}

Status_StopCode::Status_StopCode(const MotorAxis &axis, const Data::EnvironmentTime &time, const int &code)
{
    this->currentAxis = axis;
    this->latestUpdate = time;
    this->stopCode = code;
}

Status_StopCode::Status_StopCode(const Status_StopCode &copy)
{
    this->currentAxis = copy.currentAxis;
    this->latestUpdate = copy.latestUpdate;
    this->stopCode = copy.stopCode;
}

void Status_StopCode::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_StopCode::setStopCode(const int &code)
{
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
    this->stopCode = code;
}

void Status_StopCode::setTime(const Data::EnvironmentTime &time)
{
    this->latestUpdate = time;
}

MotorAxis Status_StopCode::getAxis() const
{
    return this->currentAxis;
}

Data::EnvironmentTime Status_StopCode::getTime() const
{
    return this->latestUpdate;
}

int Status_StopCode::getCode() const
{
    return this->stopCode;
}
