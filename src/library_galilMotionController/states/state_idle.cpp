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
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<State_Ready>(this->currentCommand);
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

void State_Idle::Update()
{
    //Check the status of the estop state
    if(this->checkEStop())
    {
        //this means that the estop button has been cleared
        //we should therefore transition to STATE_ESTOP
        desiredState = ECMState::STATE_ESTOP;
    }
    else if(Owner().isMotorEnabled() || Owner().isMotorInMotion())
        desiredState = ECMState::STATE_READY;
}

void State_Idle::handleCommand(const AbstractCommand* command)
{
    const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition

    CommandType currentCommand = copyCommand->getCommandType();
    switch (currentCommand) {
    case CommandType::DOWNLOAD_PROGRAM:
    {
        //we can only download/upload commands in the idle state so this command is valid
        const CommandDownloadProgram* castCommand = copyCommand->as<CommandDownloadProgram>();
        break;
    }
    case CommandType::UPLOAD_PROGRAM:
    {
        const CommandUploadProgram* castCommand = copyCommand->as<CommandUploadProgram>();
        break;
    }
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State and we no longer need the command
        desiredState = ECMState::STATE_READY;
        delete copyCommand;
        break;
    }
    case CommandType::ABSOLUTE_MOVE:
    case CommandType::RELATIVE_MOVE:
    case CommandType::JOG_MOVE:
    case CommandType::EXECUTE_PROGRAM:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to STATE_READY
        desiredState = ECMState::STATE_READY;
        this->currentCommand = copyCommand;
        break;
    }
    case CommandType::CLEAR_BIT:
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::MOTOR_OFF:
    case CommandType::STOP:
    {
        //While this state is responsive to this command, the motor should already have been turned off and not moving.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off and is moving, something is wrong.

        //First check to see if the motor is already disarmed, and if not, disarm it
        if(Owner().getAxisStatus(MotorAxis::Z)->isMotorEnabled())
        {
            //If the motor is not currently armed, issue the command to arm it
            CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();
            Owner().issueGalilCommand(command);
        }
        else{
            //since the motor was already disarmed this implies that we can safely transition to idle state
            this->desiredState = ECMState::STATE_IDLE;
        }

        //Lastly, send a command to make sure the airbrake has been engaged
        CommandSetBitPtr command = std::make_shared<CommandSetBit>();
        command->appendAddress(2); //Ken: be careful in the event that this changes. This should be handled by settings or something
        Owner().issueGalilCommand(command);

        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = ECMState::STATE_ESTOP;
        delete copyCommand;
        break;
    }
    default:
        std::cout<<"Thie command type of: "<<CommandToString(command->getCommandType())<<" has no explicit support from the idle state."<<std::endl;
        break;
    }
}

void State_Idle::OnEnter()
{
    //The first thing we should do when entering this state is to disable the motor
    //To get to this state, it should be noted that we should have already transitioned through
    //the stop state, or motion on the motor has already ceased
    //Let us check to see if the motor is already disabled, if not, follow through with the command
    if(Owner().isMotorEnabled())
    {
        CommandMotorDisablePtr castCommand = std::make_shared<CommandMotorDisable>();
        Owner().issueGalilCommand(castCommand);
    }
}

void State_Idle::OnEnter(const AbstractCommand *command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        this->handleCommand(command);
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
