#include "tuple_measurement.h"

TupleMeasurement::TupleMeasurement()
{

}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleMeasurement::TupleMeasurement(const TupleMeasurement &copy)
{
    this->measurementName = that.measurementName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
string TupleMeasurement::Type() const
{
    return "Sensor";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
string TupleMeasurement::HumanName() const
{
    return this->measurementName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleMeasurement::operator = (const TupleMeasurement& rhs)
{
    this->measurementName = rhs.measurementName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleMeasurement::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

//    if(this->labName > ((TupleSensorString*)&rhs)->labName)
//        return false;
//    if(this->labName < ((TupleSensorString*)&rhs)->labName)
//        return true;

//    if(this->modelName > ((TupleSensorString*)&rhs)->modelName)
//        return false;
//    if(this->modelName < ((TupleSensorString*)&rhs)->modelName)
//        return true;

//    if(this->entityName > ((TupleSensorString*)&rhs)->entityName)
//        return false;
//    if(this->entityName < ((TupleSensorString*)&rhs)->entityName)
//        return true;

    if(this->measurementName >= ((TupleMeasurement*)&rhs)->measurementName)
        return false;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleMeasurement::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->measurementName != ((TupleMeasurement*)&rhs)->measurementName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleMeasurement::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

