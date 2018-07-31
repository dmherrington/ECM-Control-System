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
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffDisable>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this desired transition state from state jogging."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_TouchoffEnable::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
}

void ECMState_TouchoffEnable::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_JOGGING));
    //this shouldn't really happen as how are we supposed to know the actual state jogging command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
