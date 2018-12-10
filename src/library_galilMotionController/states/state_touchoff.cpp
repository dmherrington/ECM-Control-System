#include "state_touchoff.h"

namespace ECM{
namespace Galil {

State_Touchoff::State_Touchoff():
    AbstractStateGalil(), touchoffExecuting(false)
{
    this->currentState = GalilState::STATE_TOUCHOFF;
    this->desiredState = GalilState::STATE_TOUCHOFF;
}

void State_Touchoff::OnExit()
{
    Owner().statusVariableValues->removeVariableNotifier("touchst",this);

    common::TupleProfileVariableString tupleVariable("Default","Touchoff","touchst");
    Owner().issueGalilRemovePollingRequest(tupleVariable);
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
        //Owner().issueGalilRemovePollingRequest("touchst"); this should be done onExit

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
            rtn = hsm::SiblingTransition<State_MotionStop>(currentCommand);
            break;
        }
        case GalilState::STATE_ESTOP:
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
            Owner().issueGalilCommand(command); //this will not be considered a motion command as the profile contains the BG parameters
        }
        break;
    }
    case CommandType::STOP:
    {
        //we have aborted the touchoff routine
        ProfileState_Touchoff newState("Touchoff Routine", "touchof");
        newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
        desiredState = GalilState::STATE_MOTION_STOP;
        Owner().issueUpdatedMotionProfileState(newProfileState);
        //delete copyCommand;
        break;
    }
    case CommandType::ESTOP:
    {
        //we have aborted the touchoff routine
        ProfileState_Touchoff newState("Touchoff Routine", "touchof");
        newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED);
        MotionProfileState newProfileState;
        newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
        desiredState = GalilState::STATE_ESTOP;
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
        desiredState = GalilState::STATE_ESTOP;
    }
}

void State_Touchoff::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_TOUCHOFF);
    //this shouldn't really happen as how are we supposed to know the actual touchoff command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = GalilState::STATE_READY;
}

void State_Touchoff::OnEnter(const AbstractCommandPtr command)
{
    if(command != nullptr)
    {
        Owner().issueNewGalilState(GalilState::STATE_TOUCHOFF);
        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("Touchoff Status","touchst");
        common::TupleProfileVariableString tupleVariable("Default","Touchoff","touchst");
        request->setTupleDescription(tupleVariable);
        Owner().issueGalilAddPollingRequest(request,1000);

        this->handleCommand(command);
    }
    else{
        this->OnEnter();
    }
}

void State_Touchoff::stateSetup()
{
    Owner().statusVariableValues->addVariableNotifier("touchst",this,[this]{
        double varValue = 0.0;
        bool valid = Owner().statusVariableValues->getVariableValue("touchst",varValue);
        if(!valid)
        {
            std::cout<<"The variable homest does not exist and therefore we do not know how to handle this case."<<std::endl;
            desiredState = GalilState::STATE_MOTION_STOP;
            return;
        }
        switch ((int)varValue) {
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
        {
            //continue searching for touchoff position
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
        {

            Owner().setTouchoffIndicated(true);
            //we have finished the touchoff routine
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = GalilState::STATE_READY;
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        {
            //ERROR: inconsistent or positional limit exceeded
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = GalilState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        {
            //ERROR: inconsistent or positional limit exceeded
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = GalilState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);

//            CommandAbsoluteMove* command = new CommandAbsoluteMove(MotorAxis::Z,0);
//            this->currentCommand = command;
            break;
        }
        case (int)ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
        {
            //ERROR: already touch part
            ProfileState_Touchoff newState("Touchoff Routine", "touchof");
            newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING);
            MotionProfileState newProfileState;
            newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
            desiredState = GalilState::STATE_MOTION_STOP;
            Owner().issueUpdatedMotionProfileState(newProfileState);

//            CommandAbsoluteMove* command = new CommandAbsoluteMove(MotorAxis::Z,0);
//            this->currentCommand = command;
            break;
        }
        default:
            //there is a case condition that does not follow the flow chart
            std::cout<<"There is another value condition not considered here."<<std::endl;
            break;
        } //end of switch statement
    });

    //Issue the current command based on what we are doing
    ProfileState_Touchoff newState("Touchoff Routine", "touchof");
    newState.setCurrentCode(ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING);
    MotionProfileState newProfileState;
    newProfileState.setProfileState(std::make_shared<ProfileState_Touchoff>(newState));
    Owner().issueUpdatedMotionProfileState(newProfileState);

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
