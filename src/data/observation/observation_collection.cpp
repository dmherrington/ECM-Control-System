#include "observation_collection.h"

namespace common_data {
namespace observation {

//!
//! \brief Constructor
//!
ObservationCollection::ObservationCollection()
{
    connect(&m_InsertQueuedData, SIGNAL(PerformWork()), this, SLOT(Do_ApplyDataInsertion()));
}


//!
//! \brief Get the number system assoctiated with a specfic observation in the collection
//! \param [in]  ID Identifier of the observation
//! \param [out] numberSystem Returned number system
//! \return True if ID exists, false otherwise.
//!
bool ObservationCollection::getNumberSystem(const IPlotComparable &ID, NumberSystems::StorableDimensions &numberSystem) const
{

    if(m_DataScalar.contains(ID))
    {
        numberSystem = m_DataScalar[ID]->NumberSystem();
        return true;
    }

    return false;
}


//!
//! \brief Get the number system assoctiated with a specfic observation in the collection
//!
//! Will throw an exception if identifier not in collection.
//! \param ID Identifier to retreive
//! \return Number system identifier is a part of
//! \exception std::runtime_error Thrown if identifier is not part of collection.
//!
NumberSystems::StorableDimensions ObservationCollection::getNumberSystem(const IPlotComparable &ID) const
{
    if(m_DataScalar.contains(ID))
    {
        return m_DataScalar[ID]->NumberSystem();
    }

    throw new std::runtime_error("Identier not in collection");
}


//!
//! \brief Get the number system associated with a TimeDataReference object
//! \param ref Reference to getnumber system of
//! \return Resulting number system
//!
NumberSystems::StorableDimensions ObservationCollection::getNumberSystem(const TimeDataReference &ref) const
{
    if(ref.ContainsComponent() == true)
        return NumberSystems::SCALAR;
    else
        return getNumberSystem(*ref.SourceID().get());
}


//!
//! \brief Distribute the current time to all manage observation
//!
//! This method will cause a recaluclation such that value returned by getInstantaniousValue method will be changed.
//! \param time Current time to distribute
//!
void ObservationCollection::DistributeCurrentTime(const QDateTime &time)
{
    QList<ObservationScalar*> scalarObservationList = m_DataScalar.values();
    for(int i = 0 ; i < scalarObservationList.size() ; i++)
    {
        scalarObservationList.at(i)->setCurrentTime(time);
    }
}


//!
//! \brief Get scalar instantanious value from a source
//!
//! The instantanious value is based on the time given by DistributeCurrentTime method
//! \param ID Source to get from
//! \param value Variable to place value into
//! \return True if source exists and is scalar, false otherwise
//!
bool ObservationCollection::getInstantaniousValue(const IPlotComparable &ID, double &value) const
{
    if(m_DataScalar.contains(ID))
    {
        value = m_DataScalar[ID]->getCurrentScalarRange();
        return true;
    }

    return false;
}


//!
//! \brief Evaluate a member of the collection and retreive its cartesian data
//! \param [in] ID Identifier ot observation in component
//! \param [out] data object to place data into
//! \param [in] parameters Parameters for cartesian time conversion
//! \param [in] componentIndex Specific scalar component of observation retreive. Defaults to empty string if desired to retreive full observation.
//! \return True if identifier exists in collection, false otherwise
//!
bool ObservationCollection::Evaluate(const IPlotComparable &ID, CartesianData &data, const CartesianEvaluationParameters &parameters, const std::string &componentIndex) const
{
    if(m_DataScalar.contains(ID))
    {
        data = m_DataScalar[ID]->ConvertToScalarTime(parameters, componentIndex);
        return true;
    }
    return false;
}


//!
//! \brief Determin if source exists in the collection
//! \param ID Identifier of source
//! \return True if exists
//!
bool ObservationCollection::SourceExists(const IPlotComparable &ID) const
{
    if(m_DataScalar.contains(ID))
        return true;

    return false;
}


//!
//! \brief Insert scalar data into the collection
//!
//! Data will be inserted into the collection in the same thread that method is called in.
//! \param ID Identifier of source
//! \param time Domain
//! \param value Range value
//! \exception std::runtime_error Thrown if source does not exists as scalar
//!
void ObservationCollection::InsertData(const IPlotComparable& ID, const QDateTime &time, const double &value)
{
    if(m_DataScalar.contains(ID) == false)
        throw new std::runtime_error("Unknown Scalar Identifier");
    m_DataScalar[ID]->AddData(time, value);
    m_DataScalar[ID]->setCurrentTime(time);
}

//!
//! \brief Schedule the application of any queued data to be inserted on seperate thread
//!
void ObservationCollection::ApplyDataInsertion()
{
    m_InsertQueuedData.Schedule();
}


//!
//! \brief Make plot in the collection, if already made this method does nothing
//! \param ID Identifier of source to create
//! \param unit Unit of source
//! \return True if created, false if already existed
//!
bool ObservationCollection::MakeScalarContainer(const IPlotComparable &ID, const std::string &unit)
{
    ObservationIDReference IDreference(ID);
    bool made = false;
    if(!m_DataScalar.contains(IDreference))
    {
        m_DataScalar.insert(IDreference, new ObservationScalar(ID));
        made = true;
    }

    m_DataScalar[IDreference]->setUnit(unit);

    return made;
}

//!
//! \brief Apply Queued data insertion
//!
void ObservationCollection::Do_ApplyDataInsertion()
{
    m_QueuedDataMutex.lock();

    QHash<ObservationScalar*, QList<QPair<QDateTime, double> > > data = m_ScalarTempData;
    QList<ObservationScalar*> tempDataKeys = m_ScalarTempData.keys();
    for(int i = 0 ; i < tempDataKeys.size() ; i++)
    {
        m_ScalarTempData[tempDataKeys.at(i)].clear();
    }

    m_QueuedDataMutex.unlock();



    //insert scalars
    QList<ObservationScalar*> keys = data.keys();
    QList<QList<QPair<QDateTime, double> > > values = data.values();
    for(int i = 0 ; i < data.size() ; i++)
    {
        for(int j = 0 ; j < values.at(i).size() ; j++)
        {
            keys.at(i)->AddData(values.at(i).at(j).first, values.at(i).at(j).second);
        }
    }

    m_InsertQueuedData.Called();
}

} //end of namespace observation
} //end of namespace data
