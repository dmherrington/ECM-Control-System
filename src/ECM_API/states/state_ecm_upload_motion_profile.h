#ifndef STATE_ECM_UPLOAD_MOTION_PROFILE_H
#define STATE_ECM_UPLOAD_MOTION_PROFILE_H

#include "states/state_abstract_ecm_process.h"
#include "commands/ecm_command_execute_collection.h"
#include "library_SPIIMotionController/commands/spii_command_upload_program_suite.h"

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

ECM_CLASS_FORWARD(ECMState_UploadMotionProfile);

class ECMState_UploadMotionVariables;
class ECMState_UploadFailed;

class ECMState_UploadMotionProfile : public AbstractStateECMProcess
{
public:
    ECMState_UploadMotionProfile();

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

#endif // STATE_ECM_UPLOAD_MOTION_PROFILE_H
