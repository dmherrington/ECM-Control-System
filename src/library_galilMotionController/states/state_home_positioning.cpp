#include "state_home_positioning.h"

namespace ECM{
namespace Galil {

State_HomePositioning::State_HomePositioning():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_HOME_POSITIONING;
    this->desiredState = ECMState::STATE_HOME_POSITIONING;
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
        Owner().issueGalilRemovePollingRequest("homest");

        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<State_MotionStop>();
            break;
        }
        case ECMState::STATE_ESTOP:
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

void State_HomePositioning::handleCommand(const AbstractCommand* command)
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

void State_HomePositioning::Update()
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
    if(Owner().statusVariableValues->getVariableValue("homest",varValue))
    {
        switch ((int)varValue) {
        case 0:
        {
            processFlag = true;
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
            if(processFlag)
            {
                Owner().setHomeInidcated(true);
                //a home position has been found
                ProfileState_Homing newState("Homing Routine", "homest");
                newState.setCurrentCode(ProfileState_Homing::HOMINGProfileCodes::COMPLETE);
                MotionProfileState newProfileState;
                newProfileState.setProfileState(std::make_shared<ProfileState_Homing>(newState));
                Owner().issueUpdatedMotionProfileState(newProfileState);
            }
            break;
        }
        default:
            //there is a case condition that does not follow the flow chart
            break;
        }
    }
}

void State_HomePositioning::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_HOME_POSITIONING));
    //this shouldn't really happen as how are we supposed to know the actual home position command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

void State_HomePositioning::OnEnter(const AbstractCommand* command)
{
    this->processFlag = false;

    Owner().setHomeInidcated(false);

    if(command != nullptr)
    {
        Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_HOME_POSITIONING));
        Request_TellVariablePtr request = std::make_shared<Request_TellVariable>("Home Status","homest");
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
