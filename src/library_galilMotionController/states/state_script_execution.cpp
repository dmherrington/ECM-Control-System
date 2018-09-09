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

void State_ScriptExecution::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::EXECUTE_PROGRAM:
    {
        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
        Owner().issueGalilCommand(castCommand);

        break;
    }
    case CommandType::STOP:
    {
        ProfileState_Machining newState("Machining Profile", scriptProfileName);
        newState.setCurrentCode(ProfileState_Machining::MACHININGProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Machining>(newState));
        Owner().issueUpdatedMotionProfileState(newProfileState);

        desiredState = GalilState::STATE_MOTION_STOP;

        break;
    }
    case CommandType::ESTOP:
    {
        ProfileState_Machining newState("Machining Profile", scriptProfileName);
        newState.setCurrentCode(ProfileState_Machining::MACHININGProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Machining>(newState));
        Owner().issueUpdatedMotionProfileState(newProfileState);

        desiredState = GalilState::STATE_ESTOP;

        break;
    }
    default:
        std::cout<<"The current command: "<<CommandToString(command->getCommandType())<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
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
    Owner().statusVariableValues->removeVariableNotifier("ppos",this);
    Owner().statusVariableValues->removeVariableNotifier("cutdone",this);

    //Ken we need to remove the polling measurements here
    for(size_t i = 0; i < currentScriptRequests.size(); i++)
    {
        Owner().issueGalilRemovePollingRequest(currentScriptRequests.at(i));
    }
//    common::TupleProfileVariableString tupleVariablePPOS("Default","Profile","ppos");
//    Owner().issueGalilRemovePollingRequest(tupleVariablePPOS);
//    common::TupleProfileVariableString tupleVariableCUTTING("Default","Profile","cutdone");
//    Owner().issueGalilRemovePollingRequest(tupleVariableCUTTING);
}

void State_ScriptExecution::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_SCRIPT_EXECUTION);
    //this shouldn't really happen as how are we supposed to know the the actual profile to execute
    //we therefore are going to do nothing other than change the state back to State_Ready
    desiredState = GalilState::STATE_READY;
}

void State_ScriptExecution::OnEnter(const AbstractCommandPtr command)
{
    if((command != nullptr) && (command.get()->getCommandType()==CommandType::EXECUTE_PROGRAM))
    {
        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
        QString profileName = QString::fromStdString(castCommand->getProfileName());
        this->scriptProfileName = profileName.toStdString();

        Owner().issueNewGalilState(GalilState::STATE_SCRIPT_EXECUTION);

        Request_TellVariablePtr requestPosition = std::make_shared<Request_TellVariable>("Bottom Position","ppos");
        common::TupleProfileVariableString tupleVariablePPOS("", "", "ppos");
        requestPosition->setTupleDescription(tupleVariablePPOS);
        Owner().issueGalilAddPollingRequest(requestPosition);        
        currentScriptRequests.push_back(tupleVariablePPOS);


        Request_TellVariablePtr requestCutting = std::make_shared<Request_TellVariable>("Machining Complete","cutdone");
        common::TupleProfileVariableString tupleVariableCUTTING("",profileName,"cutdone");
        requestCutting->setTupleDescription(tupleVariableCUTTING);
        Owner().issueGalilAddPollingRequest(requestCutting);
        currentScriptRequests.push_back(tupleVariableCUTTING);

        //The command isnt null so we should handle it
        this->handleCommand(command);

        Owner().statusVariableValues->addVariableNotifier("cutdone",this,[this]
        {
            double varValue = 0.0;
            bool valid = Owner().statusVariableValues->getVariableValue("cutdone",varValue);
            switch ((ProfileState_Machining::MACHININGProfileCodes)varValue) {
            case ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE:
            {
                //the part is still being cut
                ProfileState_Machining newState("Machining Profile", scriptProfileName);
                newState.setCurrentCode(ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE);
                MotionProfileState newProfileState;
                newProfileState.setProfileState(std::make_shared<ProfileState_Machining>(newState));
                Owner().issueUpdatedMotionProfileState(newProfileState);

                break;
            }
            case ProfileState_Machining::MACHININGProfileCodes::COMPLETE:
            {
                //the part is finished being cut
                ProfileState_Machining newState("Machining Profile", scriptProfileName);
                newState.setCurrentCode(ProfileState_Machining::MACHININGProfileCodes::COMPLETE);
                MotionProfileState newProfileState;
                newProfileState.setProfileState(std::make_shared<ProfileState_Machining>(newState));
                Owner().issueUpdatedMotionProfileState(newProfileState);

                desiredState = GalilState::STATE_READY;
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
