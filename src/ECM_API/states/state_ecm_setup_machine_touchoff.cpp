#include "state_ecm_setup_machine_touchoff.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoff::ECMState_SetupMachineTouchoff():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
}

void ECMState_SetupMachineTouchoff::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineTouchoff::getClone() const
{
    return (new ECMState_SetupMachineTouchoff(*this));
}

void ECMState_SetupMachineTouchoff::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoff(*this);
}

hsm::Transition ECMState_SetupMachineTouchoff::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(IsInInnerState<ECMState_SetupMachineTouchoffCompleted>())
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachinePump>(this->m_Config);
    }
    else if(IsInInnerState<ECMState_SetupMachineTouchoffFailed>())
    {
        rtn = hsm::SiblingTransition<ECMState_Idle>();
    }
    else{
        if(currentState != desiredState)
        {
            switch (desiredState) {
            case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT:
            {
                rtn = hsm::InnerEntryTransition<ECMState_SetupMachineTouchoffConnect>(this->m_Config);
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
                break;
            }
        }
    }
    return rtn;
}

void ECMState_SetupMachineTouchoff::Update()
{

}

void ECMState_SetupMachineTouchoff::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoff::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"

#include "states/state_ecm_setup_machine_touchoff_connect.h"
#include "states/state_ecm_setup_machine_touchoff_completed.h"
#include "states/state_ecm_setup_machine_touchoff_failed.h"

#include "states/state_ecm_setup_machine_pump.h"
