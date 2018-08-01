#include "state_script_execution.h"

namespace ECM{
namespace Galil {

State_ScriptExecution::State_ScriptExecution():
    AbstractStateGalil()
{
    this->currentState = GalilState::STATE_SCRIPT_EXECUTION;
    this->desiredState = GalilState::STATE_SCRIPT_EXECUTION;
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
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case GalilState::STATE_READY:
        {
            return hsm::SiblingTransition<State_Ready>();
            break;
        }
        case GalilState::STATE_MOTION_STOP:
        {
            return hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case GalilState::STATE_ESTOP:
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
        desiredState = GalilState::STATE_MOTION_STOP;
        this->clearCommand();
        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = GalilState::STATE_ESTOP;
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
        desiredState = GalilState::STATE_ESTOP;
    }
}

void State_ScriptExecution::OnExit()
{
    //Ken we need to remove the polling measurements here
    Request_TellVariable requestPosition("Bottom Position","ppos");
    Owner().issueGalilRemovePollingRequest(requestPosition.getTupleDescription());
    Request_TellVariable requestCutting("Machining Complete","cutdone");
    Owner().issueGalilRemovePollingRequest(requestCutting.getTupleDescription());

    Owner().statusVariableValues->removeVariableNotifier("ppos",this);
    Owner().statusVariableValues->removeVariableNotifier("cutdone",this);
}

void State_ScriptExecution::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(GalilState::STATE_SCRIPT_EXECUTION));
    //this shouldn't really happen as how are we supposed to know the the actual profile to execute
    //we therefore are going to do nothing other than change the state back to State_Ready
    desiredState = GalilState::STATE_READY;
}

void State_ScriptExecution::OnEnter(const AbstractCommand* command)
{
    if(command != nullptr)
    {
        Owner().issueNewGalilState(ECMStateToString(GalilState::STATE_SCRIPT_EXECUTION));

        Request_TellVariablePtr requestPosition = std::make_shared<Request_TellVariable>("Bottom Position","ppos");
        Status_VariableValue newPPOS;
        newPPOS.setVariableName("ppos");
        Owner().statusVariableValues->addVariable(newPPOS);
        Owner().issueGalilAddPollingRequest(requestPosition);

        Request_TellVariablePtr requestCutting = std::make_shared<Request_TellVariable>("Machining Complete","cutdone");
        Status_VariableValue newCUTDONE;
        newCUTDONE.setVariableName("cutdone");
        Owner().statusVariableValues->addVariable(newCUTDONE);
        Owner().issueGalilAddPollingRequest(requestCutting);
        //The command isnt null so we should handle it
        this->handleCommand(command);

        Owner().statusVariableValues->addVariableNotifier("cutdone",this,[this]
        {
            double value = 0;
            Owner().statusVariableValues->getVariableValue("cutdone",value);
            switch ((ProfileState_Machining::MACHININGProfileCodes)value) {
            case ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE:
            {
                //the part is still being cut
                break;
            }
            case ProfileState_Machining::MACHININGProfileCodes::COMPLETE:
            {
                //the part is finished being cut
                CommandExecuteProfile* command = new CommandExecuteProfile(MotionProfile::ProfileType::HOMING,"home");
                this->currentCommand = command;
                desiredState = GalilState::STATE_MOTION_STOP;
                break;
            }
            default:
                //there is a case condition that does not follow the flow chart
                break;
            }
        });
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
