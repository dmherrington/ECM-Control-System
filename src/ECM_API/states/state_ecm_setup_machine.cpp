#include "state_ecm_setup_machine.h"

namespace ECM{
namespace API {

ECMState_SetupMachine::ECMState_SetupMachine():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE;
}

void ECMState_SetupMachine::OnExit()
{

}

void ECMState_SetupMachine::stopProcess()
{
    ECM::API::AbstractStateECMProcess* currentInnerState = static_cast<ECM::API::AbstractStateECMProcess*>(this->GetImmediateInnerState());
    currentInnerState->stopProcess();
}

AbstractStateECMProcess* ECMState_SetupMachine::getClone() const
{
    return (new ECMState_SetupMachine(*this));
}

void ECMState_SetupMachine::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachine(*this);
}

hsm::Transition ECMState_SetupMachine::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        if(IsInInnerState<ECMState_SetupMachineComplete>())
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachine>(this->m_ECMCollection);
        }
        else if(IsInInnerState<ECMState_SetupMachineFailed>())
        {

            ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration(); //find the current configuration we had been working on
            activeConfiguration->m_ExecProperties.completeExecution();
            Owner().concludeExecutingOperation(activeConfiguration);

            this->m_ECMCollection->establishEndTime();
            Owner().concludeExecutingCollection(this->m_ECMCollection);

            rtn = hsm::SiblingTransition<ECMState_Idle>();
        }
        else
        {
            ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();
            switch (activeConfiguration->getConfigType()) {
            case ProfileOpType::OPERATION:
            {
                switch (desiredState) {
                case ECMState::STATE_ECM_SETUP_MACHINE_HOME:
                {
                    rtn = hsm::InnerEntryTransition<ECMState_SetupMachineHome>(activeConfiguration);
                    break;
                }
                default:
                    std::cout<<"I dont know how we eneded up in this transition from within ECMState_SetupMachine with a OPERATION configuration."<<std::endl;
                    break;
                }

                break;
            }
            case ProfileOpType::PAUSE:
            {
                switch (desiredState) {
                case ECMState::STATE_ECM_SETUP_MACHINE_PUMP:
                {
                    rtn = hsm::InnerEntryTransition<ECMState_SetupMachinePump>(activeConfiguration);
                    break;
                }
                default:
                    std::cout<<"I dont know how we eneded up in this transition from within ECMState_SetupMachine with a PAUSE configuration."<<std::endl;
                    break;
                }
            }
            default:
                break;
            }
        }
    }

    return rtn;
}

void ECMState_SetupMachine::Update()
{

}

void ECMState_SetupMachine::OnEnter()
{

}

void ECMState_SetupMachine::OnEnter(ECMCommand_ExecuteCollectionPtr collection)
{
    this->m_ECMCollection = collection;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    ECMCommand_AbstractProfileConfigPtr currentConfig = this->m_ECMCollection->getActiveConfiguration();

    switch (currentConfig->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_HOME;
        break;
    }
    case ProfileOpType::PAUSE:
    {
        this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
        break;
    }
    default:
        break;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_complete.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_home.h"
#include "states/state_ecm_setup_machine_pump.h"
#include "states/state_ecm_setup_machine_touchoff.h"

#include "states/state_ecm_profile_machine.h"
