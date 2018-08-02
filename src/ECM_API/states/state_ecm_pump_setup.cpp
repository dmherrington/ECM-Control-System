#include "state_ecm_pump_setup.h"

namespace ECM{
namespace API {

ECMState_PumpSetup::ECMState_PumpSetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PUMP_SETUP;
    this->desiredState = ECMState::STATE_ECM_PUMP_SETUP;
}

AbstractStateECMProcess* ECMState_PumpSetup::getClone() const
{
    return (new ECMState_PumpSetup(*this));
}

void ECMState_PumpSetup::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_PumpSetup(*this);
}

hsm::Transition ECMState_PumpSetup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from STATE_READY."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_PumpSetup::Update()
{

}

void ECMState_PumpSetup::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_profile_machine.h"
