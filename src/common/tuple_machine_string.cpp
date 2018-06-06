#include "tuple_machine_string.h"

namespace common {

TupleMachineString::TupleMachineString(const QString &source, const QString &state)
{
    this->sourceName = source;
    this->stateName = state;
}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleMachineString::TupleMachineString(const TupleMachineString &copy)
{
    this->sourceName = copy.sourceName;
    this->stateName = copy.stateName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleMachineString::Type() const
{
    return "Machine String";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleMachineString::HumanName() const
{
    return this->stateName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleMachineString::operator = (const TupleMachineString& rhs)
{
    this->sourceName = rhs.sourceName;
    this->stateName = rhs.stateName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleMachineString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->sourceName > ((TupleMachineString*)&rhs)->sourceName)
        return false;
    if(this->sourceName < ((TupleMachineString*)&rhs)->sourceName)
        return true;

    if(this->stateName >= ((TupleMachineString*)&rhs)->stateName)
        return false;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleMachineString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->sourceName != ((TupleMachineString*)&rhs)->sourceName)
        return false;

    if(this->stateName != ((TupleMachineString*)&rhs)->stateName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleMachineString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace common
