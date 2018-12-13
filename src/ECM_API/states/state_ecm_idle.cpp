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

void ECMState_Idle::executeCollection(const ECMCommand_ExecuteCollection &collection)
{
    m_ECMCollection = collection;
    m_ECMCollection.establishStartTime();

    /*
     * We need to establish if we should clear the logs. Since this is a recursive process, we require that two conditions
     * be met satisfactorily.
     * 1) Require that the logs indeed in the first place desire to be overwritten.
     * 2) Require that the operation is the first operation of the collection. This is required that since we can return
     * to this condition from another event, we would then subsequently not want to clear the original logs.
     */
    if(m_ECMCollection.shouldOverwriteLogs() && m_ECMCollection.isFirstOperation(m_ECMCollection.getActiveIndex()))
    {
        Owner().initializeOperationalCollection(m_ECMCollection, true);
    }
    else if(m_ECMCollection.isFirstOperation(m_ECMCollection.getActiveIndex()))
    {
        Owner().initializeOperationalCollection(m_ECMCollection, false);
    }

    this->desiredState = ECMState::STATE_ECM_UPLOAD;
}

void ECMState_Idle::Update()
{

}

void ECMState_Idle::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload.h"
