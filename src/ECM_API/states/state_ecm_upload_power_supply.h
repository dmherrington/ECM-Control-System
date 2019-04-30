#ifndef STATE_ECM_UPLOAD_POWER_SUPPLY_H
#define STATE_ECM_UPLOAD_POWER_SUPPLY_H

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

class ECMState_UploadPowerSupplyPause;
class ECMState_UploadPowerSupplyFailed;
class ECMState_UploadPowerSupplySucceeded;
class ECMState_UploadPowerPulseMode;

class ECMState_UploadFailed;
class ECMState_UploadPumpParameters;

ECM_CLASS_FORWARD(ECMState_UploadPowerSupply);

class ECMState_UploadPowerSupply : public AbstractStateECMProcess
{
public:
    ECMState_UploadPowerSupply();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void OnEnter() override;
    void Update() override;
    void OnExit() override;

    void stopProcess() override;

public:
    void OnEnter(ECMCommand_AbstractProfileConfigPtr config);

private:
    ECMCommand_AbstractProfileConfigPtr m_Config;
};

} //end of namespace API
} //end of namespace ECM



#endif // STATE_ECM_UPLOAD_POWER_SUPPLY_H
