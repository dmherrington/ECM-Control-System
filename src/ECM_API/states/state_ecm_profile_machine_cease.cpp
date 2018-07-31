#include "state_ecm_profile_machine_cease.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineCease::ECMState_ProfileMachineCease():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_CEASE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_CEASE;
}

AbstractStateECMProcess* ECMState_ProfileMachineCease::getClone() const
{
    return (new ECMState_ProfileMachineCease(*this));
}

void ECMState_ProfileMachineCease::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineCease(*this);
}

hsm::Transition ECMState_ProfileMachineCease::GetTransition()
{
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            //return hsm::SiblingTransition<State_Ready>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {

        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }
    else{
        return hsm::NoTransition();
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
