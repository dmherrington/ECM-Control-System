#include "state_motion_stop.h"

namespace ECM{
namespace Galil {

State_MotionStop::State_MotionStop():
    AbstractStateGalil()
{
    this->currentState = GalilState::STATE_MOTION_STOP;
    this->desiredState = GalilState::STATE_MOTION_STOP;
}

AbstractStateGalil* State_MotionStop::getClone() const
{
    return (new State_MotionStop(*this));
}

void State_MotionStop::getClone(AbstractStateGalil** state) const
{
    *state = new State_MotionStop(*this);
}

hsm::Transition State_MotionStop::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case GalilState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<State_Ready>(this->currentCommand);
            break;
        }
        case GalilState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>(this->currentCommand);
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_MotionStop::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    default:
        //During this state we really dont handle any commands
        //This state should only allow transitions back to the ready state
        break;
    }
}

void State_MotionStop::Update()
{
    //Check the status of the estop state
    //estop will always take precidence and cause the state machine to progress into that state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = GalilState::STATE_ESTOP;
    }
    else if(!Owner().isMotorInMotion()) //the exit condition for this state is that the machine motion has stopped on all axis
    {
        desiredState = GalilState::STATE_READY;
    }
}

void State_MotionStop::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_MOTION_STOP);

    if(!Owner().isMotorInMotion()) //the exit condition for this state is that the machine motion has stopped on all axis
    {
        //If we get into this condition this implies that the machine had already stopped motion
        //This could be caused by a limit switch being reached, in either case, we should move to the next state
        desiredState = GalilState::STATE_READY;
    }else
    {
        //The first thing we should do when entering this state is to stop motion of the motor
        CommandStopPtr castCommand = std::make_shared<CommandStop>(); //the axis is defaulted to Z with no args
        Owner().issueGalilCommand(castCommand);
    }
}

void State_MotionStop::OnEnter(const AbstractCommandPtr command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command might not be empty, however, we cannot handle anything in this state
        //Allow the state to transition and perhaps it will get handled in the next
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_estop.h"
