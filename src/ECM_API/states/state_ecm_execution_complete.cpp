#include "state_ecm_execution_complete.h"

namespace ECM{
namespace API {

ECMState_ExecutionComplete::ECMState_ExecutionComplete():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_EXECUTION_COMPLETE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_EXECUTION_COMPLETE;
    this->desiredState = ECMState::STATE_ECM_EXECUTION_COMPLETE;
}

void ECMState_ExecutionComplete::OnExit()
{

}

AbstractStateECMProcess* ECMState_ExecutionComplete::getClone() const
{
    return (new ECMState_ExecutionComplete(*this));
}

void ECMState_ExecutionComplete::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ExecutionComplete(*this);
}

hsm::Transition ECMState_ExecutionComplete::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        switch (desiredState) {
        case ECMState::STATE_ECM_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Idle>();
            break;
        }
        default:
            break;
        }
    }
    return rtn;
}

void ECMState_ExecutionComplete::Update()
{

}


void ECMState_ExecutionComplete::OnEnter()
{
    this->desiredState = ECMState::STATE_ECM_IDLE;
}

void ECMState_ExecutionComplete::OnEnter(const ECMCommand_ExecuteCollection &collection)
{
    this->m_ECMCollection = collection;

    this->OnEnter();
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"
