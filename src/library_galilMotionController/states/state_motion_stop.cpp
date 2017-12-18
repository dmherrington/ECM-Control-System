#include "state_motion_stop.h"

namespace ECM{
namespace Galil {

State_MotionStop::State_MotionStop():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_MOTION_STOP;
    this->desiredState = ECMState::STATE_MOTION_STOP;
}

AbstractStateGalil* State_MotionStop::getClone() const
{
    return (new State_MotionStop(*this));
}

void State_MotionStop::getClone(AbstractStateGalil** state) const
{
    *state = new State_MotionStop(*this);
}

void State_MotionStop::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    default:
        //During this state we really dont handle any commands
        //This state should only allow transitions back to the ready state
        break;
    }
}

hsm::Transition State_MotionStop::GetTransition()
{
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            return hsm::SiblingTransition<State_Ready>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            return hsm::SiblingTransition<State_EStop>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }
    else{
        return hsm::NoTransition();
    }
}

void State_MotionStop::OnEnter()
{
    //The first thing we should do when entering this state is to stop motion of the motor
    CommandStop cmd;
    Owner().transmitMessage(cmd.getCommandString());
    //Setup the state we should transition to
    this->desiredState = ECMState::STATE_READY;
}

void State_MotionStop::OnEnter(const AbstractCommand* command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command isnt null so we should handle it if applicable
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
