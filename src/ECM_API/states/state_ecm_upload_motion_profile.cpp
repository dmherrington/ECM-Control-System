#include "state_ecm_upload_motion_profile.h"

namespace ECM{
namespace API {

ECMState_UploadMotionProfile::ECMState_UploadMotionProfile():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
}

AbstractStateECMProcess* ECMState_UploadMotionProfile::getClone() const
{
    return (new ECMState_UploadMotionProfile(*this));
}

void ECMState_UploadMotionProfile::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadMotionProfile(*this);
}

hsm::Transition ECMState_UploadMotionProfile::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadMotionProfile::Update()
{

}

void ECMState_UploadMotionProfile::OnEnter()
{

}

void ECMState_UploadMotionProfile::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    this->m_ProfileConfiguration = config;

    Owner().m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        if(completed)
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
        }else
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        }
    });
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_motion_variables.h"
#include "states/state_ecm_upload_failed.h"
