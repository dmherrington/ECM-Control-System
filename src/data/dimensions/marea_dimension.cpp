#include "marea_dimension.h"

namespace common_data
{


//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
MAREADimension::MAREADimension(const MAREAUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
MAREADimension::MAREADimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((MAREADimension*)&that)->m_type;
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool MAREADimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((MAREADimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions MAREADimension::getType() const
{
    return MAREA;
}


//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string MAREADimension::ShortHand() const
{
    switch(m_type)
    {
    case MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS:
        return "A-s";
    default:
        throw new std::runtime_error("Unkown Unit");
    }
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* MAREADimension::Copy() const
{
    return new MAREADimension(this->m_type);
}


//!
//! \brief Return the default unit for this dimension
//! \return Default unit
//!
MAREAUnit MAREADimension::BaseUnit() const
{
    return MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's default unit.
//! \return Ratio of default unit over unit known by object.
//!
double MAREADimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS:
        return 1.0;
    default:
        throw new std::runtime_error("Unkown Unit");
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double MAREADimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double MAREADimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}


} //end of namespace common_data
