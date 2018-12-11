#include "state_ecm_profile_machine_failed.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineFailed::ECMState_ProfileMachineFailed():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachineFailed::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineFailed::getClone() const
{
    return (new ECMState_ProfileMachineFailed(*this));
}

void ECMState_ProfileMachineFailed::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineFailed(*this);
}

hsm::Transition ECMState_ProfileMachineFailed::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachineFailed::Update()
{

}

void ECMState_ProfileMachineFailed::OnEnter()
{

}
void ECMState_ProfileMachineFailed::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{

}

} //end of namespace API
} //end of namespace ECM
