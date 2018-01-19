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
            std::cout<<"I dont know how we eneded up in this desired transition state from state jogging."<<std::endl;
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
        CommandJogPtr castCommand = std::make_shared<CommandJog>(*command->as<CommandJog>());
        Owner().commsMarshaler->sendAbstractGalilCommand(castCommand);
        break;
    }
    case CommandType::STOP:
    {
        this->desiredState = ECMState::STATE_MOTION_STOP;
        break;
    }
    case CommandType::ESTOP:
    {
        this->desiredState = ECMState::STATE_ESTOP;
        break;
    }
    default:
        std::cout<<"Thie command type of: "<<CommandToString(command->getCommandType())<<" has no explicit support from the idle state."<<std::endl;
        break;
    }
}

void State_Jogging::Update()
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

void State_Jogging::OnEnter()
{
    //this shouldn't really happen as how are we supposed to know the jogging rate
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

void State_Jogging::OnEnter(const AbstractCommand *command)
{
    if(command != nullptr)
    {
        //There are no specific things to have performed in this state as we should only
        //have arrived here from a ready state. We will go right to handling the command.
        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
