#include "state_ecm_setup_machine_complete.h"

namespace ECM{
namespace API {

ECMState_SetupMachineComplete::ECMState_SetupMachineComplete():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_COMPLETE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
}

void ECMState_SetupMachineComplete::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineComplete::getClone() const
{
    return (new ECMState_SetupMachineComplete(*this));
}

void ECMState_SetupMachineComplete::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineComplete(*this);
}

hsm::Transition ECMState_SetupMachineComplete::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void ECMState_SetupMachineComplete::Update()
{

}

void ECMState_SetupMachineComplete::OnEnter()
{

}

void ECMState_SetupMachineComplete::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{

}

} //end of namespace API
} //end of namespace ECM
