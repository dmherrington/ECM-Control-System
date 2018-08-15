#include "position_dimension.h"
namespace common_data {

//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
PositionDimension::PositionDimension(const PositionUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
PositionDimension::PositionDimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((PositionDimension*)&that)->m_type;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions PositionDimension::getType() const
{
    return POSITION;
}


//!
//! \brief get index of enumeration describing current unit
//! \return index of enumeration
//!
size_t PositionDimension::getUnitIndex() const
{
    return m_type;
}


//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string PositionDimension::ShortHand() const
{
    switch(m_type)
    {
    case UNIT_POSITION_COUNTS:
        return "counts";
    case UNIT_POSITION_MICRO_METER:
        return "um";
    default:
        throw new std::runtime_error("Unknown Unit");
    }
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool PositionDimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((PositionDimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* PositionDimension::Copy() const
{
    return new PositionDimension(this->m_type);
}


//!
//! \brief Return the SI unit for this dimension
//! \return SI unit
//!
PositionUnit PositionDimension::BaseUnit() const
{
    return UNIT_POSITION_COUNTS;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's SI unit.
//! \return Ratio of SI unit to supplied unit.
//!
double PositionDimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case UNIT_POSITION_COUNTS:
        return 1.0;
    case UNIT_POSITION_MICRO_METER:
        return 0.1;
    default:
        throw;
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double PositionDimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double PositionDimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}

} // end of namespace common_data
