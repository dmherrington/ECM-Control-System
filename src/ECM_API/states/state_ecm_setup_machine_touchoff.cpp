#include "state_ecm_setup_machine_touchoff.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoff::ECMState_SetupMachineTouchoff():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
}

void ECMState_SetupMachineTouchoff::OnExit()
{

}

void ECMState_SetupMachineTouchoff::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

AbstractStateECMProcess* ECMState_SetupMachineTouchoff::getClone() const
{
    return (new ECMState_SetupMachineTouchoff(*this));
}

void ECMState_SetupMachineTouchoff::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoff(*this);
}

hsm::Transition ECMState_SetupMachineTouchoff::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(IsInInnerState<ECMState_SetupMachineTouchoffCompleted>())
    {
        //rtn = hsm::SiblingTransition<ECMState_SetupMachineComplete>();
        rtn = hsm::SiblingTransition<ECMState_SetupMachinePump>(this->m_Config);
    }
    else if(IsInInnerState<ECMState_SetupMachineTouchoffFailed>())
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
    }
    else{
        if(currentState != desiredState)
        {
            switch (desiredState) {
            case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT:
            {
                rtn = hsm::InnerEntryTransition<ECMState_SetupMachineTouchoffConnect>(this->m_Config);
                break;
            }
            case ECMState::STATE_ECM_SETUP_MACHINE_PUMP:
            {
                rtn = hsm::InnerEntryTransition<ECMState_SetupMachinePump>(this->m_Config);
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
                break;
            }
        }
    }
    return rtn;
}

void ECMState_SetupMachineTouchoff::Update()
{

}

void ECMState_SetupMachineTouchoff::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoff::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (this->m_Config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(this->m_Config);

        if(castConfig->m_Touchoff.shouldTouchoffBeUtilized())
            desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_CONNECT;
        else
            desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_SETUP_MACHINE_TOUCHOFF with the current command type."<<std::endl;
        break;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_connect.h"
#include "states/state_ecm_setup_machine_touchoff_completed.h"
#include "states/state_ecm_setup_machine_touchoff_failed.h"

#include "states/state_ecm_setup_machine_pump.h"
#include "states/state_ecm_setup_machine_complete.h"
#include "states/state_ecm_setup_machine_failed.h"
