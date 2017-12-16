#ifndef STATE1_H
#define STATE1_H

#include "hsm.h"
#include <iostream>

using namespace hsm;

namespace test{
namespace test2{
class State2;

class State1 : public State {
public:
    State1();

    void updateValue(const double &test);

    virtual Transition GetTransition();
private:
    double mTest;
};

}
}
#endif // STATE1_H
