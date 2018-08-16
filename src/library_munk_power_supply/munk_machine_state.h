#ifndef MUNK_MACHINE_STATE_H
#define MUNK_MACHINE_STATE_H

#include <map>

#include "common/data_get_set_notifier.h"
#include "data_response/fault_register_state.h"

class Munk_MachineState
{
public:
    Munk_MachineState();

    ~Munk_MachineState();

    bool updateRegisterFaults(const response_Munk::FaultRegisterState &newState);

    bool doesFaultExist() const;

    bool getCurrentFaultCodes(std::vector<std::string> &rtnFaults) const;

private:
    std::map<data_Munk::FaultRegisterType,DataGetSetNotifier<response_Munk::FaultRegisterState>*> map_FaultRegisters;

};

#endif // MUNK_MACHINE_STATE_H
