#ifndef STATE_ECM_UPLOAD_PUMP_PARAMETERS_H
#define STATE_ECM_UPLOAD_PUMP_PARAMETERS_H

#include "states/state_abstract_ecm_process.h"
#include "commands/ecm_command_profile_configuration.h"

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

ECM_CLASS_FORWARD(ECMState_UploadPumpParameters);

class ECMState_UploadComplete;
class ECMState_UploadFailed;

class ECMState_UploadPumpParameters : public AbstractStateECMProcess
{
public:
    ECMState_UploadPumpParameters();

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
#endif //STATE_ECM_UPLOAD_PUMP_PARAMETERS_H
