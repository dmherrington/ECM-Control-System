#include "register_flow_rate.h"


namespace registers_WestinghousePump{

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

void Register_FlowRate::parseFromArray(const QByteArray &msg)
{
    this->setSlaveAddress(msg.at(0));
    //parse if it is read/write
    if(msg.at(1) == static_cast<int>(data_WestinghousePump::ReadWriteType::READ))
        this->setReadorWrite(data_WestinghousePump::ReadWriteType::READ);
    else
        this->setReadorWrite(data_WestinghousePump::ReadWriteType::WRITE);

    uint8_t dataHi = msg.at(4);
    uint8_t dataLo = msg.at(5);
    uint32_t setFlow = dataLo | (dataHi<<8);
    double GPM = setFlow / 1000.0;
    this->flowRate = GPM/0.264172;
}

void Register_FlowRate::setVolumetricFlow(const double &value)
{
    this->flowRate = value;
}

double Register_FlowRate::getVolumetricFlow() const
{
    return this->flowRate;
}

} //end of namespace registers_WestinghousePump 

