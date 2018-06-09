#include "tuple_profile_variable_string.h"

namespace common {

TupleProfileVariableString::TupleProfileVariableString(const QString &program, const QString &profile, const QString &variable)
{
    this->programName = program;
    this->profileName = profile;
    this->variableName = variable;
}

//!
//! \brief Copy Constructor
//! \param that Object to copy from
//!
TupleProfileVariableString::TupleProfileVariableString(const TupleProfileVariableString &copy)
{
    this->programName = copy.programName;
    this->profileName = copy.profileName;
    this->variableName = copy.variableName;
}


//!
//! \brief Type of tuple object this is
//! \return String indicating type
//!
QString TupleProfileVariableString::Type() const
{
    return "Profile Variable String";
}


//!
//! \brief method to find human readable name
//! \return string name
//!
QString TupleProfileVariableString::HumanName() const
{
    return this->variableName;
}


//!
//! \brief Assignment operator
//! \param rhs Right hand side of assignment
//!
void TupleProfileVariableString::operator = (const TupleProfileVariableString& rhs)
{
    this->programName = rhs.programName;
    this->profileName = rhs.profileName;
    this->variableName = rhs.variableName;
}


//!
//! \brief Less than operator required by some Qt containers
//! \param rhs Right hand side of assignment
//! \return true is less than, false otherwise
//!
bool TupleProfileVariableString::operator< (const TupleGeneric& rhs) const
{
    if(*this == rhs)
        return false;

    if(this->Type() != rhs.Type())
        return this->Type() < rhs.Type();

    if(this->programName > ((TupleProfileVariableString*)&rhs)->programName)
        return false;
    if(this->programName < ((TupleProfileVariableString*)&rhs)->programName)
        return true;


    if(this->profileName > ((TupleProfileVariableString*)&rhs)->profileName)
        return false;
    if(this->profileName < ((TupleProfileVariableString*)&rhs)->profileName)
        return true;


    if(this->variableName >= ((TupleProfileVariableString*)&rhs)->variableName)
        return false;

    return true;
}


//!
//! \brief Equivilance operator
//! \param rhs Right hand side of equivilance
//! \return true if equivilant
//!
bool TupleProfileVariableString::operator==(const TupleGeneric& rhs) const
{
    if(typeid(*this) != typeid(rhs))
        return false;

    if(this->programName != ((TupleProfileVariableString*)&rhs)->programName)
        return false;

    if(this->profileName != ((TupleProfileVariableString*)&rhs)->profileName)
        return false;

    if(this->variableName != ((TupleProfileVariableString*)&rhs)->variableName)
        return false;

    return true;
}


//!
//! \brief Not-Equivilance operator
//! \param rhs Right hand side of non-equivilance
//! \return true if not equivilant
//!
bool TupleProfileVariableString::operator!=(const TupleGeneric& rhs) const
{
    return !((*this) == rhs);
}

} //end of namespace common
