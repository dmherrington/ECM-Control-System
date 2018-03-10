#include "ECM_plot_collection.h"

#include "data/Sensors/sensor.h"
#include "data/Sensors/sensor_voltage.h"

static const uint Sensed_Voltage_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('V') ^ qHash('o') ^ qHash('l') ^ qHash('t') ^ qHash('a') ^ qHash('g') ^ qHash('e');

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

//!
//! \brief Update any plots for an observed sensor state
//! \param sensor ECM sensor component to update
//! \param state Observed sensor state
//!
void ECMPlotCollection::UpdateSensorPlots(const common::TupleSensorString sensor, const data::SensorState &state)
{
    QDate tmp_Date(state.validityTime->year, state.validityTime->month, state.validityTime->dayOfMonth);
    QTime tmp_Time(state.validityTime->hour, state.validityTime->minute, state.validityTime->second, state.validityTime->millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    switch(state.getSensorData()->getType())
    {
    case data::SENSOR_VOLTAGE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Voltage", 14, Sensed_Voltage_Hash);
        MakePlot(ID_S, data::VoltageDimension(data::UNIT_VOLTAGE_VOLTS).ShortHand());
        double value = ((data::SensorVoltage*)state.getSensorData().get())->getVoltage(data::UNIT_VOLTAGE_VOLTS);
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
QList<std::shared_ptr<data::observation::IPlotComparable> > ECMPlotCollection::getPlots(const common::TupleECMData &element) const
{
    QList<std::shared_ptr<data::observation::IPlotComparable>> rtnList;

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

        m_PlotReferenceString.append(ID.DelimitPlotIdentifier(".", ":", "."));
        return true;
    }
    return false;
}
