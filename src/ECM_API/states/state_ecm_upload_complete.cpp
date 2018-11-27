#include "state_ecm_upload_complete.h"

namespace ECM{
namespace API {

ECMState_UploadComplete::ECMState_UploadComplete():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD;
    this->desiredState = ECMState::STATE_ECM_UPLOAD;
}

AbstractStateECMProcess* ECMState_UploadComplete::getClone() const
{
    return (new ECMState_UploadComplete(*this));
}

void ECMState_UploadComplete::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadComplete(*this);
}

hsm::Transition ECMState_UploadComplete::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {

    }

    return rtn;
}

void ECMState_UploadComplete::Update()
{

}

void ECMState_UploadComplete::OnEnter()
{

}

void ECMState_UploadComplete::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    this->m_ProfileConfiguration = config;
}

} //end of namespace Galil
} //end of namespace ECM

