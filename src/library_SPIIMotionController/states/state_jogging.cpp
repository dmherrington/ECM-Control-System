#include "state_jogging.h"

namespace ECM{
namespace SPII {

State_Jogging::State_Jogging():
    AbstractStateSPII()
{
    this->currentState = SPIIState::STATE_JOGGING;
    this->desiredState = SPIIState::STATE_JOGGING;
}

AbstractStateSPII* State_Jogging::getClone() const
{
    return (new State_Jogging(*this));
}

void State_Jogging::getClone(AbstractStateSPII** state) const
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
        case SPIIState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case SPIIState::STATE_ESTOP:
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

void State_Jogging::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::JOG_MOVE:
    {
        //This is the command that brought us into this state
        Owner().issueGalilMotionCommand(command);
        break;
    }
    case CommandType::STOP:
    {
        this->desiredState = SPIIState::STATE_MOTION_STOP;
        break;
    }
    case CommandType::ESTOP:
    {
        this->desiredState = SPIIState::STATE_ESTOP;
        break;
    }
    default:
        std::cout<<"The command type of: "<<CommandToString(command->getCommandType())<<" has no explicit support from the idle state."<<std::endl;
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
        desiredState = SPIIState::STATE_ESTOP;
    }
}

void State_Jogging::OnEnter()
{
    Owner().issueNewGalilState(SPIIState::STATE_JOGGING);
    //this shouldn't really happen as how are we supposed to know the actual state jogging command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = SPIIState::STATE_READY;
}

void State_Jogging::OnEnter(const AbstractCommandPtr command)
{
    if(command != nullptr)
    {
        Owner().issueNewGalilState(SPIIState::STATE_JOGGING);
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
