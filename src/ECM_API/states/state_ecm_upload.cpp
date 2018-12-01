#include "state_ecm_upload.h"

namespace ECM{
namespace API {

ECMState_Upload::ECMState_Upload():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD;
    this->desiredState = ECMState::STATE_ECM_UPLOAD;
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
            //Let us check to see if we should execute this profile
//            if(m_ProfileConfiguration.shouldProfileExecute()){
//                rtn = hsm::SiblingTransition<ECMState::STATE_ECM_INITIALIZATION>(m_ProfileConfiguration);
//            }
//            else{
//                rtn = hsm::SiblingTransition<ECMState::STATE_ECM_IDLE>();
//            }
        }
        else if(IsInInnerState<ECMState_UploadFailed>())
        {
            //rtn = hsm::SiblingTransition<ECMState::STATE_ECM_IDLE>();
        }
        else
        {
            //this means we want to chage the state of the vehicle for some reason
            //this could be caused by a command, action sensed by the vehicle, or
            //for various other peripheral reasons
            switch (desiredState) {
            case ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE:
            {
                //rtn = hsm::InnerEntryTransition<ECMState_UploadMotionProfile>(m_ProfileCollection);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_MOTION_VARIABLES:
            {
                //rtn = hsm::InnerEntryTransition<ECMState_UploadMotionVariables>(m_ProfileCollection);
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

}

void ECMState_Upload::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_motion_profile_initialization.h"

#include "states/state_ecm_idle.h"
#include "states/state_ecm_upload_complete.h"
#include "states/state_ecm_upload_failed.h"
#include "states/state_ecm_upload_motion_profile.h"
#include "states/state_ecm_upload_motion_variables.h"
#include "states/state_ecm_upload_power_register_segments.h"
#include "states/state_ecm_upload_pump_parameters.h"
