#include "state_test.h"

namespace ECM{
namespace API {

state_test::state_test():
    AbstractStateECMProcess()
{

}

void state_test::OnExit()
{

}

AbstractStateECMProcess* state_test::getClone() const
{
    return (new state_test(*this));
}

void state_test::getClone(AbstractStateECMProcess** state) const
{
    *state = new state_test(*this);
}

hsm::Transition state_test::GetTransition()
{
    hsm::Transition rtn = hsm::NoTransition();

    return rtn;
}

void state_test::Update()
{

}

void state_test::OnEnter()
{

}


} //end of namespace Galil
} //end of namespace ECM
