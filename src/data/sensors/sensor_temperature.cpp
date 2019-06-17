#include "sensor_temperature.h"

namespace common_data
{


/*!
 * \brief Constructor
 * \param name Name of sensor
 */
SensorTemperature::SensorTemperature(const std::string &name)
    :Sensor(name)
{
}


/*!
 * \brief Get the voltage value held by the sensor.
 * \param unit Desired unit of voltage.
 * \return The tempture in the desired unit.
 */
double SensorTemperature::getTemperature(const TemperatureUnit &unit) const
{
    return m_temp * common_data::TemperatureDimension(unit).RatioToBaseUnit();
}


/*!
 * \brief Set the voltage value.
 * \param value Voltage value to set to.
 * \param unit Unit of tempurature.
 */
void SensorTemperature::setTemperature(const double &value, const TemperatureUnit &unit)
{
    m_temp = value / TemperatureDimension(unit).RatioToBaseUnit();
}


//! Get the type of the concrete sensor
/*!
 *  \return Type of sensor
 */
SensorTypes SensorTemperature::getType() const
{
    return SENSOR_TEMPERATURE;
}


//! Get the description of the concrete sensor
/*!
 *  \return Description of sensor
 */
std::string SensorTemperature::getDescription() const
{
    return "This sensor is used to hold a single temperature value.";
}

std::string SensorTemperature::getLoggingString() const
{
    TemperatureDimension dimension(TemperatureUnit::UNIT_FARENHEIT);
    std::string rtnStr = std::to_string(m_temp) + "\t" + dimension.ShortHand();
    return rtnStr;
}

/*!
 * \brief Assign a data from a sensor to this instance.
 * \param S Sensor to assign to.
 */
void SensorTemperature::Assign(const Sensor *S)
{
    this->m_temp = ((SensorTemperature*)S)->m_temp;
}

} //end of namespace common_data
