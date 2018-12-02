#include "state_ecm_setup_machine_pump.h"

namespace ECM{
namespace API {

ECMState_SetupMachinePump::ECMState_SetupMachinePump():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_PUMP."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
}

void ECMState_SetupMachinePump::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachinePump::getClone() const
{
    return (new ECMState_SetupMachinePump(*this));
}

void ECMState_SetupMachinePump::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachinePump(*this);
}

hsm::Transition ECMState_SetupMachinePump::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineComplete>();
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachinePump::Update()
{

}

void ECMState_SetupMachinePump::OnEnter()
{

}

void ECMState_SetupMachinePump::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_complete.h"
#include "states/state_ecm_setup_machine_failed.h"

