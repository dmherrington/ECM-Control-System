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
            rtn = hsm::SiblingTransition<ECMState_SetupMachine>(this->m_ECMCollection);
        }
        else if(IsInInnerState<ECMState_UploadFailed>())
        {
            this->m_ECMCollection.establishEndTime();
            Owner().concludeExecutingCollection(this->m_ECMCollection);
            rtn = hsm::SiblingTransition<ECMState_Idle>();
        }
        else
        {
            ECMCommand_ProfileConfiguration activeConfiguration = m_ECMCollection.getActiveConfiguration();
            //this means we want to chage the state of the vehicle for some reason
            //this could be caused by a command, action sensed by the vehicle, or
            //for various other peripheral reasons
            switch (desiredState) {
            case ECMState::STATE_ECM_UPLOAD_COMPLETE:
            {
                rtn = hsm::SiblingTransition<ECMState_SetupMachine>(this->m_ECMCollection);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadMotionProfile>(activeConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadMotionVariables>(activeConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS:
            {
                //rtn = hsm::InnerEntryTransition<ECMState_UploadPowerRegisterSegments>(m_ProfileCollection);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS:
            {
                //rtn = hsm::InnerEntryTransition<ECMState_UploadPumpParameters>(m_ProfileCollection);
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

void ECMState_Upload::OnEnter(const ECMCommand_ExecuteCollection &collection)
{
    //First update the configuation per what was received upon entering the state
    this->m_ECMCollection = collection;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    /*
     * We should only transition to the upload motion profile state if the
     * profile is the first in the queue and we desire to upload the script.
     * Otherwise, we should set the appropriate variables related to the
     * motion profile.
     */
    if(collection.isFirstOperation(collection.getActiveIndex()) && collection.shouldWriteGalilScript())
    {
        this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE;
    }
    else{
        this->desiredState = ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES;
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
#include "states/state_ecm_upload_power_pulse_mode.h"
#include "states/state_ecm_upload_power_register_segments.h"
#include "states/state_ecm_upload_pump_parameters.h"
