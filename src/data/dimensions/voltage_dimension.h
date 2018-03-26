#ifndef VOLTAGE_DIMENSION_H
#define VOLTAGE_DIMENSION_H

#include "dimension.h"

namespace common_data {

//!
//! \brief Allowed units in voltage dimension
//!
enum class VoltageUnit
{
    UNIT_VOLTAGE_VOLTS,
    UNIT_VOLTAGE_MILLIVOLT,
    UNIT_VOLTAGE_MICROVOLT,
    UNIT_VOLTAGE_NR
};


//!
//! \brief Object representing a voltage dimension
//!
class VoltageDimension : public IDimension, IDimensionUnits<VoltageUnit>
{
public:


    //!
    //! \brief Default Constructor
    //! \param unit Unit of dimension
    //!
    VoltageDimension(const VoltageUnit &unit);


    //!
    //! \brief Construct position from existing IDimension object
    //! \param that existing IDimension object
    //!
    VoltageDimension(const IDimension &that);


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
    virtual VoltageUnit BaseUnit() const;


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

    VoltageUnit m_type;

};

} //END DimensionalAnalysis

#endif // VOLTAGE_DIMENSION_H
