#include "register_flow_rate.h"

namespace westinghousePump{
namespace registers{

Register_FlowRate::Register_FlowRate():
    AbstractRegister(RegisterTypeToInt(RegisterType::FLOWRATE))
{

}
Register_FlowRate::Register_FlowRate(const Register_FlowRate &copy):
    AbstractRegister(copy)
{

}

//!
//! \brief getDescription
//! \return
//!
std::string Register_FlowRate::getDescription() const
{
    return "";
}

//!
//! \brief getRegisterType
//! \return
//!
RegisterType Register_FlowRate::getRegisterType() const
{
    return RegisterType::OPERATION_SIGNAL;
}

//!
//! \brief getByteArray
//! \return
//!
QByteArray Register_FlowRate::getByteArray() const
{
    //convert the liters per minute to gallons per minute
    double GPM = flowRate * 0.264172;
    uint32_t desiredFlow = GPM * 1000.0;

    QByteArray data;
    uint8_t HIGHBType = (uint8_t)((desiredFlow & 0xFF00) >> 8);
    uint8_t LOWBType = (uint8_t)(desiredFlow & 0x00FF);

    data.append(HIGHBType);
    data.append(LOWBType);

    return data;
}

void Register_FlowRate::setVolumetricFlow(const double &value)
{
    this->flowRate = value;
}

double Register_FlowRate::getVolumetricFlow() const
{
    return this->flowRate;
}

} //end of namespace registers
} //end of namespace westinghousePump
