#ifndef TUPLE_MACHINE_STRING_H
#define TUPLE_MACHINE_STRING_H

#include <QString>
#include "tuple_generic.h"

namespace common {

class COMMONSHARED_EXPORT TupleMachineString : public TupleGeneric
{
public:

    TupleMachineString(const std::string &source = "", const std::string &sensor = "", const std::string &measure = "");

    TupleMachineString(const TupleMachineString &copy);

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
    void operator= (const TupleSensorString &rhs);


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

    //! Name of the source originating the new state
    QString sourceName;

    //! Name of the actual new state of the device
    QString stateName;

    //! Name of the measurement
    QString measurementName;

};

} //end of namespace common

Q_DECLARE_METATYPE(common::TupleMachineString)

#endif // TUPLE_MACHINE_STRING_H
