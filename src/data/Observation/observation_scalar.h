#ifndef OBSERVATION_SCALAR_H
#define OBSERVATION_SCALAR_H

#include <QDateTime>
#include <QList>
#include <QVector>
#include <QMutex>

#include "stdlib.h"
#include <memory>

#include "data_global.h"

#include "common/threaded_scheduler.h"

#include "I_plot_comparable.h"
#include "I_observation.h"
#include "I_time_data.h"

namespace data {
namespace observation {

//!
//! \brief This an object that contains scalar observations and times of observation.
//!
//! This class is to be used to hold data in preperation to be plotted or displayed to the user.
//!
//! Each plot is given an identifier that it used to identify itself.
//! Each plot can also be given a dimension/unit that describes the data (meters, seconds, etc).
//!
//! This object is intended to be the data sink for a higher order object controlling the plots.
//! Data is added to this class using the AddData method.
//!
//! The ConvertToScalarTime method is to be used to prepare a TimeSeries object that can be plotted.
//! This method converts the QDateTime domain held in this object to a list of doubles for the plot.
//! Additionally this method can select a subset of data depending on what was requested by the user.
//!
//!
//!
class Export ObservationScalar : public QObject, public IObservation
{
Q_OBJECT
public:


    //!
    //! \brief Constructor
    //! \param dataKey key for Data
    //!
    ObservationScalar(const IPlotComparable &dataKey);

    virtual ~ObservationScalar();


    void setUnit(const std::string &unit);


    //!
    //! \brief Add vectors of data to graph being plotting in this object
    //! \param domain vector of times
    //! \param range vector of values to add
    //!
    void AddData(const QList<QDateTime> &domain, const QList<double> range);


    //!
    //! \brief Add data to a graph being plotted in this object
    //! \param domain new time to add
    //! \param range value to add
    //!
    void AddData(const QDateTime &domain, const double range);


    //!
    //! \brief Prepare data contained in this object for display on a plot.
    //! \param [in] parameters Parameters for cartesian time conversion
    //! \return A time seires object that can be plotted
    //!
    virtual CartesianData ConvertToScalarTime(const CartesianEvaluationParameters &parameters, const std::string &componentIndex = "");


    //!
    //! \brief The number system the container holds
    //! \return Number system
    //!
    virtual NumberSystems::StorableDimensions NumberSystem() const;


    //!
    //! \brief Produce a copy of the domains of this plot
    //! \return Vector of times
    //!
    QList<QDateTime> Domain() const;


    //!
    //! \brief Produce a copy of ranges in this plot
    //! \return Vector of scalers
    //!
    QList<double> Range() const;


    //!
    //! \brief Determine if this plot is a constant value
    //! \return true if constant plot, false otherwise
    //!
    virtual bool IsConstValuePlot() const;

    //!
    //! \brief Set the current time of the test event.
    //!
    //! This method will recompute the current instantaneous value
    //! \param time Current time of the test event.
    //!
    virtual void setCurrentTime(const QDateTime &time);


    //!
    //! \brief Get a list of current values of the range for the current time.
    //!
    //! The size of returned list is based on the Number system of the observation
    //! \return List of values
    //!
    virtual QList<double> getCurrentTimeRange() const;


    //!
    //! \brief Get scalar associated with the current domain value
    //! \return Current scalar
    //!
    virtual double getCurrentScalarRange() const;


    //!
    //! \brief Get a key that can identify this observation in a feild among others
    //! \return std::shared_ptr to key interface
    //!
    virtual std::shared_ptr<IPlotComparable> Key() const;


private slots:


private:

    QString m_Name;

    QList<QDateTime> m_Domain;

    QList<double> m_Range;

    std::shared_ptr<IPlotComparable> m_DataKey;

    std::string m_Unit;

    //! Current Time
    QDateTime m_CurrTime;

    //! Range value at the current time
    double m_CurrTimeRange;

    QMutex m_UnitMutex;

    //! Mutex to protect critical resources.
    QMutex m_DataMutex;


    QList<QDateTime> m_TempDomainAdd;
    QList<double> m_TempRangeAdd;

    QMutex m_TempDataMutex;

};

} //end of namespace observation
} //end of namespace data

#endif // OBSERVATION_SCALAR_H
