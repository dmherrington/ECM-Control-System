#include "ECM_plot_collection.h"

#include "Sensors/sensor.h"
#include "Sensors/sensor_waypoint.h"

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
void ECMPlotCollection::UpdateSensorPlots(const ECMCore::TupleSensorString sensor, const double &state)
{
//    QDate tmp_Date(state.validityTime->year, state.validityTime->month, state.validityTime->dayOfMonth);
//    QTime tmp_Time(state.validityTime->hour, state.validityTime->minute, state.validityTime->second, state.validityTime->millisecond);
//    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    switch(state.getSensorData()->getType())
    {
    case Data::SENSOR_VOLTAGE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Voltage", 14, Sensed_Voltage_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::VoltageDimension(DimensionalAnalysis::UNIT_VOLTAGE_VOLTS)));
        HSI_FLOAT64 value = ((Data::SensorVoltage*)state.getSensorData().get())->getVoltage(DimensionalAnalysis::UNIT_VOLTAGE_VOLTS);
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
QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > ECMPlotCollection::getPlots(const ECMCore::TupleECMData &element) const
{
    QList<std::shared_ptr<ExpressionEngine::IPlotComparable>> rtnList;

    QList<ECMPlotIdentifier> ID_list = m_ComponentToIDsHash[element];

    for(int i = 0 ; i < ID_list.size() ; i++)
        rtnList.append(ID_list[i].CreateSharedPtr());

    return rtnList;

}


//!
//! \brief Retreive a list of all ECM components contained in a single math expressions
//! \param expr Math expression
//! \return List of ECM components
//!
QList<ECMCore::TupleECMData> ECMPlotCollection::ECMComponentInExpression(const ExpressionEngine::MathExpression &expr)
{
    QList<ECMCore::TupleECMData> rtnList;


    QList<std::shared_ptr<ExpressionEngine::IPlotComparable> > plotsInExpression = expr.SourcesInExpression();
    for(int i = 0 ; i < plotsInExpression.size() ; i++)
    {
        std::shared_ptr<ExpressionEngine::IPlotComparable> ptr = plotsInExpression.at(i);
        ECMCore::TupleECMData component = ((ECMPlotIdentifier*)ptr.get())->ECMComponent();
        if(!rtnList.contains(component))
            rtnList.append(component);
    }

    return rtnList;
}


//!
//! \brief Assist in compleating a string
//! \param partialString Partial string to compleate
//! \return List of strings that can be used
//!
QStringList ECMPlotCollection::CompleteAssist(const QString &partialString)
{
    QStringList wordList;
    for(int i = 0 ; i < m_PlotReferenceString.size() ; i++)
    {
        if(strncmp(m_PlotReferenceString.at(i).toStdString().c_str(), partialString.toStdString().c_str(), partialString.size()) == 0)
        {

            int startElement = 0;
            for(int j = partialString.size() ; j > 0 ; j--)
            {
                if(m_PlotReferenceString.at(i).size() <= j)
                    continue;

                if(m_PlotReferenceString.at(i).at(j) == ':' || m_PlotReferenceString.at(i).at(j) == '.')
                {
                    startElement = j;
                    break;
                }
            }

            QString referenceWord;
            for(int j = startElement ; j < m_PlotReferenceString.at(i).size() ; j++)
            {
                if(j != startElement && ( m_PlotReferenceString.at(i).at(j) == ':' || m_PlotReferenceString.at(i).at(j) == '.') )
                {
                    break;
                }
                referenceWord += m_PlotReferenceString.at(i).at(j);
            }

            if(!wordList.contains(referenceWord))
                wordList.append(referenceWord);
        }
    }

    return wordList;
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
QList<ECMPlotIdentifier> ECMPlotCollection::AllSubPlots(const ECMCore::TupleECMData &component) const
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
bool ECMPlotCollection::MakePlot(const ECMPlotIdentifier &ID, const DimensionalAnalysis::DimensionalExpression &unit)
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
