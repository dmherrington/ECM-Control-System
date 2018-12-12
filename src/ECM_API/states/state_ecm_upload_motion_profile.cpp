#include "state_ecm_upload_motion_profile.h"

namespace ECM{
namespace API {

ECMState_UploadMotionProfile::ECMState_UploadMotionProfile():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_MOTION_PROFILE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
}

void ECMState_UploadMotionProfile::OnExit()
{
    Owner().m_Galil->RemoveHost(this);
}

AbstractStateECMProcess* ECMState_UploadMotionProfile::getClone() const
{
    return (new ECMState_UploadMotionProfile(*this));
}

void ECMState_UploadMotionProfile::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadMotionProfile(*this);
}

hsm::Transition ECMState_UploadMotionProfile::GetTransition()
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
        case ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadMotionVariables>(m_Config);
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadMotionProfile::Update()
{

}

void ECMState_UploadMotionProfile::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadMotionProfile::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = config;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    Owner().m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool &completed, const GalilCurrentProgram &program){
        if(completed)
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
        }else
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        }
    });

    CommandUploadProgramPtr cmdProgram = std::make_shared<CommandUploadProgram>();
    cmdProgram->setCurrentScript(config.m_GalilOperation.getProgram());

    Owner().m_Galil->executeCommand(cmdProgram);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_motion_variables.h"
#include "states/state_ecm_upload_failed.h"
