#include "register_fault_state.h"
namespace DataParameter
{

//!
//! \brief RegisterStandardFaults::RegisterStandardFaults
//! \param type
//!
RegisterFaultState::RegisterFaultState(const Data::FaultRegisterType &type):
    AbstractParameter()
{
    this->parameterCode = static_cast<int>(type);
    this->setReadorWrite(Data::ReadWriteType::READ);
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

} //end of namepsace DataParameter
