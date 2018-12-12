#include "state_ecm_profile_machine_complete.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineComplete::ECMState_ProfileMachineComplete():
    ECMState_ProfileMachineBase()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_COMPLETE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE;
    //AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachineComplete::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileMachineComplete::getClone() const
{
    return (new ECMState_ProfileMachineComplete(*this));
}

void ECMState_ProfileMachineComplete::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineComplete(*this);
}

hsm::Transition ECMState_ProfileMachineComplete::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachineComplete::Update()
{

}

void ECMState_ProfileMachineComplete::OnEnter()
{

}

void ECMState_ProfileMachineComplete::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;
}

} //end of namespace API
} //end of namespace ECM
