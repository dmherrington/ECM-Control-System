#ifndef TUPLE_PROFILE_VARIABLE_STRING_H
#define TUPLE_PROFILE_VARIABLE_STRING_H

#include <QString>
#include "tuple_generic.h"

namespace common {

class COMMONSHARED_EXPORT TupleProfileVariableString : public TupleGeneric
{
public:

    TupleProfileVariableString(const QString &program = "", const QString &profile = "", const QString &variable = "");

    TupleProfileVariableString(const TupleProfileVariableString &copy);

    //!
    //! \brief Type of tuple object this is
    //! \return String indicating type
    //!
    QString Type() const override;


    //!
    //! \brief method to find human readable name
    //! \return string name
    //!
    QString HumanName() const override;


    //!
    //! \brief Assignment operator
    //! \param rhs Right hand side of assignment
    //!
    void operator= (const TupleProfileVariableString &rhs);


    //!
    //! \brief Less than operator required by some Qt containers
    //! \param rhs Right hand side of assignment
    //! \return true is less than, false otherwise
    //!
    virtual bool operator< (const TupleGeneric& rhs) const;


    //!
    //! \brief Equivilance operator
    //! \param rhs Right hand side of equivilance
    //! \return true if equivilant
    //!
    virtual bool operator==(const TupleGeneric& rhs) const;


    //!
    //! \brief Not-Equivilance operator
    //! \param rhs Right hand side of non-equivilance
    //! \return true if not equivilant
    //!
    virtual bool operator!=(const TupleGeneric& rhs) const;

    //! Name of the source originating the sensor
    QString programName;

    //! Name of profile in which the variable was contained
    QString profileName;

    //! Name of the variable
    QString variableName;

};

} //end of namespace common

Q_DECLARE_METATYPE(common::TupleProfileVariableString)

#endif // TUPLE_PROFILE_VARIABLE_STRING_H
