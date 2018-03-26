#include "ECM_plot_collection.h"

static const uint Position_Hash = qHash('P') ^ qHash('o') ^ qHash('s') ^ qHash('i') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint Profile_Variable_Value_Hash = qHash('P') ^ qHash('r') ^ qHash('o') ^ qHash('f') ^ qHash('i') ^ qHash('l') ^ qHash('e') ^ qHash('_') ^ qHash('V') ^ qHash('a') ^ qHash('r') ^ qHash('i') ^ qHash('a') ^ qHash('b') ^ qHash('l') ^ qHash('e')^ qHash('_') ^ qHash('V') ^ qHash('a') ^ qHash('l') ^ qHash('u') ^ qHash('e');
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

void ECMPlotCollection::UpdatePositionalStatePlots(const common::TuplePositionalString &position, const common_data::MachinePositionalState &state)
{
    common::EnvironmentTime observationTime = state.getObservationTime();

    QDate tmp_Date(observationTime.year, observationTime.month, observationTime.dayOfMonth);
    QTime tmp_Time(observationTime.hour, observationTime.minute, observationTime.second, observationTime.millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    ECMPlotIdentifier ID_S(position, "Position", 8, Profile_Variable_Value_Hash);
    MakePlot(ID_S, common_data::PositionDimension(common_data::PositionUnit::UNIT_POSITION_MICRO_METER).ShortHand());
    double value = ((common_data::PositionalState*)state.getPositionalState().get())->getVariableValue();
    InsertData(ID_S, time, value);
}

void ECMPlotCollection::UpdateProfileVariablePlots(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state)
{
    common::EnvironmentTime observationTime = state.getObservationTime();

    QDate tmp_Date(observationTime.year, observationTime.month, observationTime.dayOfMonth);
    QTime tmp_Time(observationTime.hour, observationTime.minute, observationTime.second, observationTime.millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    ECMPlotIdentifier ID_S(variable, "Profile_Variable_Value", 22, Profile_Variable_Value_Hash);
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
        ECMPlotIdentifier ID_S(sensor, "Sensed_Voltage", 14, Sensed_Voltage_Hash);
        MakePlot(ID_S, common_data::VoltageDimension(common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS).ShortHand());
        double value = ((common_data::SensorVoltage*)state.getSensorData().get())->getVoltage(common_data::VoltageUnit::UNIT_VOLTAGE_VOLTS);
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
QList<std::shared_ptr<common_data::observation::IPlotComparable> > ECMPlotCollection::getPlots(const common::TupleECMData &element) const
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
