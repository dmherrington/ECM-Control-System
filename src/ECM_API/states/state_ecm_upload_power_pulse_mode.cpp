#include "state_ecm_upload_power_pulse_mode.h"

namespace ECM{
namespace API {

ECMState_UploadPowerPulseMode::ECMState_UploadPowerPulseMode():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_PULSE_MODE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
    //AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerPulseMode::OnExit()
{
    Owner().m_Munk->RemoveHost(this);
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

}

void ECMState_UploadPowerPulseMode::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = config;

//    Owner().m_Munk->AddLambda_FinishedUploadingPulseMode(this,[this](const bool completed, const DeviceInterface_PowerSupply::FINISH_CODE finishCode){
//            if(completed)
//            {
//                desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
//            }else
//            {
//                desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
//            }
//    });

//    Owner().m_Munk->writeRegisterPulseMode(config.m_ConfigPowerSupply.m_MunkPulseMode);

    desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_pump_parameters.h"
#include "states/state_ecm_upload_failed.h"
