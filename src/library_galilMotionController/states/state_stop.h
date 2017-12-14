#ifndef STATE_STOP_H
#define STATE_STOP_H

#include "common/class_forward.h"

#include "states/hsm.h"

ECM_CLASS_FORWARD(State_Stop);

class State_Idle;

class State_Stop : public hsm::State
{
public:
    State_Stop();
};

#endif // STATE_STOP_H
