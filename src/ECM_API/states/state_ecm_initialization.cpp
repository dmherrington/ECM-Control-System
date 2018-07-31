#include "state_ecm_initialization.h"

namespace ECM{
namespace API {

ECMState_Initialization::ECMState_Initialization():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_INITIALIZATION;
    this->desiredState = ECMState::STATE_ECM_INITIALIZATION;
}

AbstractStateECMProcess* ECMState_Initialization::getClone() const
{
    return (new ECMState_Setup(*this));
}

void ECMState_Initialization::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Setup(*this);
}

hsm::Transition ECMState_Initialization::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        switch (desiredState) {
        case ECMState::STATE_ECM_POWERSUPPLY_SETUP:
        {
            rtn = hsm::SiblingTransition<ECMState_PowerSupplySetup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }
    return rtn;
}

void ECMState_Initialization::Update()
{

}

void ECMState_Initialization::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_power_supply_setup.h"
