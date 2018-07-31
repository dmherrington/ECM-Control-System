#include "state_ecm_pump_setup.h"

namespace ECM{
namespace API {

ECMState_PumpSetup::ECMState_PumpSetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PUMP_SETUP;
    this->desiredState = ECMState::STATE_ECM_PUMP_SETUP;
}

AbstractStateGalil* ECMState_PumpSetup::getClone() const
{
    return (new ECMState_PumpSetup(*this));
}

void ECMState_PumpSetup::getClone(AbstractStateGalil** state) const
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
        case ECMState::STATE_MANUAL_POSITIONING:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffExecute>(currentCommand);
            break;
        }
        case ECMState::STATE_JOGGING:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffEnable>(currentCommand);
            break;
        }
        case ECMState::STATE_HOME_POSITIONING:
        {
            rtn = hsm::SiblingTransition<ECMState_PowerSupplySetup>(currentCommand);
            break;
        }
        case ECMState::STATE_SCRIPT_EXECUTION:
        {
            rtn = hsm::SiblingTransition<ECMState_MachineSetup>(currentCommand);
            break;
        }
        case ECMState::STATE_TOUCHOFF:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineProcess>(currentCommand);
            break;
        }
        case ECMState::STATE_READY_STOP:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachine>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
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
