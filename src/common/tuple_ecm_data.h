#ifndef TUPLE_ECM_DATA_H
#define TUPLE_ECM_DATA_H

#include <stdexcept>

#include <QString>
#include <QHash>

#include "common.h"
#include "tuple_positional_string.h"
#include "tuple_profile_variable_string.h"
#include "tuple_sensor_string.h"

namespace common {

//!
//! \brief A container object for tuples that ECM uses to key data
//!
//! This object is to be utilized by users of ECM to key and access data.
//!
class COMMONSHARED_EXPORT TupleECMData
{
public:

    enum DataTypes
    {
        POSITION,
        PROFILE_VARIABLE,
        SENSOR,
        NOT_DEFINED
    };


    //!
    //! \brief Default Constructor
    //!
    TupleECMData();


    //!
    //! \brief Destructor
    //!
    ~TupleECMData();


    //!
    //! \brief Copy constructor
    //! \param that object to copy from
    //!
    TupleECMData(const TupleECMData &that);


    //!
    //! \brief Contruct from an Master tuple
    //! \param that tuple to key a master state
    //!
    TupleECMData(const TuplePositionalString &that);

    //!
    //! \brief Contruct from an Profile Variable tuple
    //! \param that tuple to key a Profile Variable state
    //!
    TupleECMData(const TupleProfileVariableString &that);

    //!
    //! \brief Contruct from tuple an Sensor tuple
    //! \param that tuple to key a sensor state
    //!
    TupleECMData(const TupleSensorString &that);

    //!
    //! \brief Get the type of this data
    //! \return Type
    //!
    DataTypes getType() const;


    //!
    //! \brief Retreive a pointer to the data
    //! \return Pointer to the data of the component
    //!
    TupleGeneric* getData() const;


    //!
    //! \brief Assignment operator
    //! \param rhs tuple container to assign from
    //!
    void operator=(const TupleECMData& rhs);


    //!
    //! \brief Less than operator on tuple held by two containers
    //! \param rhs right side of less than
    //! \return true if less than
    //!
    bool operator<(TupleECMData const& rhs) const;


    //!
    //! \brief Equivilance operator on tuple held by two containers
    //! \param rhs right side of equivilance
    //! \return true if equal
    //!
    bool operator==(const TupleECMData& rhs) const;


    //!
    //! \brief Non-Equivilance operator on tuple held by two containers
    //! \param rhs right side of non-equivilance
    //! \return true if not equal
    //!
    bool operator!=(const TupleECMData& rhs) const;


    //!
    //! \brief Delimit the names needed to reference the data by a string
    //! \param delimiter String to delement by
    //! \return
    //!
    QString DelimitData(const QString &delementor) const;


    uint ComputeHash() const;


    //!
    //! \brief Hash function
    //! \param key key to hash
    //! \param seed seed to hash
    //! \return Hash value
    //!
    COMMONSHARED_EXPORT friend uint qHash(const TupleECMData &key, uint seed = 0);

private:

    //! The tuple contained in this object
    TupleGeneric* m_Data;

    //! The type of data held by this object
    DataTypes m_Type;
};



} //end of namespace common

Q_DECLARE_METATYPE(common::TupleECMData)

#endif // TUPLE_ECM_DATA_H
