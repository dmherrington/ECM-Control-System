#include "ECM_plot_collection.h"

#include "Sensors/sensor.h"
#include "Sensors/sensor_waypoint.h"

static const uint I_Hash = qHash('I');
static const uint J_Hash = qHash('J');
static const uint K_Hash = qHash('K');
static const uint W_Hash = qHash('W');
static const uint V_Hash = qHash('V');
static const uint Lat_Hash = qHash('L') ^ qHash('a') ^ qHash('t') ^ qHash('e') ^ qHash('n') ^ qHash('c') ^ qHash('y');

static const uint Metric_Hash = qHash('M') ^ qHash('e') ^ qHash('t') ^ qHash('r') ^ qHash('i') ^ qHash('c');
static const uint Position_Hash = qHash('P') ^ qHash('o') ^ qHash('s') ^ qHash('i') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint LinearVelocity_Hash = qHash('L') ^ qHash('i') ^ qHash('n') ^ qHash('e') ^ qHash('a') ^ qHash('r') ^ qHash('V') ^ qHash('e') ^ qHash('l') ^ qHash('o') ^ qHash('c') ^ qHash('i') ^ qHash('t') ^ qHash('y');
static const uint LinearAcceleration_Hash = qHash('L') ^ qHash('i') ^ qHash('n') ^ qHash('e') ^ qHash('a') ^ qHash('r') ^ qHash('A') ^ qHash('c') ^ qHash('c') ^ qHash('e') ^ qHash('l') ^ qHash('e') ^ qHash('r') ^ qHash('a') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint Orientation_Hash = qHash('O') ^ qHash('r') ^ qHash('i') ^ qHash('e') ^ qHash('n') ^ qHash('t') ^ qHash('a') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint AngularVelocity_Hash = qHash('A') ^ qHash('n') ^ qHash('g') ^ qHash('u') ^ qHash('l') ^ qHash('a') ^ qHash('r') ^ qHash('V') ^ qHash('e') ^ qHash('l') ^ qHash('o') ^ qHash('c') ^ qHash('i') ^ qHash('t') ^ qHash('y');
static const uint AngularAcceleration_Hash = qHash('A') ^ qHash('n') ^ qHash('g') ^ qHash('u') ^ qHash('l') ^ qHash('a') ^ qHash('r') ^ qHash('A') ^ qHash('c') ^ qHash('c') ^ qHash('e') ^ qHash('l') ^ qHash('e') ^ qHash('r') ^ qHash('a') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');


static const uint Sensed_Accleration_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('A') ^ qHash('c') ^ qHash('c') ^ qHash('e') ^ qHash('l') ^ qHash('e') ^ qHash('r') ^ qHash('a') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint Sensed_Curret_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('C') ^ qHash('u') ^ qHash('r') ^ qHash('r') ^ qHash('e') ^ qHash('n') ^ qHash('t');
static const uint Sensed_Distance_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('D') ^ qHash('i') ^ qHash('s') ^ qHash('t') ^ qHash('a') ^ qHash('n') ^ qHash('c') ^ qHash('e');
static const uint Sensed_Gryo_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('G') ^ qHash('y') ^ qHash('r') ^ qHash('o');
static const uint Sensed_Gauss_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('G') ^ qHash('a') ^ qHash('u') ^ qHash('s') ^ qHash('s');
static const uint Sensed_Tempurature_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('T') ^ qHash('e') ^ qHash('m') ^ qHash('p') ^ qHash('u') ^ qHash('r') ^ qHash('a') ^ qHash('t') ^ qHash('u') ^ qHash('r') ^ qHash('e');
static const uint Sensed_Torque_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('T') ^ qHash('o') ^ qHash('r') ^ qHash('q') ^ qHash('u') ^ qHash('e');
static const uint Sensed_Voltage_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('V') ^ qHash('o') ^ qHash('l') ^ qHash('t') ^ qHash('a') ^ qHash('g') ^ qHash('e');
static const uint Sensed_Position_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('P') ^ qHash('o') ^ qHash('s') ^ qHash('i') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint Sensed_Orientation_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('O') ^ qHash('r') ^ qHash('i') ^ qHash('e') ^ qHash('n') ^ qHash('t') ^ qHash('a') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');


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
//! \brief Method to notify the plot collection about exo dynamic data present in an ISAAC component.
//! \param component ISAAC component that contains data
//! \param dataName Name of ExoDynamic data
//! \param dim Dimension of data
//!
void ECMPlotCollection::NotifyExoDynamicInformation(const ECMCore::TupleECMData &component, const QString &dataName, const DimensionalAnalysis::DimensionalExpression &dim)
{
    ECMPlotIdentifier exoDynamicData_ID = ECMPlotIdentifier(component, "ExoDynamicData", dataName.toStdString().c_str());

    MakePlot(exoDynamicData_ID, dim);
}


//!
//! \brief Update dynamic plots with an observed state, including ExoDynamic data
//! \param element ISAAC component to update
//! \param state Observed state
//!
void ECMPlotCollection::UpdateDynamicPlots(const ECMCore::TupleECMData &element, const Data::ModelState &state, const double &ms_delay)
{
    QDate tmp_Date(state.validityTime->year, state.validityTime->month, state.validityTime->dayOfMonth);
    QTime tmp_Time(state.validityTime->hour, state.validityTime->minute, state.validityTime->second, state.validityTime->millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    DimensionalAnalysis::PositionDimension posDimension = DimensionalAnalysis::PositionDimension(state.dynamics->getPositionUnit());
    DimensionalAnalysis::TimeDimension timeDimension = DimensionalAnalysis::TimeDimension(state.dynamics->getTimeUnit());
    DimensionalAnalysis::AngleDimension angleDimension = DimensionalAnalysis::AngleDimension(state.dynamics->getAngleUnit());

    bool createPlots = false;
    if(!m_PlotsCreated.contains(element))
    {
        createPlots = true;
        m_PlotsCreated.insert(element, true);
    }


    ECMPlotIdentifier ID_metric_lat(element, "Latency", 7, Lat_Hash);
    if(createPlots == true)
    {
        MakePlot(ID_metric_lat, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TimeDimension(DimensionalAnalysis::TimeUnit::UNIT_TIME_MILLISECOND)));
    }
    QueueInsertData(ID_metric_lat, time, ms_delay);


    ECMPlotIdentifier ID_Pos(element, "Position", 8, Position_Hash);
    if(createPlots)
        MakeVector3Plot(ID_Pos, DimensionalAnalysis::DimensionalExpression(posDimension));
    QueueInsertData(ID_Pos, time, state.dynamics->position);


    ECMPlotIdentifier ID_LV(element, "LinearVelocity", 14, LinearVelocity_Hash);
    if(createPlots)
        MakeVector3Plot(ID_LV, DimensionalAnalysis::DimensionalExpression(posDimension) / DimensionalAnalysis::DimensionalExpression(timeDimension));
    QueueInsertData(ID_LV, time, state.dynamics->linearVelocity);



    ECMPlotIdentifier ID_LA(element, "LinearAcceleration", 18, LinearAcceleration_Hash);
    if(createPlots)
        MakeVector3Plot(ID_LA, DimensionalAnalysis::DimensionalExpression(posDimension) / (DimensionalAnalysis::DimensionalExpression(timeDimension) * DimensionalAnalysis::DimensionalExpression(timeDimension)));
    QueueInsertData(ID_LA, time, state.dynamics->linearAcceleration);



    ECMPlotIdentifier ID_O(element, "Orientation", 11, Orientation_Hash);
    if(createPlots)
        MakeQuaternionPlot(ID_O);
    QueueInsertData(ID_O, time, state.dynamics->orientation);



    ECMPlotIdentifier ID_AV(element, "AngularVelocity", 15, AngularVelocity_Hash);
    if(createPlots)
        MakeVector3Plot(ID_AV, DimensionalAnalysis::DimensionalExpression(angleDimension) / DimensionalAnalysis::DimensionalExpression(timeDimension));
    QueueInsertData(ID_AV, time, state.dynamics->angularVelocity);



    ECMPlotIdentifier ID_AA(element, "AngularAcceleration", 19, AngularAcceleration_Hash);
    if(createPlots)
        MakeVector3Plot(ID_AA, DimensionalAnalysis::DimensionalExpression(angleDimension) / (DimensionalAnalysis::DimensionalExpression(timeDimension) * DimensionalAnalysis::DimensionalExpression(timeDimension)));
    QueueInsertData(ID_AA, time, state.dynamics->angularAcceleration);



    ApplyDataInsertion();

}


//!
//! \brief Update dynamic plots with an observed state, including ExoDynamic data
//! \param element ISAAC component to update
//! \param state List of observed state
//!
void ECMPlotCollection::UpdateDynamicPlots(const ECMCore::TupleECMData &element, const QList<Data::ModelState> &stateList, const QList<double> &ms_delay)
{
    for(int i = 0 ; i < stateList.size() ; i++)
    {
        if(ms_delay.size() == 0)
            UpdateDynamicPlots(element, stateList.at(i), 0);
        else
            UpdateDynamicPlots(element, stateList.at(i), ms_delay.at(i));
    }
}


//!
//! \brief Update dynamic plots with a list of observed sensor state
//! \param element ISAAC component to update
//! \param state Observed sensor state
//!
void ECMPlotCollection::UpdateDynamicPlots(const ECMCore::TupleECMData &element, const QList<Data::SensorState> &stateList, const QList<double> &ms_delay)
{
    for(int i = 0 ; i < stateList.size() ; i++)
    {
        if(ms_delay.size() == 0)
            UpdateDynamicPlots(element, stateList.at(i), 0);
        else
            UpdateDynamicPlots(element, stateList.at(i), ms_delay.at(i));
    }
}


//!
//! \brief Update Plots containing exodynamic data
//! \param element Component containing exodynamic data
//! \param time Time data is valid at
//! \param names Name of ExoDynamic data
//! \param values Value
//!
void ECMPlotCollection::UpdateExoDynamicPlots(const ECMCore::TupleECMData &element, const QDateTime time, QList<QString> &names, QList<HSI_FLOAT64> &values)
{
    QList<ECMPlotIdentifier> exoDynamicData_ID;
    for(int i = 0 ; i < names.length() ; i++)
    {
        exoDynamicData_ID.append(ECMPlotIdentifier(element, "ExoDynamicData", names.at(i).toStdString().c_str()));
    }


    for(int i = 0 ; i < exoDynamicData_ID.size() ; i++)
    {
        QueueInsertData(exoDynamicData_ID.at(i), time, values.at(i));
    }

    //if we queued data, apply it
    if(exoDynamicData_ID.size() > 0)
        ApplyDataInsertion();
}


//!
//! \brief Update any plots for an observed sensor state
//! \param sensor ISAAC sensor component to update
//! \param state Observed sensor state
//!
void ECMPlotCollection::UpdateSensorPlots(const ECMCore::TupleSensorString sensor, const Data::SensorState &state)
{
    QDate tmp_Date(state.validityTime->year, state.validityTime->month, state.validityTime->dayOfMonth);
    QTime tmp_Time(state.validityTime->hour, state.validityTime->minute, state.validityTime->second, state.validityTime->millisecond);
    QDateTime time = QDateTime(tmp_Date, tmp_Time);

    switch(state.getSensorData()->getType())
    {
    case Data::SENSOR_ACCELEROMETER:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Acceleration", 19, Sensed_Accleration_Hash);

        Data::SensorAccelerometer *accel = (Data::SensorAccelerometer*)state.getSensorData().get();
        Dynamics::Vector vec = accel->getAccel(DimensionalAnalysis::UNIT_POSITION_METER, DimensionalAnalysis::UNIT_TIME_SECOND);

        DimensionalAnalysis::DimensionalExpression acceleration = DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::PositionDimension(DimensionalAnalysis::UNIT_POSITION_METER)) / (DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TimeDimension(DimensionalAnalysis::UNIT_TIME_SECOND)) * DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TimeDimension(DimensionalAnalysis::UNIT_TIME_SECOND)));

        MakeVector3Plot(ID_S, acceleration);

        InsertData(ID_S, time, vec);
        break;
    }
    case Data::SENSOR_CURRENT:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Current", 14, Sensed_Curret_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::CurrentDimension(DimensionalAnalysis::UNIT_CURRENT_AMPERES)));
        HSI_FLOAT64 current = ((Data::SensorCurrent*)state.getSensorData().get())->getCurrent(DimensionalAnalysis::UNIT_CURRENT_AMPERES);

        InsertData(ID_S, time, current);

        break;
    }
    case Data::SENSOR_DISTANCE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Distance", 15, Sensed_Distance_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::PositionDimension(DimensionalAnalysis::UNIT_POSITION_METER)));
        HSI_FLOAT64 current = ((Data::SensorDistance*)state.getSensorData().get())->getDist(DimensionalAnalysis::UNIT_POSITION_METER);

        InsertData(ID_S, time, current);

        break;
    }
    case Data::SENSOR_GYROSCOPE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Gyro", 11, Sensed_Gryo_Hash);
        DimensionalAnalysis::DimensionalExpression radpersec = DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::AngleDimension(DimensionalAnalysis::UNIT_ANGLE_RADIANS)) / DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TimeDimension(DimensionalAnalysis::UNIT_TIME_SECOND));
        MakeVector3Plot(ID_S, radpersec);

        Dynamics::Vector vec = ((Data::SensorGyroscope*)state.getSensorData().get())->getGyro(DimensionalAnalysis::UNIT_ANGLE_RADIANS, DimensionalAnalysis::UNIT_TIME_SECOND);

        InsertData(ID_S, time, vec);

        break;
    }
    case Data::SENSOR_MAGNETOMETER:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Gauss", 12, Sensed_Gauss_Hash);
        DimensionalAnalysis::DimensionalExpression gauss = DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::MagneticFieldDimension(DimensionalAnalysis::UNIT_MAGNETIC_GAUSS));
        MakeVector3Plot(ID_S, gauss);

        Dynamics::Vector vec = ((Data::SensorMagnetometer*)state.getSensorData().get())->getMag(DimensionalAnalysis::UNIT_MAGNETIC_GAUSS);

        InsertData(ID_S, time, vec);

        break;
    }
    case Data::SENSOR_TEMPURATURE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Tempurature", 18, Sensed_Tempurature_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TemperatureDimension(DimensionalAnalysis::UNIT_TEMPERATURE_KELVIN)));
        HSI_FLOAT64 value = ((Data::SensorTemperature*)state.getSensorData().get())->getTemp(DimensionalAnalysis::UNIT_TEMPERATURE_KELVIN);
        InsertData(ID_S, time, value);

        break;
    }
    case Data::SENSOR_TORQUE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Torque", 13, Sensed_Torque_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::TorqueDimension(DimensionalAnalysis::UNIT_TORQUE_NEWTON_METRE)));
        HSI_FLOAT64 value = ((Data::SensorTorque*)state.getSensorData().get())->getTorque(DimensionalAnalysis::UNIT_TORQUE_NEWTON_METRE);
        InsertData(ID_S, time, value);

        break;
    }
    case Data::SENSOR_VOLTAGE:
    {
        ECMPlotIdentifier ID_S(sensor, "Sensed_Voltage", 14, Sensed_Voltage_Hash);
        MakePlot(ID_S, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::VoltageDimension(DimensionalAnalysis::UNIT_VOLTAGE_VOLTS)));
        HSI_FLOAT64 value = ((Data::SensorVoltage*)state.getSensorData().get())->getVoltage(DimensionalAnalysis::UNIT_VOLTAGE_VOLTS);
        InsertData(ID_S, time, value);

        break;
    }
    case Data::SENSOR_WAYPOINT:
    {
        ECMPlotIdentifier ID_SP(sensor, "Sensed_Position", 15, Sensed_Position_Hash);
        ECMPlotIdentifier ID_SO(sensor, "Sensed_Orientation", 18, Sensed_Orientation_Hash);
        MakeVector3Plot(ID_SP, DimensionalAnalysis::DimensionalExpression(DimensionalAnalysis::PositionDimension(DimensionalAnalysis::PositionUnit::UNIT_POSITION_METER)));
        MakeQuaternionPlot(ID_SO);

        Data::SensorWaypoint* waypoint = (Data::SensorWaypoint*)state.getSensorData().get();

        InsertData(ID_SP, time, waypoint->getWaypoint(DimensionalAnalysis::PositionUnit::UNIT_POSITION_METER).vec);
        InsertData(ID_SO, time, waypoint->getWaypoint(DimensionalAnalysis::PositionUnit::UNIT_POSITION_METER).quat);

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
//! \brief Get list of plotted data that corrispond to specific ISAAC component
//! \param element ISAAC components
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
//! \brief Retreive a list of all ISAAC components contained in a single math expressions
//! \param expr Math expression
//! \return List of ISAAC components
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
