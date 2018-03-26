#include "tuple_positional_string.h"

namespace common {

//!
//! \brief Default Constructor
//!
TuplePositionalString::TuplePositionalString()
{

}


//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TuplePositionalString::TuplePositionalString(const TuplePositionalString &that)
{
    this->axisName = that.axisName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TuplePositionalString::Type() const
{
    return "Master";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TuplePositionalString::HumanName() const
{
    return this->axisName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TuplePositionalString::operator = (const TuplePositionalString& rhs)
{
    this->axisName = rhs.axisName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TuplePositionalString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->axisName > ((TuplePositionalString*)&rhs)->axisName)
        return false;
    if(this->axisName < ((TuplePositionalString*)&rhs)->axisName)
        return true;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TuplePositionalString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->axisName != ((TuplePositionalString*)&rhs)->axisName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TuplePositionalString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace common
