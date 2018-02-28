#include "tuple_sensor_string.h"

TupleSensorString::TupleSensorString()
{

}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleSensorString::TupleSensorString(const TupleSensorString &copy)
{
    this->sourceName = copy.sourceName;
    this->sensorName = copy.sensorName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleSensorString::Type() const
{
    return "Sensor";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleSensorString::HumanName() const
{
    return this->sensorName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleSensorString::operator = (const TupleSensorString& rhs)
{
    this->sourceName = rhs.sourceName;
    this->sensorName = rhs.sensorName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleSensorString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->sourceName > ((TupleSensorString*)&rhs)->sourceName)
        return false;
    if(this->sourceName < ((TupleSensorString*)&rhs)->sourceName)
        return true;

    if(this->sensorName >= ((TupleSensorString*)&rhs)->sensorName)
        return false;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleSensorString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->sourceName != ((TupleSensorString*)&rhs)->sourceName)
        return false;

    if(this->sensorName != ((TupleSensorString*)&rhs)->sensorName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleSensorString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

