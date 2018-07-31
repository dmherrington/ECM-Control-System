#include "state_ecm_touchoff.h"

namespace ECM{
namespace API {

ECMState_Touchoff::ECMState_Touchoff():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_TOUCHOFF;
    this->desiredState = ECMState::STATE_ECM_TOUCHOFF;
}

AbstractStateECMProcess* ECMState_Touchoff::getClone() const
{
    return (new ECMState_Touchoff(*this));
}

void ECMState_Touchoff::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Touchoff(*this);
}

hsm::Transition ECMState_Touchoff::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        if(IsInInnerState<State_TakeoffComplete>())
        {
            rtn = hsm::SiblingTransition<State_Flight>();
        }
        else if()
        {

        }
        else
        {
            //this means we want to chage the state for some reason
            //now initiate the state transition to the correct class
            switch (desiredState) {
            case ECMState::STATE_ECM_IDLE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_Idle>();
                break;
            }
            case ECMState::STATE_ECM_TOUCHOFF_ENABLE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_TouchoffEnable>();
                break;
            }
            case ECMState::STATE_ECM_TOUCHOFF_EXECUTE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_TouchoffExecute>();
                break;
            }
            case ECMState::STATE_ECM_TOUCHOFF_DISABLE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_TouchoffDisable>();
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
                break;
            }
        } //end of else statement
    }

    return rtn;
}

void ECMState_Touchoff::Update()
{

}

void ECMState_Touchoff::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_touchoff_disable.h"
#include "states/state_ecm_touchoff_enable.h"
#include "states/state_ecm_touchoff_execute.h"
#include "states/state_ecm_pump_setup.h"
