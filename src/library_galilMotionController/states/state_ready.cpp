#include "state_ready.h"

namespace ECM{
namespace Galil {

State_Ready::State_Ready():
    AbstractStateGalil()
{
    this->currentState = GalilState::STATE_READY;
    this->desiredState = GalilState::STATE_READY;
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
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case GalilState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<State_Idle>(currentCommand);
            break;
        }
        case GalilState::STATE_MANUAL_POSITIONING:
        {
            rtn = hsm::SiblingTransition<State_ManualPositioning>(currentCommand);
            break;
        }
        case GalilState::STATE_JOGGING:
        {
            rtn = hsm::SiblingTransition<State_Jogging>(currentCommand);
            break;
        }
        case GalilState::STATE_HOME_POSITIONING:
        {
            rtn = hsm::SiblingTransition<State_HomePositioning>(currentCommand);
            break;
        }
        case GalilState::STATE_SCRIPT_EXECUTION:
        {
            rtn = hsm::SiblingTransition<State_ScriptExecution>(currentCommand);
            break;
        }
        case GalilState::STATE_TOUCHOFF:
        {
            rtn = hsm::SiblingTransition<State_Touchoff>(currentCommand);
            break;
        }
        case GalilState::STATE_READY_STOP:
        {
            rtn = hsm::SiblingTransition<State_ReadyStop>();
            break;
        }
        case GalilState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from STATE_READY."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_Ready::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::DOWNLOAD_PROGRAM:
    case CommandType::UPLOAD_PROGRAM:
    {
        desiredState = GalilState::STATE_READY_STOP;
        this->currentCommand = command;
        break;
    }
    case CommandType::SPEED:
    {
        Owner().issueGalilCommand(command);
        break;
    }
    case CommandType::ABSOLUTE_MOVE:
    case CommandType::RELATIVE_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to STATE_MANUAL_POSITIONING
        desiredState = GalilState::STATE_MANUAL_POSITIONING;
        this->currentCommand = command;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        //This command will transition the machine to STATE_JOGGING
        desiredState = GalilState::STATE_JOGGING;
        this->currentCommand = command;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        //While this state is responsive to this command, it is only responsive by causing the state machine to progress to a new state.
        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
        switch (castCommand->getProfileType()) {
        case MotionProfile::ProfileType::HOMING:
        {
            //This command will transition the machine to STATE_HOME_POSITIONING
            desiredState = GalilState::STATE_HOME_POSITIONING;
            this->currentCommand = command;
            break;
        }
        case MotionProfile::ProfileType::PROFILE:
        {
            //This command will transition the machine to STATE_SCRIPT_EXECUTION
            desiredState = GalilState::STATE_SCRIPT_EXECUTION;
            this->currentCommand = command;
            break;
        }
        case MotionProfile::ProfileType::TOUCHOFF:
        {
            //This command will transition the machine to STATE_TOUCHOFF
            desiredState = GalilState::STATE_TOUCHOFF;
            this->currentCommand = command;
            break;
        }
        default:
            break;
        }
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        desiredState = GalilState::STATE_READY_STOP;
        break;
    }
    case CommandType::STOP:
    {
        //at the moment we only have this transitioning to the ready state
        break;
    }
    case CommandType::MOTOR_ON:
    {
        //While this state is responsive to this command, the motor should already be completely armed when it has arrived to this state.
        //First check to see if the motor is already armed, and if not, arm it
        if(!Owner().isMotorEnabled())
        {
            //If the motor is not currently armed, issue the command to arm it
            //CommandMotorEnablePtr castCommand = std::make_shared<CommandMotorEnable>(*command->as<CommandMotorEnable>());
            Owner().issueGalilCommand(command);
        }
        break;
    }
    case CommandType::CLEAR_BIT:
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(command->getCommandType())<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::SET_VARIABLE:
    {
        //const Command_Variable* castCommand = copyCommand->as<Command_Variable>();
        //Command_VariablePtr command = std::make_shared<Command_Variable>(*castCommand);
        Owner().issueGalilCommand(command);
        break;
    }
    default:
        break;
    }
}

void State_Ready::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = GalilState::STATE_ESTOP;
    }
    else
    {
        if(!Owner().isMotorEnabled())
            desiredState = GalilState::STATE_IDLE;
    }
}

void State_Ready::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_READY);
    //The first thing we should do when entering this state is to engage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command

    if(!Owner().isMotorEnabled())
    {
        CommandMotorEnablePtr command = std::make_shared<CommandMotorEnable>();
        command->setEnableAxis(MotorAxis::Z);
        Owner().issueGalilCommand(command);
    }

    //Next we should establish the necessary gains for motion within this state
    CommandControllerGain command;
    Owner().issueGalilControllerGains(command);
}

void State_Ready::OnEnter(const AbstractCommandPtr command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command isnt null so we should handle it
        this->handleCommand(command);
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
#include "states/state_home_positioning.h"
#include "states/state_jogging.h"
#include "states/state_manual_positioning.h"
#include "states/state_script_execution.h"
#include "states/state_touchoff.h"
#include "states/state_estop.h"
#include "states/state_ready_stop.h"
