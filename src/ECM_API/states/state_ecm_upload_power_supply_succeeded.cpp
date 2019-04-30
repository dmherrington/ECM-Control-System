#include "state_ecm_upload_power_supply_succeeded.h"


namespace ECM{
namespace API {

ECMState_UploadPowerSupplySucceeded::ECMState_UploadPowerSupplySucceeded():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_POWER_SUPPLY_FAILED;
}

void ECMState_UploadPowerSupplySucceeded::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadPowerSupplySucceeded::getClone() const
{
    return (new ECMState_UploadPowerSupplySucceeded(*this));
}

void ECMState_UploadPowerSupplySucceeded::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerSupplySucceeded(*this);
}

hsm::Transition ECMState_UploadPowerSupplySucceeded::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void ECMState_UploadPowerSupplySucceeded::Update()
{

}

void ECMState_UploadPowerSupplySucceeded::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPowerSupplySucceeded::OnEnter(const ECMCommand_AbstractProfileConfigPtr &configuration)
{
    this->OnEnter();
}

} //end of namespace API
} //end of namespace ECM

