#include "state_ecm_upload_power_supply_failed.h"

namespace ECM{
namespace API {

ECMState_UploadPowerSupplyFailed::ECMState_UploadPowerSupplyFailed():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED;
}

void ECMState_UploadPowerSupplyFailed::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadPowerSupplyFailed::getClone() const
{
    return (new ECMState_UploadPowerSupplyFailed(*this));
}

void ECMState_UploadPowerSupplyFailed::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerSupplyFailed(*this);
}

hsm::Transition ECMState_UploadPowerSupplyFailed::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void ECMState_UploadPowerSupplyFailed::Update()
{

}

void ECMState_UploadPowerSupplyFailed::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerSupplyFailed::OnEnter(const ECMCommand_AbstractProfileConfigPtr &configuration)
{
    UNUSED(configuration);

    this->OnEnter();
}

} //end of namespace API
} //end of namespace ECM
