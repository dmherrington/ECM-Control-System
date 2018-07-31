#include "state_ecm_touchoff_disable.h"

namespace ECM{
namespace API {

ECMState_TouchoffDisable::ECMState_TouchoffDisable():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_TOUCHOFF_DISABLE;
    this->desiredState = ECMState::STATE_ECM_TOUCHOFF_DISABLE;
}

AbstractStateECMProcess* ECMState_TouchoffDisable::getClone() const
{
    return (new ECMState_TouchoffDisable(*this));
}

void ECMState_TouchoffDisable::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_TouchoffDisable(*this);
}

hsm::Transition ECMState_TouchoffDisable::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<ECMState_PumpSetup>(this->currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>(this->currentCommand);
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_TouchoffDisable::Update()
{

}

void ECMState_TouchoffDisable::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
