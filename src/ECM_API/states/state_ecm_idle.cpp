#include "state_ecm_idle.h"

namespace ECM{
namespace API {

ECMState_Idle::ECMState_Idle():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_IDLE;
    this->desiredState = ECMState::STATE_ECM_IDLE;
}

void ECMState_Idle::OnExit()
{

}

AbstractStateECMProcess* ECMState_Idle::getClone() const
{
    return (new ECMState_Idle(*this));
}

void ECMState_Idle::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Idle(*this);
}

hsm::Transition ECMState_Idle::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_ECM_INITIALIZATION:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_Idle::Update()
{

}

void ECMState_Idle::OnEnter()
{

}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_initialization.h"
