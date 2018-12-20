#include "state_manual_positioning.h"

namespace ECM{
namespace Galil {

State_ManualPositioning::State_ManualPositioning():
    AbstractStateGalil()
{
    this->currentState = GalilState::STATE_MANUAL_POSITIONING;
    this->desiredState = GalilState::STATE_MANUAL_POSITIONING;
}

void State_ManualPositioning::OnExit()
{
    Owner().getAxisStatus(MotorAxis::Z)->stopCode.RemoveNotifier(this);
    Owner().getAxisStatus(MotorAxis::Z)->position.RemoveNotifier(this);
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
        case GalilState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case GalilState::STATE_ESTOP:
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

void State_ManualPositioning::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::ABSOLUTE_MOVE:
    {
        Owner().issueGalilMotionCommand(command);
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        int targetPosition = Owner().getAxisStatus(MotorAxis::Z)->getPosition().getPosition() + command->as<CommandRelativeMove>()->getRelativeDistance(MotorAxis::Z) * 10;
        Owner().getAxisStatus(MotorAxis::Z)->position.AddNotifier(this,[this, targetPosition]
        {
            int currentPosition = Owner().getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
            if(abs(currentPosition - targetPosition) < 2)
            {
                this->desiredState = GalilState::STATE_READY;
            }
        });

        Owner().issueGalilMotionCommand(command);
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        this->desiredState = GalilState::STATE_MOTION_STOP;
        this->currentCommand = command;
    }
    case CommandType::STOP:
    {
        this->desiredState = GalilState::STATE_MOTION_STOP;
        break;
    }
    case CommandType::ESTOP:
    {
        this->desiredState = GalilState::STATE_ESTOP;
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
        desiredState = GalilState::STATE_ESTOP;
        return;
    }
    else
    {
        if(this->currentCommand->getCommandType() == CommandType::RELATIVE_MOVE)
        {

        }
    }
}

void State_ManualPositioning::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_MANUAL_POSITIONING);
    //For some reason no command was passed to this case. This is an interesting case.
    this->desiredState = GalilState::STATE_READY;
}

void State_ManualPositioning::OnEnter(const AbstractCommandPtr command)
{
    Owner().issueNewGalilState(GalilState::STATE_MANUAL_POSITIONING);

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
                desiredState = GalilState::STATE_MOTION_STOP;
                break;
            }
            case 2:
            {
                //Decelerating or stopped by FWD limit switch or soft limit FL
                desiredState = GalilState::STATE_MOTION_STOP;
                break;
            }
            case 3:
            {
                //Decelerating or stopped by REV limit switch or soft limit BL
                desiredState = GalilState::STATE_MOTION_STOP;
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
        this->desiredState = GalilState::STATE_READY;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
