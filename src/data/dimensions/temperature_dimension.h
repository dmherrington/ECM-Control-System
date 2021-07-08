#ifndef TEMPERATURE_DIMENSION_H
#define TEMPERATURE_DIMENSION_H

#include "dimension.h"

namespace common_data {

//!
//! \brief Allowed units in temperature dimension
//!
enum class TemperatureUnit
{
    UNIT_FAHRENHEIT,
    UNIT_CELSIUS,
    UNIT_TEMPERATURE_NR
};


//!
//! \brief Object representing a voltage dimension
//!
class TemperatureDimension : public IDimension, IDimensionUnits<TemperatureUnit>
{
public:


    //!
    //! \brief Default Constructor
    //! \param unit Unit of dimension
    //!
    TemperatureDimension(const TemperatureUnit &unit);


    //!
    //! \brief Construct position from existing IDimension object
    //! \param that existing IDimension object
    //!
    TemperatureDimension(const IDimension &that);


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
    virtual TemperatureUnit BaseUnit() const;


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

    TemperatureUnit m_type;

};

} //end of namespace common_data

#endif // TEMPERATURE_DIMENSION_H
