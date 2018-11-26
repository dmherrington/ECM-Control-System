#include "state_ecm_upload_complete.h"

namespace ECM{
namespace API {

ECMState_UploadComplete::ECMState_UploadComplete():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD;
    this->desiredState = ECMState::STATE_ECM_UPLOAD;
}

void ECMState_UploadComplete::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadComplete::getClone() const
{
    return (new ECMState_Upload(*this));
}

void ECMState_UploadComplete::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Upload(*this);
}

hsm::Transition ECMState_UploadComplete::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentStateEnum != desiredStateEnum)
    {
        if(IsInInnerState<State_LandingComplete>())
        {
            rtn = hsm::SiblingTransition<State_Grounded>();
        }
        else
        {
            //this means we want to chage the state of the vehicle for some reason
            //this could be caused by a command, action sensed by the vehicle, or
            //for various other peripheral reasons
            switch (desiredStateEnum) {
            case ECMState::STATE_ECM_UPLOAD_MOTION_PROFILE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadMotionProfile>(m_CurrentConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_POWER_PARAMETERS:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadPowerParameters>(m_CurrentConfiguration);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadPumpParameters>(m_CurrentConfiguration);
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition state from STATE_TAKEOFF."<<std::endl;
                break;
            }
        }
    }

    return rtn;
}

void ECMState_UploadComplete::Update()
{

}

void ECMState_UploadComplete::OnEnter(const ECMCommand_ProfileConfigurationPtr command)
{
    Owner().m_Munk->AddLambda_FinishedUploadingParameters(this,[this](const bool completed, const uint8_t finishCode){
        if(!completed)
        {
            //for some reason a timeout has occured, should we handle this differently
            std::cout<<"A timeout has occured when trying to send a goto command."<<std::endl;
            desiredStateEnum = ArdupilotFlightState::STATE_FLIGHT_GUIDED_IDLE;
        }else if(finishCode != MAV_MISSION_ACCEPTED)
        {
            std::cout<<"The autopilot says there is an error with the goTo command."<<std::endl;
            desiredStateEnum = ArdupilotFlightState::STATE_FLIGHT_GUIDED_IDLE;
        }
        else if(completed && (finishCode == MAV_MISSION_ACCEPTED))
        {
            this->commandAccepted = true;
        }
    });
}

} //end of namespace Galil
} //end of namespace ECM

