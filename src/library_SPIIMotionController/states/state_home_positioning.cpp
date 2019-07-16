#include "state_home_positioning.h"

namespace ECM{
namespace SPII {

State_HomePositioning::State_HomePositioning():
    AbstractStateSPII()
{
    std::cout<<"In constructor of STATE_HOME_POSITIONING"<<std::endl;
    this->currentState = SPIIState::STATE_HOME_POSITIONING;
    this->desiredState = SPIIState::STATE_HOME_POSITIONING;
}

void State_HomePositioning::OnExit()
{
    Owner().m_MasterVariableValues->removeVariableNotifier("operationStatus",this);

    //Ken we need to remove the polling measurements here
    for(size_t i = 0; i < currentScriptRequests.size(); i++)
    {
        Owner().issueSPIIRemovePollingRequest(currentScriptRequests.at(i));
    }
}

AbstractStateSPII* State_HomePositioning::getClone() const
{
    return (new State_HomePositioning(*this));
}

void State_HomePositioning::getClone(AbstractStateSPII** state) const
{
    *state = new State_HomePositioning(*this);
}

hsm::Transition State_HomePositioning::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case SPIIState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<State_Ready>();
            break;
        }
        case SPIIState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case SPIIState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<State_EStop>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from State_HomePositioning."<<std::endl;
            break;
        }
    }

    return rtn;
}

void State_HomePositioning::handleCommand(const AbstractCommandPtr command)
{
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition

    switch (command->getCommandType()) {
    case CommandType::EXECUTE_PROGRAM:
    {
        if(!this->homeExecuting)
        {
            this->homeExecuting = true;
            CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
            Owner().issueSPIIMotionCommand(castCommand);
        }
        break;
    }
    case CommandType::STOP:
    {
        ProfileState_Homing newState("Home Positioning", scriptProfileName, ProfileState_Homing::ProfileType::MOVE_TO_HOME);
        newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
        desiredState = SPIIState::STATE_MOTION_STOP;

        //Owner().issueUpdatedMotionProfileState(newProfileState);
        break;
    }
    case CommandType::ESTOP:
    {
        ProfileState_Homing newState("Home Positioning", scriptProfileName, ProfileState_Homing::ProfileType::MOVE_TO_HOME);
        newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
        desiredState = SPIIState::STATE_ESTOP;

        //Owner().issueUpdatedMotionProfileState(newProfileState);
        break;
    }
    default:
        std::cout<<"The current command: "<<CommandToString(command->getCommandType())<<" is not available while SPII is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
}

void State_HomePositioning::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = SPIIState::STATE_ESTOP;
    }
}

void State_HomePositioning::OnEnter()
{
    Owner().issueNewSPIIState(SPIIState::STATE_HOME_POSITIONING);
    //this shouldn't really happen as how are we supposed to know the actual home position command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = SPIIState::STATE_READY;
}

void State_HomePositioning::OnEnter(const AbstractCommandPtr command)
{
    if((command != nullptr) && (command.get()->getCommandType()==CommandType::EXECUTE_PROGRAM))
    {
        Status_VariableValue resetOperationStatus;
        Owner().m_MasterVariableValues->getVariable("operationStatus",resetOperationStatus);
        resetOperationStatus.setVariableValue(0);
        Owner().m_MasterVariableValues->updateVariable(resetOperationStatus);

        CommandExecuteProfilePtr castCommand = std::make_shared<CommandExecuteProfile>(*command->as<CommandExecuteProfile>());
        QString profileName = QString::fromStdString(castCommand->getProfileName());
        this->scriptProfileName = profileName.toStdString();

        Owner().issueNewSPIIState(SPIIState::STATE_HOME_POSITIONING);

        Request_TellVariablePtr requestHoming = std::make_shared<Request_TellVariable>("Home Positioning Complete","operationStatus");
        common::TupleProfileVariableString tupleVariableHOMING("",profileName,"operationStatus");
        requestHoming->setTupleDescription(tupleVariableHOMING);
        Owner().issueSPIIAddPollingRequest(requestHoming, 100);
        currentScriptRequests.push_back(tupleVariableHOMING);

        Owner().m_MasterVariableValues->addVariableNotifier("operationStatus",this,[this]
        {
            double varValue = 0.0;
            bool valid = Owner().m_MasterVariableValues->getVariableValue("operationStatus",varValue);
            UNUSED(valid);

            switch (static_cast<ProfileState_Homing::HOMINGProfileCodes>(varValue)) {
            case ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE:
            {
                //the part is still being cut
                ProfileState_Homing newState("Home Positioning", scriptProfileName, ProfileState_Homing::ProfileType::MOVE_TO_HOME);
                newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE);
                Owner().issueUpdatedHomePositioning(newState);

                MotionProfileState newProfileState;
                newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
                Owner().issueUpdatedMotionProfileState(newProfileState);
                break;
            }
            case ProfileState_Homing::HOMINGProfileCodes::COMPLETE:
            {
                //the part is finished being cut
                ProfileState_Homing newState("Home Positioning", scriptProfileName, ProfileState_Homing::ProfileType::MOVE_TO_HOME);
                newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::COMPLETE);
                Owner().issueUpdatedHomePositioning(newState);

                MotionProfileState newProfileState;
                newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
                desiredState = SPIIState::STATE_READY;
                Owner().issueUpdatedMotionProfileState(newProfileState);

                break;
            }
            default:
                //there is a case condition that does not follow the flow chart
                break;
            }
        });

        //The command isnt null so we should handle it
        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

} //end of namespace SPII
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
