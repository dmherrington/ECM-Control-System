#include "state_ecm_power_supply_setup.h"

namespace ECM{
namespace API {

ECMState_PowerSupplySetup::ECMState_PowerSupplySetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_POWERSUPPLY_SETUP;
    this->desiredState = ECMState::STATE_ECM_POWERSUPPLY_SETUP;
}

void ECMState_PowerSupplySetup::OnExit()
{
    Owner().statusVariableValues->removeVariableNotifier("homest",this);
}

AbstractStateECMProcess* ECMState_PowerSupplySetup::getClone() const
{
    return (new ECMState_PowerSupplySetup(*this));
}

void ECMState_PowerSupplySetup::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_PowerSupplySetup(*this);
}

hsm::Transition ECMState_PowerSupplySetup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //        Owner().issueGalilRemovePollingRequest("homest"); This should be completed onExit

        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            rtn = hsm::SiblingTransition<ECMState_PumpSetup>();
            break;
        }
        case ECMState::STATE_MOTION_STOP:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffDisable>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from State_HomePositioning."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_PowerSupplySetup::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
}

void ECMState_PowerSupplySetup::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_HOME_POSITIONING));
    //this shouldn't really happen as how are we supposed to know the actual home position command
    //we therefore are going to do nothing other than change the state back to State_Ready
    this->desiredState = ECMState::STATE_READY;
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
