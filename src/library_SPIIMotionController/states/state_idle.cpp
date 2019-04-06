#include "state_idle.h"

namespace ECM{
namespace SPII {

State_Idle::State_Idle():
    AbstractStateSPII()
{
    std::cout<<"We are in the Idle State"<<std::endl;
    this->currentState = SPIIState::STATE_IDLE;
    this->desiredState = SPIIState::STATE_IDLE;
}

AbstractStateSPII* State_Idle::getClone() const
{
    return (new State_Idle(*this));
}

void State_Idle::getClone(AbstractStateSPII** state) const
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
        case SPIIState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<State_Ready>(this->currentCommand);
            break;
        }
        case SPIIState::STATE_ESTOP:
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
        desiredState = SPIIState::STATE_ESTOP;
    }
    else if(Owner().isMotorEnabled() || Owner().isMotorInMotion())
        desiredState = SPIIState::STATE_READY;
}

void State_Idle::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::DOWNLOAD_PROGRAM:
    {
        //we can only download/upload commands in the idle state so this command is valid
        //const CommandDownloadProgram* castCommand = copyCommand->as<CommandDownloadProgram>();
        //CommandDownloadProgramPtr command = std::make_shared<CommandDownloadProgram>(*castCommand);
        //const CommandDownloadProgram* castCommand = copyCommand->as<CommandDownloadProgram>();
        Owner().issueSPIIDownloadProgram(command);
        break;
    }
    case CommandType::UPLOAD_PROGRAM:
    {
        //const CommandUploadProgram* castCommand = copyCommand->as<CommandUploadProgram>();
        //CommandUploadProgramPtr command = std::make_shared<CommandUploadProgram>(*castCommand);
        //const CommandUploadProgram* castCommand = copyCommand->as<CommandUploadProgram>();
        Owner().issueSPIIUploadProgram(command);
        break;
    }
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to the Ready State and we no longer need the command
        desiredState = SPIIState::STATE_READY;
        //delete copyCommand;
        break;
    }
    case CommandType::ABSOLUTE_MOVE:
    case CommandType::RELATIVE_MOVE:
    case CommandType::JOG_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to STATE_READY
        desiredState = SPIIState::STATE_READY;
        this->currentCommand = command;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        //This is a tricky case to handle, for now we will handle in this manner
        const CommandExecuteProfile* castCommand = command->as<CommandExecuteProfile>();
        if(castCommand->getProfileType() == MotionProfile::ProfileType::SETUP)
        {
            //This means we can handle this in this state
            //CommandExecuteProfilePtr commandPtr = std::make_shared<CommandExecuteProfile>(*castCommand);
            Owner().issueSPIICommand(command); //this will call the setup routine
        }
        else{
            //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
            //This command will transition the machine to STATE_READY
            desiredState = SPIIState::STATE_READY;
            this->currentCommand = command;
        }
        break;
    }
    case CommandType::CLEAR_BIT:
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(command->getCommandType())<<" is not available while SPII is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::MOTOR_OFF:
    case CommandType::STOP:
    {
        //While this state is responsive to this command, the motor should already have been turned off and not moving.
        //If this is a user command it is them unaware of what has already occured.
        //If we are here because the motor hasn't turned off and is moving, something is wrong.

        //First check to see if the motor is already disarmed, and if not, disarm it
        if(Owner().m_MotorStatus->areAnyMotorsEnabled())
        {
            //If the motor is not currently armed, issue the command to arm it
            Owner().issueSPIICommand(command);
        }
        else{
            //since the motor was already disarmed this implies that we can safely transition to idle state
            this->desiredState = SPIIState::STATE_IDLE;
        }

        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = SPIIState::STATE_ESTOP;
        //delete copyCommand;
        break;
    }
    case CommandType::SET_VARIABLE:
    {
        //const Command_Variable* castCommand = copyCommand->as<Command_Variable>();
        //Command_VariablePtr command = std::make_shared<Command_Variable>(*castCommand);
        Owner().issueSPIICommand(command);
        break;
    }
    case CommandType::SET_VARIABLE_ARRAY:
    {
        //const Command_Variable* castCommand = copyCommand->as<Command_Variable>();
        //Command_VariablePtr command = std::make_shared<Command_Variable>(*castCommand);
        Owner().issueSPIICommand(command);
        break;
    }
    default:
        std::cout<<"The command type of: "<<CommandToString(command->getCommandType())<<" has no explicit support from the idle state."<<std::endl;
        break;
    }
}

void State_Idle::OnEnter()
{
    Owner().issueNewSPIIState(SPIIState::STATE_IDLE);

    //The first thing we should do when entering this state is to disable the motor
    //To get to this state, it should be noted that we should have already transitioned through
    //the stop state, or motion on the motor has already ceased
    //Let us check to see if the motor is already disabled, if not, follow through with the command
    if(Owner().isMotorEnabled())
    {
        CommandMotorDisablePtr castCommand = std::make_shared<CommandMotorDisable>();
        Owner().issueSPIICommand(castCommand);
    }

    //Update the state to indicate that the previous home indication is no longer valid
    Owner().setHomeInidcated(false);
    Owner().setTouchoffIndicated(false);
}

void State_Idle::OnEnter(const AbstractCommandPtr command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        this->handleCommand(command);
    }
}

} //end of namespace SPII
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
