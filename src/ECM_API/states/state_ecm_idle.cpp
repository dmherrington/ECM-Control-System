#include "state_ecm_idle.h"

namespace ECM{
namespace API {

ECMState_Idle::ECMState_Idle():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_IDLE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_IDLE;
    this->desiredState = ECMState::STATE_ECM_IDLE;
}

void ECMState_Idle::OnExit()
{

}

AbstractStateECMProcess* ECMState_Idle::getClone() const
{
    return (new ECMState_Idle(*this));
}

void ECMState_Idle::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_Idle(*this);
}

hsm::Transition ECMState_Idle::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    if(currentState != desiredState)
    {
        switch (desiredState) {
        case ECMState::STATE_ECM_MOTION_PROFILE_INITIALIZATION:
        {
            ECMCommand_ProfileCollection* collection = m_ECMCollection.get()->as<ECMCommand_ProfileCollection>();
            rtn = hsm::SiblingTransition<ECMState_MotionProfileInitialization>(*collection);
            break;
        }
        case ECMState::STATE_ECM_UPLOAD:
        {
            rtn = hsm::SiblingTransition<ECMState_Upload>(m_ECMCollection);
            break;
        }
        default:
            break;
        }
    }
    return rtn;
}

void ECMState_Idle::initializeFromCollection(const ECMCommand_ProfileCollection &collection)
{
    m_ECMCollection = std::make_shared<ECMCommand_ProfileCollection>(collection);
    this->desiredState = ECMState::STATE_ECM_MOTION_PROFILE_INITIALIZATION;
}

void ECMState_Idle::executeCollection(const ECMCommand_ExecuteCollection &collection)
{
    m_ECMCollection = std::make_shared<ECMCommand_ExecuteCollection>(collection);
    this->desiredState = ECMState::STATE_ECM_UPLOAD;
}

void ECMState_Idle::Update()
{

}

void ECMState_Idle::OnEnter()
{

}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_motion_profile_initialization.h"
#include "states/state_ecm_upload.h"
