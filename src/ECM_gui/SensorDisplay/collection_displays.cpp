#include "collection_displays.h"

//!
//! \brief Static method to create a new SensorDisplay object
//! \param sensor Identifier of the sensor
//! \param type Enum of type to create
//! \param plotCollection Pointer to plot collection
//! \return Pointer to newly created object
//!
ISensorDisplay* CollectionDisplays::CreateNewDisplayObject(const TupleSensorString &sensor,  const Data::SensorTypes &type, ECMPlotCollection *plotCollection)
{
    ISensorDisplay *sensorFrame;
    switch(type)
    {
    case Data::SENSOR_VOLTAGE:
    {
        ECMPlotIdentifier A1 = ECMPlotIdentifier(sensor, "Sensed_Voltage");
        if(plotCollection->SourceExists(A1) == false) return NULL;

        sensorFrame = new DisplayVoltage(sensor, plotCollection);

        QList<std::shared_ptr<ExpressionEngine::IPlotComparable>> plots;
        plots.append(A1.CreateSharedPtr());
        ((DisplayVoltage*)sensorFrame)->setPlotData(plots);

        break;
    }
    default:
        throw new std::runtime_error("Unknown sensor type");
    }
    return sensorFrame;
}


//!
//! \brief default constructor
//! \param plotCollection Pointer to plot collection
//!
CollectionDisplays::CollectionDisplays(ECMPlotCollection *plotCollection) :
    m_PlotCollection(plotCollection)
{

}


//!
//! \brief Change plot mode of all plots in the collection.
//!
//! All current plots will be changed and future plots will use the given mode.
//! \param mode Mode to change to
//!
void CollectionDisplays::SetPlotMode(const graphing::PlotHandler::PlotMode &mode)
{
    m_PlotMode = mode;

    QList<ISensorDisplay*> displays = m_SensorDisplays.values();
    for(int i = 0 ; i < displays.size() ; i++)
    {
        displays.at(i)->ChangePlotMode(mode);
    }
}


//!
//! \brief Distribute an origin time to the plot collection.
//!
//! All current plots will be changed and any future plot will use the given time.
//! \param originTime New origin time
//!
void CollectionDisplays::DistributeOriginTime(const QDateTime &originTime)
{
    m_OriginTime = originTime;

    QList<ISensorDisplay*> displays = m_SensorDisplays.values();
    for(int i = 0 ; i < displays.size() ; i++)
    {
        displays.at(i)->setOriginTime(originTime);
    }
}


//!
//! \brief Create a specific sensor display
//!
//! Will return NULL if already created.
//! \param sensor Identifier for sensor.
//! \param type Type of sensor.
//! \return Pointer to widget.
//!
QObject* CollectionDisplays::CreateSensor(const TupleSensorString &sensor, const Data::SensorTypes &type)
{
    if(m_SensorDisplays.contains(sensor) == true && m_SensorDisplays[sensor] != NULL)
        return NULL;

    ISensorDisplay* createdSensorDisplay = CollectionDisplays::CreateNewDisplayObject(sensor, type, m_PlotCollection);
    if(createdSensorDisplay == NULL)
        return NULL;

    m_SensorDisplays[sensor] = createdSensorDisplay;
    m_SensorDisplays[sensor]->setOriginTime(m_OriginTime);

    return m_SensorDisplays[sensor]->getWidget();
}



//!
//! \brief Get the underlaying widget for a sensor display.
//! \param sensor Identifier of widget.
//! \return  Return pointer to widget, NULL if not.
//!
QWidget* CollectionDisplays::getWidget(const TupleSensorString &sensor)
{
    if(m_SensorDisplays.contains(sensor))
        return m_SensorDisplays[sensor]->getWidget();
    else
        return NULL;
}


//!
//! \brief Update any non-plotted data for a sensor in the collection
//! \param sensor Sensor in the collection to update
//! \param state Sensor state containing the data
//!
void CollectionDisplays::UpdateNonPlottedData(const TupleSensorString &sensor, const Data::SensorState &state)
{
    if(!m_SensorDisplays.contains(sensor) || m_SensorDisplays[sensor] == NULL)
        return;

    m_SensorDisplays[sensor]->UpdateNonPlottedData(sensor, state);
}


//!
//! \brief Request an update of plotted data for a sensor in the collection.
//! \param sensor Key to sensor in collection.
//!
void CollectionDisplays::PlottedDataUpdated(const TupleSensorString &sensor)
{
    if(!m_SensorDisplays.contains(sensor) || m_SensorDisplays[sensor] == NULL)
        return;

    m_SensorDisplays[sensor]->PlottedDataUpdated();
}


//!
//! \brief Distribute current time to all active Sensor display.
//! \param currTime Current time to distribute.
//!
void CollectionDisplays::DistributeCurrentTime(const QDateTime &currTime)
{
    QList<ISensorDisplay*> displays = m_SensorDisplays.values();
    for(int i = 0 ; i < displays.size() ; i++)
    {
        if(displays.at(i) == NULL)
            continue;

        displays.at(i)->CurrentTime(currTime);
    }
}


//!
//! \brief Distribute an update axis to any active plots in the collection
//! \param leftTime Left time
//! \param rightTime Right time
//!
void CollectionDisplays::DistributeUpdateAxis(QDateTime leftTime, QDateTime rightTime)
{
    QList<ISensorDisplay*> displays = m_SensorDisplays.values();
    for(int i = 0 ; i < displays.size() ; i++)
    {
        if(displays.at(i) == NULL)
            continue;

        displays.at(i)->UpdateAxis(leftTime, rightTime);
        displays.at(i)->PlottedDataUpdated();
    }
}


//!
//! \brief Distribute a change to color scheme to all active plots in the collection.
//! \param scheme New colour scheme
//!
void CollectionDisplays::DistributeChangeColorScheme(bool scheme)
{
    QList<ISensorDisplay*> displays = m_SensorDisplays.values();
    for(int i = 0 ; i < displays.size() ; i++)
    {
        if(displays.at(i) == NULL)
            continue;

        displays.at(i)->ChangeColorScheme(scheme);
    }
}
