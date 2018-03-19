#include "state_touchoff.h"

namespace ECM{
namespace Galil {

State_Touchoff::State_Touchoff():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_TOUCHOFF;
    this->desiredState = ECMState::STATE_TOUCHOFF;
}

AbstractStateGalil* State_Touchoff::getClone() const
{
    return (new State_Touchoff(*this));
}

void State_Touchoff::getClone(AbstractStateGalil** state) const
{
    *state = new State_Touchoff(*this);
}

hsm::Transition State_Touchoff::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        Owner().issueGalilRemovePollingRequest("touchst");

        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            return hsm::SiblingTransition<State_Ready>();
            break;
        }
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>(currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from STATE_TOUCHOFF."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_Touchoff::handleCommand(const AbstractCommand* command)
{
    const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition

    CommandType currentCommand = copyCommand->getCommandType();
    switch (currentCommand) {
    case CommandType::EXECUTE_PROGRAM:
    {
        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*copyCommand->as<CommandExecuteProfile>());
        Owner().issueGalilMotionCommand(castCommand);
        break;
    }
    case CommandType::STOP:
    {
        desiredState = ECMState::STATE_MOTION_STOP;
        delete copyCommand;
        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = ECMState::STATE_ESTOP;
        delete copyCommand;
        break;
    }
    default:
        break;
    }
}

void State_Touchoff::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }

    double varValue;
    if(Owner().statusVariables.getVariableValue("touchof",varValue))
    {
        switch ((int)varValue) {
        case 0:
        {
            //continue searching for home
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(TOUCHOFFProfileCodes::SEARCHING);
            MotionProfileState newProfileState;
            newProfileState.setProfileState();
            Owner().issueUpdatedMotionProfileState();
            break;
        }
        case 1:
        {
            MotionProfileState profileUpdate;
            profileUpdate.setProfileState();
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(TOUCHOFFProfileCodes::FINISHED);
            //we have finished the touchoff routine

            break;
        }
        case 2:
        {
            //ERROR: inconsistent or positional limit exceeded
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(TOUCHOFFProfileCodes::ERROR_INCONSISTENT);

            CommandAbsoluteMove* command = new CommandAbsoluteMove(MotorAxis::Z,0);
            this->currentCommand = command;
            desiredState = ECMState::STATE_MOTION_STOP;
            break;
        }
        case 3:
        {
            //ERROR: already touch part
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(TOUCHOFFProfileCodes::ERROR_TOUCHING);

            CommandAbsoluteMove* command = new CommandAbsoluteMove(MotorAxis::Z,0);
            this->currentCommand = command;
            desiredState = ECMState::STATE_MOTION_STOP;
            break;
        }
        default:
            //there is a case condition that does not follow the flow chart
            break;
        }
    }
    else
    {
        //this variable doesnt exist so we should abort the touchoff routine
        desiredState = ECMState::STATE_MOTION_STOP;
    }
}

void State_Touchoff::OnEnter()
{
    //this shouldn't really happen as how are we supposed to know the actual touchoff command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

void State_Touchoff::OnEnter(const AbstractCommand* command)
{
    if(command != nullptr)
    {
        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("touchst");
        Owner().issueGalilAddPollingRequest(request);
        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
