#ifndef ECM_STATE_UPLOAD_POWER_PULSE_MODE_H
#define ECM_STATE_UPLOAD_POWER_PULSE_MODE_H

#include "states/state_abstract_ecm_process.h"
#include "commands/ecmcommand_profile_configuration.h"

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

ECM_CLASS_FORWARD(ECMState_UploadPowerPulseMode);

class ECMState_UploadPumpParameters;
class ECMState_UploadFailed;

class ECMState_UploadPowerPulseMode : public AbstractStateECMProcess
{
public:
    ECMState_UploadPowerPulseMode();

public:
    AbstractStateECMProcess* getClone() const override;

    void getClone(AbstractStateECMProcess** state) const override;

public:
    hsm::Transition GetTransition() override;

public:
    void Update() override;

    void OnEnter() override;

    void OnEnter(const ECMCommand_ProfileConfiguration &config);

};

} //end of namespace API
} //end of namespace ECM

#endif // ECM_STATE_UPLOAD_POWER_PULSE_MODE_H
