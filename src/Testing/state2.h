#ifndef STATE2_H
#define STATE2_H

#include "hsm.h"
#include <iostream>

using namespace hsm;

namespace test{
namespace test2{

class State2 : public State {
public:
    State2();

    virtual Transition GetTransition();

    void OnEnter(const double value);

private:
    double mTest;
};
}
}
#endif // STATE2_H
