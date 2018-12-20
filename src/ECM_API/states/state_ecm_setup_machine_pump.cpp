#include "state_ecm_setup_machine_pump.h"

namespace ECM{
namespace API {

ECMState_SetupMachinePump::ECMState_SetupMachinePump():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_PUMP."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_PUMP;
}

void ECMState_SetupMachinePump::OnExit()
{
    Owner().m_Pump->RemoveHost(this);
}

void ECMState_SetupMachinePump::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

AbstractStateECMProcess* ECMState_SetupMachinePump::getClone() const
{
    return (new ECMState_SetupMachinePump(*this));
}

void ECMState_SetupMachinePump::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachinePump(*this);
}

hsm::Transition ECMState_SetupMachinePump::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineComplete>();
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachinePump::Update()
{

}

void ECMState_SetupMachinePump::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();
    /*
     * We should not be able to enter this method. This is an overloaded method as required from the base.
     * If for some reason this state has been entered while trying to setup the machine, we shall say
     * that the setup has therefore failed.
     */
    desiredState = ECMState::STATE_ECM_PROFILE_MACHINE_FAILED;
}

void ECMState_SetupMachinePump::OnEnter(ECMCommand_AbstractProfileConfigPtr configuration)
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    switch (configuration->getConfigType()) {
    case ProfileOpType::OPERATION:
    {
        ECMCommand_ProfileConfigurationPtr castConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(configuration);

        //if the pump should be running and is currently not already running
        if(castConfig->m_PumpParameters.shouldPumpBeUtilized() && !Owner().m_Pump->isPumpRunning())
        {
            Owner().m_Pump->AddLambda_FinishedPumpInitialization(this,[this](const bool &completed){
                if(completed)
                {
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
                }else{
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
                }
            });

            registers_WestinghousePump::Register_OperationSignal newOps;
            newOps.shouldRun(castConfig->m_PumpParameters.shouldPumpBeUtilized());
            Owner().m_Pump->setPumpOperations(newOps);
        }
        else if(castConfig->m_PumpParameters.shouldPumpBeUtilized() && !Owner().m_Pump->isPumpInitialized()) //the pump is already running, however, is not currently initialized
        {
            Owner().m_Pump->AddLambda_FinishedPumpInitialization(this,[this](const bool &completed){
                if(completed)
                {
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
                }else{
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
                }
            });
        }
        else
        {
            desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
        }
        break;
    }
    case ProfileOpType::PAUSE:
    {
        ECMCommand_ProfilePausePtr castConfig = static_pointer_cast<ECMCommand_ProfilePause>(configuration);

        if(!castConfig->m_PumpParameters.shouldPumpBeUtilized() && Owner().m_Pump->isPumpRunning())
        {
            Owner().m_Pump->AddLambda_FinishedPumpInitialization(this,[this](const bool &completed){
                if(completed)
                {
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
                }else{
                    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
                }
            });

            registers_WestinghousePump::Register_OperationSignal newOps;
            newOps.shouldRun(castConfig->m_PumpParameters.shouldPumpBeUtilized());
            Owner().m_Pump->setPumpOperations(newOps);
        }
        else if(!castConfig->m_PumpParameters.shouldPumpBeUtilized() && !Owner().m_Pump->isPumpRunning())
        {
            desiredState = ECMState::STATE_ECM_SETUP_MACHINE_COMPLETE;
        }
        break;
    }
    default:
        std::cout<<"We should not have gotten into STATE_ECM_SETUP_MACHINE_PUMP with the current command type."<<std::endl;
        desiredState = ECMState::STATE_ECM_UPLOAD_FAILED;
        break;
    }
}

} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_idle.h"
#include "states/state_ecm_setup_machine_complete.h"
#include "states/state_ecm_setup_machine_failed.h"

