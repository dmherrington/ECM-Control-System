#ifndef GALIL_STATE_INTERFACE_H
#define GALIL_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "gclib.h"
#include "gclibo.h"

#include "common/data_get_set_notifier.h"
#include "data/motion_profile_state.h"

#include "common/axis_definitions.h"

#include "programs/galil_current_program.h"
#include "programs/program_variable_value_list.h"

#include "commands/command_components.h"
#include "requests/request_components.h"
#include "status/status_components.h"

class GalilCallback_StateInterface
{
public:
    virtual void cbi_AbstractGalilCommand(const AbstractCommandPtr command) = 0;
    virtual void cbi_AbstractGalilMotionCommand(const AbstractCommandPtr command) = 0;
    virtual void cbi_AbstractGalilRequest(const AbstractRequestPtr request) = 0;
    virtual void cbi_AbstractGalilAddPolled(const AbstractRequestPtr request, const int &period) = 0;
    virtual void cbi_AbstractGalilRemovePolled(const common::TupleECMData &tuple) = 0;
    virtual void cbi_GalilControllerGains(const CommandControllerGain &gains) = 0;
    virtual void cbi_GalilHomeIndicated(const bool &indicated) = 0;
    virtual void cbi_NewMotionProfileState(const MotionProfileState &state) = 0;
    virtual void cbi_GalilNewMachineState(const std::string &state) = 0;
    virtual void cbi_GalilUploadProgram(const AbstractCommandPtr command) = 0;
    virtual void cbi_GalilDownloadProgram(const AbstractCommandPtr command) = 0;
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

    void issueGalilUploadProgram(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_GalilUploadProgram(command);
    }

    void issueGalilDownloadProgram(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_GalilDownloadProgram(command);
    }

    void issueNewGalilState(const std::string &state)
    {
        if(m_CB)
            m_CB->cbi_GalilNewMachineState(state);
    }

    void issueGalilCommand(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilCommand(command);
    }

    void issueGalilRequest(const AbstractRequestPtr request)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilRequest(request);
    }

    void issueGalilMotionCommand(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilMotionCommand(command);
    }

    void issueGalilControllerGains(const CommandControllerGain &gains)
    {
        if(m_CB)
            m_CB->cbi_GalilControllerGains(gains);
    }

    void issueGalilAddPollingRequest(const AbstractRequestPtr request, const int &period = 1000)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilAddPolled(request, period);
    }

    void issueGalilRemovePollingRequest(const common::TupleECMData &tuple)
    {
        if(m_CB)
            m_CB->cbi_AbstractGalilRemovePolled(tuple);
    }

    void issueUpdatedMotionProfileState(const MotionProfileState &state)
    {
        if(m_CB)
            m_CB->cbi_NewMotionProfileState(state);
    }

public:
    GalilStatus* getAxisStatus(const MotorAxis &axis);

public:
    bool isMotorInMotion() const;
    bool isMotorEnabled() const;
    bool isEStopEngaged() const;

public:
    bool isConnected() const;
    bool isHomeInidcated() const;

public:
    void setConnected(const bool &val);
    void setHomeInidcated(const bool &val);

private:
    bool connected = false;
    bool indicatedHome = false;

private:
    GalilCallback_StateInterface *m_CB;

public:
    DataGetSetNotifier<StatusInputs> statusInputs; /**< Member variable containing the current state
inputs of the Galil Unit. Inputs can be gathered based on the enum settings contained within the file.
Eventually this should change to be pulled from a configuraiton.*/

    ProgramVariableValueList* statusVariableValues;/**< Member variable containing the current list of variables
based on the program that is currently on the Galil Unit. Values of this may be updated per the
the request of the polling status function.*/

    GalilCurrentProgram* galilProgram; /**< Member variable containing the current program, labels,
and variables actually aboard the galil. This can be used as a comparison for determining if the
current program matches what the user witnesses. Also, this can be used to restore the current state
of the program.*/

private:
    std::map<MotorAxis, GalilStatus*> mStatus; /**< Member variable containing the current status
of each individual axis of the galil. This information contains positioning, motion, arming. */



};

#endif // GALIL_STATE_INTERFACE_H
