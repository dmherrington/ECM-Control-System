#ifndef SENSOR_TEMPERATURE_H
#define SENSOR_TEMPERATURE_H

#include "../data_global.h"

#include "sensor.h"

#include "../dimensions/temperature_dimension.h"

namespace common_data {


/*!
 * \brief A Sensor to hold the temperature
 */
class SensorTemperature : public Sensor
{
public:

    /*!
     * \brief Constructor
     * \param name Name of sensor
     */
    SensorTemperature(const std::string &name);


    /*!
     * \brief Get the voltage value held by the sensor.
     * \param unit Desired unit of voltage.
     * \return The voltage in the disired unit.
     */
    double getTemperature(const common_data::TemperatureUnit &unit) const;


    /*!
     * \brief Set the voltage value.
     * \param value Voltage value to set to.
     * \param unit Unit of voltage.
     */
    void setTemperature(const double &value, const common_data::TemperatureUnit &unit);


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
     * \brief getLoggingString
     * \return
     */
    std::string getLoggingString() const override;

    /*!
     * \brief Assign a data from a sensor to this instance.
     * \param S Sensor to assign to.
     */
    virtual void Assign(const Sensor* S);

    friend std::ostream& operator<< (std::ostream& stream, const SensorTemperature& data)
    {
        return stream << data.getLoggingString();
    }

private:
    double m_temp;
};

} //end of common_data namespace



#endif // SENSOR_TEMPERATURE_H
