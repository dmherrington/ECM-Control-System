#include "state_ready.h"

namespace ECM{
namespace Galil {

State_Ready::State_Ready():
    AbstractStateGalil()
{
    std::cout<<"I have moved to the ready state"<<std::endl;
}

AbstractStateGalil* State_Ready::getClone() const
{
    return (new State_Ready(*this));
}

void State_Ready::getClone(AbstractStateGalil** state) const
{
    *state = new State_Ready(*this);
}

hsm::Transition State_Ready::GetTransition()
{
    return hsm::NoTransition();
}

void State_Ready::OnEnter()
{

}

void State_Ready::OnEnter(AbstractCommand* command){

    if(command != nullptr)
    {

    }
    else{

    }
}

void State_Ready::handleCommand(const AbstractCommand* command)
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
