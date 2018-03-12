#ifndef TUPLE_MASTER_STRING_H
#define TUPLE_MASTER_STRING_H

#include <QString>
#include <QMetaType>

#include "common_global.h"
#include "tuple_generic.h"

namespace common {

//!
//! \brief A tuple to uniquly identify a master state in ECM
//!
class COMMONSHARED_EXPORT TupleMasterString : public TupleGeneric
{
public:

    //!
    //! \brief Default Constructor
    //!
    TupleMasterString();


    //!
    //! \brief Copy Constructor
    //! \param that Object to copy from
    //!
    TupleMasterString(const TupleMasterString& that);


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
    void operator= (const TupleMasterString& rhs);


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


    //! Unique identifier for a model
    QString modelName;

};

} // end of namespace ECMCore

Q_DECLARE_METATYPE(common::TupleMasterString)

#endif // TUPLE_MASTER_STRING_H
