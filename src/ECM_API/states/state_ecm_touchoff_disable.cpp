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
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_TouchoffDisable::Update()
{
    //Check the status of the estop state
    //estop will always take precidence and cause the state machine to progress into that state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
    else if(!Owner().isMotorInMotion()) //the exit condition for this state is that the machine motion has stopped on all axis
    {
        desiredState = ECMState::STATE_READY;
    }
}

void ECMState_TouchoffDisable::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_MOTION_STOP));

    if(!Owner().isMotorInMotion()) //the exit condition for this state is that the machine motion has stopped on all axis
    {
        //If we get into this condition this implies that the machine had already stopped motion
        //This could be caused by a limit switch being reached, in either case, we should move to the next state
        desiredState = ECMState::STATE_READY;
    }else
    {
        //The first thing we should do when entering this state is to stop motion of the motor
        CommandStopPtr castCommand = std::make_shared<CommandStop>(); //the axis is defaulted to Z with no args
        Owner().issueGalilCommand(castCommand);
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
