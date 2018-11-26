#include "state_ecm_upload_power_parameters.h"

namespace ECM{
namespace API {

ECMState_UploadPowerParameters::ECMState_UploadPowerParameters():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_TOUCHOFF_EXECUTE;
    this->desiredState = ECMState::STATE_ECM_TOUCHOFF_EXECUTE;
}

void ECMState_UploadPowerParameters::OnExit()
{

}

AbstractStateECMProcess* ECMState_UploadPowerParameters::getClone() const
{
    return (new ECMState_UploadPowerParameters(*this));
}

void ECMState_UploadPowerParameters::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_UploadPowerParameters(*this);
}

hsm::Transition ECMState_UploadPowerParameters::GetTransition()
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

void ECMState_UploadPowerParameters::Update()
{

}

void ECMState_UploadPowerParameters::OnEnter()
{

}

void ECMState_UploadPowerParameters::OnEnter(const ECMCommand_ProfileConfigurationPtr command)
{
    Owner().m_Munk->AddLambda_FinishedUploadingParameters(this,[this](const bool completed, const uint8_t finishCode){
        Owner().m_Pump->AddLambda_FinishedUploadingParameters(this,[this](const bool completed, const uint8_t finishCode){
            if(completed)
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_PUMP_PARAMETERS;
            }else
            {
                desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
            }
        });
    });

    Owner().m_Munk->generateAndTransmitMessage(command->m_MunkParameters);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload_pump_parameters.h"
#include "states/state_ecm_upload_failed.h"
