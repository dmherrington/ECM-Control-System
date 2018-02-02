#ifndef GALIL_STATE_INTERFACE_H
#define GALIL_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "common/data_get_set_notifier.h"

#include "axis_definitions.h"

#include "programs/galil_current_program.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/status_components.h"

class GalilCallback_StateInterface
{
public:
    virtual void cbi_AbstractGalilCommand(const AbstractCommandPtr command) = 0;
    virtual void cbi_AbstractGalilRequest(const AbstractRequestPtr request) = 0;
    virtual void cbi_GalilControllerGains(const CommandControllerGain &gains) = 0;
};

class GalilStateInterface
{
public:
    GalilStateInterface(const std::vector<MotorAxis> &availableAxis);

    ~GalilStateInterface();

public:
    void connectCallback(GalilCallback_StateInterface *cb)
    {
        m_CB = cb;
    }

    void issueGalilCommand(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilCommand(command);
    }
    void issueGalilControllerGains(const CommandControllerGain &gains)
    {
        if(m_CB)
            m_CB->cbi_GalilControllerGains(gains);
    }
public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);

public:
    bool isMotorInMotion() const;
    bool isMotorEnabled() const;
    bool isEStopEngaged() const;

private:
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

private:
    GalilCallback_StateInterface *m_CB;

public:
    DataGetSetNotifier<StatusInputs> statusInputs; /**< Member variable containing the current state
inputs of the Galil Unit. Inputs can be gathered based on the enum settings contained within the file.
Eventually this should change to be pulled from a configuraiton.*/

private:
    std::map<MotorAxis, GalilStatus*> mStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */

    GalilCurrentProgram* galilProgram; /**< Member variable containing the current program, labels,
and variables actually aboard the galil. This can be used as a comparison for determining if the
current program matches what the user witnesses. Also, this can be used to restore the current state
of the program.*/

};

#endif // GALIL_STATE_INTERFACE_H
