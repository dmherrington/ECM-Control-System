#include "state_ecm_setup_machine_touchoff_failed.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffFailed::ECMState_SetupMachineTouchoffFailed():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}

void ECMState_SetupMachineTouchoffFailed::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffFailed::getClone() const
{
    return (new ECMState_SetupMachineTouchoffFailed(*this));
}

void ECMState_SetupMachineTouchoffFailed::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffFailed(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffFailed::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    return rtn;
}

void ECMState_SetupMachineTouchoffFailed::Update()
{

}

void ECMState_SetupMachineTouchoffFailed::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}


} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_pump.h"
