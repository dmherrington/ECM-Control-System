#include "state_ecm_profile_machine_pause.h"

namespace ECM{
namespace API {

ECMState_ProfileMachinePause::ECMState_ProfileMachinePause():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_PROCESS."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
}

void ECMState_ProfileMachinePause::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachinePause::getClone() const
{
    return (new ECMState_ProfileMachinePause(*this));
}

void ECMState_ProfileMachinePause::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachinePause(*this);
}

hsm::Transition ECMState_ProfileMachinePause::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        switch (desiredState) {
        case ECMState::STATE_ECM_PROFILE_MACHINE_ABORT:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineAbort>(this->m_Config);
            break;
        }
        case ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineCompleteExecution>(this->m_Config);
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachinePause::Update()
{

}

void ECMState_ProfileMachinePause::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
}

void ECMState_ProfileMachinePause::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachinePause::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}

void ECMState_ProfileMachinePause::continueProcess()
{
    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION;
}



} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_abort.h"
#include "states/state_ecm_profile_machine_complete_execution.h"
