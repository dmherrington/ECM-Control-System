#ifndef IPLOTCOMPARABLE_H
#define IPLOTCOMPARABLE_H

#include <QString>
#include <memory>
#include "stdlib.h"

#include "../data_global.h"
#include "common/common.h"
#include "common/class_forward.h"

namespace data {
namespace observation {

ECM_CLASS_FORWARD(IPlotComparable);

//!
//! \brief Interface to uniquly identifiy a data source.
//!
class IPlotComparable
{
public:


    //!
    //! \brief pure virtual method for equivilance
    //! \return true if equal
    //!
    virtual bool operator==(const IPlotComparable& rhs) const = 0;


    //!
    //! \brief pure virtual method for non-equivilance
    //! \return true if not equal
    //!
    virtual bool operator!=(const IPlotComparable& rhs) const = 0;


    //!
    //! \brief copy the data held into this comparable object to a shared_ptr
    //! \return A shared_ptr containing data in the comparable object
    //!
    virtual std::shared_ptr<IPlotComparable> CreateSharedPtr() const = 0;


    //!
    //! \brief Produce a hash value for this source identifier
    //! \return Hash value
    //!
    virtual uint hash() const = 0;

};


inline uint qHash(const IPlotComparable &key, uint seed = 0)
{
    UNUSED(seed);
    return key.hash();
}


inline uint qHash(const std::shared_ptr<IPlotComparable> &key, uint seed = 0)
{
    UNUSED(seed);
    return key->hash();
}


//!
//! \brief Equivilance operator between two std::shared_ptr<IPlotComparable>
//! \param a left side of equivilance
//! \param b right side of equivilance
//! \return True if equivilance
//!
inline bool operator ==(const std::shared_ptr<IPlotComparable> &a, const std::shared_ptr<IPlotComparable> &b)
{
    return *a == *b;
}


//!
//! \brief Non-Equivilance operator between two std::shared_ptr<IPlotComparable>
//! \param a left side of equivilance
//! \param b right side of equivilance
//! \return True if equivilance
//!
inline bool operator !=(const std::shared_ptr<IPlotComparable> &a, const std::shared_ptr<IPlotComparable> &b)
{
    return !(a == b);
}


} //end of namespace observation
} //end of namespace data

#endif // IPLOTCOMPARABLE_H
