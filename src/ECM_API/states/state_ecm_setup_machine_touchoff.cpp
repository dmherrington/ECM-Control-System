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
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_PUMP:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachinePump>(this->m_Config);
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineTouchoff::Update()
{

}

void ECMState_SetupMachineTouchoff::OnEnter()
{

}

void ECMState_SetupMachineTouchoff::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    if(configuration.m_Touchoff.shouldTouchoffBeUtilized())
    {
        Owner().m_Galil->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

            switch (profileState.getProfileState()->getType()) {
            case MotionProfile::ProfileType::TOUCHOFF:
            {
                ProfileState_Touchoff* castState = (ProfileState_Touchoff*)profileState.getProfileState().get();
                switch (castState->getCurrentCode()) {
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::CLEARED:
                {
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
                    break;
                }
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
                {
                    //there is nothing to do yet as the profile is active
                    break;
                }
                case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
                {
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
                    break;
                }
                default:
                    break;
                }
                break;
            }
            default:
                break;
            }
        });
    }
    else{

    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_pump.h"
