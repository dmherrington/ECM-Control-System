#ifndef COLLECTION_DISPLAYS_H
#define COLLECTION_DISPLAYS_H

#include "I_sensor_display.h"
#include "display_voltage.h"

#include "../ECM_plot_collection.h"


//!
//! \brief Class to be used to create and manage a collection of sensor display objects
//!
class CollectionDisplays : public QObject
{
    Q_OBJECT

private:

    //!
    //! \brief Static method to create a new SensorDisplay object
    //! \param sensor Identifier of the sensor
    //! \param type Enum of type to create
    //! \param plotCollection Pointer to plot collection
    //! \return Pointer to newly created object
    //!
    static ISensorDisplay* CreateNewDisplayObject(const common::TupleSensorString &sensor, const common_data::SensorTypes &type, ECMPlotCollection* plotCollection);


public:


    //!
    //! \brief default constructor
    //! \param plotCollection Pointer to plot collection
    //!
    CollectionDisplays(ECMPlotCollection *plotCollection);


    //!
    //! \brief Change plot mode of all plots in the collection.
    //!
    //! All current plots will be changed and future plots will use the given mode.
    //! \param mode Mode to change to
    //!
    void SetPlotMode(const graphing::PlotHandler::PlotMode &mode);


    //!
    //! \brief Distribute an origin time to the plot collection.
    //!
    //! All current plots will be changed and any future plot will use the given time.
    //! \param originTime New origin time
    //!
    void DistributeOriginTime(const QDateTime &originTime);


    //!
    //! \brief Create a specific sensor display
    //!
    //! Will return NULL if the display is already created.
    //! \param sensor Identifier for sensor.
    //! \param type Type of sensor.
    //! \return Pointer to widget.
    //!
    QObject* CreateSensor(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);


    //!
    //! \brief Get the underlaying widget for a sensor display.
    //! \param sensor Identifier of widget.
    //! \return  Return pointer to widget, NULL if not.
    //!
    QWidget* getWidget(const common::TupleSensorString &sensor);


    //!
    //! \brief Update any non-plotted data for a sensor in the collection
    //! \param sensor Sensor in the collection to update
    //! \param state Sensor state containing the data
    //!
    void UpdateNonPlottedData(const common::TupleSensorString &sensor, const common_data::SensorState &state);


    //!
    //! \brief Request an update of plotted data for a sensor in the collection.
    //! \param sensor Key to sensor in collection.
    //!
    void PlottedDataUpdated(const common::TupleSensorString &sensor);


    //!
    //! \brief Distribute current time to all active Sensor display.
    //! \param currTime Current time to distribute.
    //!
    void DistributeCurrentTime(const QDateTime &currTime);


public slots:


    //!
    //! \brief Distribute an update axis to any active plots in the collection
    //! \param leftTime Left time
    //! \param rightTime Right time
    //!
    void DistributeUpdateAxis(QDateTime leftTime, QDateTime rightTime);


    //!
    //! \brief Distribute a change to color scheme to all active plots in the collection.
    //! \param scheme New colour scheme
    //!
    void DistributeChangeColorScheme(bool scheme);


private:


    //! Map to Sensor display objects to be shown in the popout GUI window
    QMap<common::TupleSensorString, ISensorDisplay*> m_SensorDisplays;

    //! Pointer to the plot collection object in ECM
    ECMPlotCollection *m_PlotCollection;

    //! Current mode of the plots in this collection
    graphing::PlotHandler::PlotMode m_PlotMode;

    //! Origin time to base all plots in any display off of
    QDateTime m_OriginTime;
};

#endif // COLLECTION_DISPLAYS_H
