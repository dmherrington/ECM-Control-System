#include "state_manual_positioning.h"

namespace ECM{
namespace Galil {

State_ManualPositioning::State_ManualPositioning():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_MANUAL_POSITIONING;
    this->desiredState = ECMState::STATE_MANUAL_POSITIONING;
}

void State_ManualPositioning::OnExit()
{
    Owner().getAxisStatus(MotorAxis::Z)->stopCode.RemoveNotifier(this);
}

AbstractStateGalil* State_ManualPositioning::getClone() const
{
    return (new State_ManualPositioning(*this));
}

void State_ManualPositioning::getClone(AbstractStateGalil** state) const
{
    *state = new State_ManualPositioning(*this);
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

void State_ManualPositioning::handleCommand(const AbstractCommand* command)
{
    const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition

    CommandType currentCommand = copyCommand->getCommandType();

    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {
//        Owner().getAxisStatus(MotorAxis::Z)->axisMoving.AddNotifier(this,[this]
//        {
//            if(Owner().getAxisStatus(MotorAxis::Z)->axisMoving.get())
//                motionFlag = true;
//        });

        CommandAbsoluteMovePtr castCommand = std::make_shared<CommandAbsoluteMove>(*copyCommand->as<CommandAbsoluteMove>());
        this->clearCommand();
        Owner().issueGalilMotionCommand(castCommand);
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
//        Owner().getAxisStatus(MotorAxis::Z)->axisMoving.AddNotifier(this,[this]
//        {
//            if(Owner().getAxisStatus(MotorAxis::Z)->axisMoving.get())
//                motionFlag = true;
//        });
        CommandRelativeMovePtr castCommand = std::make_shared<CommandRelativeMove>(*copyCommand->as<CommandRelativeMove>());
        this->clearCommand();
        Owner().issueGalilMotionCommand(castCommand);
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        this->desiredState = ECMState::STATE_MOTION_STOP;
        this->currentCommand = copyCommand;
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
        std::cout<<"The command type of: "<<CommandToString(command->getCommandType())<<" has no explicit support within the manual positioning state."<<std::endl;
        break;
    }
}

void State_ManualPositioning::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
        return;
    }
}

void State_ManualPositioning::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_MANUAL_POSITIONING));
    //For some reason no command was passed to this case. This is an interesting case.
    this->desiredState = ECMState::STATE_READY;
}

void State_ManualPositioning::OnEnter(const AbstractCommand *command)
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_MANUAL_POSITIONING));

    if(command != nullptr)
    {
        //Let us establish the callback notification to when the stop code has changed
        Owner().getAxisStatus(MotorAxis::Z)->stopCode.AddNotifier(this,[this]
        {
            int currentStopCode = Owner().getAxisStatus(MotorAxis::Z)->stopCode.get().getCode();
            switch (currentStopCode) {
            case 0:
            {
                //the machine is still in motion
                break;
            }
            case 1:
            {
                //the machine has reached its commanded position
                desiredState = ECMState::STATE_MOTION_STOP;
                break;
            }
            case 2:
            case 3:
            {
                //the machine has reached a limit switch
                break;
            }
            default:
                break;
            }
        });

        //This means there is a command for us to handle
        this->handleCommand(command);
    }
    else{
        //For some reason the command was null. This is an interesting case.
        this->desiredState = ECMState::STATE_READY;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
