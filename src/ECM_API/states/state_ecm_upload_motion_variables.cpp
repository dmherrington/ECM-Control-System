#include "state_ecm_upload_motion_variables.h"

namespace ECM{
namespace API {

ECMState_UploadMotionVariables::ECMState_UploadMotionVariables():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
}

void ECMState_UploadMotionVariables::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadMotionVariables::getClone() const
{
    return (new ECMState_UploadMotionVariables(*this));
}

void ECMState_UploadMotionVariables::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadMotionVariables(*this);
}

hsm::Transition ECMState_UploadMotionVariables::GetTransition()
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

void ECMState_UploadMotionVariables::Update()
{

}

void ECMState_UploadMotionVariables::OnEnter(const ECMCommand_ProfileConfigurationPtr command)
{
    Owner().m_Munk->AddLambda_FinishedUploadingParameters(this,[this](const bool completed, const uint8_t finishCode){
        if(completed)
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PARAMETERS;
        }else
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        }

    });
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_power_parameters.h"
#include "states/state_ecm_upload_failed.h"
