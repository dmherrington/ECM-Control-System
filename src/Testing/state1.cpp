#include "state1.h"
namespace test{
namespace test2 {


State1::State1()
{
    mTest = 0.0;
}

void State1::updateValue(const double &test)
{
    std::cout<<"We are here 3.1"<<std::endl;
    mTest = test + 1;
    std::cout<<"We are here 3.2"<<std::endl;
    std::cout<<"The value of test"<<mTest<<std::endl;
}
Transition State1::GetTransition()
{
    if(mTest <= 1)
        return hsm::NoTransition();
    else
    {
        return hsm::SiblingTransition<State2>();
    }
}
}
}
#include "state2.h"

