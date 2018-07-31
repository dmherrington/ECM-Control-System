#include "state_ecm_profile_machine.h"

namespace ECM{
namespace API {

ECMState_ProfileMachine::ECMState_ProfileMachine():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE;
}

AbstractStateECMProcess* ECMState_ProfileMachine::getClone() const
{
    return (new ECMState_ProfileMachine(*this));
}

void ECMState_ProfileMachine::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachine(*this);
}

hsm::Transition ECMState_ProfileMachine::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Touchoff>(currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>(currentCommand);
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachine::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
    else if(!Owner().isMotorEnabled())
        desiredState = ECMState::STATE_IDLE;
}

void ECMState_ProfileMachine::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_READY_STOP));

    //The first thing we should do when entering this state is to disengage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command

    //First check to see if the motor is already disarmed, and if not, disarm it
    if(Owner().isMotorEnabled())
    {
        //If the motor is currently armed, issue the command to disarm it
        CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();
        Owner().issueGalilCommand(command);
    }
    else{
        //since the motor was already disarmed this implies that we can safely transition to idle state
        this->desiredState = ECMState::STATE_IDLE;
    }

    //Lastly, send a command to make sure the airbrake has been engaged
    CommandSetBitPtr command = std::make_shared<CommandSetBit>();
    command->appendAddress(2); //Ken: be careful in the event that this changes. This should be handled by settings or something
    Owner().issueGalilCommand(command);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
#include "states/state_estop.h"
