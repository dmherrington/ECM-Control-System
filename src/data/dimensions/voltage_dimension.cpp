#include "voltage_dimension.h"

namespace common_data
{


//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
VoltageDimension::VoltageDimension(const VoltageUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
VoltageDimension::VoltageDimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((VoltageDimension*)&that)->m_type;
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool VoltageDimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((VoltageDimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions VoltageDimension::getType() const
{
    return VOLTAGE;
}

//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string VoltageDimension::ShortHand() const
{
    switch(m_type)
    {
    case VoltageUnit::UNIT_VOLTAGE_VOLTS:
        return "v";
    case VoltageUnit::UNIT_VOLTAGE_MILLIVOLT:
        return "mv";
    case VoltageUnit::UNIT_VOLTAGE_MICROVOLT:
        return "uv";
    default:
        throw new std::runtime_error("Unknown Unit");
    }
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* VoltageDimension::Copy() const
{
    return new VoltageDimension(this->m_type);
}


//!
//! \brief Return the default unit for this dimension
//! \return Default unit
//!
VoltageUnit VoltageDimension::BaseUnit() const
{
    return VoltageUnit::UNIT_VOLTAGE_VOLTS;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's default unit.
//! \return Ratio of default unit over unit known by object.
//!
double VoltageDimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case VoltageUnit::UNIT_VOLTAGE_VOLTS:
        return 1.0;
    case VoltageUnit::UNIT_VOLTAGE_MILLIVOLT:
        return 1000.0;
    case VoltageUnit::UNIT_VOLTAGE_MICROVOLT:
        return 1000.0 * 1000.0;
    default:
        throw new std::runtime_error("Unkown Unit");
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double VoltageDimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double VoltageDimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}


} //end of namespace common_data
