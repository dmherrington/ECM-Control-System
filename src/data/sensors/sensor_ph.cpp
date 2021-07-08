#include "sensor_ph.h"

namespace common_data
{

/*!
 * \brief Constructor
 * \param name Name of sensor
 */
Sensor_pH::Sensor_pH(const std::string &name)
    :Sensor(name)
{
}


/*!
 * \brief Get the voltage value held by the sensor.
 * \param unit Desired unit of voltage.
 * \return The tempture in the desired unit.
 */
double Sensor_pH::getPH(const pHUnit &unit) const
{
    return m_ph * common_data::PHDimension(unit).RatioToBaseUnit();
}


/*!
 * \brief Set the voltage value.
 * \param value Voltage value to set to.
 * \param unit Unit of tempurature.
 */
void Sensor_pH::setPH(const double &value, const pHUnit &unit)
{
    m_ph = value / PHDimension(unit).RatioToBaseUnit();
}


//! Get the type of the concrete sensor
/*!
 *  \return Type of sensor
 */
SensorTypes Sensor_pH::getType() const
{
    return SENSOR_PH;
}


//! Get the description of the concrete sensor
/*!
 *  \return Description of sensor
 */
std::string Sensor_pH::getDescription() const
{
    return "This sensor is used to hold a single temperature value.";
}

std::string Sensor_pH::getLoggingString() const
{
    PHDimension dimension(pHUnit::UNIT_BASE);
    std::string rtnStr = std::to_string(m_ph) + "\t" + dimension.ShortHand();
    return rtnStr;
}

/*!
 * \brief Assign a data from a sensor to this instance.
 * \param S Sensor to assign to.
 */
void Sensor_pH::Assign(const Sensor *S)
{
    this->m_ph = ((Sensor_pH*)S)->m_ph;
}

} //end of namespace common_data
