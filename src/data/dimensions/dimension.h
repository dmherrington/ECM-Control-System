#ifndef UNITS_H
#define UNITS_H

#include <exception>
#include <stdexcept>

#include <string>
#include <sstream>

#include <QList>
#include <QString>

namespace common_data {


enum Dimensions
{
    POSITION,
    TIME,
    VOLTAGE,
    MAREA,
    DIMENSIONS_NR
};

//!
//! \brief Basic interface of a dimension
//!
class IDimension
{
public:

    //!
    //! \brief Get the type of dimension.
    //! \return Type of dimension.
    //!
    virtual Dimensions getType() const = 0;



    //!
    //! \brief Short hand notation of dimension
    //! \return Short hand notation
    //!
    virtual std::string ShortHand() const = 0;


    //!
    //! \brief Equivilance operator for dimension
    //! \param rhs Right hand side of equivilance
    //! \return True if equal
    //!
    virtual bool operator ==(const IDimension &rhs) const = 0;


    //!
    //! \brief Create a copy of this dimension
    //!
    //! The caller becomes responsible for deleting the created element.
    //! \return Pointer to new object
    //!
    virtual IDimension* Copy() const = 0;


};


//!
//! \brief Interface defining how to interact with a dimension's units
//!
template< typename ENUM_TYPE >
class IDimensionUnits
{
    //!
    //! \brief Return the default unit for this dimension
    //! \return Default unit
    //!
    virtual ENUM_TYPE BaseUnit() const = 0;


    //!
    //! \brief Return the amount of the supplied unit in the dimension's default unit.
    //! \return Ratio of default unit to supplied unit.
    //!
    virtual double RatioToBaseUnit() const = 0;


    //!
    //! \brief Convert a value to the default unit from the unit contained in the object
    //! \param value Value to convert
    //! \return Converted value in unit of this object
    //!
    virtual double ConvertToBase(const double &value) const = 0;


    //!
    //! \brief Convert a value from the default unit to the unit contained in the object
    //! \param value Value to convert
    //! \return Converted value in default unit of the dimension
    //!
    virtual double ConvertFromBase(const double &value) const = 0;

};



} //end DimensionalAnalysis

#endif // UNITS_H
