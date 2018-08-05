#include "ECM_plot_collection.h"

//!
//! \brief Constructor
//!
ECMPlotCollection::ECMPlotCollection()
{
    connect(&m_DistributeCurrentTimeScheduler, SIGNAL(PerformWork()), this, SLOT(DoDistributeCurrentTime()), Qt::DirectConnection);
}


//!
//! \brief Destructor
//!
ECMPlotCollection::~ECMPlotCollection()
{

}

void ECMPlotCollection::UpdatePositionalStatePlots(const common::TuplePositionalString &position, const common_data::MachinePositionalState &state)
{
    common::EnvironmentTime observationTime = state.getObservationTime();

    QDate tmp_Date(observationTime.year, observationTime.month, observationTime.dayOfMonth);
    QTime tmp_Time(observationTime.hour, observationTime.minute, observationTime.second, observationTime.millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    ECMPlotIdentifier ID_S(position);
    MakePlot(ID_S, common_data::PositionDimension(common_data::PositionUnit::UNIT_POSITION_MICRO_METER).ShortHand());
    double value = ((common_data::PositionalState*)state.getPositionalState().get())->getAxisPosition();
    InsertData(ID_S, time, value / 10.0); //we need to divide this by 10 as the units performed with this object refer to counts
}

void ECMPlotCollection::UpdateProfileVariablePlots(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state)
{
    common::EnvironmentTime observationTime = state.getObservationTime();

    QDate tmp_Date(observationTime.year, observationTime.month, observationTime.dayOfMonth);
    QTime tmp_Time(observationTime.hour, observationTime.minute, observationTime.second, observationTime.millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    ECMPlotIdentifier ID_S(variable);
    MakePlot(ID_S, "unitless");
    double value = ((common_data::ProfileVariableState*)state.getProfileStateVariable().get())->getVariableValue();
    InsertData(ID_S, time, value);
}

//!
//! \brief Update any plots for an observed sensor state
//! \param sensor ECM sensor component to update
//! \param state Observed sensor state
//!
void ECMPlotCollection::UpdateSensorPlots(const common::TupleSensorString &sensor, const common_data::SensorState &state)
{
    common::EnvironmentTime observationTime = state.getObservationTime();

    QDate tmp_Date(observationTime.year, observationTime.month, observationTime.dayOfMonth);
    QTime tmp_Time(observationTime.hour, observationTime.minute, observationTime.second, observationTime.millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    switch(state.getSensorData()->getType())
    {
    case common_data::SENSOR_VOLTAGE:
    {
        ECMPlotIdentifier ID_S(sensor);
        MakePlot(ID_S, common_data::VoltageDimension(common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS).ShortHand());
        double value = ((common_data::SensorVoltage*)state.getSensorData().get())->getVoltage(common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
        InsertData(ID_S, time, value);
        break;
    }
    case common_data::SENSOR_MAREA:
    {
        ECMPlotIdentifier ID_S(sensor);
        MakePlot(ID_S, common_data::MAREADimension(common_data::MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS).ShortHand());
        double value = ((common_data::SensorMAREA*)state.getSensorData().get())->getCurrentArea(common_data::MAREAUnit::UNIT_VOLTAGE_AMPERE_SECONDS);
        InsertData(ID_S, time, value);
        break;
    }
    default:
    {
        //do nothing
        break;
    }
    }
}


//!
//! \brief Get list of plotted data that corrispond to specific ECM component
//! \param element ECM components
//! \return List of pointers to plot data
//!
QList<std::shared_ptr<common_data::observation::IPlotComparable>> ECMPlotCollection::getPlots(const common::TupleECMData &element) const
{
    QList<std::shared_ptr<common_data::observation::IPlotComparable>> rtnList;

    QList<ECMPlotIdentifier> ID_list = m_ComponentToIDsHash[element];

    for(int i = 0 ; i < ID_list.size() ; i++)
        rtnList.append(ID_list[i].CreateSharedPtr());

    return rtnList;
}


//!
//! \brief Set current time of the plots
//! \param currTime Time to set to
//!
void ECMPlotCollection::CurrentTime(const QDateTime &currTime)
{
    m_CurrTime = currTime;

    m_DistributeCurrentTimeScheduler.Schedule();
}


//!
//! \brief Retreive all sub plots of a component
//! \param component Component querying
//! \return List of all subplots
//!
QList<ECMPlotIdentifier> ECMPlotCollection::AllSubPlots(const common::TupleECMData &component) const
{
    return m_ComponentToIDsHash[component];
}

QList<ECMPlotIdentifier> ECMPlotCollection::AllSubPlots() const
{
    QList<ECMPlotIdentifier> rtnList;

    for (auto it = m_ComponentToIDsHash.begin(); it != m_ComponentToIDsHash.end(); ++it)
        rtnList.append(it.value());

    return rtnList;
}



//!
//! \brief Slot to asyncronously tell each ExpressionEngine::PlotTimeData object of the current time.
//!
void ECMPlotCollection::DoDistributeCurrentTime()
{
    QDateTime currTime = m_CurrTime;

    DistributeCurrentTime(currTime);

    m_DistributeCurrentTimeScheduler.Called();
}


//!
//! \brief Make plot in the collection, if already made this method does nothing
//! \param ID ID to make
//! \return True if a plot was made
//!
bool ECMPlotCollection::MakePlot(const ECMPlotIdentifier &ID, const std::string &unit)
{
    if(MakeScalarContainer(ID, unit))
    {
        if(!m_ComponentToIDsHash.contains(ID.ECMComponent()))
            m_ComponentToIDsHash.insert(ID.ECMComponent(), QList<ECMPlotIdentifier>());
        m_ComponentToIDsHash[ID.ECMComponent()].append(ID);

        //m_PlotReferenceString.append(ID.DelimitPlotIdentifier(".", ":", "."));
        return true;
    }
    return false;
}
