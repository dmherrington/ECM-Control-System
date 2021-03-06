#include "state_ecm_upload_power_pulse_mode.h"

namespace ECM{
namespace API {

ECMState_UploadPowerPulseMode::ECMState_UploadPowerPulseMode():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_PULSE_MODE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
}

void ECMState_UploadPowerPulseMode::OnExit()
{
    Owner().m_Munk->RemoveHost(this);
}

void ECMState_UploadPowerPulseMode::stopProcess()
{
    desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
}

AbstractStateECMProcess* ECMState_UploadPowerPulseMode::getClone() const
{
    return (new ECMState_UploadPowerPulseMode(*this));
}

void ECMState_UploadPowerPulseMode::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerPulseMode(*this);
}

hsm::Transition ECMState_UploadPowerPulseMode::GetTransition()
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

void ECMState_UploadPowerPulseMode::Update()
{

}

void ECMState_UploadPowerPulseMode::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerPulseMode::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (this->m_Config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(this->m_Config);

        Owner().m_Munk->AddLambda_FinishedUploadingPulseMode(this,[this](const bool completed, const DeviceInterface_PowerSupply::FINISH_CODE finishCode){
            NotificationUpdate APIUpdate("API",ECMDevice::DEVICE_POWERSUPPLY);

                if(completed)
                {
                    APIUpdate.setUpdateType(common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL);
                    APIUpdate.setPeripheralMessage("Upload of power pulse mode was successful.");
                    desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
                }else
                {
                    APIUpdate.setUpdateType(common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR);
                    APIUpdate.setPeripheralMessage("Upload of power pulse mode has failed.");
                    desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
                }
                emit Owner().signal_APINotification(APIUpdate);
        });

        Owner().m_Munk->writeRegisterPulseMode(castConfig->m_ConfigPowerSupply.m_MunkPulseMode);
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_UPLOAD_POWER_PULSE_MODE with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        break;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_pump_parameters.h"
#include "states/state_ecm_upload_failed.h"
