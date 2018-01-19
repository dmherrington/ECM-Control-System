#include "state2.h"
namespace test{
namespace test2{
State2::State2()
{

}

Transition State2::GetTransition()
{
    return NoTransition();
}
void State2::OnEnter(const double value) {
    mTest = value + 1;
    std::cout<<"The value here is "<<mTest<<std::endl;
}
}
}
