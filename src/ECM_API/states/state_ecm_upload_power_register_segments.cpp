#include "state_ecm_upload_power_register_segments.h"

namespace ECM{
namespace API {

ECMState_UploadPowerRegisterSegments::ECMState_UploadPowerRegisterSegments():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS;
}

void ECMState_UploadPowerRegisterSegments::OnExit()
{
    Owner().m_Munk->RemoveHost(this);
}

void ECMState_UploadPowerRegisterSegments::stopProcess()
{
    desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
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
        case ECMState::STATE_ECM_UPLOAD_FAILED:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadFailed>();
            break;
        }
        case ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPowerPulseMode>(this->m_Config);
            break;
        }
        case ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPumpParameters>(this->m_Config);
            break;
        }
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
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerRegisterSegments::OnEnter(ECMCommand_AbstractProfileConfigPtr config)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = config;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(config);

        if(castConfig->m_ConfigPowerSupply.m_MunkSegment.getRegisterData().size() > 0)
        {
            Owner().m_Munk->AddLambda_FinishedUploadingSegments(this,[this](const bool completed, const DeviceInterface_PowerSupply::FINISH_CODE finishCode){
                UNUSED(finishCode);
                NotificationUpdate APIUpdate("API",ECMDevice::DEVICE_POWERSUPPLY);

                if(completed)
                    {
                    APIUpdate.setUpdateType(common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
                    APIUpdate.setPeripheralMessage("Upload of power segments was successful.");
                        desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
                    }else
                    {
                    APIUpdate.setUpdateType(common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR);
                    APIUpdate.setPeripheralMessage("Upload of power segments has failed.");
                        desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
                    }
                emit Owner().signal_APINotification(APIUpdate);
            });

            Owner().m_Munk->generateAndTransmitMessage(castConfig->m_ConfigPowerSupply.m_MunkSegment);
        }
        else
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
        }
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_UPLOAD_POWER_REGISTER_SEGMENTS with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        break;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_power_pulse_mode.h"
#include "states/state_ecm_upload_pump_parameters.h"
#include "states/state_ecm_upload_failed.h"
