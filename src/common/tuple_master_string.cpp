#include "tuple_master_string.h"

namespace ECMCore
{


//!
//! \brief Default Constructor
//!
TupleMasterString::TupleMasterString()
{

}


//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleMasterString::TupleMasterString(const TupleMasterString &that)
{
    this->modelName = that.modelName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleMasterString::Type() const
{
    return "Master";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleMasterString::HumanName() const
{
    return this->modelName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleMasterString::operator = (const TupleMasterString& rhs)
{
    this->modelName = rhs.modelName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleMasterString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->modelName > ((TupleMasterString*)&rhs)->modelName)
        return false;
    if(this->modelName < ((TupleMasterString*)&rhs)->modelName)
        return true;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleMasterString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->modelName != ((TupleMasterString*)&rhs)->modelName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleMasterString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

}

