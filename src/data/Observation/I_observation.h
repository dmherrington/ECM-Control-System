#ifndef I_OBSERVATION_H
#define I_OBSERVATION_H

#include <QList>

#include "I_time_data.h"

namespace data {
namespace observation {

//!
//! \brief An abstract interface extension of ITimeData that describes the long-term storage for an observation.
//! An observation is a component of some sort whoose values can change as time goes on, such as when data flows through the system
//!
class IObservation : public ITimeData
{
public:

    virtual ~IObservation(){ }


    //!
    //! \brief Get a list of current values of the range for the current time.
    //!
    //! The size of returned list is based on the Number system of the observation
    //! \return List of values
    //!
    virtual QList<double> getCurrentTimeRange() const = 0;


    //!
    //! \brief Set the current time of the test event.
    //!
    //! This method will recompute the current instantaneous value
    //! \param time Current time of the test event.
    //!
    virtual void setCurrentTime(const QDateTime &time) = 0;


    //!
    //! \brief Get a key that can identify this observation in a feild among others
    //! \return std::shared_ptr to key interface
    //!
    virtual std::shared_ptr<IPlotComparable> Key() const = 0;


};

} //end of namespace observation
} //end of namespace data

#endif // I_OBSERVATION_H
