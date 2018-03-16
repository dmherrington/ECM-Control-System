#ifndef OBSERVATION_ID_REFERENCE_H
#define OBSERVATION_ID_REFERENCE_H

#include "I_plot_comparable.h"

namespace common_data {
namespace observation {

class ObservationIDReference
{
public:

    ObservationIDReference(const IPlotComparable &ID)
    {
        m_ID = ID.CreateSharedPtr();
    }


    ObservationIDReference(const ObservationIDReference &that)
    {
        *this = that;
    }


    void operator =(const ObservationIDReference &rhs)
    {
        m_ID = rhs.m_ID->CreateSharedPtr();
    }


    bool operator ==(const ObservationIDReference &rhs) const
    {
        return *m_ID == *rhs.m_ID;
    }


    bool operator !=(const ObservationIDReference &rhs) const
    {
        return *m_ID != *rhs.m_ID;
    }


    std::shared_ptr<IPlotComparable> ptr() const
    {
        return m_ID->CreateSharedPtr();
    }

    friend uint qHash(const ObservationIDReference &that, int seed = 0)
    {
        UNUSED(seed);
        return qHash(*that.m_ID);
    }


private:

    std::shared_ptr<IPlotComparable> m_ID;
};


} //end of namespace observation
} //end of namespace data

#endif // OBSERVATION_ID_REFERENCE_H
