#include "state_ecm_profile_handling.h"


namespace ECM{
namespace API {

ECMState_ProfileHandling::ECMState_ProfileHandling():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_MOTION_PROFILE_HANDLING."<<std::endl;
    this->currentState = ECMState::STATE_ECM_MOTION_PROFILE_HANDLING;
    this->desiredState = ECMState::STATE_ECM_MOTION_PROFILE_HANDLING;
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
        case ECMState::STATE_ECM_IDLE:
        {
            rtn = hsm::SiblingTransition<ECMState_Idle>();
            break;
        }
        case ECMState::STATE_ECM_UPLOAD:
        {
            rtn = hsm::SiblingTransition<ECMState_Upload>(this->m_ECMCollection);
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

void ECMState_ProfileHandling::OnEnter(ECMCommand_ExecuteCollectionPtr collection)
{
    this->m_ECMCollection = collection;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    /*
     * We need to establish if we should clear the logs. Since this is a recursive process, we require that two conditions
     * be met satisfactorily. The first check will be to see if this profile is repeating from an exesting collection,
     * or a completely new execution.
     *
     * A new execution will have transitioned to this state from idle.
     * A follow-on execution will have transitioned to this state from the profile machining state.
     */


    /*
     * The only way to transition beyond this state if there are currenly active operations within the collection
     * that have yet to have been executed. Let us check that is true. If it is not true and we have landed in this
     * state, we therefore have concluded executing the current collection successfully, or the collection is empty.
     */
    if(m_ECMCollection->doActiveOperationsRemain())
    {
        /*
        * 1) Require that the operation is the first operation of the collection. This is required that since we can return
        * to this condition from another event, we would then subsequently not want to clear the original logs.
        */
        if(this->m_ECMCollection->isFirstOperation(this->m_ECMCollection->getActiveIndex()))
        {
            this->m_ECMCollection->establishStartTime(); //Set the start time associated with the collection

            /*
             * 2) Assess whether the logs should be overwritten, this would only have happened if also it is the
             * first operation of the collection.
            */
            if(this->m_ECMCollection->shouldOverwriteLogs())
            {
                /*
                 * Initializing the collection performs the following steps:
                 * 1) Establishes the directory structure
                 * 2) Writes the current configuration to the directory
                 * 3) Notifies listeners how many operations are present, etc.
                 */
                Owner().initializeOperationalCollection(this->m_ECMCollection, true);
            }
            else
            {
                Owner().initializeOperationalCollection(this->m_ECMCollection, false);
            }
        }

        /*
         * Initialize the profile that is about to be executing
         * 1) Set the profile as executed to reflect it has been moved and acted upon in the current queue
         * 2) Set the start time associated with the profile
         */
        this->m_ECMCollection->initializeProfileExecution();

        /*
         * Write the header appropriate header contents to the log file.
         */
        Owner().initializeLoggingOperation(this->m_ECMCollection->getPartNumber(), this->m_ECMCollection->getSerialNumber(),
                                           this->m_ECMCollection->getActiveConfiguration(), "");

        Owner().beginOperationalProfile(this->m_ECMCollection->getActiveConfiguration());

        desiredState = ECMState::STATE_ECM_UPLOAD;
    }
    else if(m_ECMCollection->getActiveCollectionSize() > 0) //there were some profiles and we clearly executed them all
    {
        this->m_ECMCollection->establishEndTime();
        Owner().concludeExecutingCollection(this->m_ECMCollection);

        desiredState = ECMState::STATE_ECM_IDLE;
    }
    else //there must have been no active profiles within the collection or the collection was empty
    {
        desiredState = ECMState::STATE_ECM_IDLE;
    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_upload.h"
