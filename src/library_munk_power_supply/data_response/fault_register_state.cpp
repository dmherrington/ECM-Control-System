#include "fault_register_state.h"

namespace response_Munk{


FaultRegisterState::FaultRegisterState(const data_Munk::FaultRegisterType &registerType, const unsigned int &code)
{
    this->currentRegister = registerType;
    this->faultCode = code;
    this->parseFaultCode();
}

FaultRegisterState::FaultRegisterState(const FaultRegisterState &copy)
{
    this->currentRegister = copy.currentRegister;
    this->faultCode = copy.faultCode;
    this->faultErrors = copy.faultErrors;
}

void FaultRegisterState::updateRegisterType(const data_Munk::FaultRegisterType &registerType)
{
    this->currentRegister = registerType;
}

data_Munk::FaultRegisterType FaultRegisterState::getFaultRegister() const
{
    return this->currentRegister;
}

std::vector<std::string> FaultRegisterState::getCurrentFaultCodes() const
{
    return this->faultErrors;
}

bool FaultRegisterState::doesFaultExist() const
{
    return (this->faultCode != 0);
}

void FaultRegisterState::parseFaultCode()
{
    this->faultErrors.clear();

    if(this->faultCode == 0) //if there is no error, there is nothing to do
        return;

    uint16_t mask = 0;

    for(int i = 0; i < 16; i++)
    {
        mask = 1<<i;
        if((this->faultCode & mask) != 0)
        {
            uint16_t currentCode = pow(2,i);

            switch (this->currentRegister) {
            case data_Munk::FaultRegisterType::FAULT_REGISTER_1:
                this->faultErrors.push_back(data_Munk::FaultCodesRegister1ToString(static_cast<data_Munk::FaultCodesRegister1>(currentCode)));
                break;
            case data_Munk::FaultRegisterType::FAULT_REGISTER_2:
                this->faultErrors.push_back(data_Munk::FaultCodesRegister2ToString(static_cast<data_Munk::FaultCodesRegister2>(currentCode)));
                break;
            case data_Munk::FaultRegisterType::FAULT_REGISTER_3:
                this->faultErrors.push_back(data_Munk::FaultCodesRegister3ToString(static_cast<data_Munk::FaultCodesRegister3>(currentCode)));
                break;
            default:
                throw std::runtime_error("FaultRegisterType seen in MunkPowerSupply::FaultCodeReceived.");
                break;
            }
        }
    }
}

} //end of namespace response_Munk
