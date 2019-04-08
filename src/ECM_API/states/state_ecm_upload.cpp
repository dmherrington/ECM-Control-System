#include "state_ecm_upload.h"

namespace ECM{
namespace API {

ECMState_Upload::ECMState_Upload():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD;
    this->desiredState = ECMState::STATE_ECM_UPLOAD;
}

void ECMState_Upload::OnExit()
{

}

void ECMState_Upload::stopProcess()
{
    desiredState = ECMState::STATE_ECM_IDLE;
}

AbstractStateECMProcess* ECMState_Upload::getClone() const
{
    return (new ECMState_Upload(*this));
}

void ECMState_Upload::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Upload(*this);
}

hsm::Transition ECMState_Upload::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        if(IsInInnerState<ECMState_UploadComplete>())
        {
            std::cout<<"The upload state sees that all of the uploads are complete"<<std::endl;

            ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();
            if(activeConfiguration->getConfigType() == ProfileOpType::OPERATION)
                Owner().logCurrentOperationalSettings();

            rtn = hsm::SiblingTransition<ECMState_SetupMachine>(this->m_ECMCollection);
        }
        else if(IsInInnerState<ECMState_UploadFailed>())
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
            switch (desiredState) {
            case ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE:
            {
                ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();
                ECMCommand_ProfileConfigurationPtr castConfiguration = static_pointer_cast<ECMCommand_ProfileConfiguration>(activeConfiguration);
                rtn = hsm::InnerEntryTransition<ECMState_UploadMotionProfile>(castConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES:
            {
                ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();
                ECMCommand_ProfileConfigurationPtr castConfiguration = static_pointer_cast<ECMCommand_ProfileConfiguration>(activeConfiguration);
                rtn = hsm::InnerEntryTransition<ECMState_UploadMotionVariables>(castConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS:
            {
                ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();
                ECMCommand_ProfilePausePtr castConfiguration = static_pointer_cast<ECMCommand_ProfilePause>(activeConfiguration);
                rtn = hsm::InnerEntryTransition<ECMState_UploadPumpParameters>(castConfiguration);
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition from within ECMState_Upload."<<std::endl;
                break;
            }
        }
    }

    return rtn;
}

void ECMState_Upload::Update()
{

}

void ECMState_Upload::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    //If we entered this state and received nothing, we should assume it is a failure.
    this->desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
}

void ECMState_Upload::OnEnter(ECMCommand_ExecuteCollectionPtr collection)
{
    //First update the configuation per what was received upon entering the state
    this->m_ECMCollection = collection;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    ECMCommand_AbstractProfileConfigPtr activeConfiguration = m_ECMCollection->getActiveConfiguration();

    switch (activeConfiguration->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        /*
         * We should only transition to the upload motion profile state if the
         * profile is the first in the queue and we desire to upload the script.
         * Otherwise, we should set the appropriate variables related to the
         * motion profile.
         */
        if(this->m_ECMCollection->isFirstOperation(this->m_ECMCollection->getActiveIndex()) && this->m_ECMCollection->shouldWriteMotionScript())
        {
            this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
        }
        else{
            this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
        }

        break;
    }
    case ProfileOpType::PAUSE:
    {
        this->desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
        break;
    }
    default:
        std::cout<<"This profile type is not handled in STATE_ECM_UPLOAD."<<std::endl;
        break;
    }
}

} //end of namespace API
} //end of namespace ECM


#include "states/state_ecm_idle.h"

#include "states/state_ecm_setup_machine.h"

#include "states/state_ecm_upload_complete.h"
#include "states/state_ecm_upload_failed.h"
#include "states/state_ecm_upload_motion_profile.h"
#include "states/state_ecm_upload_motion_variables.h"
#include "states/state_ecm_upload_pump_parameters.h"
