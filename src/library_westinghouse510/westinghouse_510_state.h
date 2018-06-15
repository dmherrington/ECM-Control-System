#ifndef WESTINGHOUSE_510_STATE_H
#define WESTINGHOUSE_510_STATE_H

#include "common/data_get_set_notifier.h"


class Westinghouse510_State
{
public:
    Westinghouse510_State();

public:
    DataGetSetNotifier<bool> pumpConnected;

public:
    DataGetSetNotifier<bool> pumpInitialized;

public:
    DataGetSetNotifier<bool> pumpON;
    DataGetSetNotifier<double> flowRate;
    DataGetSetNotifier<unsigned int> delayTime;
};    

#endif // WESTINGHOUSE_510_STATE_H
