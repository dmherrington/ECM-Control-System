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

void ECMState_Touchoff::Update()
{
    //Check the status of the estop state
    if(this->checkEStop())
    {
        //this means that the estop button has been cleared
        //we should therefore transition to STATE_ESTOP
        desiredState = ECMState::STATE_ESTOP;
    }
    else if(Owner().isMotorEnabled() || Owner().isMotorInMotion())
        desiredState = ECMState::STATE_READY;
}

void ECMState_Touchoff::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_IDLE));

    //The first thing we should do when entering this state is to disable the motor
    //To get to this state, it should be noted that we should have already transitioned through
    //the stop state, or motion on the motor has already ceased
    //Let us check to see if the motor is already disabled, if not, follow through with the command
    if(Owner().isMotorEnabled())
    {
        CommandMotorDisablePtr castCommand = std::make_shared<CommandMotorDisable>();
        Owner().issueGalilCommand(castCommand);
    }

    //Update the state to indicate that the previous home indication is no longer valid
    Owner().setHomeInidcated(false);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
