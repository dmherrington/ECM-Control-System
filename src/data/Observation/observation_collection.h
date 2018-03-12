#ifndef OBSERVATION_COLLECTION_H
#define OBSERVATION_COLLECTION_H

#include <QObject>
#include <QHash>

#include "data_global.h"

#include "common/threaded_scheduler.h"

#include "I_plot_comparable.h"

#include "observation_scalar.h"

#include "observation_ID_reference.h"

#include "time_data_reference.h"

namespace data {
namespace observation {

//!
//! \brief Class to manage a set of observations using a IPlotComparable interface object as the key
//!
//! Using this class a set of IObservation objects are to be encapsulated and stored.
//! When using this object, this class is the only entity that has knowledge on the IObservation objects.
//! Entities requing use of the collection interface via IPlotComparable objects.
//!
//! InsertData immediatly inserts the provided data into the IObservation object.

class ObservationCollection : public QObject
{
    Q_OBJECT
public:
    //!
    //! \brief Constructor
    //!
    ObservationCollection();


    //!
    //! \brief Get the number system assoctiated with a specfic observation in the collection
    //! \param [in]  ID Identifier of the observation
    //! \param [out] numberSystem Returned number system
    //! \return True if ID exists, false otherwise.
    //!
    bool getNumberSystem(const IPlotComparable &ID, NumberSystems::StorableDimensions &numberSystem) const;


    //!
    //! \brief Get the number system assoctiated with a specfic observation in the collection
    //!
    //! Will throw an exception if identifier not in collection.
    //! \param ID Identifier to retreive
    //! \return Number system identifier is a part of
    //! \exception std::runtime_error Thrown if identifier is not part of collection.
    //!
    NumberSystems::StorableDimensions getNumberSystem(const IPlotComparable &ID) const;


    //!
    //! \brief Get the number system associated with a TimeDataReference object
    //! \param ref Reference to getnumber system of
    //! \return Resulting number system
    //!
    NumberSystems::StorableDimensions getNumberSystem(const TimeDataReference &ref) const;


    //!
    //! \brief Distribute the current time to all manage observation
    //!
    //! This method will cause a recaluclation such that value returned by getInstantaniousValue method will be changed.
    //! \param time Current time to distribute
    //!
    void DistributeCurrentTime(const QDateTime &time);


    //!
    //! \brief Get scalar instantanious value from a source
    //!
    //! The instantanious value is based on the time given by DistributeCurrentTime method
    //! \param ID Source to get from
    //! \param value Variable to place value into
    //! \return True if source exists and is scalar, false otherwise
    //!
    bool getInstantaniousValue(const IPlotComparable &ID, double &value) const;

    //!
    //! \brief Determin if source exists in the collection
    //! \param ID Identifier of source
    //! \return True if exists
    //!
    bool SourceExists(const IPlotComparable &ID) const;

    //!
    //! \brief Evaluate a member of the collection and retreive its cartesian data
    //! \param [in] ID Identifier ot observation in component
    //! \param [out] data object to place data into
    //! \param [in] parameters Parameters for cartesian time conversion
    //! \param [in] componentIndex Specific scalar component of observation retreive. Defaults to empty string if desired to retreive full observation.
    //! \return True if identifier exists in collection, false otherwise
    //!
    bool Evaluate(const IPlotComparable &ID, CartesianData &data, const CartesianEvaluationParameters &parameters, const std::string &componentIndex = "") const;


public:

    //!
    //! \brief Insert scalar data into the collection
    //!
    //! Data will be inserted into the collection in the same thread that method is called in.
    //! \param ID Identifier of source
    //! \param time Domain
    //! \param value Range value
    //! \exception std::runtime_error Thrown if source does not exists as scalar
    //!
    void InsertData(const IPlotComparable& ID, const QDateTime &time, const double &value);


    //!
    //! \brief Schedule the application of any queued data to be inserted on seperate thread
    //!
    void ApplyDataInsertion();


public:



    //!
    //! \brief Make plot in the collection, if already made this method does nothing
    //! \param ID Identifier of source to create
    //! \param unit Unit of source
    //! \return True if created, false if already existed
    //!
    bool MakeScalarContainer(const IPlotComparable &ID, const std::string &unit);

private slots:


    //!
    //! \brief Apply Queued data insertion
    //!
    void Do_ApplyDataInsertion();

private:

    QHash<ObservationIDReference, ObservationScalar*> m_DataScalar;

    //! Temporary data to insert in ExpressionEngine::PlotTimeData objects
    QHash<ObservationScalar*, QList<QPair<QDateTime, double> > > m_ScalarTempData;

    ThreadedScheduler m_InsertQueuedData;

    QMutex m_QueuedDataMutex;
};

} //end of namespace observation
} //end of namespace data

#endif // OBSERVATION_COLLECTION_H
