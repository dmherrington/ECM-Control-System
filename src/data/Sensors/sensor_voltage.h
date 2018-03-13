#ifndef SENSOR_VOLTAGE_H
#define SENSOR_VOLTAGE_H

#include "../data_global.h"

#include "sensor.h"

#include "dimensions/voltage_dimension.h"

namespace data
{


/*!
 * \brief A Sensor to hold the voltage
 */
class SensorVoltage : public Sensor
{
public:

    /*!
     * \brief Constructor
     * \param name Name of sensor
     */
    SensorVoltage(const std::string &name);


    /*!
     * \brief Get the voltage value held by the sensor.
     * \param unit Desired unit of voltage.
     * \return The voltage in the disired unit.
     */
    double getVoltage(const data::VoltageUnit &unit) const;


    /*!
     * \brief Set the voltage value.
     * \param value Voltage value to set to.
     * \param unit Unit of voltage.
     */
    void SetVoltage(const double &value, const data::VoltageUnit &unit);


    //! Get the type of the concrete sensor
    /*!
     *  \return Type of sensor
     */
    virtual SensorTypes getType() const;

    //! Get the description of the concrete sensor
    /*!
     *  \return Description of sensor
     */
    virtual std::string getDescription() const;

    /*!
     * \brief Assign a data from a sensor to this instance.
     * \param S Sensor to assign to.
     */
    virtual void Assign(const Sensor* S);

private:
    double m_Volt;
};

} //Data Namespace

#endif // SENSOR_VOLTAGE_H
