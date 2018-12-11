#include "state_ecm_upload_pump_parameters.h"

namespace ECM{
namespace API {

ECMState_UploadPumpParameters::ECMState_UploadPumpParameters():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_UPLOAD_PUMP_PARAMETERS."<<std::endl;
    this->currentState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
    this->desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

void ECMState_UploadPumpParameters::OnExit()
{
    Owner().m_Pump->RemoveHost(this);
}

AbstractStateECMProcess* ECMState_UploadPumpParameters::getClone() const
{
    return (new ECMState_UploadPumpParameters(*this));
}

void ECMState_UploadPumpParameters::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPumpParameters(*this);
}

hsm::Transition ECMState_UploadPumpParameters::GetTransition()
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
        case ECMState::STATE_ECM_UPLOAD_COMPLETE:
        {
            rtn = hsm::SiblingTransition<ECMState_UploadComplete>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_UploadPumpParameters::Update()
{

}

void ECMState_UploadPumpParameters::OnEnter()
{

}

void ECMState_UploadPumpParameters::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    //First update the configuation per what was received upon entering the state
    this->m_Config = config;

    Owner().m_Pump->AddLambda_FinishedUploadingParameters(this,[this](const bool completed, const DeviceInterface_Pump::FINISH_CODE finishCode){
        UNUSED(finishCode);

        if(completed)
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_COMPLETE;
        }else
        {
            desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        }
    });

    Owner().m_Pump->setPumpProperties(config.m_PumpParameters);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_complete.h"
#include "states/state_ecm_upload_failed.h"
