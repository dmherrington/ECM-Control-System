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
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }
    return rtn;
}

void ECMState_MachineSetup::Update()
{

}

void ECMState_MachineSetup::OnExit()
{

}

void ECMState_MachineSetup::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ready.h"
#include "states/state_motion_stop.h"
#include "states/state_estop.h"
