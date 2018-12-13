#include "state_ecm_setup_machine_touchoff_disconnect.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffDisconnect::ECMState_SetupMachineTouchoffDisconnect():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT;
}

void ECMState_SetupMachineTouchoffDisconnect::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffDisconnect::getClone() const
{
    return (new ECMState_SetupMachineTouchoffDisconnect(*this));
}

void ECMState_SetupMachineTouchoffDisconnect::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffDisconnect(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffDisconnect::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_COMPLETED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffCompleted>();
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineTouchoffDisconnect::Update()
{

}

void ECMState_SetupMachineTouchoffDisconnect::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    Owner().notifyPausedEvent("Please disable the touchoff switch.");
}

void ECMState_SetupMachineTouchoffDisconnect::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoffDisconnect::continueProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_COMPLETED;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_failed.h"
#include "states/state_ecm_setup_machine_touchoff_completed.h"
