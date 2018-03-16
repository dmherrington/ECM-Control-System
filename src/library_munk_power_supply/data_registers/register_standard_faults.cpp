#include "register_fault_state.h"


namespace registers_Munk {

//!
//! \brief RegisterStandardFaults::RegisterStandardFaults
//! \param type
//!
RegisterFaultState::RegisterFaultState(const data_Munk::FaultRegisterType &type):
    AbstractParameter()
{
    this->parameterCode = static_cast<int>(type);
    this->setReadorWrite(data_Munk::ReadWriteType::READ);
}

//!
//! \brief RegisterStandardFaults::RegisterStandardFaults
//! \param copy
//!
RegisterFaultState::RegisterFaultState(const RegisterFaultState &copy):
    AbstractParameter(copy)
{

}


ParameterType RegisterFaultState::getParameterType() const
{
    return ParameterType::FAULT_STATE;
}

std::string RegisterFaultState::getDescription() const
{
    std::string str = "";
    return str;
}

QByteArray RegisterFaultState::getByteArray() const
{
    QByteArray ba;
    return ba;
}

QByteArray RegisterFaultState::getExpectedResponse() const
{
    QByteArray ba;
    return ba;
}

} //end of namespace registers_Munk

