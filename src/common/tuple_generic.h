#ifndef TUPLE_GENERIC_H
#define TUPLE_GENERIC_H

#include <string>

using namespace std;
class TupleGeneric
{
public:


    //!
    //! \brief pure virtual method giving the name of tuple
    //! \return string name
    //!
    virtual string Type() const = 0;


    //!
    //! \brief pure virtual method to find human readable name
    //! \return string name
    //!
    virtual string HumanName() const = 0;


    //!
    //! \brief pure virtual method for less than operator
    //! \return true if less than
    //!
    virtual bool operator< (const TupleGeneric& rhs) const = 0;


    //!
    //! \brief pure virtual method for equivilance
    //! \return true if equal
    //!
    virtual bool operator==(const TupleGeneric& rhs) const = 0;


    //!
    //! \brief pure virtual method for non-equivilance
    //! \return true if not equal
    //!
    virtual bool operator!=(const TupleGeneric& rhs) const = 0;
};

#endif // TUPLE_GENERIC_H
