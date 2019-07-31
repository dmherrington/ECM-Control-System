#include "sensor_conductivity.h"

namespace common_data
{

/*!
 * \brief Constructor
 * \param name Name of sensor
 */
Sensor_Conductivity::Sensor_Conductivity(const std::string &name)
    :Sensor(name)
{
}


/*!
 * \brief Get the voltage value held by the sensor.
 * \param unit Desired unit of voltage.
 * \return The tempture in the desired unit.
 */
double Sensor_Conductivity::getConductivity(const ConductivityUnit &unit) const
{
    return m_Conductivity * common_data::ConductivityDimension(unit).RatioToBaseUnit();
}


/*!
 * \brief Set the voltage value.
 * \param value Voltage value to set to.
 * \param unit Unit of tempurature.
 */
void Sensor_Conductivity::setConductivity(const double &value, const ConductivityUnit &unit)
{
    m_Conductivity = value / ConductivityDimension(unit).RatioToBaseUnit();
}


//! Get the type of the concrete sensor
/*!
 *  \return Type of sensor
 */
SensorTypes Sensor_Conductivity::getType() const
{
    return SensorTypes::SENSOR_CONDUCTIVITY;
}


//! Get the description of the concrete sensor
/*!
 *  \return Description of sensor
 */
std::string Sensor_Conductivity::getDescription() const
{
    return "This sensor is used to hold a single temperature value.";
}

std::string Sensor_Conductivity::getLoggingString() const
{
    ConductivityDimension dimension(ConductivityUnit::UNIT_BASE);
    std::string rtnStr = std::to_string(m_Conductivity) + "\t" + dimension.ShortHand();
    return rtnStr;
}

/*!
 * \brief Assign a data from a sensor to this instance.
 * \param S Sensor to assign to.
 */
void Sensor_Conductivity::Assign(const Sensor *S)
{
    this->m_Conductivity = ((Sensor_Conductivity*)S)->m_Conductivity;
}

} //end of namespace common_data

