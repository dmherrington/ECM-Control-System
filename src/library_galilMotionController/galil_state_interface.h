#ifndef GALIL_STATE_INTERFACE_H
#define GALIL_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "axis_definitions.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/status_components.h"


class GalilStateInterface
{
public:
    GalilStateInterface(const std::vector<MotorAxis> &availableAxis);

    ~GalilStateInterface();

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);
    StatusInputs* getStatusInputs() const;

public:
    void transmitMessage(const std::string &msg);

    void transmitMessage(const AbstractCommand* cmd);

    void transmitMessage(const AbstractRequest* req);

public:
    void updatePosition(const std::vector<Status_Position> &data);

public:
    bool isConnected();
    bool isLatched();

public:
    void setConnected(const bool &val);
    void setLatched(const bool &val);
private:
    bool connected = false;
    bool latched = false;

    StatusInputs* statusInputs; /**< Member variable containing the current state
inputs of the Galil Unit. Only specific inputs are relevant within the request. Relevant
inputs are established through the settings file.*/

    std::vector<std::string> currentLabels;
    std::vector<std::string> currentVariables;

    std::map<MotorAxis, GalilStatus*> mStatus;
};

#endif // GALIL_STATE_INTERFACE_H
