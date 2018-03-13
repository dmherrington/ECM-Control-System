#ifndef TUPLE_SENSOR_STRING_H
#define TUPLE_SENSOR_STRING_H

#include <QString>
#include "tuple_generic.h"

namespace common {

class COMMONSHARED_EXPORT TupleSensorString : public TupleGeneric
{
public:
    TupleSensorString();

    TupleSensorString(const TupleSensorString &copy);

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

    //! Name of the source originating the sensor
    QString sourceName;

    //! Name of sensor
    QString sensorName;

};

} //end of namespace common

Q_DECLARE_METATYPE(common::TupleSensorString)

#endif // TUPLE_SENSOR_STRING_H
