#include "state_idle.h"

namespace ECM{
namespace Galil {

State_Idle::State_Idle():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_IDLE;
    this->desiredState = ECMState::STATE_IDLE;
}

AbstractStateGalil* State_Idle::getClone() const
{
    return (new State_Idle(*this));
}

void State_Idle::getClone(AbstractStateGalil** state) const
{
    *state = new State_Idle(*this);
}

hsm::Transition State_Idle::GetTransition()
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

void State_Idle::OnEnter()
{

}

void State_Idle::OnEnter(AbstractCommand* command){

    if(command != nullptr)
    {

    }
    else{

    }
}

void State_Idle::Update()
{
    this->desiredState = ECMState::STATE_READY;

}
void State_Idle::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();
    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::CLEAR_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        //While this state is responsive to this command, the motor should already have been turned off.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off, something is wrong.
        break;
    }
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        break;
    }
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::STOP:
    {
        //While this state is responsive to this command, the motor should already have been turned off and not moving.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off and is moving, something is wrong.
        break;
    }
    case CommandType::TELL_POSITION:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    default:
        break;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"