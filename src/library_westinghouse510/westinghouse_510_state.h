#ifndef WESTINGHOUSE_510_STATE_H
#define WESTINGHOUSE_510_STATE_H

#include "common/data_get_set_notifier.h"


class Westinghouse510_State
{
public:
    Westinghouse510_State();

public:
    bool pumpConnected = false;

public:
    DataGetSetNotifier<bool> pumpON;
    DataGetSetNotifier<double> flowRate;
    DataGetSetNotifier<double> delayTime;
};    

#endif // WESTINGHOUSE_510_STATE_H
