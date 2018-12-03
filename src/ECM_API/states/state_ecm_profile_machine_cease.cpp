#include "state_ecm_profile_machine_cease.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineCease::ECMState_ProfileMachineCease():
    ECMState_ProfileMachineBase()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_CEASE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_CEASE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_CEASE;
}

void ECMState_ProfileMachineCease::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineCease::getClone() const
{
    return (new ECMState_ProfileMachineCease(*this));
}

void ECMState_ProfileMachineCease::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineCease(*this);
}

hsm::Transition ECMState_ProfileMachineCease::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case(ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE):
        {
            rtn = hsm::InnerEntryTransition<ECMState_ProfileMachineComplete>(m_Config);
            break;
        }
        case(ECMState::STATE_ECM_PROFILE_MACHINE_FAILED):
        {
            rtn = hsm::InnerEntryTransition<ECMState_ProfileMachineFailed>(m_Config);
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

void ECMState_ProfileMachineCease::Update()
{

}

void ECMState_ProfileMachineCease::OnEnter()
{

}

void ECMState_ProfileMachineCease::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;
    m_Config.execProperties.completeExecution();
    Owner().concludeMachiningProcess(m_Config);

    Owner().action_StopMachine();

    //now let us figure out where we are going
    if(m_Config.execProperties.getProfileCode() == ProfileState_Machining::MACHININGProfileCodes::COMPLETE)
    {
        desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE;
    }
    else
    {
        desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
    }
}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_complete.h"
#include "states/state_ecm_profile_machine_failed.h"
