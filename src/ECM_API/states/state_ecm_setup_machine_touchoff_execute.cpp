#include "state_ecm_setup_machine_touchoff_execute.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffExecute::ECMState_SetupMachineTouchoffExecute():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE;
}

void ECMState_SetupMachineTouchoffExecute::OnExit()
{
    Owner().m_MotionController->RemoveHost(this);
}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffExecute::getClone() const
{
    return (new ECMState_SetupMachineTouchoffExecute(*this));
}

void ECMState_SetupMachineTouchoffExecute::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffExecute(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffExecute::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_DISCONNECT:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffDisconnect>();
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineTouchoffExecute::Update()
{

}

void ECMState_SetupMachineTouchoffExecute::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoffExecute::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (this->m_Config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(this->m_Config);


        /*
         * First, lets setup the necessary touchoff ref and gap variables per the configuration
         */
        Command_VariableArrayPtr commandTouchRef = nullptr;

        if(castConfig->m_Touchoff.shouldTouchoffUtilizePreviousPosition())
        {
            std::vector<double> axisPosition = Owner().m_MotionController->m_StateInterface->m_AxisPosition->getAxisPositionVector();
            commandTouchRef = std::make_shared<Command_Variable>("", axisPosition);
        }
        else{
            commandTouchRef = std::make_shared<Command_Variable>(castConfig->m_Touchoff.getTouchoffRefCommand());
        }
        Command_VariableArrayPtr commandTouchGap = std::make_shared<Command_VariableArray>(castConfig->m_Touchoff.getTouchoffGapCommand());

        Owner().m_MotionController->executeCommand(commandTouchRef);
        Owner().m_MotionController->executeCommand(commandTouchGap);

        Owner().m_MotionController->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

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

        CommandExecuteProfilePtr commandTouchoffExecute = std::make_shared<CommandExecuteProfile>(MotionProfile::ProfileType::TOUCHOFF,"TOUCHOFF");
        Owner().m_MotionController->executeCommand(commandTouchoffExecute);
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_UPLOAD_MOTION_PROFILE with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
        break;
    }
}

void ECMState_SetupMachineTouchoffExecute::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_failed.h"
#include "states/state_ecm_setup_machine_touchoff_disconnect.h"
