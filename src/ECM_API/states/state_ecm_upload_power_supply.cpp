#include "state_ecm_upload_power_supply.h"

namespace ECM{
namespace API {

ECMState_UploadPowerSupply::ECMState_UploadPowerSupply():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_SUPPLY."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY;
}

void ECMState_UploadPowerSupply::OnExit()
{

}

void ECMState_UploadPowerSupply::stopProcess()
{
    desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
}

AbstractStateECMProcess* ECMState_UploadPowerSupply::getClone() const
{
    return (new ECMState_UploadPowerSupply(*this));
}

void ECMState_UploadPowerSupply::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerSupply(*this);
}

hsm::Transition ECMState_UploadPowerSupply::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        if(IsInInnerState<ECMState_UploadPowerSupplyFailed>())
        {
            std::cout<<"Something is wrong with uploading to the munk and therefore the upload has terminated."<<std::endl;
            rtn = hsm::SiblingTransition<ECMState_UploadFailed>();
        }
        else if(IsInInnerState<ECMState_UploadPowerSupplySucceeded>())
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPumpParameters>(this->m_Config);
        }
        else
        {
            switch (desiredState) {
            case ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSED:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadPowerSupplyPause>(this->m_Config);
                break;
            }
            case ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE:
            {
                rtn = hsm::InnerEntryTransition<ECMState_UploadPowerPulseMode>(this->m_Config);
                break;
            }
            default:
                std::cout<<"I dont know how we eneded up in this transition from within ECMState_UploadPowerSupply."<<std::endl;
                break;
            }
        }
    }

    return rtn;
}

void ECMState_UploadPowerSupply::Update()
{

}

void ECMState_UploadPowerSupply::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerSupply::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (this->m_Config->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        if(Owner().m_Munk->isConnected())
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_POWER_PULSE_MODE;
        }
        else {
            desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSED;
        }
        break;
    }
    case ProfileOpType::PAUSE:
    {
        desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
        break;
    }
    default:

        break;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_upload_power_pulse_mode.h"
#include "states/state_ecm_upload_power_supply_failed.h"
#include "states/state_ecm_upload_power_supply_pause.h"
#include "states/state_ecm_upload_power_supply_succeeded.h"

#include "states/state_ecm_upload_pump_parameters.h"
#include "states/state_ecm_upload_failed.h"
