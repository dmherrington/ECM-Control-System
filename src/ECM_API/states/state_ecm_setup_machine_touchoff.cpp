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
    Owner().m_Galil->RemoveHost(this);
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
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffDisconnect>(this->m_Config);
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
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoff::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    if(configuration.m_Touchoff.shouldTouchoffBeUtilized())
    {
        /*
         * First, lets setup the necessary touchoff ref and gap variables per the configuration
         */
        Command_VariablePtr commandTouchRef = nullptr;

        if(configuration.m_Touchoff.shouldTouchoffUtilizePreviousPosition())
        {
            int currentPosition = Owner().m_Galil->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
            commandTouchRef = std::make_shared<Command_Variable>("touchref",currentPosition);
        }
        else{
            commandTouchRef = std::make_shared<Command_Variable>(configuration.m_Touchoff.getTouchoffRefCommand());
        }
        Command_VariablePtr commandTouchGap = std::make_shared<Command_Variable>(configuration.m_Touchoff.getTouchoffGapCommand());

        Owner().m_Galil->executeCommand(commandTouchRef);
        Owner().m_Galil->executeCommand(commandTouchGap);


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
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT;
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

        CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"touchof");
        Owner().m_Galil->executeCommand(commandTouchoffExecute);
    }
    else{
        desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_disconnect.h"
#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_failed.h"
#include "states/state_ecm_setup_machine_pump.h"
