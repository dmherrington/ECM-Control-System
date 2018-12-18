#ifndef STATE_ECM_UPLOAD_POWER_PARAMETERS_H
#define STATE_ECM_UPLOAD_POWER_PARAMETERS_H

#include "states/state_abstract_ecm_process.h"
#include "commands/ecm_command_execute_collection.h"

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

ECM_CLASS_FORWARD(ECMState_UploadPowerRegisterSegments);

class ECMState_UploadPowerPulseMode;
class ECMState_UploadPumpParameters;
class ECMState_UploadFailed;

class ECMState_UploadPowerRegisterSegments : public AbstractStateECMProcess
{
public:
    ECMState_UploadPowerRegisterSegments();

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
    void OnEnter(ECMCommand_AbstractProfileConfigPtr config);

private:
    ECMCommand_AbstractProfileConfigPtr m_Config;
};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_UPLOAD_POWER_PARAMETERS_H
