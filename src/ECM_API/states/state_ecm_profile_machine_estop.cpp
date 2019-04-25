#include "state_ecm_profile_machine_estop.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineEStop::ECMState_ProfileMachineEStop():
    ECMState_ProfileMachineBase()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_ESTOP."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_ESTOP;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ESTOP;
}

void ECMState_ProfileMachineEStop::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineEStop::getClone() const
{
    return (new ECMState_ProfileMachineEStop(*this));
}

void ECMState_ProfileMachineEStop::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineEStop(*this);
}

hsm::Transition ECMState_ProfileMachineEStop::GetTransition()
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

void ECMState_ProfileMachineEStop::Update()
{

}

void ECMState_ProfileMachineEStop::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachineEStop::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    this->OnEnter();

    Owner().action_EStopMachine();

    m_Config->m_ExecProperties.completeExecution();
    Owner().concludeExecutingOperation(m_Config);

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_failed.h"
