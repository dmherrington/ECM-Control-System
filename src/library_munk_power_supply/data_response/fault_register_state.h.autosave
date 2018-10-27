#ifndef FAULT_REGISTER_STATE_H
#define FAULT_REGISTER_STATE_H

#include <math.h>

#include "data/fault_codes_register_one.h"
#include "data/fault_codes_register_two.h"
#include "data/fault_codes_register_three.h"

#include "data/type_fault_status_registers.h"

namespace response_Munk{

class FaultRegisterState
{

public:
    FaultRegisterState(const data_Munk::FaultRegisterType &registerType = data_Munk::FaultRegisterType::FAULT_REGISTER_1, const unsigned int &code = 0);

    FaultRegisterState(const FaultRegisterState &copy);

    ~FaultRegisterState() = default;

public:
    void updateRegisterType(const data_Munk::FaultRegisterType &registerType);

public:
    data_Munk::FaultRegisterType getFaultRegister() const;

    std::vector<std::string> getCurrentFaultCodes() const;

    bool doesFaultExist() const;

private:
    void parseFaultCode();

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    FaultRegisterState& operator = (const FaultRegisterState &rhs)
    {
        this->currentRegister = rhs.currentRegister;
        this->faultCode = rhs.faultCode;
        this->faultErrors = rhs.faultErrors;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const FaultRegisterState &rhs)
    {
        if(this->temperature_Board != rhs.temperature_Board){
            return false;
        }
        if(this->faultCode != rhs.faultCode){
            return false;
        }
        if(this->faultErrors != rhs.faultErrors){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const FaultRegisterState &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int temperature_Board = 0;
    double temperatureStatus_1 = 0.0;
    double temperatureStatus_2 = 0.0;
};

} //end of namespace

#endif // FAULT_REGISTER_STATE_H
