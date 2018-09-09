#include "state_ecm_touchoff_enable.h"

namespace ECM{
namespace API {

ECMState_TouchoffEnable::ECMState_TouchoffEnable():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_TOUCHOFF_DISABLE;
    this->desiredState = ECMState::STATE_ECM_TOUCHOFF_DISABLE;
}

AbstractStateECMProcess* ECMState_TouchoffEnable::getClone() const
{
    return (new ECMState_TouchoffEnable(*this));
}

void ECMState_TouchoffEnable::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_TouchoffEnable(*this);
}

hsm::Transition ECMState_TouchoffEnable::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_TouchoffEnable::Update()
{

}

void ECMState_TouchoffEnable::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
