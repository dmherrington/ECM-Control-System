#include "time_dimension.h"


namespace common_data
{


//!
//! \brief Default Constructor
//! \param unit Unit of dimension
//!
TimeDimension::TimeDimension(const TimeUnit &unit)
{
    m_type = unit;
}


//!
//! \brief Construct position from existing IDimension object
//! \param that existing IDimension object
//!
TimeDimension::TimeDimension(const IDimension &that)
{
    if(this->getType() != that.getType())
        throw std::runtime_error("Uncompatable assignment");

    m_type = ((TimeDimension*)&that)->m_type;
}


//!
//! \brief Get the type of dimension.
//! \return Type of dimension.
//!
Dimensions TimeDimension::getType() const
{
    return TIME;
}


//!
//! \brief get index of enumeration describing current unit
//! \return index of enumeration
//!
size_t TimeDimension::getUnitIndex() const
{
    return m_type;
}


//!
//! \brief Short hand notation of dimension
//! \return Short hand notation
//!
std::string TimeDimension::ShortHand() const
{
    switch(m_type)
    {
    case UNIT_TIME_SECOND:
        return "s";
    case UNIT_TIME_MILLISECOND:
        return "ms";
    case UNIT_TIME_MICROSECOND:
        return "μs";
    default:
        throw new std::runtime_error("Unknown Unit");
    }
}


//!
//! \brief Equivilance operator for dimension
//! \param rhs Right hand side of equivilance
//! \return True if equal
//!
bool TimeDimension::operator ==(const IDimension &rhs) const
{
    if(this->getType() != rhs.getType())
        return false;

    if(m_type != ((TimeDimension*)&rhs)->m_type)
        return false;

    return true;
}


//!
//! \brief Create a copy of this dimension
//!
//! The caller becomes responsible for deleting the created element.
//! \return Pointer to new object
//!
IDimension* TimeDimension::Copy() const
{
    return new TimeDimension(this->m_type);
}


//!
//! \brief Return the SI unit for this dimension
//! \return SI unit
//!
TimeUnit TimeDimension::BaseUnit() const
{
    return UNIT_TIME_SECOND;
}


//!
//! \brief Return the amount of the supplied unit in the dimension's SI unit.
//! \return Ratio of SI unit to supplied unit.
//!
double TimeDimension::RatioToBaseUnit() const
{
    switch(m_type)
    {
    case UNIT_TIME_SECOND:
        return 1.0;
        break;
    case UNIT_TIME_MILLISECOND:
        return 0.001;
    case UNIT_TIME_MICROSECOND:
        return 0.000001;
    default:
        throw;
    }
}


//!
//! \brief Convert a value to the base unit from the unit contained in the object
//! \param value Value to convert
//! \return Converted value in unit of this object
//!
double TimeDimension::ConvertToBase(const double &value) const
{
    return value * RatioToBaseUnit();
}


//!
//! \brief Convert a value from the default unit to the unit contained in the object
//! \param value Value to convert
//! \return Converted value in default unit of the dimension
//!
double TimeDimension::ConvertFromBase(const double &value) const
{
    return value / RatioToBaseUnit();
}


} //END DimensionalAnalysis
