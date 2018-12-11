#include "state_ecm_upload_failed.h"

namespace ECM{
namespace API {

ECMState_UploadFailed::ECMState_UploadFailed():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_FAILED;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadFailed::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadFailed::getClone() const
{
    return (new ECMState_UploadFailed(*this));
}

void ECMState_UploadFailed::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadFailed(*this);
}

hsm::Transition ECMState_UploadFailed::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {

    }

    return rtn;
}

void ECMState_UploadFailed::Update()
{

}

void ECMState_UploadFailed::OnEnter()
{

}

void ECMState_UploadFailed::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
}

} //end of namespace Galil
} //end of namespace ECM

