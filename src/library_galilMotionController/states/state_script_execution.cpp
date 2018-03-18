#include "state_script_execution.h"

namespace ECM{
namespace Galil {

State_ScriptExecution::State_ScriptExecution():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_SCRIPT_EXECUTION;
    this->desiredState = ECMState::STATE_SCRIPT_EXECUTION;
}

AbstractStateGalil* State_ScriptExecution::getClone() const
{
    return (new State_ScriptExecution(*this));
}

void State_ScriptExecution::getClone(AbstractStateGalil** state) const
{
    *state = new State_ScriptExecution(*this);
}

hsm::Transition State_ScriptExecution::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        Owner().issueGalilRemovePollingRequest("cutdone");
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
            return hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state script execution."<<std::endl;
            break;
        }
    }
    return rtn;
}

void State_ScriptExecution::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::EXECUTE_PROGRAM:
    {
        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
        Owner().issueGalilCommand(castCommand);
        this->clearCommand();
        break;
    }
    case CommandType::STOP:
    {
        desiredState = ECMState::STATE_MOTION_STOP;
        this->clearCommand();
        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = ECMState::STATE_ESTOP;
        this->clearCommand();
        break;
    }
    default:
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
}

void State_ScriptExecution::Update()
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
            //the part is still being cut
            break;
        }
        case 1:
        {
            //the part is finished being cut
            CommandExecuteProfile* command = new CommandExecuteProfile(ProfileType::HOMING,"home");
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

void State_ScriptExecution::OnEnter()
{
    //this shouldn't really happen as how are we supposed to know the the actual profile to execute
    //we therefore are going to do nothing other than change the state back to State_Ready
    desiredState = ECMState::STATE_READY;
}

void State_ScriptExecution::OnEnter(const AbstractCommand* command)
{
    if(command != nullptr)
    {
        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("cutdone");
        Owner().issueGalilAddPollingRequest(request);
        //The command isnt null so we should handle it
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
