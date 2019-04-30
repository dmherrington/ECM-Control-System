#include "state_ecm_upload_power_supply_pause.h"

namespace ECM{
namespace API {

ECMState_UploadPowerSupplyPause::ECMState_UploadPowerSupplyPause():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSED;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_PAUSED;
}

void ECMState_UploadPowerSupplyPause::OnExit()
{

}

void ECMState_UploadPowerSupplyPause::stopProcess()
{
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED;
}

AbstractStateECMProcess* ECMState_UploadPowerSupplyPause::getClone() const
{
    return (new ECMState_UploadPowerSupplyPause(*this));
}

void ECMState_UploadPowerSupplyPause::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerSupplyPause(*this);
}

hsm::Transition ECMState_UploadPowerSupplyPause::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        switch (desiredState) {
        case ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_SUCCEEDED:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPowerSupplySucceeded>();
            break;
        }
        case ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadPowerSupplyFailed>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadPowerSupplyPause::Update()
{

}

void ECMState_UploadPowerSupplyPause::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_ABORT;
}

void ECMState_UploadPowerSupplyPause::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    Owner().notifyPausedEvent("The machining process has been paused because there is no connection to the munk.");
}

void ECMState_UploadPowerSupplyPause::continueProcess()
{
    desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_SUCCEEDED;
}



} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_power_supply_succeeded.h"
#include "states/state_ecm_upload_power_supply_failed.h"
