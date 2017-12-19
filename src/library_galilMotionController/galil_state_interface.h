#ifndef GALIL_STATE_INTERFACE_H
#define GALIL_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "axis_definitions.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/galil_status.h"

//virtual void cbi_GalilStatusUpdatePosition() = 0;
//virtual void cbi_GalilStatusUpdateSwitches() = 0;
//virtual void cbi_GalilStatusUpdateStopCodes() = 0;


class GalilStateInterface
{
public:
    GalilStateInterface();

    ~GalilStateInterface();

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);

public:
    void transmitMessage(const std::string &msg);

    void transmitMessage(const AbstractCommand* cmd);

    void transmitMessage(const AbstractRequest* req);

public:
    bool isConnected();
    bool isLatched();

    void setConnected(const bool &val);
    void setLatched(const bool &val);
private:
    bool connected = false;
    bool latched = false;

    std::map<MotorAxis, GalilStatus*> mStatus;
};

#endif // GALIL_STATE_INTERFACE_H
