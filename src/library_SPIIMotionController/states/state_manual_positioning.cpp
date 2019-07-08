#include "state_manual_positioning.h"

namespace ECM{
namespace SPII {

State_ManualPositioning::State_ManualPositioning():
    AbstractStateSPII()
{
    this->currentState = SPIIState::STATE_MANUAL_POSITIONING;
    this->desiredState = SPIIState::STATE_MANUAL_POSITIONING;
}

void State_ManualPositioning::OnExit()
{
    removeNotifiers();
}

AbstractStateSPII* State_ManualPositioning::getClone() const
{
    return (new State_ManualPositioning(*this));
}

void State_ManualPositioning::getClone(AbstractStateSPII** state) const
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
        CommandAbsoluteMove* castCommand = command->as<CommandAbsoluteMove>();
        targetPosition = castCommand->getAbsoluteMovePosition();
        populateMotionComplete();
        setupNotifiers();
        Owner().issueSPIIMotionCommand(command);
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        CommandRelativeMove* castCommand = command->as<CommandRelativeMove>();
        targetPosition = castCommand->getRelativeMoveDistance();
        populateMotionComplete();
        setupNotifiers();
        Owner().issueSPIIMotionCommand(command);
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        this->desiredState = SPIIState::STATE_MOTION_STOP;
        this->currentCommand = command;
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
        desiredState = SPIIState::STATE_ESTOP;
        return;
    }
    else
    {
//        int currentPosition = 0.0; // = Owner().getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
//        if(abs(currentPosition - this->targetPosition) < 2)
//        {
//            this->desiredState = SPIIState::STATE_READY;
//        }
    }
}

void State_ManualPositioning::OnEnter()
{
    Owner().issueNewSPIIState(SPIIState::STATE_MANUAL_POSITIONING);
    //For some reason no command was passed to this case. This is an interesting case.
    this->desiredState = SPIIState::STATE_READY;
}

void State_ManualPositioning::OnEnter(const AbstractCommandPtr command)
{
    Owner().issueNewSPIIState(SPIIState::STATE_MANUAL_POSITIONING);

    if(command != nullptr)
    {
        /*
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
                desiredState = SPIIState::STATE_MOTION_STOP;
                break;
            }
            case 2:
            {
                //Decelerating or stopped by FWD limit switch or soft limit FL
                desiredState = SPIIState::STATE_MOTION_STOP;
                break;
            }
            case 3:
            {
                //Decelerating or stopped by REV limit switch or soft limit BL
                desiredState = SPIIState::STATE_MOTION_STOP;
                break;
            }
            default:
                break;
            }
        });
        */
        //This means there is a command for us to handle
        this->handleCommand(command);
    }
    else{
        //For some reason the command was null. This is an interesting case.
        this->desiredState = SPIIState::STATE_READY;
    }
}


void State_ManualPositioning::populateMotionComplete()
{
    motionComplete.clear();

    for (std::map<MotorAxis,double>::iterator it=targetPosition.begin(); it!=targetPosition.end(); ++it)
      motionComplete.insert(std::pair<MotorAxis,bool>(it->first,false));
}

bool State_ManualPositioning::allMotionComplete() const
{
    for (std::map<MotorAxis,bool>::const_iterator it=motionComplete.begin(); it!=motionComplete.end(); ++it)
    {
        if(!it->second)
            return false;
    }
    return true;
}

void State_ManualPositioning::setupNotifiers()
{
    for (std::map<MotorAxis,double>::iterator it=targetPosition.begin(); it!=targetPosition.end(); ++it)
    {
        MotorAxis currentAxis = it->first;
        motionComplete.insert(std::pair<MotorAxis,bool>(currentAxis,false));

        DataGetSetNotifier<Status_MotorPerAxis>* notifier = Owner().m_MotorStatus->getAxisStatusNotifier(currentAxis);
        notifier->AddNotifier(this,[this, currentAxis]
        {
            Status_MotorPerAxis newStatus;
            if(!Owner().m_MotorStatus->getAxisStatus(currentAxis,newStatus))
                return;

            if(newStatus.hasMotorReachedTarget())
                this->motionComplete.at(currentAxis) = true;
            if(this->allMotionComplete())
                desiredState = SPIIState::STATE_MOTION_STOP;
        });
    }
}

void State_ManualPositioning::removeNotifiers()
{
    for (std::map<MotorAxis,double>::iterator it=targetPosition.begin(); it!=targetPosition.end(); ++it)
    {
        MotorAxis currentAxis = it->first;
        DataGetSetNotifier<Status_MotorPerAxis>* notifier = Owner().m_MotorStatus->getAxisStatusNotifier(currentAxis);
        notifier->RemoveNotifier(this);
    }
}

} //end of namespace SPII
} //end of namespace ECM

#include "states/state_motion_stop.h"
#include "states/state_estop.h"
