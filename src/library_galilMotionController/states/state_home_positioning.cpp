#include "state_home_positioning.h"

namespace ECM{
namespace Galil {

State_HomePositioning::State_HomePositioning():
    AbstractStateGalil()
{
    std::cout<<"In constructor of STATE_HOME_POSITIONING"<<std::endl;
    this->currentState = GalilState::STATE_HOME_POSITIONING;
    this->desiredState = GalilState::STATE_HOME_POSITIONING;
}

void State_HomePositioning::OnExit()
{
    Owner().statusVariableValues->removeVariableNotifier("homest",this);

    common::TupleProfileVariableString tupleVariable("Default","Homing","homest");
    Owner().issueGalilRemovePollingRequest(tupleVariable);
}

AbstractStateGalil* State_HomePositioning::getClone() const
{
    return (new State_HomePositioning(*this));
}

void State_HomePositioning::getClone(AbstractStateGalil** state) const
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
        case GalilState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<State_Ready>();
            break;
        }
        case GalilState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case GalilState::STATE_ESTOP:
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
    //const AbstractCommand* copyCommand = command->getClone(); //we first make a local copy so that we can manage the memory
    this->clearCommand(); //this way we have cleaned up the old pointer in the event we came here from a transition
    //CommandType currentCommand = copyCommand->getCommandType();

    switch (command->getCommandType()) {
    case CommandType::EXECUTE_PROGRAM:
    {
        if(!this->homeExecuting)
        {
            this->homeExecuting = true;
            Owner().statusVariableValues->addVariableNotifier("homest",this,[this]{
                double varValue = 0.0;
                bool valid = Owner().statusVariableValues->getVariableValue("homest",varValue);
                if(!valid)
                {
                    std::cout<<"The variable homest does not exist and therefore we do not know how to handle this case."<<std::endl;
                    desiredState = GalilState::STATE_MOTION_STOP;
                    return;
                }

                switch ((int)varValue) {
                case 0:
                {
                    //continue searching for home
                    ProfileState_Homing newState("Homing Routine", "homest");
                    newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE);
                    MotionProfileState newProfileState;
                    newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
                    Owner().issueUpdatedMotionProfileState(newProfileState);
                    break;
                }
                case 1:
                {
                    Owner().setHomeInidcated(true);
                    //a home position has been found
                    ProfileState_Homing newState("Homing Routine", "homest");
                    newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::COMPLETE);
                    MotionProfileState newProfileState;
                    newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
                    desiredState = GalilState::STATE_READY;
                    Owner().issueUpdatedMotionProfileState(newProfileState);
                    break;
                }
                } //end of switch statement
            });
            Owner().issueGalilCommand(command); //this will not be considered a motion command as the profile contains the BG parameters
        }
        break;
    }
    case CommandType::STOP:
    {
        desiredState = GalilState::STATE_MOTION_STOP;
        //delete copyCommand;
        break;
    }
    case CommandType::ESTOP:
    {
        desiredState = GalilState::STATE_ESTOP;
        //delete copyCommand;
        break;
    }
    default:
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
        desiredState = GalilState::STATE_ESTOP;
    }
}

void State_HomePositioning::OnEnter()
{
    Owner().issueNewGalilState(GalilState::STATE_HOME_POSITIONING);
    //this shouldn't really happen as how are we supposed to know the actual home position command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = GalilState::STATE_READY;
}

void State_HomePositioning::OnEnter(const AbstractCommandPtr command)
{
    Owner().setHomeInidcated(false);

    if(command != nullptr)
    {
        Owner().issueNewGalilState(GalilState::STATE_HOME_POSITIONING);
        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("Home Status","homest");
        common::TupleProfileVariableString tupleVariable("Default","Homing","homest");
        request->setTupleDescription(tupleVariable);
        Owner().issueGalilAddPollingRequest(request,1000);

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
