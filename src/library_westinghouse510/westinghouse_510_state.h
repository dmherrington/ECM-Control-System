#ifndef WESTINGHOUSE_510_STATE_H
#define WESTINGHOUSE_510_STATE_H

#include "common/data_get_set_notifier.h"

namespace westinghousePump {
class Westinghouse510_State
{
public:
    Westinghouse510_State();

public:
    DataGetSetNotifier<bool> pumpON;
    DataGetSetNotifier<double> flowRate;
};    

} //end of namespace westinghouse

#endif // WESTINGHOUSE_510_STATE_H
