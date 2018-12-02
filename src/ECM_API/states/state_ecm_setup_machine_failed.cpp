#include "state_ecm_setup_machine_failed.h"

namespace ECM{
namespace API {

ECMState_SetupMachineFailed::ECMState_SetupMachineFailed():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineFailed::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineFailed::getClone() const
{
    return (new ECMState_SetupMachineFailed(*this));
}

void ECMState_SetupMachineFailed::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineFailed(*this);
}

hsm::Transition ECMState_SetupMachineFailed::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void ECMState_SetupMachineFailed::Update()
{

}

void ECMState_SetupMachineFailed::OnEnter()
{

}

void ECMState_SetupMachineFailed::OnEnter(const ECMCommand_ProfileConfiguration &collection)
{

}

} //end of namespace API
} //end of namespace ECM
