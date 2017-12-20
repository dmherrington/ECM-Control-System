#include "status_switch.h"

Status_Switch::Status_Switch():
    currentAxis(MotorAxis::Z), originalCode(0)
{
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
    initializeMap();
}

Status_Switch::Status_Switch(const MotorAxis &axis, const int &code)
{
    this->setSwitchCode(code); //this will also set the time
    this->setAxis(axis);
}

Status_Switch::Status_Switch(const MotorAxis &axis, const Data::EnvironmentTime &time, const int &code)
{
    this->currentAxis = axis;
    this->latestUpdate = time;
    this->originalCode = code;
    this->parseInt(this->originalCode);
}

Status_Switch::Status_Switch(const Status_Switch &copy)
{
    this->currentAxis = copy.currentAxis;
    this->originalCode = copy.originalCode;
    this->mapStatus = copy.mapStatus;
    this->latestUpdate = copy.latestUpdate;
}

void Status_Switch::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_Switch::setSwitchCode(const int &code)
{
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
    this->originalCode = code;
    this->parseInt(this->originalCode);
}

void Status_Switch::setTime(const Data::EnvironmentTime &time)
{
    this->latestUpdate = time;
}

MotorAxis Status_Switch::getAxis() const
{
    return this->currentAxis;
}

Data::EnvironmentTime Status_Switch::getTime() const
{
    return this->latestUpdate;
}

int Status_Switch::getCode() const
{
    return this->originalCode;
}

bool Status_Switch::getSwitchStatus(const SwitchStatus &status) const
{
    if(mapStatus.count(status) > 0)
        return mapStatus.at(status);
    return false;
}

void Status_Switch::initializeMap()
{
    mapStatus = {{POSLAT,false}, {HOME_SW,false}, {RLIMIT,false},
                 {FLIMIT,false}, {RESERVED,false}, {MOTOR_OFF,false},
                 {POSITION_ERROR,false},{AXIS_IN_MOTION,false}};
}

void Status_Switch::parseInt(const uint8_t &value)
{
    std::map<SwitchStatus,bool>::iterator it;
    int i = 0;
    for(it = mapStatus.begin(); it!=mapStatus.end(); ++it)
    {
        ++i;
        mapStatus.at(it->first) = (value >> i) & 1;
    }
}
