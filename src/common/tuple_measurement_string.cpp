#include "tuple_measurement_string.h"

namespace common {

TupleMeasurementString::TupleMeasurementString()
{

}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleMeasurementString::TupleMeasurementString(const TupleMeasurementString &copy)
{
    this->sourceName = copy.sourceName;
    this->measurementName = copy.measurementName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleMeasurementString::Type() const
{
    return "Measurement";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleMeasurementString::HumanName() const
{
    return this->measurementName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleMeasurementString::operator = (const TupleMeasurementString& rhs)
{
    this->sourceName = rhs.sourceName;
    this->measurementName = rhs.measurementName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleMeasurementString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->sourceName > ((TupleMeasurementString*)&rhs)->sourceName)
        return false;
    if(this->sourceName < ((TupleMeasurementString*)&rhs)->sourceName)
        return true;

    if(this->measurementName >= ((TupleMeasurementString*)&rhs)->measurementName)
        return false;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleMeasurementString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->sourceName != ((TupleMeasurementString*)&rhs)->sourceName)
        return false;

    if(this->measurementName != ((TupleMeasurementString*)&rhs)->measurementName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleMeasurementString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace common


