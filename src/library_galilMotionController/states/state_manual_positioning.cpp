#include "state_manual_positioning.h"

namespace ECM{
namespace Galil {

State_ManualPositioning::State_ManualPositioning():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_MANUAL_POSITIONING;
    this->desiredState = ECMState::STATE_MANUAL_POSITIONING;
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
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {        
        Owner().getAxisStatus(MotorAxis::Z)->axisMoving.AddNotifier(this,[this]
        {
            if(Owner().getAxisStatus(MotorAxis::Z)->axisMoving.get())
                motionFlag = true;
        });

        CommandAbsoluteMovePtr castCommand = std::make_shared<CommandAbsoluteMove>(*command->as<CommandAbsoluteMove>());
        this->clearCommand();
        Owner().issueGalilMotionCommand(castCommand);
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        Owner().getAxisStatus(MotorAxis::Z)->axisMoving.AddNotifier(this,[this]
        {
            if(Owner().getAxisStatus(MotorAxis::Z)->axisMoving.get())
                motionFlag = true;
        });
        CommandRelativeMovePtr castCommand = std::make_shared<CommandRelativeMove>(*command->as<CommandRelativeMove>());
        this->clearCommand();
        Owner().issueGalilMotionCommand(castCommand);
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

    //this may get checked to fast and therefore needs a flag to conditionally enable this check once motion has started
    if(motionFlag)
    {
        if(!Owner().getAxisStatus(MotorAxis::Z)->isAxisinMotion())
        {
            //the motor is no longer moving, now let us determine why it is no longer moving
            if(Owner().getAxisStatus(MotorAxis::Z)->stopCode.get().getCode() == 1)
            {
                //the motor has come to a stop because it has reached the desired position
            }
        }
    }
}

void State_ManualPositioning::OnEnter()
{
    //For some reason no command was passed to this case. This is an interesting case.
    std::cout<<"The command is null even though we have been told to enter the manual positioning state."<<std::endl;
    this->desiredState = ECMState::STATE_READY;
}

void State_ManualPositioning::OnEnter(const AbstractCommand *command)
{
    if(command != nullptr)
    {
        //This means there is a command for us to handle
        this->handleCommand(command);
    }
    else{
        //For some reason the command was null. This is an interesting case.
        std::cout<<"The command is null even though we have been told to enter the manual positioning state."<<std::endl;
        this->desiredState = ECMState::STATE_READY;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
