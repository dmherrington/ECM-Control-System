#include "state_jogging.h"

namespace ECM{
namespace Galil {

State_Jogging::State_Jogging():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_JOGGING;
    this->desiredState = ECMState::STATE_JOGGING;
}

AbstractStateGalil* State_Jogging::getClone() const
{
    return (new State_Jogging(*this));
}

void State_Jogging::getClone(AbstractStateGalil** state) const
{
    *state = new State_Jogging(*this);
}

hsm::Transition State_Jogging::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_Jogging::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::JOG_MOVE:
    {
        //This is the command that brought us into this state
        break;
    }
    case CommandType::STOP:
    {
        this->desiredState = ECMState::STATE_MOTION_STOP;
    }
    default:
    {
        //For some reason we got a command in here that wasn't the only two that are conceptually supported.
        //We will therefore ignore it for the time being.
    }
    }
}

void State_Jogging::OnEnter()
{
    //this shouldn't really happen as how are we supposed to know the jogging rate
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

void State_Jogging::OnEnter(const AbstractCommand *command){

    if(command != nullptr)
    {
        //There are no specific things to have performed in this state as we should only
        //have arrived here from a ready state. We will go right to handling the command.
    }
    else{
        this->OnEnter();
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
