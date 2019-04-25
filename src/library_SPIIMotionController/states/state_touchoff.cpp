#include "state_touchoff.h"

namespace ECM{
namespace SPII {

State_Touchoff::State_Touchoff():
    AbstractStateSPII(), touchoffExecuting(false)
{
    this->currentState = SPIIState::STATE_TOUCHOFF;
    this->desiredState = SPIIState::STATE_TOUCHOFF;
}

void State_Touchoff::OnExit()
{
    Owner().m_MasterVariableValues->removeVariableNotifier("touchOffStatus",this);

    common::TupleProfileVariableString tupleVariable("Default","Touchoff","touchOffStatus");
    Owner().issueSPIIRemovePollingRequest(tupleVariable);
}

AbstractStateSPII* State_Touchoff::getClone() const
{
    return (new State_Touchoff(*this));
}

void State_Touchoff::getClone(AbstractStateSPII** state) const
{
    *state = new State_Touchoff(*this);
}

hsm::Transition State_Touchoff::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case SPIIState::STATE_READY:
        {
            return hsm::SiblingTransition<State_Ready>();
            break;
        }
        case SPIIState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>(currentCommand);
            break;
        }
        case SPIIState::STATE_ESTOP:
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

void State_Touchoff::handleCommand(const AbstractCommandPtr command)
{
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::EXECUTE_PROGRAM:
    {
        if(!this->touchoffExecuting)
        {
            this->touchoffExecuting = true;;
            this->stateSetup();
            Owner().issueSPIIMotionCommand(command); //this will not be considered a motion command as the profile contains the BG parameters
        }
        break;
    }
    case CommandType::STOP:
    {
        //we have aborted the touchoff routine
        ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
        newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
        desiredState = SPIIState::STATE_MOTION_STOP;
        Owner().issueUpdatedMotionProfileState(newProfileState);
        //delete copyCommand;
        break;
    }
    case CommandType::ESTOP:
    {
        //we have aborted the touchoff routine
        ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
        newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
        desiredState = SPIIState::STATE_ESTOP;
        Owner().issueUpdatedMotionProfileState(newProfileState);
        //delete copyCommand;
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
        desiredState = SPIIState::STATE_ESTOP;
    }
}

void State_Touchoff::OnEnter()
{
    Owner().issueNewSPIIState(SPIIState::STATE_TOUCHOFF);
    //this shouldn't really happen as how are we supposed to know the actual touchoff command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = SPIIState::STATE_READY;
}

void State_Touchoff::OnEnter(const AbstractCommandPtr command)
{
    if(command != nullptr)
    {
        Owner().issueNewSPIIState(SPIIState::STATE_TOUCHOFF);

        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("Touchoff Status","touchOffStatus");
        common::TupleProfileVariableString tupleVariable("Default","Touchoff","touchOffStatus");
        request->setTupleDescription(tupleVariable);
        Owner().issueSPIIAddPollingRequest(request,500);

        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

void State_Touchoff::stateSetup()
{
    Owner().m_MasterVariableValues->addVariableNotifier("touchOffStatus",this,[this]{
        double varValue = 0.0;
        bool valid = Owner().m_MasterVariableValues->getVariableValue("touchOffStatus",varValue);
        if(!valid)
        {
            std::cout<<"The variable homest does not exist and therefore we do not know how to handle this case."<<std::endl;
            desiredState = SPIIState::STATE_MOTION_STOP;
            return;
        }
        switch ((int)varValue) {
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
        {
            //continue searching for touchoff position
            ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            Owner().issueUpdatedMotionProfileState(newProfileState,false);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
        {

            Owner().setTouchoffIndicated(true);
            //we have finished the touchoff routine
            ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            Owner().issueUpdatedMotionProfileState(newProfileState,false);
            desiredState = SPIIState::STATE_READY;
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        {
            //ERROR: inconsistent or positional limit exceeded
            ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = SPIIState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        {
            //ERROR: inconsistent or positional limit exceeded
            ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = SPIIState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
        {
            //ERROR: already touch part
            ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = SPIIState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        default:
            //there is a case condition that does not follow the flow chart
            std::cout<<"There is another value condition not considered here."<<std::endl;
            desiredState = SPIIState::STATE_MOTION_STOP;
            break;
        } //end of switch statement
    });

    //Issue the current command based on what we are doing
    ProfileState_Touchoff newState("Touchoff Routine", "TOUCHOFF");
    newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING);
    MotionProfileState newProfileState;
    newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
    Owner().issueUpdatedMotionProfileState(newProfileState,false);

}

} //end of namespace SPII
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
