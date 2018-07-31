#include "state_ecm_pump_setup.h"

namespace ECM{
namespace API {

ECMState_PumpSetup::ECMState_PumpSetup():
    AbstractStateECMProcess()
{
    this->currentState = ECMState::STATE_ECM_PUMP_SETUP;
    this->desiredState = ECMState::STATE_ECM_PUMP_SETUP;
}

AbstractStateGalil* ECMState_PumpSetup::getClone() const
{
    return (new ECMState_PumpSetup(*this));
}

void ECMState_PumpSetup::getClone(AbstractStateGalil** state) const
{
    *state = new ECMState_PumpSetup(*this);
}

hsm::Transition ECMState_PumpSetup::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_MANUAL_POSITIONING:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffExecute>(currentCommand);
            break;
        }
        case ECMState::STATE_JOGGING:
        {
            rtn = hsm::SiblingTransition<ECMState_TouchoffEnable>(currentCommand);
            break;
        }
        case ECMState::STATE_HOME_POSITIONING:
        {
            rtn = hsm::SiblingTransition<ECMState_PowerSupplySetup>(currentCommand);
            break;
        }
        case ECMState::STATE_SCRIPT_EXECUTION:
        {
            rtn = hsm::SiblingTransition<ECMState_MachineSetup>(currentCommand);
            break;
        }
        case ECMState::STATE_TOUCHOFF:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachineProcess>(currentCommand);
            break;
        }
        case ECMState::STATE_READY_STOP:
        {
            rtn = hsm::SiblingTransition<ECMState_ProfileMachine>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            rtn = hsm::SiblingTransition<ECMState_Setup>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from STATE_READY."<<std::endl;
            break;
        }
    }

    return rtn;
}

void ECMState_PumpSetup::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == true)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_ESTOP;
    }
}

void ECMState_PumpSetup::OnEnter()
{
    Owner().issueNewGalilState(ECMStateToString(ECMState::STATE_READY));
    //The first thing we should do when entering this state is to engage the motor
    //Let us check to see if the motor is already armed, if not, follow through with the command

    if(!Owner().isMotorEnabled())
    {
        CommandMotorEnablePtr command = std::make_shared<CommandMotorEnable>();
        command->setEnableAxis(MotorAxis::Z);
        Owner().issueGalilCommand(command);
    }

    //Next we should establish the necessary gains for motion within this state
    CommandControllerGain command;
    Owner().issueGalilControllerGains(command);
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_home_positioning.h"
#include "states/state_jogging.h"
#include "states/state_manual_positioning.h"
#include "states/state_script_execution.h"
#include "states/state_touchoff.h"
#include "states/state_estop.h"
#include "states/state_ready_stop.h"
