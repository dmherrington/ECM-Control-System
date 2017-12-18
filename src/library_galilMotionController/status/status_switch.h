#ifndef STATUS_SWITCH_H
#define STATUS_SWITCH_H

#include <iostream>
#include <stdint.h>
#include <map>

enum SwitchStatus{
    POSLAT = 0,
    HOME_SW = 1,
    RLIMIT = 2,
    FLIMIT = 3,
    RESERVED = 4,
    MOTOR_OFF = 5,
    POSITION_ERROR = 6,
    AXIS_IN_MOTION = 7
};

class Status_Switch
{
public:
    Status_Switch();

    Status_Switch(const Status_Switch &copy);

    void parseResponse(const std::string &str);

    bool getStatus(const SwitchStatus &status);

private:
    void initializeMap();

private:
    std::map<SwitchStatus,bool> mapStatus;
};

#endif // STATUS_SWITCH_H
