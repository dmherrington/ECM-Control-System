#include "state_ecm_setup_machine_home.h"

namespace ECM{
namespace API {

ECMState_SetupMachineHome::ECMState_SetupMachineHome():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_HOME."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_HOME;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_HOME;
}

void ECMState_SetupMachineHome::OnExit()
{

}

AbstractStateECMProcess* ECMState_SetupMachineHome::getClone() const
{
    return (new ECMState_SetupMachineHome(*this));
}

void ECMState_SetupMachineHome::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineHome(*this);
}

hsm::Transition ECMState_SetupMachineHome::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoff>(this->m_Config);
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineHome::Update()
{

}

void ECMState_SetupMachineHome::OnEnter()
{

}

void ECMState_SetupMachineHome::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    if(configuration.shouldHomeBeIndicated())
    {
        Owner().m_Galil->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

            switch (profileState.getProfileState()->getType()) {

            case MotionProfile::ProfileType::HOMING:
            {
                ProfileState_Homing* castState = (ProfileState_Homing*)profileState.getProfileState().get();
                switch (castState->getCurrentCode()) {
                case ProfileState_Homing::HOMINGProfileCodes::COMPLETE:
                {
                    //we have therefore finished indicating the home position
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
                    break;
                }
                case ProfileState_Homing::HOMINGProfileCodes::INCOMPLETE:
                {
                    //this seems strange that an incomplete would cause this, need more finite defintion
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
                    break;
                }
                default:
                    break;
                }
            }
            default:
                break;
            }
        }); //end of lambda expression
    } //end of if statement
    else{

    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_touchoff.h"
