#ifndef MUNK_MACHINE_STATE_H
#define MUNK_MACHINE_STATE_H

#include <map>

#include "common/data_get_set_notifier.h"
#include "data_response/fault_register_state.h"

#include "data_registers/segment_time_detailed.h"

class Munk_MachineState
{
public:
    Munk_MachineState();

    ~Munk_MachineState();

    bool updateRegisterFaults(const response_Munk::FaultRegisterState &newState);

    bool doesFaultExist() const;

    bool getCurrentFaultCodes(std::vector<std::string> &rtnFaults) const;

    void updateCurrentSegmentData(const registers_Munk::SegmentTimeDetailed &data);

    registers_Munk::SegmentTimeDetailed getCurrentSegmentData() const;

private:
    std::map<data_Munk::FaultRegisterType,DataGetSetNotifier<response_Munk::FaultRegisterState>*> map_FaultRegisters;

    registers_Munk::SegmentTimeDetailed segmentData;
};

#endif // MUNK_MACHINE_STATE_H
