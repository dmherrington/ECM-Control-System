#include "sensor_voltage.h"

namespace common_data
{


/*!
 * \brief Constructor
 * \param name Name of sensor
 */
SensorVoltage::SensorVoltage(const std::string &name)
    :Sensor(name)
{
}


/*!
 * \brief Get the voltage value held by the sensor.
 * \param unit Desired unit of voltage.
 * \return The tempture in the desired unit.
 */
double SensorVoltage::getVoltage(const VoltageUnit &unit) const
{
    return m_Volt * common_data::VoltageDimension(unit).RatioToBaseUnit();
}


/*!
 * \brief Set the voltage value.
 * \param value Voltage value to set to.
 * \param unit Unit of tempurature.
 */
void SensorVoltage::SetVoltage(const double &value, const VoltageUnit &unit)
{
    m_Volt = value / VoltageDimension(unit).RatioToBaseUnit();
}


//! Get the type of the concrete sensor
/*!
 *  \return Type of sensor
 */
SensorTypes SensorVoltage::getType() const
{
    return SENSOR_VOLTAGE;
}


//! Get the description of the concrete sensor
/*!
 *  \return Description of sensor
 */
std::string SensorVoltage::getDescription() const
{
    return "This sensor is used to hold a single voltage";
}

std::string SensorVoltage::getLoggingString() const
{
    VoltageDimension dimension(VoltageUnit::UNIT_VOLTAGE_VOLTS);
    std::string rtnStr = std::to_string(m_Volt) + "\t" + dimension.ShortHand();
    return rtnStr;
}

/*!
 * \brief Assign a data from a sensor to this instance.
 * \param S Sensor to assign to.
 */
void SensorVoltage::Assign(const Sensor *S)
{
    this->m_Volt = ((SensorVoltage*)S)->m_Volt;
}

}
