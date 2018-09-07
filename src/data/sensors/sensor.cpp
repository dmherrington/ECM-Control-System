#include "sensor.h"

#include <stdexcept>

namespace common_data
{


//! Constructor
/*!
 *  \param name Name of sensor
 */
Sensor::Sensor(const std::string &name)
{
    m_Name = name;
}

//! Destructor
Sensor::~Sensor()
{
}


//! Get the name of this sensor
/*!
 *  \return Name of sensor
 */
std::string Sensor::getName() const
{
    return m_Name;
}


//! Assignment operator
Sensor& Sensor::operator =(const Sensor &that)
{
    this->m_Name = that.m_Name;
    return *this;
}


//! Convert a SensorType enum to a String
//!
//!  \param SensorType enum value
//!  \return String value corresponding to the enumeration
//!
std::string Sensor::SensorTypeToString(const SensorTypes &sensorType)
{
    std::string returnString;
    switch(sensorType)
    {
    case SENSOR_VOLTAGE:
        returnString = "Voltage";
        break;
    case SENSORTYPES_NR_ITEMS:
        returnString = "Sensor Type Number";
        break;
    default:
        throw new std::runtime_error("Unknown enumeration seen");
    }

    return returnString;
}

//!
//! \brief static method to convert a SensorTypes enum to a string
//! \param unitString String to convert
//! \return typeEnum SensorType enum corresponding to unitString
//!
SensorTypes Sensor::StringToSensorTypeEnum(const std::string &unitString)
{
    SensorTypes typeEnum;
    if(unitString == "Voltage")
        typeEnum = SENSOR_VOLTAGE;
    else if(unitString == "Sensor Type Number")
        typeEnum = SENSORTYPES_NR_ITEMS;
    else
        throw new std::runtime_error("Unknown String seen");

    return typeEnum;
}


} // Data
