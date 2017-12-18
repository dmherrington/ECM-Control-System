#include "state_manual_positioning.h"

namespace ECM{
namespace Galil {

State_ManualPositioning::State_ManualPositioning():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_MANUAL_POSITIONING;
    this->desiredState = ECMState::STATE_MANUAL_POSITIONING;
}

AbstractStateGalil* State_ManualPositioning::getClone() const
{
    return (new State_ManualPositioning(*this));
}

void State_ManualPositioning::getClone(AbstractStateGalil** state) const
{
    *state = new State_ManualPositioning(*this);
}

void State_ManualPositioning::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {
        CommandAbsoluteMove cmd;
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        CommandRelativeMove cmd;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        CommandJog cmd;
        break;
    }
    case CommandType::STOP:
    {
        CommandStop cmd;
        break;
    }
    default:
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
}


hsm::Transition State_ManualPositioning::GetTransition()
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

void State_ManualPositioning::OnEnter()
{
    //For some reason no command was passed to this case. This is an interesting case.
    std::cout<<"The command is null even though we have been told to enter the manual positioning state."<<std::endl;
    this->desiredState = ECMState::STATE_READY;
}

void State_ManualPositioning::OnEnter(const AbstractCommand *command)
{
    if(command != nullptr)
    {

    }
    else{
        //For some reason the command was null. This is an interesting case.
        std::cout<<"The command is null even though we have been told to enter the manual positioning state."<<std::endl;
        this->desiredState = ECMState::STATE_READY;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
