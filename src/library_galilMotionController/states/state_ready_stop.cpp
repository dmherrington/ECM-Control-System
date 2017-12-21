#include "state_ready_stop.h"

namespace ECM{
namespace Galil {

State_ReadyStop::State_ReadyStop():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_READY_STOP;
    this->desiredState = ECMState::STATE_READY_STOP;
}

AbstractStateGalil* State_ReadyStop::getClone() const
{
    return (new State_ReadyStop(*this));
}

void State_ReadyStop::getClone(AbstractStateGalil** state) const
{
    *state = new State_ReadyStop(*this);
}

hsm::Transition State_ReadyStop::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<State_Idle>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_ReadyStop::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    default:
        //We shouldn't have any commands in this state to handle
        break;
    }
}

void State_ReadyStop::OnEnter()
{
    //The first thing we should do when entering this state is to disengage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command
    CommandMotorDisable cmdDisable;

    //The next thing is to engage the airbrake
    CommandSetBit commandSetBit;
    commandSetBit.appendAddress(2);
}

void State_ReadyStop::OnEnter(const AbstractCommand* command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command isnt null so we should handle it
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
#include "states/state_estop.h"
