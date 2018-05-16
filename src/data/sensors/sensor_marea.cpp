#include "sensor_marea.h"

namespace common_data
{

/*!
 * \brief Constructor
 * \param name Name of sensor
 */
SensorMAREA::SensorMAREA(const std::string &name)
    :Sensor(name)
{
}


double SensorMAREA::getCurrentArea(const MAREAUnit &unit) const
{
    return m_IArea * common_data::MAREADimension(unit).RatioToBaseUnit();
}


/*!
 * \brief Set the voltage value.
 * \param value Voltage value to set to.
 * \param unit Unit of tempurature.
 */
void SensorMAREA::SetCurrentArea(const double &value, const MAREAUnit &unit)
{
    m_IArea = value / MAREADimension(unit).RatioToBaseUnit();
}


//! Get the type of the concrete sensor
/*!
 *  \return Type of sensor
 */
SensorTypes SensorMAREA::getType() const
{
    return SENSOR_MAREA;
}


//! Get the description of the concrete sensor
/*!
 *  \return Description of sensor
 */
std::string SensorMAREA::getDescription() const
{
    return "This sensor is used to hold the current area measured by an oscilliscope.";
}

std::string SensorMAREA::getLoggingString() const
{
    MAREADimension dimension(MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS);
    std::string rtnStr = std::to_string(m_IArea) + "\t" + dimension.ShortHand();
    return rtnStr;
}

/*!
 * \brief Assign a data from a sensor to this instance.
 * \param S Sensor to assign to.
 */
void SensorMAREA::Assign(const Sensor *S)
{
    this->m_IArea = ((SensorMAREA*)S)->m_IArea;
}

}
