#include "state_ecm_profile_machine.h"

namespace ECM{
namespace API {

ECMState_ProfileMachine::ECMState_ProfileMachine():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE;
}

AbstractStateECMProcess* ECMState_ProfileMachine::getClone() const
{
    return (new ECMState_ProfileMachine(*this));
}

void ECMState_ProfileMachine::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachine(*this);
}

hsm::Transition ECMState_ProfileMachine::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Touchoff>(currentCommand);
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>(currentCommand);
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachine::Update()
{

}

void ECMState_ProfileMachine::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
#include "states/state_estop.h"
