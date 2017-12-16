#include "state_ready.h"

namespace ECM{
namespace Galil {

State_Ready::State_Ready(const GalilSettings &settings):
    AbstractStateGalil(settings)
{

}

AbstractStateGalil* State_Ready::getClone() const
{
    return (new State_Ready(*this));
}

void State_Ready::getClone(AbstractStateGalil** state) const
{
    *state = new State_Ready(*this);
}

void State_Ready::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::CLEAR_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::EXECUTE_PROGRAM:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::JOG_MOVE:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::MOTOR_OFF:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::MOTOR_ON:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::RELATIVE_MOVE:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::SET_BIT:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::STOP:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    case CommandType::TELL_POSITION:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    default:
        break;
    }
}

hsm::Transition State_Ready::GetTransition()
{
    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        //now initiate the state transition to the correct class
        switch (desiredState) {
        case ECMState::STATE_STOP:
        {
            return hsm::SiblingTransition<State_Stop>();
            break;
        }
        case ECMState::STATE_ESTOP:
        {
            return hsm::SiblingTransition<State_EStop>();
            break;
        }
        case ECMState::STATE_JOGGING:
        {
            return hsm::SiblingTransition<State_Jogging>();
            break;
        }
        case ECMState::STATE_MANUAL_POSITIONING:
        {
            return hsm::SiblingTransition<State_ManualPositioning>();
            break;
        }
        case ECMState::STATE_TOUCHOFF:
        {
            return hsm::SiblingTransition<State_Touchoff>();
            break;
        }
        case ECMState::STATE_SCRIPT_EXECUTION:
        {
            return hsm::SiblingTransition<State_ScriptExecution>();
            break;
        }
        case ECMState::STATE_HOME_POSITIONING:
        {
            return hsm::SiblingTransition<State_HomePositioning>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from state idle."<<std::endl;
            break;
        }
    }
    else{
        return hsm::NoTransition();
    }
}

#include "states/state_stop.h"
#include "states/state_estop.h"
#include "states/state_jogging.h"
#include "states/state_manual_positioning.h"
#include "states/state_touchoff.h"
#include "states/state_script_execution.h"
#include "states/state_home_positioning.h"

} //end of namespace Galil
} //end of namespace ECM
