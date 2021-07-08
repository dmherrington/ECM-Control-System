#ifndef SENSOR_H
#define SENSOR_H

#include "../data_global.h"

#include <string>

#include <istream>
#include <ostream>

namespace common_data
{

/*!
 * \brief Enumeration of the types of sensors that can be used
 */
enum SensorTypes
{
    SENSOR_PH,              //! A pH sensor
    SENSOR_CONDUCTIVITY,    //! A Conductivity sensor
    SENSOR_VOLTAGE,         //! A Voltage sensor
    SENSOR_MAREA,           //! A Current Area measurement
    SENSOR_TEMPERATURE,
    SENSORTYPES_NR_ITEMS    //! The number of sensor types
};

//! An absract sensor object
/*!
 *  This is the abstract object which is used as an entry and exit for the Lab API
 *  It is up to the process implimenting the API library to cast this object into the correct object (or fail if cant)
 */
class Sensor
{

public:


    //! Constructor
    /*!
     *  \param name Name of sensor
     */
    Sensor(const std::string &name);


    //! Destructor
    virtual ~Sensor();


    //! Get the name of this sensor
    /*!
     *  \return Name of sensor
     */
    std::string getName() const;


    //! Get the type of the concrete sensor
    /*!
     *  \return Type of sensor
     */
    virtual SensorTypes getType() const = 0;


    //! Get the description of the concrete sensor
    /*!
     *  \return Description of sensor
     */
    virtual std::string getDescription() const = 0;

    //!
    //! \brief getLoggingString
    //! \return
    //!
    virtual std::string getLoggingString() const = 0;


    /*!
     * \brief Assign a data from a sensor to this instance.
     * \param S Sensor to assign to.
     */
    virtual void Assign(const Sensor* S) = 0;


    //! Assignment operator
    Sensor& operator =(const Sensor &that);


    // //////////////////////////////////////////////////////////////
    // ////////////// STATIC METHODS ////////////////////////////////
    // //////////////////////////////////////////////////////////////

    //! Convert a SensorType enum to a String
    //!
    //!  \param SensorType enum value
    //!  \return String value corresponding to the enumeration
    //!
    static std::string SensorTypeToString(const SensorTypes &sensorType);

    //!
    //! \brief static method to convert a SensorTypes enum to a string
    //! \param unitString String to convert
    //! \return typeEnum SensorType enum corresponding to unitString
    //!
    static SensorTypes StringToSensorTypeEnum(const std::string &unitString);

    friend std::ostream& operator<< (std::ostream &stream, const Sensor &data)
    {
        return stream<<data.getLoggingString();
    }

private:

    //! Name of the sensor
    std::string m_Name;
};

} // Data namespace

#endif // SENSOR_H
