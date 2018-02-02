#include "state_ready_stop.h"

namespace ECM{
namespace Galil {

State_ReadyStop::State_ReadyStop():
    AbstractStateGalil()
{
    std::cout<<"We are in the constructor of State_ReadyStop"<<std::endl;
    this->currentState = ECMState::STATE_READY_STOP;
    this->desiredState = ECMState::STATE_READY_STOP;
}

AbstractStateGalil* State_ReadyStop::getClone() const
{
    return (new State_ReadyStop(*this));
}

void State_ReadyStop::getClone(AbstractStateGalil** state) const
{
    *state = new State_ReadyStop(*this);
}

hsm::Transition State_ReadyStop::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<State_Idle>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_ReadyStop::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    default:
        //We shouldn't have any commands in this state to handle
        break;
    }
}

void State_ReadyStop::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
    else if(!Owner().isMotorEnabled())
        desiredState = ECMState::STATE_IDLE;
}

void State_ReadyStop::OnEnter()
{
    //The first thing we should do when entering this state is to disengage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command

    //First check to see if the motor is already disarmed, and if not, disarm it
    if(Owner().isMotorEnabled())
    {
        //If the motor is currently armed, issue the command to disarm it
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
}

void State_ReadyStop::OnEnter(const AbstractCommand* command)
{
    this->OnEnter();

    if(command != nullptr)
    {
        //The command isnt null so we should handle it
    }
    else{
        //There was no actual command, therefore, there is nothing else to do at this point
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
#include "states/state_estop.h"
