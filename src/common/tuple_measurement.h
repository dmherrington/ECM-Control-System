#ifndef TUPLE_MEASUREMENT_H
#define TUPLE_MEASUREMENT_H

#include "tuple_generic.h"

class TupleMeasurement : public TupleGeneric
{
public:
    TupleMeasurement();

    TupleMeasurement(const TupleMeasurement &copy);



    //!
    //! \brief Type of tuple object this is
    //! \return String indicating type
    //!
    string Type() const override;


    //!
    //! \brief method to find human readable name
    //! \return string name
    //!
    string HumanName() const override;


    //!
    //! \brief Assignment operator
    //! \param rhs Right hand side of assignment
    //!
    void operator= (const TupleMeasurement &rhs);


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


    //! Name of sensor
    string measurementName;


};

#endif // TUPLE_MEASUREMENT_H
