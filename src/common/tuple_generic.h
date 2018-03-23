#ifndef TUPLE_GENERIC_H
#define TUPLE_GENERIC_H

#include <QMetaType>
#include <QString>
#include <typeinfo>

#include "common_global.h"

using namespace std;

namespace common {

class TupleGeneric
{
public:


    //!
    //! \brief pure virtual method giving the name of tuple
    //! \return string name
    //!
    virtual QString Type() const = 0;


    //!
    //! \brief pure virtual method to find human readable name
    //! \return string name
    //!
    virtual QString HumanName() const = 0;


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

}//end of namespace common
#endif // TUPLE_GENERIC_H
