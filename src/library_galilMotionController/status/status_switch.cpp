#include "status_switch.h"

Status_Switch::Status_Switch():
    AbstractStatus(StatusTypes::STATUS_SWITCH)
{
    this->currentAxis = MotorAxis::Z;
    initializeMap();
}

Status_Switch::Status_Switch(const MotorAxis &axis, const int &code):
    AbstractStatus(StatusTypes::STATUS_SWITCH)
{
    this->setSwitchCode(code); //this will also set the time
    this->setAxis(axis);
}

Status_Switch::Status_Switch(const Status_Switch &copy):
    AbstractStatus(StatusTypes::STATUS_SWITCH)
{
    this->currentAxis = copy.currentAxis;
    this->originalCode = copy.originalCode;
    this->mapStatus = copy.mapStatus;
}

void Status_Switch::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_Switch::setSwitchCode(const int &code)
{
    this->originalCode = code;
    this->parseInt(this->originalCode);
}

MotorAxis Status_Switch::getAxis() const
{
    return this->currentAxis;
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
    mapStatus = {{SwitchStatus::POSLAT,false}, {SwitchStatus::HOME_SW,false}, {SwitchStatus::RLIMIT,false},
                 {SwitchStatus::FLIMIT,false}, {SwitchStatus::RESERVED,false}, {SwitchStatus::MOTOR_OFF,false},
                 {SwitchStatus::POSITION_ERROR,false},{SwitchStatus::AXIS_IN_MOTION,false}};
}

void Status_Switch::parseInt(const uint8_t &value)
{
    unsigned int mask = 1 << (sizeof(uint8_t) * 8 - 1);

    std::map<SwitchStatus,bool>::reverse_iterator it;
    for(it = mapStatus.rbegin(); it!=mapStatus.rend(); ++it)
    {
        if( (value & mask) == 0 )
            mapStatus.at(it->first) = false;
        else
           mapStatus.at(it->first) = true;
        mask  >>= 1;
    }
}
