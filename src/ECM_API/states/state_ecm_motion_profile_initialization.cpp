#include "state_ecm_motion_profile_initialization.h"

namespace ECM{
namespace API {

ECMState_MotionProfileInitialization::ECMState_MotionProfileInitialization():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_MOTION_PROFILE_INITIALIZATION;
    this->desiredState = ECMState::STATE_ECM_MOTION_PROFILE_INITIALIZATION;
}

AbstractStateECMProcess* ECMState_MotionProfileInitialization::getClone() const
{
    return (new ECMState_MotionProfileInitialization(*this));
}

void ECMState_MotionProfileInitialization::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_MotionProfileInitialization(*this);
}

hsm::Transition ECMState_MotionProfileInitialization::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        switch (desiredState) {
        case(ECMState::STATE_ECM_IDLE):
        {
            rtn = hsm::SiblingTransition<ECMState::STATE_ECM_IDLE>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from "<<ECMStateToString(this->currentState)<<"."<<std::endl;
            break;
        }
    }
    return rtn;
}

void ECMState_MotionProfileInitialization::Update()
{

}

void ECMState_MotionProfileInitialization::OnEnter()
{

}

void ECMState_MotionProfileInitialization::OnEnter(const ECMCommand_ProfileConfiguration &config)
{
    Owner().m_Galil->AddLambda_FinishedUploadingScript(this,[this](const bool completed, const DeviceInterface_Pump::FINISH_CODE finishCode){
        if(completed)
        {
            desiredState = ECMState::STATE_ECM_IDLE;
        }else
        {
            desiredState = ECMState::STATE_ECM_IDLE;
        }
    });
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_power_supply_setup.h"
