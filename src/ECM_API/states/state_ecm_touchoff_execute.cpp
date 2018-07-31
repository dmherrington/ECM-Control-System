#include "state_ecm_touchoff_execute.h"

namespace ECM{
namespace API {

ECMState_TouchoffExecute::ECMState_TouchoffExecute():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_TOUCHOFF_EXECUTE;
    this->desiredState = ECMState::STATE_ECM_TOUCHOFF_EXECUTE;
}

void ECMState_TouchoffExecute::OnExit()
{

}

AbstractStateECMProcess* ECMState_TouchoffExecute::getClone() const
{
    return (new ECMState_TouchoffExecute(*this));
}

void ECMState_TouchoffExecute::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_TouchoffExecute(*this);
}

hsm::Transition ECMState_TouchoffExecute::GetTransition()
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
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_TouchoffExecute::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
        return;
    }
}

void ECMState_TouchoffExecute::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_MANUAL_POSITIONING));
    //For some reason no command was passed to this case. This is an interesting case.
    this->desiredState = ECMState::STATE_READY;
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
