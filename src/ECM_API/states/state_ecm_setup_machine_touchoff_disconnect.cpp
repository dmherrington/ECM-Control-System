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
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_PUMP:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachinePump>(this->m_Config);
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

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoffDisconnect::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_SetupMachineTouchoffDisconnect::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoffDisconnect::continueProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_pump.h"
