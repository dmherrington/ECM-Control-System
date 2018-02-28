#ifndef TUPLE_MEASUREMENT_STRING_H
#define TUPLE_MEASUREMENT_STRING_H

#include "tuple_generic.h"

class COMMONSHARED_EXPORT TupleMeasurementString : public TupleGeneric
{
public:
    TupleMeasurementString();

    TupleMeasurementString(const TupleMeasurementString &copy);

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
    void operator= (const TupleMeasurementString &rhs);


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

    //! Name of the source originating the measurement
    QString sourceName;

    //! Name of measurement
    QString measurementName;

};

#endif // TUPLE_MEASUREMENT_STRING_H
