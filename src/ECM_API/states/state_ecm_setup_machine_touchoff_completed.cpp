#include "state_ecm_setup_machine_touchoff_completed.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffCompleted::ECMState_SetupMachineTouchoffCompleted():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_COMPLETED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_COMPLETED;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_COMPLETED;
}

void ECMState_SetupMachineTouchoffCompleted::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffCompleted::getClone() const
{
    return (new ECMState_SetupMachineTouchoffCompleted(*this));
}

void ECMState_SetupMachineTouchoffCompleted::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffCompleted(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffCompleted::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void ECMState_SetupMachineTouchoffCompleted::Update()
{

}

void ECMState_SetupMachineTouchoffCompleted::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}


} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
