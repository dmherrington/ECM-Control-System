#include "state_ecm_setup_machine_touchoff_connect.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffConnect::ECMState_SetupMachineTouchoffConnect():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT;
}

void ECMState_SetupMachineTouchoffConnect::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffConnect::getClone() const
{
    return (new ECMState_SetupMachineTouchoffConnect(*this));
}

void ECMState_SetupMachineTouchoffConnect::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffConnect(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffConnect::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffFailed>();
        break;
    }   
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_POSITION:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffPosition>(this->m_Config);
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineTouchoffConnect::Update()
{

}

void ECMState_SetupMachineTouchoffConnect::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}

void ECMState_SetupMachineTouchoffConnect::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    Owner().notifyPausedEvent("Please enable the touchoff switch.");
}

void ECMState_SetupMachineTouchoffConnect::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}

void ECMState_SetupMachineTouchoffConnect::continueProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_POSITION;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_failed.h"
#include "states/state_ecm_setup_machine_touchoff_position.h"
