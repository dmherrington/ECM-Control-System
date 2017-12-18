#include "status_switch.h"

Status_Switch::Status_Switch()
{
    initializeMap();
}

Status_Switch::Status_Switch(const Status_Switch &copy)
{
    this->mapStatus = copy.mapStatus;
}

void Status_Switch::initializeMap()
{
    mapStatus = {{POSLAT,false}, {HOME_SW,false}, {RLIMIT,false},
                 {FLIMIT,false}, {RESERVED,false}, {MOTOR_OFF,false},
                 {POSITION_ERROR,false},{AXIS_IN_MOTION,false}};
}

bool Status_Switch::getStatus(const SwitchStatus &status)
{
    if(mapStatus.count(status) > 0)
        return mapStatus.at(status);
    return false;
}

void Status_Switch::parseResponse(const std::string &str)
{
    uint8_t value = std::stoi(str);
    std::map<SwitchStatus,bool>::iterator it;
    int i = 0;
    for(it = mapStatus.begin(); it!=mapStatus.end(); ++it)
    {
        ++i;
        mapStatus.at(it->first) = (value >> i) & 1;
    }
}
