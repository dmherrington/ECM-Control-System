#ifndef GALIL_INTERFACE_H
#define GALIL_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "axis_definitions.h"
#include "galil_poll_status.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/galil_status.h"
#include "states/hsm.h"


class GalilInterface : public GalilPolling_Interface
{
public:
    GalilInterface();

    ~GalilInterface();

public:
    void cbi_GalilStatusUpdatePosition() override;
    void cbi_GalilStatusUpdateSwitches() override;
    void cbi_GalilStatusUpdateStopCodes() override;

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);

public:
    void transmitMessage(const std::string &msg);

    void transmitMessage(const AbstractCommand* cmd);

    void transmitMessage(const AbstractRequest* req);

public:
    GCon galil;

    hsm::StateMachine* stateMachine;

    GalilPollState* galilPolling;
    std::map<MotorAxis, GalilStatus*> mStatus;
};

#endif // GALIL_INTERFACE_H
