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
    Owner().m_MotionController->RemoveHost(this);
}

void ECMState_SetupMachineHome::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
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
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_SetupMachineHome::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    //check that we should indicate home and it has not previously completed
    if(this->m_Config->shouldHomeBeIndicated() && !Owner().m_MotionController->m_StateInterface->isHomeInidcated())
    {
        //at this time the homing sequence is no longer valid this check will persist in case it is desired in the future
        /*
        Owner().m_MotionController->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

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
                    //desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
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

        CommandExecuteProfilePtr command = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::HOMING,"latch");
        Owner().m_MotionController->executeCommand(command);
        */
        desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;

    } //end of if statement
    else{
        //the home function did not need to be executed at this time, therefore, we can move on to touchoff
        desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_touchoff.h"
