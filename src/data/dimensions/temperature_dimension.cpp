#include "temperature_dimension.h"

namespace common_data
{


//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
TemperatureDimension::TemperatureDimension(const TemperatureUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
TemperatureDimension::TemperatureDimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((TemperatureDimension*)&that)->m_type;
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool TemperatureDimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((TemperatureDimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions TemperatureDimension::getType() const
{
    return TEMPERATURE;
}

//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string TemperatureDimension::ShortHand() const
{
    switch(m_type)
    {
    case TemperatureUnit::UNIT_FAHRENHEIT:
        return "F";
    case TemperatureUnit::UNIT_CELSIUS:
        return "C";
    default:
        throw new std::runtime_error("Unknown Voltage Unit");
    }
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* TemperatureDimension::Copy() const
{
    return new TemperatureDimension(this->m_type);
}


//!
//! \brief Return the default unit for this dimension
//! \return Default unit
//!
TemperatureUnit TemperatureDimension::BaseUnit() const
{
    return TemperatureUnit::UNIT_FAHRENHEIT;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's default unit.
//! \return Ratio of default unit over unit known by object.
//!
double TemperatureDimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case TemperatureUnit::UNIT_FAHRENHEIT:
        return 1.0;
    case TemperatureUnit::UNIT_CELSIUS:
        return 1000.0;
    default:
        throw new std::runtime_error("Unkown Temperature Unit");
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double TemperatureDimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double TemperatureDimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}


} //end of namespace common_data
