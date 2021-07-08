#include "ph_dimension.h"

namespace common_data {

//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
PHDimension::PHDimension(const pHUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
PHDimension::PHDimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((PHDimension*)&that)->m_type;
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool PHDimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((PHDimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions PHDimension::getType() const
{
    return TEMPERATURE;
}

//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string PHDimension::ShortHand() const
{
    switch(m_type)
    {
    case pHUnit::UNIT_BASE:
        return "pH";
    default:
        throw new std::runtime_error("Unknown pH Unit");
    }
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* PHDimension::Copy() const
{
    return new PHDimension(this->m_type);
}


//!
//! \brief Return the default unit for this dimension
//! \return Default unit
//!
pHUnit PHDimension::BaseUnit() const
{
    return pHUnit::UNIT_BASE;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's default unit.
//! \return Ratio of default unit over unit known by object.
//!
double PHDimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case pHUnit::UNIT_BASE:
        return 1.0;
    default:
        throw new std::runtime_error("Unkown Temperature Unit");
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double PHDimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double PHDimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}

} //end of namespace common_data

