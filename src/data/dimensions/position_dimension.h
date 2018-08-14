#ifndef POSITION_DIMENSION_H
#define POSITION_DIMENSION_H

#include "dimension.h"

namespace common_data
{

//!
//! \brief Allowed units in position dimenson.
//!
enum PositionUnit
{
    UNIT_POSITION_COUNTS,
    UNIT_POSITION_MICRO_METER,
    UNIT_POSITION_NR
};

//!
//! \brief Object representing the position dimension
//!
class PositionDimension : public IDimension, IDimensionUnits<PositionUnit>
{
public:


    //!
    //! \brief Default Constructor
    //! \param unit Unit of dimension
    //!
    PositionDimension(const PositionUnit &unit);


    //!
    //! \brief Construct position from existing IDimension object
    //! \param that existing IDimension object
    //!
    PositionDimension(const IDimension &that);


    //!
    //! \brief Get the type of dimension.
    //! \return Type of dimension.
    //!
    virtual Dimensions getType() const;


    //!
    //! \brief get index of enumeration describing current unit
    //! \return index of enumeration
    //!
    virtual size_t getUnitIndex() const;


    //!
    //! \brief Short hand notation of dimension
    //! \return Short hand notation
    //!
    virtual std::string ShortHand() const;


    //!
    //! \brief Equivilance operator for dimension
    //! \param rhs Right hand side of equivilance
    //! \return True if equal
    //!
    virtual bool operator ==(const IDimension &rhs) const;


    //!
    //! \brief Create a copy of this dimension
    //!
    //! The caller becomes responsible for deleting the created element.
    //! \return Pointer to new object
    //!
    virtual IDimension* Copy() const;


    //!
    //! \brief Return the SI unit for this dimension
    //! \return SI unit
    //!
    virtual PositionUnit BaseUnit() const;


    //!
    //! \brief Return the amount of the supplied unit in the dimension's SI unit.
    //! \return Ratio of SI unit to supplied unit.
    //!
    virtual double RatioToBaseUnit() const;


    //!
    //! \brief Convert a value to the base unit from the unit contained in the object
    //! \param value Value to convert
    //! \return Converted value in unit of this object
    //!
    virtual double ConvertToBase(const double &value) const;


    //!
    //! \brief Convert a value from the default unit to the unit contained in the object
    //! \param value Value to convert
    //! \return Converted value in default unit of the dimension
    //!
    virtual double ConvertFromBase(const double &value) const;

private:

    PositionUnit m_type;

};


} //end of namespace common_data
#endif // POSITION_DIMENSION_H
