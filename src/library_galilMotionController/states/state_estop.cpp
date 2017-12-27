#include "state_estop.h"

namespace ECM{
namespace Galil {

State_EStop::State_EStop():
    AbstractStateGalil()
{
    this->currentState = ECMState::STATE_ESTOP;
    this->desiredState = ECMState::STATE_ESTOP;
}

AbstractStateGalil* State_EStop::getClone() const
{
    return (new State_EStop(*this));
}

void State_EStop::getClone(AbstractStateGalil** state) const
{
    *state = new State_EStop(*this);
}

hsm::Transition State_EStop::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    if(currentState != desiredState)
    {
        //this means we want to chage the state for some reason
        switch (desiredState) {
        case ECMState::STATE_IDLE:
        {
            rtn = hsm::SiblingTransition<State_Idle>();
            break;
        }
        default:
            std::cout<<"I dont know how we eneded up in this transition state from State_EStop."<<std::endl;
            break;
        }
    }
    return rtn;
}

void State_EStop::handleCommand(const AbstractCommand* command)
{
    CommandType currentCommand = command->getCommandType();

    switch (currentCommand) {
    case CommandType::ABSOLUTE_MOVE:
    case CommandType::CLEAR_BIT:
    case CommandType::EXECUTE_PROGRAM:
    case CommandType::JOG_MOVE:
    case CommandType::MOTOR_OFF:
    case CommandType::MOTOR_ON:
    case CommandType::RELATIVE_MOVE:
    case CommandType::SET_BIT:
    case CommandType::STOP:
    {
        std::cout<<"The current command: "<<CommandToString(currentCommand)<<" is not available while Galil is in the state of: "<<ECMStateToString(currentState)<<"."<<std::endl;
        break;
    }
    default:
        break;
    }
}

void State_EStop::Update()
{
    //Check the status of the estop state
    bool eStopState = this->checkEStop();
    if(eStopState == false)
    {
        //this means that the estop button has been cleared
        //we should therefore transition to the idle state
        desiredState = ECMState::STATE_IDLE;
    }
}

void State_EStop::OnEnter()
{

}

void State_EStop::OnEnter(const AbstractCommand *command){

    if(command != nullptr)
    {

    }
    else{

    }
}

} //end of namespace Galil
} //end of namespace ECM

#include "states/state_idle.h"
