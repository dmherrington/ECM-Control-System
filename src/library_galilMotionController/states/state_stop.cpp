#include "state_stop.h"

State_Stop::State_Stop()
{
    hsm::SiblingTransition<State_Idle>();
}

#include "states/state_idle.h"
