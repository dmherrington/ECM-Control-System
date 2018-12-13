#include "state_ecm_setup_machine_touchoff_position.h"

namespace ECM{
namespace API {

ECMState_SetupMachineTouchoffPosition::ECMState_SetupMachineTouchoffPosition():
    AbstractStateECMProcess()
{
    std::cout<<"We are currently in the constructor of STATE_ECM_SETUP_MACHINE_TOUCHOFF_POSITION."<<std::endl;
    this->currentState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_POSITION;
    this->desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_POSITION;
}

void ECMState_SetupMachineTouchoffPosition::OnExit()
{
    Owner().m_Galil->RemoveHost(this);
}

AbstractStateECMProcess* ECMState_SetupMachineTouchoffPosition::getClone() const
{
    return (new ECMState_SetupMachineTouchoffPosition(*this));
}

void ECMState_SetupMachineTouchoffPosition::getClone(AbstractStateECMProcess** state) const
{
    *state = new ECMState_SetupMachineTouchoffPosition(*this);
}

hsm::Transition ECMState_SetupMachineTouchoffPosition::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();
    switch (desiredState) {
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffFailed>();
        break;
    }
    case ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE:
    {
        rtn = hsm::SiblingTransition<ECMState_SetupMachineTouchoffExecute>(this->m_Config);
        break;
    }
    default:
        break;
    }
    return rtn;
}

void ECMState_SetupMachineTouchoffPosition::Update()
{

}

void ECMState_SetupMachineTouchoffPosition::OnEnter()
{
    AbstractStateECMProcess::notifyOwnerStateTransition();

    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_FAILED;
}

void ECMState_SetupMachineTouchoffPosition::OnEnter(const ECMCommand_ProfileConfiguration &configuration)
{
    this->m_Config = configuration;

    AbstractStateECMProcess::notifyOwnerStateTransition();

    //First set the move to touchoff speed based on the following static value
    CommandSpeedPtr commandSpeed = std::make_shared<CommandSpeed>(MotorAxis::Z, 100000);
    Owner().m_Galil->executeCommand(commandSpeed);

    if(this->m_Config.m_Touchoff.shouldTouchoffUtilizePreviousPosition())
    {
        /*
         * In this case, there is no reason to proceed any further,
         * as the machine will already be in the correct position.
         */
        desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE;
    }
    else
    {
        int touchoffPosition = Owner().m_Galil->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
        //Next, transmit the move to home command
        CommandAbsoluteMovePtr command = std::make_shared<CommandAbsoluteMove>(MotorAxis::Z,touchoffPosition);
        Owner().m_Galil->executeCommand(command);
        Owner().m_Galil->stateInterface->getAxisStatus(MotorAxis::Z)->position.AddNotifier(this,[this,touchoffPosition]
        {
            int currentPosition = Owner().m_Galil->stateInterface->getAxisStatus(MotorAxis::Z)->getPosition().getPosition();
            if(abs(currentPosition - touchoffPosition) < 10) //what is the tolerance allowed for the move
                desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_EXECUTE;
        });
    }

}

void ECMState_SetupMachineTouchoffPosition::stopProcess()
{
    desiredState = ECMState::STATE_ECM_SETUP_MACHINE_TOUCHOFF_FAILED;
}


} //end of namespace API
} //end of namespace ECM

#include "states/state_ecm_setup_machine_touchoff_failed.h"
#include "states/state_ecm_setup_machine_touchoff_execute.h"
