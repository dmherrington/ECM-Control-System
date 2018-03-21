#ifndef MAREA_DIMENSION_H
#define MAREA_DIMENSION_H

#include "dimension.h"

namespace common_data {

//!
//! \brief Allowed units in voltage dimension
//!
enum MAREAUnit
{
    UNIT_VOLTAGE_AMPERE_SECONDS,
    UNIT_VOLTAGE_NR
};


//!
//! \brief Object representing a voltage dimension
//!
class MAREADimension : public IDimension, IDimensionUnits<MAREAUnit>
{
public:


    //!
    //! \brief Default Constructor
    //! \param unit Unit of dimension
    //!
    MAREADimension(const MAREAUnit &unit);


    //!
    //! \brief Construct position from existing IDimension object
    //! \param that existing IDimension object
    //!
    MAREADimension(const IDimension &that);


    //!
    //! \brief Equivilance operator for dimension
    //! \param rhs Right hand side of equivilance
    //! \return True if equal
    //!
    bool operator ==(const IDimension &rhs) const;


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
    //! \brief Create a copy of this dimension
    //!
    //! The caller becomes responsible for deleting the created element.
    //! \return Pointer to new object
    //!
    virtual IDimension* Copy() const;


    //!
    //! \brief Return the default unit for this dimension
    //! \return Default unit
    //!
    virtual MAREAUnit BaseUnit() const;


    //!
    //! \brief Return the amount of the supplied unit in the dimension's SI unit.
    //! \return Ratio of default unit to supplied unit.
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

    MAREAUnit m_type;

};

} //END DimensionalAnalysis

#endif // MAREA_DIMENSION_H
