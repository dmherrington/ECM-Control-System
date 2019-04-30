#ifndef STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSE_H
#define STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSE_H

#include "states/state_abstract_ecm_process.h"

#include "library_munk_power_supply/munk_power_supply.h"

/**
\* @file  state_ecm_touchoff.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System.
\*
\* @section DESCRIPTION
\*/

namespace ECM{
namespace API {

class ECMState_UploadPowerSupplySucceeded;
class ECMState_UploadPowerSupplyFailed;

ECM_CLASS_FORWARD(ECMState_UploadPowerSupplyPause);

class ECMState_UploadPowerSupplyPause : public AbstractStateECMProcess
{
public:
    ECMState_UploadPowerSupplyPause();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void OnEnter() override;
    void Update() override;
    void OnExit() override;

public:
    void stopProcess() override;

    void continueProcess() override;

public:
    void OnEnter(ECMCommand_AbstractProfileConfigPtr config);

private:
    ECMCommand_AbstractProfileConfigPtr m_Config;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSE_H
