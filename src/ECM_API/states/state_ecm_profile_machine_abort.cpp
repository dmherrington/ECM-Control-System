#include "state_ecm_profile_machine_abort.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineAbort::ECMState_ProfileMachineAbort():
    ECMState_ProfileMachineBase()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_ABORT."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
}

void ECMState_ProfileMachineAbort::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineAbort::getClone() const
{
    return (new ECMState_ProfileMachineAbort(*this));
}

void ECMState_ProfileMachineAbort::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineAbort(*this);
}

hsm::Transition ECMState_ProfileMachineAbort::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case(ECMState::STATE_ECM_PROFILE_MACHINE_FAILED):
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineFailed>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }
    else{
        rtn = hsm::NoTransition();
    }

    return rtn;
}

void ECMState_ProfileMachineAbort::Update()
{

}

void ECMState_ProfileMachineAbort::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachineAbort::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    this->OnEnter();

    Owner().action_StopMachine();


    m_Config->m_ExecProperties.completeExecution();
    Owner().concludeExecutingOperation(m_Config);

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_failed.h"
