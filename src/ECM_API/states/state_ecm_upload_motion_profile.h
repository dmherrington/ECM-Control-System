#ifndef STATE_ECM_UPLOAD_MOTION_PROFILE_H
#define STATE_ECM_UPLOAD_MOTION_PROFILE_H

#include "states/state_abstract_ecm_process.h"
#include "commands/ecmcommand_profile_configuration.h"

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

class ECMState_UploadMotionProfile;

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
    void Update() override;

    void OnEnter() override;

    void OnEnter(const ECMCommand_ProfileConfigurationPtr command);

};

} //end of namespace API
} //end of namespace ECM

#endif // STATE_ECM_UPLOAD_MOTION_PROFILE_H
