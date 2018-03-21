#ifndef SENSOR_MAREA_H
#define SENSOR_MAREA_H

#include "../data_global.h"

#include "sensor.h"

#include "dimensions/marea_dimension.h"

namespace common_data {


/*!
 * \brief A Sensor to hold the MAREA
 */
class SensorMAREA : public Sensor
{
public:

    /*!
     * \brief Constructor
     * \param name Name of sensor
     */
    SensorMAREA(const std::string &name);


    double GetCurrentArea(const common_data::MAREAUnit &unit) const;


    /*!
     * \brief Set the voltage value.
     * \param value Voltage value to set to.
     * \param unit Unit of voltage.
     */
    void SetCurrentArea(const double &value, const common_data::MAREAUnit &unit);


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
    double m_Area;
};

} //end of common_data namespace
#endif // SENSOR_MAREA_H
