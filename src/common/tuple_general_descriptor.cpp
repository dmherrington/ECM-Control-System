#include "tuple_general_descriptor.h"

namespace common {

//!
//! \brief Default Constructor
//!
TupleGeneralDescriptorString::TupleGeneralDescriptorString()
{

}

TupleGeneralDescriptorString::TupleGeneralDescriptorString(const std::string &descriptor)
{
    this->description = QString::fromStdString(descriptor);
}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleGeneralDescriptorString::TupleGeneralDescriptorString(const TupleGeneralDescriptorString &that)
{
    this->description = that.description;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleGeneralDescriptorString::Type() const
{
    return "General Description String";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleGeneralDescriptorString::HumanName() const
{
    return this->description;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleGeneralDescriptorString::operator = (const TupleGeneralDescriptorString& rhs)
{
    this->description = rhs.description;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleGeneralDescriptorString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->description > ((TupleGeneralDescriptorString*)&rhs)->description)
        return false;
    if(this->description < ((TupleGeneralDescriptorString*)&rhs)->description)
        return true;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleGeneralDescriptorString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->description != ((TupleGeneralDescriptorString*)&rhs)->description)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleGeneralDescriptorString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace common
