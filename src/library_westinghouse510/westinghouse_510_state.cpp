#include "westinghouse_510_state.h"


Westinghouse510_State::Westinghouse510_State()
{
    pumpConnected.set(false);
    pumpON.set(false);
    pumpInitialized.set(false);
    flowRate.set(0.0);
    delayTime.set(0.0);
}
