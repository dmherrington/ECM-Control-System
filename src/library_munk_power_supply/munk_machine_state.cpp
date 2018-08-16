#include "munk_machine_state.h"

Munk_MachineState::Munk_MachineState()
{
    response_Munk::FaultRegisterState faultRegister1;
    response_Munk::FaultRegisterState faultRegister2(data_Munk::FaultRegisterType::FAULT_REGISTER_2);
    response_Munk::FaultRegisterState faultRegister3(data_Munk::FaultRegisterType::FAULT_REGISTER_3);

    DataGetSetNotifier<response_Munk::FaultRegisterState>* newReg1 = new DataGetSetNotifier<response_Munk::FaultRegisterState>();
    newReg1->set(faultRegister1);
    this->map_FaultRegisters[faultRegister1.getFaultRegister()] = newReg1;

    DataGetSetNotifier<response_Munk::FaultRegisterState>* newReg2 = new DataGetSetNotifier<response_Munk::FaultRegisterState>();
    newReg2->set(faultRegister2);
    this->map_FaultRegisters[faultRegister2.getFaultRegister()] = newReg2;

    DataGetSetNotifier<response_Munk::FaultRegisterState>* newReg3 = new DataGetSetNotifier<response_Munk::FaultRegisterState>();
    newReg3->set(faultRegister3);
    this->map_FaultRegisters[faultRegister3.getFaultRegister()] = newReg3;

}

Munk_MachineState::~Munk_MachineState()
{
    std::map<data_Munk::FaultRegisterType,DataGetSetNotifier<response_Munk::FaultRegisterState>*>::iterator it = this->map_FaultRegisters.begin();

    for (; it!=this->map_FaultRegisters.end(); it++)
    {
        delete (it->second);
    }
    this->map_FaultRegisters.clear();
}

bool Munk_MachineState::updateRegisterFaults(const response_Munk::FaultRegisterState &newState)
{
    return this->map_FaultRegisters[newState.getFaultRegister()]->set(newState);
}

bool Munk_MachineState::doesFaultExist() const
{
    std::map<data_Munk::FaultRegisterType,DataGetSetNotifier<response_Munk::FaultRegisterState>*>::const_iterator it = this->map_FaultRegisters.begin();

    for (; it!=this->map_FaultRegisters.end(); ++it)
    {
        if(it->second->get().doesFaultExist())
            return true;
    }
    return false;
}

bool Munk_MachineState::getCurrentFaultCodes(std::vector<std::string> &rtnFaults) const
{
    bool faultExists = false;
    std::map<data_Munk::FaultRegisterType,DataGetSetNotifier<response_Munk::FaultRegisterState>*>::const_iterator it = this->map_FaultRegisters.begin();

    for (; it!=this->map_FaultRegisters.end(); ++it)
    {
        if(it->second->get().doesFaultExist())
        {
            std::vector<std::string> registerFaults = it->second->get().getCurrentFaultCodes();
            rtnFaults.insert(rtnFaults.end(), registerFaults.begin(), registerFaults.end());
            faultExists = true;
        }
    }
    return faultExists;
}
