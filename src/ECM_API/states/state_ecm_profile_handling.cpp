#include "state_ecm_profile_handling.h"


namespace ECM{
namespace API {

ECMState_ProfileHandling::ECMState_ProfileHandling():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_IDLE."<<std::endl;
    this->currentState = ECMState::STATE_ECM_IDLE;
    this->desiredState = ECMState::STATE_ECM_IDLE;
}

void ECMState_ProfileHandling::OnExit()
{

}

AbstractStateECMProcess* ECMState_ProfileHandling::getClone() const
{
    return (new ECMState_ProfileHandling(*this));
}

void ECMState_ProfileHandling::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_ProfileHandling(*this);
}

hsm::Transition ECMState_ProfileHandling::GetTransition()
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

void ECMState_ProfileHandling::Update()
{

}

void ECMState_ProfileHandling::OnEnter()
{

}

void ECMState_ProfileHandling::OnEnter(const ECMCommand_ExecuteCollection &collection, const bool &previouslyInitialized)
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    this->m_ECMCollection = collection;
    collection.establishStartTime();

    /*
     * We need to establish if we should clear the logs. Since this is a recursive process, we require that two conditions
     * be met satisfactorily.
     * 1) Require that the logs indeed in the first place desire to be overwritten.
     * 2) Require that the operation is the first operation of the collection. This is required that since we can return
     * to this condition from another event, we would then subsequently not want to clear the original logs.
     */
    if(collection.shouldOverwriteLogs() && collection.isFirstOperation(collection.getActiveIndex()))
    {
        Owner().initializeOperationalCollection(collection, true);
    }
    else if(collection.isFirstOperation(collection.getActiveIndex()))
    {
        Owner().initializeOperationalCollection(collection, false);
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_upload.h"
