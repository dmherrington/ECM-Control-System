#include "state_ecm_profile_machine_setup.h"

namespace ECM{
namespace API {

ECMState_MachineSetup::ECMState_MachineSetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_SETUP;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_SETUP;
}

AbstractStateECMProcess* ECMState_MachineSetup::getClone() const
{
    return (new ECMState_MachineSetup(*this));
}

void ECMState_MachineSetup::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_MachineSetup(*this);
}

hsm::Transition ECMState_MachineSetup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_READY:
        {
            return hsm::SiblingTransition<ECMState_PumpSetup>();
            break;
        }
        case ECMState::STATE_MOTION_STOP:
        {
            return hsm::SiblingTransition<ECMState_TouchoffDisable>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state script execution."<<std::endl;
            break;
        }
    }
    return rtn;
}

void ECMState_MachineSetup::Update()
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

void ECMState_MachineSetup::OnExit()
{
    //Ken we need to remove the polling measurements here
    //Owner().issueGalilRemovePollingRequest("ppos");
    Owner().statusVariableValues->removeVariable("ppos");
    //Owner().issueGalilRemovePollingRequest("cutdone");
    Owner().statusVariableValues->removeVariable("cutdone");
}

void ECMState_MachineSetup::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_SCRIPT_EXECUTION));
    //this shouldn't really happen as how are we supposed to know the the actual profile to execute
    //we therefore are going to do nothing other than change the state back to State_Ready
    desiredState = ECMState::STATE_READY;
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
