#include "state_ecm_profile_machine_complete_execution.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineCompleteExecution::ECMState_ProfileMachineCompleteExecution():
    ECMState_ProfileMachineBase()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION;
}

void ECMState_ProfileMachineCompleteExecution::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineCompleteExecution::getClone() const
{
    return (new ECMState_ProfileMachineCompleteExecution(*this));
}

void ECMState_ProfileMachineCompleteExecution::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineCompleteExecution(*this);
}

hsm::Transition ECMState_ProfileMachineCompleteExecution::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case(ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE):
        {
            rtn = hsm::InnerEntryTransition<ECMState_ProfileMachineComplete>(this->m_Config);
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

void ECMState_ProfileMachineCompleteExecution::Update()
{

}

void ECMState_ProfileMachineCompleteExecution::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachineCompleteExecution::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    configuration->execProperties.completeExecution();
    Owner().concludeExecutingOperation(configuration);

    Owner().action_StopMachine(); //we are going to move the stop action to the top level directory

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE;
}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_complete.h"
