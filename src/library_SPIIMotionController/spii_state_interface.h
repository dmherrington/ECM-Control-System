#ifndef SPII_STATE_INTERFACE_H
#define SPII_STATE_INTERFACE_H

#include <iostream>
#include <map>

#include "ACSC.h"

#include "states/state_types.h"

#include "common/data_get_set_notifier.h"
#include "data/motion_profile_state.h"

#include "common/axis_definitions.h"
#include "common/commands/abstract_command.h"
#include "common/notification_update.h"
#include "common/commands/command_components.h"
#include "requests/request_components.h"
#include "status/status_components.h"

#include "buffers/spii_current_program.h"
#include "buffers/buffer_variable_values.h"

#include "data/profiles/profile_state_homing.h"

class SPIICallback_StateInterface
{

public:
    virtual ~SPIICallback_StateInterface() = default;

public:
    virtual void cbi_AbstractSPIICommand(const AbstractCommandPtr command) = 0;
    virtual void cbi_AbstractSPIIMotionCommand(const AbstractCommandPtr command) = 0;
    virtual void cbi_AbstractSPIIRequest(const AbstractRequestPtr request) = 0;
    virtual void cbi_AbstractSPIIAddPolled(const AbstractRequestPtr request, const int &period) = 0;
    virtual void cbi_AbstractSPIIRemovePolled(const common::TupleECMData &tuple) = 0;
    virtual void cbi_SPIIControllerGains(const CommandControllerGain &gains) = 0;

    virtual void cbi_SPIIHomeIndicated(const bool &indicated) = 0;
    virtual void cbi_SPIITouchoffIndicated(const bool &indicated) = 0;
    virtual void cbi_SPIIMotionProfileState(const MotionProfileState &state, const bool &processTransitions) = 0;
    virtual void cbi_SPIINewMachineState(const ECM::SPII::SPIIState &state) = 0;
    virtual void cbi_SPIINotificationUpdate(const common::NotificationUpdate &update) = 0;
    virtual void cbi_SPIIUploadProgram(const AbstractCommandPtr command) = 0;
    virtual void cbi_SPIIDownloadProgram(const AbstractCommandPtr command) = 0;
};

class SPIIStateInterface
{
public:
    SPIIStateInterface(const std::vector<MotorAxis> &availableAxes);

    ~SPIIStateInterface();

public:
    void updateAvailableAxes(const std::vector<MotorAxis> &availableAxes);

    std::vector<MotorAxis> getAvailableAxes() const
    {
        return m_AvailableAxes;
    }

public:
    void connectCallback(SPIICallback_StateInterface *cb)
    {
        m_CB = cb;
    }

    void issueSPIINotification(const common::NotificationUpdate &update)
    {
        if(m_CB)
            m_CB->cbi_SPIINotificationUpdate(update);
    }

    void issueSPIIUploadProgram(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_SPIIUploadProgram(command);
    }

    void issueSPIIDownloadProgram(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_SPIIDownloadProgram(command);
    }

    void issueNewSPIIState(const ECM::SPII::SPIIState &state)
    {
        if(m_CB)
            m_CB->cbi_SPIINewMachineState(state);
    }

    void issueSPIICommand(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_AbstractSPIICommand(command);
    }

    void issueSPIIRequest(const AbstractRequestPtr request)
    {
        if(m_CB)
            m_CB->cbi_AbstractSPIIRequest(request);
    }

    void issueSPIIMotionCommand(const AbstractCommandPtr command)
    {
        if(m_CB)
            m_CB->cbi_AbstractSPIIMotionCommand(command);
    }

    void issueSPIIControllerGains(const CommandControllerGain &gains)
    {
        if(m_CB)
            m_CB->cbi_SPIIControllerGains(gains);
    }

    void issueSPIIAddPollingRequest(const AbstractRequestPtr request, const int &period = 1000)
    {
        if(m_CB)
            m_CB->cbi_AbstractSPIIAddPolled(request, period);
    }

    void issueSPIIRemovePollingRequest(const common::TupleECMData &tuple)
    {
        if(m_CB)
            m_CB->cbi_AbstractSPIIRemovePolled(tuple);
    }

    void issueUpdatedMotionProfileState(const MotionProfileState &state, const bool &performStateUpdate = true)
    {
        if(m_CB)
            m_CB->cbi_SPIIMotionProfileState(state, performStateUpdate);
    }

    void issueUpdatedHomingState(const ProfileState_Homing &state)
    {
        switch (state.getCurrentCode()) {
        case ProfileState_Homing::HOMINGProfileCodes::COMPLETE:
        {
            setHomeInidcated(true);
            if(m_CB)
            {
                common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL,
                                                     "Homing routine has been completed.");

                m_CB->cbi_SPIIHomeIndicated(true);
                m_CB->cbi_SPIINotificationUpdate(newUpdate);
            }
            break;
        }
        case ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE:
        {
            setHomeInidcated(false);
            if(m_CB)
            {
                common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL,
                                                     "Homing routine has started.");

                m_CB->cbi_SPIIHomeIndicated(true);
                m_CB->cbi_SPIINotificationUpdate(newUpdate);
            }
            break;
        }
        }
    }

    void issueUpdatedHomePositioning(const ProfileState_Homing &state)
    {
        switch (state.getCurrentCode()) {
        case ProfileState_Homing::HOMINGProfileCodes::COMPLETE:
        {
            if(m_CB)
            {
                common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL,
                                                     "Machine has reached home position.");

                m_CB->cbi_SPIINotificationUpdate(newUpdate);
            }
            break;
        }
        case ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE:
        {
            if(m_CB)
            {
                common::NotificationUpdate newUpdate("ACS Motion Controller",ECMDevice::DEVICE_MOTIONCONTROL,
                                                     common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL,
                                                     "Moving machine to home position.");

                m_CB->cbi_SPIINotificationUpdate(newUpdate);
            }

            break;
        }
        }
    }
public:
    std::vector<double> getAxisPositionVector() const;
    bool getAxisPosition(const MotorAxis &axis, double &position) const;

public:
    bool areAnyMotorsInMotion() const;
    bool areAnyMotorsEnabled() const;
    bool areAllMotorsEnabled() const;

    bool isEStopEngaged() const;

public:
    bool isHomeInidcated() const;
    bool isTouchoffIndicated() const;

public:
    void setHomeInidcated(const bool &val);
    void setTouchoffIndicated(const bool &val);

private:
    bool indicatedHome = false;
    bool indicatedTouchoff = false;

private:
    SPIICallback_StateInterface *m_CB;

public:

    DataGetSetNotifier<Status_SystemFault> m_SystemFaults;

    DataGetSetNotifier<int> statusInputs; /**< Member variable containing the current state
inputs of the SPII Unit. Inputs can be gathered based on the enum settings contained within the file.
Eventually this should change to be pulled from a configuraiton.*/

    BufferVariableValues* m_MasterVariableValues;/**< Member variable containing the current list of variables
based on the program that is currently on the SPII Unit. Values of this may be updated per the
the request of the polling status function.*/

    SPII_CurrentProgram* m_BufferManager; /**< Member variable containing the current program, labels,
and variables actually aboard the SPII. This can be used as a comparison for determining if the
current program matches what the user witnesses. Also, this can be used to restore the current state
of the program.*/

    std::map<MotorAxis,Status_AxisState> m_AxisState;

private:
    std::vector<MotorAxis> m_AvailableAxes;

};

#endif // SPII_STATE_INTERFACE_H
