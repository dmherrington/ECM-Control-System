#include "state_ecm_upload_power_register_segments.h"

namespace ECM{
namespace API {

ECMState_UploadPowerRegisterSegments::ECMState_UploadPowerRegisterSegments():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS;
}

AbstractStateECMProcess* ECMState_UploadPowerRegisterSegments::getClone() const
{
    return (new ECMState_UploadPowerRegisterSegments(*this));
}

void ECMState_UploadPowerRegisterSegments::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerRegisterSegments(*this);
}

hsm::Transition ECMState_UploadPowerRegisterSegments::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadPowerRegisterSegments::Update()
{

}

void ECMState_UploadPowerRegisterSegments::OnEnter()
{

}

void ECMState_UploadPowerRegisterSegments::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    Owner().m_Munk->AddLambda_FinishedUploadingSegments(this,[this](const bool completed, const DeviceInterface_PowerSupply::FINISH_CODE finishCode){
            if(completed)
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
            }else
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
            }
    });

    Owner().m_Munk->generateAndTransmitMessage(config.m_ConfigPowerSupply.m_MunkSegment);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_power_pulse_mode.h"
#include "states/state_ecm_upload_failed.h"
