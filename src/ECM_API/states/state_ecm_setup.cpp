#include "state_ecm_setup.h"

namespace ECM{
namespace API {

ECMState_Setup::ECMState_Setup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::State;
    this->desiredState = ECMState::STATE_ESTOP;
}

AbstractStateECMProcess* ECMState_Setup::getClone() const
{
    return (new ECMState_Setup(*this));
}

void ECMState_Setup::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Setup(*this);
}

hsm::Transition ECMState_Setup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Touchoff>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from State_EStop."<<std::endl;
            break;
        }
    }
    return rtn;
}

void ECMState_Setup::Update()
{
    //Check the status of the estop state
    if(!this->checkEStop())
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_IDLE;
    }
}

void ECMState_Setup::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_ESTOP));
    //First check to see if the motor is already disarmed, and if not, disarm it
    if(Owner().isMotorEnabled())
    {
        //If the motor is not currently armed, issue the command to arm it
        CommandMotorDisablePtr command = std::make_shared<CommandMotorDisable>();
        Owner().issueGalilCommand(command);
    }
    //Lastly, send a command to make sure the airbrake has been engaged
    CommandSetBitPtr command = std::make_shared<CommandSetBit>();
    command->appendAddress(2); //Ken: be careful in the event that this changes. This should be handled by settings or something
    Owner().issueGalilCommand(command);
}


} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
