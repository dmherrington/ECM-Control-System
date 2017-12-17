#include "state_idle.h"

namespace ECM{
namespace Galil {

State_Idle::State_Idle():
    AbstractStateGalil()
{
    std::cout<<"We are in the constructor of State_Idle"<<std::endl;
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

void State_Idle::Update()
{

}

void State_Idle::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();
    switch (currentCommand) {
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::ABSOLUTE_MOVE:
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
        this->currentCommand = command;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State
        desiredState = ECMState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        //While this state is responsive to this command, the motor should already have been turned off.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off, something is wrong.
        break;
    }
    case CommandType::CLEAR_BIT:
    case CommandType::SET_BIT:
    case CommandType::TELL_POSITION:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::STOP:
    {
        //While this state is responsive to this command, the motor should already have been turned off and not moving.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off and is moving, something is wrong.
        if(Owner().getAxisStatus(MotorAxis::Z)->isMotorRunning())
        {
            std::cout<<"Idle state saw a stop command and the motor was still running. This should NOT have occured."<<std::endl;
            CommandMotorDisable cmd;
        }
        break;
    }
    default:
        break;
    }
}

void State_Idle::OnEnter()
{
    //The first thing we should do when entering this state is to disable the motor
    //Let us check to see if the motor is already disabled, if not, follow through with the command
    CommandMotorDisable cmd;
    cmd.setDisableAxis(MotorAxis::Z);
    GalilStatus* status = Owner().getAxisStatus(MotorAxis::Z);
    if(status->isMotorRunning())
        Owner().transmitMessage(cmd.getCommandString());
}

void State_Idle::OnEnter(const AbstractCommand *command){

    if(command != nullptr)
    {

    }
    else{

    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
