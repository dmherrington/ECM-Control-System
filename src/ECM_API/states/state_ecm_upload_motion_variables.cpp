#include "state_ecm_upload_motion_variables.h"

namespace ECM{
namespace API {

ECMState_UploadMotionVariables::ECMState_UploadMotionVariables():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_MOTION_VARIABLES."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
}

void ECMState_UploadMotionVariables::OnExit()
{
    Owner().m_MotionController->RemoveHost(this);
}

void ECMState_UploadMotionVariables::stopProcess()
{
    desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
}

AbstractStateECMProcess* ECMState_UploadMotionVariables::getClone() const
{
    return (new ECMState_UploadMotionVariables(*this));
}

void ECMState_UploadMotionVariables::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadMotionVariables(*this);
}

hsm::Transition ECMState_UploadMotionVariables::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_ECM_UPLOAD_FAILED:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadFailed>();
            break;
        }
        case ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPowerRegisterSegments>(this->m_Config);
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadMotionVariables::Update()
{

}

void ECMState_UploadMotionVariables::OnEnter()
{

}

void ECMState_UploadMotionVariables::OnEnter(ECMCommand_AbstractProfileConfigPtr config)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = config;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(config);

        Owner().m_MotionController->AddLambda_FinishedUploadingVariables(this,[this](const bool completed, const Operation_VariableList &variableList){
            UNUSED(variableList);

            if(completed)
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS;
            }else
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
            }

        });
        Command_UploadOperationalVariablesPtr cmdProgram = std::make_shared<Command_UploadOperationalVariables>();
        cmdProgram->setOperationalVariables(castConfig->m_DesiredProgram.getCurrentUserVariables());
        Owner().m_MotionController->executeCommand(cmdProgram);

        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_UPLOAD_MOTION_VARIABLES with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        break;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_power_register_segments.h"
#include "states/state_ecm_upload_failed.h"
