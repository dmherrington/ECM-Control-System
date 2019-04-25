#include "state_ecm_profile_machine_process.h"

namespace ECM{
namespace API {

ECMState_ProfileMachineProcess::ECMState_ProfileMachineProcess():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_PROFILE_MACHINE_PROCESS."<<std::endl;
    this->currentState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_PROCESS;
}

void ECMState_ProfileMachineProcess::OnExit()
{
    Owner().m_MotionController->RemoveHost(this);
}

void ECMState_ProfileMachineProcess::stopProcess()
{
    this->desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
}

AbstractStateECMProcess* ECMState_ProfileMachineProcess::getClone() const
{
    return (new ECMState_ProfileMachineProcess(*this));
}

void ECMState_ProfileMachineProcess::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileMachineProcess(*this);
}

hsm::Transition ECMState_ProfileMachineProcess::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        switch (desiredState) {
        case ECMState::STATE_ECM_PROFILE_MACHINE_ABORT:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineAbort>(this->m_Config);
            break;
        }
        case ECMState::STATE_ECM_PROFILE_MACHINE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineEStop>(this->m_Config);
            break;
        }
        case ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineCompleteExecution>(this->m_Config);
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_ProfileMachineProcess::Update()
{

}

void ECMState_ProfileMachineProcess::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
}

void ECMState_ProfileMachineProcess::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    Owner().beginOperationalProfile(this->m_Config,ExecutionProperties::ExecutionCondition::EXECUTING);

    switch (this->m_Config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(this->m_Config);

        Owner().m_MotionController->AddLambda_AbortExecution(this,[this](){
            desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ESTOP;
        });

        Owner().m_MotionController->AddLambda_NewMotionProfileState(this,[this](const MotionProfileState &profileState){

            switch (profileState.getProfileState()->getType()) {
            case MotionProfile::ProfileType::PROFILE:
            {
                ProfileState_Machining* castState = (ProfileState_Machining*)profileState.getProfileState().get();
                m_Config->m_ExecProperties.setProfileCode(castState->getCurrentCode());

                switch (castState->getCurrentCode()) {
                case(ProfileState_Machining::MACHININGProfileCodes::INCOMPLETE):
                {
                    break;
                }
                case(ProfileState_Machining::MACHININGProfileCodes::COMPLETE):
                {
                    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION;
                    break;
                }
                case(ProfileState_Machining::MACHININGProfileCodes::ABORTED):
                {
                    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
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

        Owner().executeExplicitProfile(castConfig);
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_PROFILE_MACHINE_PROCESS with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
        break;
    }

//    m_Config.execProperties.setProfileCode(ProfileState_Machining::MACHININGProfileCodes::COMPLETE);
//    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_COMPLETE_EXECUTION;
}



} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_profile_machine_abort.h"
#include "states/state_ecm_profile_machine_estop.h"
#include "states/state_ecm_profile_machine_complete_execution.h"
