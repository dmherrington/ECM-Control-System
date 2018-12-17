#include "state_ecm_profile_machine.h"

namespace ECM{
namespace API {

ECMState_ProfileMachine::ECMState_ProfileMachine():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE;
}

void ECMState_ProfileMachine::OnExit()
{

}

void ECMState_ProfileMachine::stopProcess()
{
    ECM::API::AbstractStateECMProcess* currentInnerState = static_cast<ECM::API::AbstractStateECMProcess*>(this->GetImmediateInnerState());
    currentInnerState->stopProcess();
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
        if(IsInInnerState<ECMState_ProfileMachineFailed>())
        {
            this->m_ECMCollection.establishEndTime();
            Owner().concludeExecutingCollection(this->m_ECMCollection);

            //if we have failed we can completely stop the machining process
            rtn = hsm::SiblingTransition<ECMState_Idle>();
        }
        else if(IsInInnerState<ECMState_ProfileMachineComplete>())
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileHandling>(this->m_ECMCollection);
        }
        else
        {
            switch (desiredState) {
            case ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS:
            {
                rtn = hsm::InnerEntryTransition<ECMState_ProfileMachineProcess>(m_ECMCollection.getActiveConfiguration());
                break;
            }
            case ECMState::STATE_ECM_PROFILE_MACHINE_PAUSED:
            {
                rtn = hsm::InnerEntryTransition<ECMState_ProfileMachinePause>(m_ECMCollection.getActiveConfiguration());
                break;
            }
            default:
                break;
            }
        }
        }

    return rtn;
}

void ECMState_ProfileMachine::Update()
{

}

void ECMState_ProfileMachine::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_ProfileMachine::OnEnter(const ECMCommand_ExecuteCollection &collection)
{
    //First update the configuation per what was received upon entering the state
    this->m_ECMCollection = collection;

    //Notify the world what state we are currently in
    AbstractStateECMProcess::notifyOwnerStateTransition();

    ECMCommand_AbstractProfileConfigPtr currentConfig = this->m_ECMCollection.getActiveConfiguration();

    switch (currentConfig->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        Owner().beginLoggingOperationalData(ProfileOpType::OPERATION);
        this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
        break;
    }
    case ProfileOpType::PAUSE:
    {
        Owner().beginLoggingOperationalData(ProfileOpType::PAUSE);
        this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_PAUSED;
        break;
    }
    default:
        break;
    }

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"

#include "states/state_ecm_profile_handling.h"

#include "states/state_ecm_profile_machine_complete_execution.h"
#include "states/state_ecm_profile_machine_complete.h"
#include "states/state_ecm_profile_machine_failed.h"
#include "states/state_ecm_profile_machine_pause.h"
#include "states/state_ecm_profile_machine_process.h"
