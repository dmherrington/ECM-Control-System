#include "state_home_positioning.h"

namespace ECM{
namespace Galil {

State_HomePositioning::State_HomePositioning():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_HOME_POSITIONING;
    this->desiredState = ECMState::STATE_HOME_POSITIONING;
}

AbstractStateGalil* State_HomePositioning::getClone() const
{
    return (new State_HomePositioning(*this));
}

void State_HomePositioning::getClone(AbstractStateGalil** state) const
{
    *state = new State_HomePositioning(*this);
}

void State_HomePositioning::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::STOP:
    {
        CommandStop cmd;
        this->desiredState = ECMState::STATE_MOTION_STOP;
        break;
    }
    default:
        break;
    }
}

hsm::Transition State_HomePositioning::GetTransition()
{
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_MOTION_STOP:
        {
            return hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            return hsm::SiblingTransition<State_EStop>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from State_HomePositioning."<<std::endl;
            break;
        }
    }
    else{
        return hsm::NoTransition();
    }
}

void State_HomePositioning::OnEnter()
{

}

void State_HomePositioning::OnEnter(const AbstractCommand *command){

    if(command != nullptr)
    {

    }
    else{

    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
