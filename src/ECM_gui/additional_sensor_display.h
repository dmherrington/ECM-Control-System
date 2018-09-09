#ifndef ADDITIONAL_SENSOR_DISPLAY_H
#define ADDITIONAL_SENSOR_DISPLAY_H
#include <qglobal.h>
#include <QtCore/qglobal.h>

#include <QMainWindow>
#include <QDockWidget>
#include <QDebug>
#include <QList>
#include <QMenu>

#include "general_dialog_window.h"

#include "common/tuple_sensor_string.h"
#include "ECM_plot_collection.h"

#include "SensorDisplay/collection_displays.h"



namespace Ui {
class AdditionalSensorDisplay;
}


//!
//! \brief A window that utilizes QDockWidget to show additional sensor displays.
//!
//! The QDockWidget allows for multiple displays to be shown at one time.
//! While also allowing the user to break out the display for individual display.
//!
class AdditionalSensorDisplay : public GeneralDialogWindow
{
    Q_OBJECT

public:

    /**
     * @brief Default AdditionalSensorDisplay constructor
     * @param parent
     */
    explicit AdditionalSensorDisplay(ECMPlotCollection *plotCollection, QWidget *parent = 0);


    //!
    //! \brief Deconstructor
    //!
    ~AdditionalSensorDisplay();


    //!
    //! \brief Create a new dock with a sensor inside of it.
    //! \param sensor Sensor to create
    //! \param type Type of sensor to make
    //!
    Q_INVOKABLE void NewDock(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);


    /**
     * @brief isSensorDisplayed Method to determine if a sensor is currently being displayed
     * @param sensorName Name of the sensor of interest
     * @return True if the sensor is displayed, false otherwise
     */
    bool isSensorDisplayed(const common::TupleSensorString &sensor);


    //!
    //! \brief Notify about a sensor that can be used by this object
    //! \param sensor Sensor that can be used
    //!
    void AddUsableSensor(const common::TupleSensorString &sensor);


    //!
    //! \brief Change plot mode for displays in this dock window
    //! \param mode Mode to change to
    //!
    void ChangePlotMode(const graphing::PlotHandler::PlotMode &mode);


    //!
    //! \brief Set the origin time for displays in this window
    //! \param time Time to set to
    //!
    void SetOriginTime(const QDateTime &time);


    //!
    //! \brief Updated the non-plotted data of a plot in the additional window
    //! \param sensor Sensor to update
    //! \param state State to give
    //!
    void UpdateNonPlottedData(const common::TupleSensorString &sensor, const common_data::SensorState &state);


    //!
    //! \brief update plotted data in displays kept by the dock window
    //!
    void UpdatePlottedData(const common::TupleSensorString &sensor);


    //!
    //! \brief set the current time in all the displays kept by this dock window
    //! \param dateTime Current date time
    //!
    void CurrentTime(const QDateTime &dateTime);

public slots:


    void AxisChanged(QDateTime lower, QDateTime upper);


    //!
    //! \brief Change the color scheme between Qt Default and Dark
    //! \param True indicates Qt Default and False indicates Dark
    //!
    void ChangeColorScheme(bool scheme);

private:
    void closeEvent(QCloseEvent *event) override;

signals:

    //!
    //! \brief signal_DialogWindowVisibilty
    //! \param type
    //! \param visibility
    //!
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

    //!
    //! \brief Signal to emit when a new dock is to be created
    //! \param sensor Sensor adding
    //! \param type type of sensor
    //!
    void CreateNewDock(common::TupleSensorString sensor, common_data::SensorTypes type);

    //!
    //! \brief WindowRangeChanged Signal to be emitted when the x-axis range is changed
    //! \param left Minimum x-axis range value
    //! \param right Maximum x-axis range value
    //!
    void WindowRangeChanged(QDateTime left, QDateTime right);


    //!
    //! \brief Signal to emit when display state of a sensor in the dock has changed.
    //! \param sensor Sensor whoose state has changed.
    //!
    void SensorDisplayChanged(common::TupleSensorString sensor, bool display);

    //!
    //! \brief changeColorScheme Signal to be emitted when the color scheme is changed
    //! \param True indicates Qt Default and False indicates Dark
    //!
    void SchemeChanged(bool scheme);

private slots:
    void CustomContextMenuRequested(const QPoint &pos);

    void DisplayActionTriggered();

    //!
    //! \brief Slot fired when a dock becomes visible or unvible
    //! \param visible true if dock is now visible, false otherwise
    //!
    void OnDockVisibilitiy(bool visible);

private:

private:
    Ui::AdditionalSensorDisplay *ui;

    //! Graph collection in ECM, needed to create new sensor displays
    ECMPlotCollection *m_PlotCollection;

    // Boolean indicating whether the docks were created
    bool m_SensorDocksCreated;

    // Boolean indicating whether the context menus were created
    bool m_ContextMenuCreated;

    //! Available sensors that can be displayed by this object
    QMap<common::TupleSensorString, bool> m_ShownSensors;


    QMap<common::TupleSensorString, QAction*> m_SensorActionMap;

    // Map of a sensor tuple and the corresponding dock widget (with SensorDisplay widget) pointer
    QMap<common::TupleSensorString, QDockWidget*> m_SensorDockMap;

    std::vector<common::TupleSensorString> sensorDockOrdering;

    //! Collection of display objects
    CollectionDisplays m_SensorDisplays;

    // QDateTime containing test origin time
    QDateTime m_OriginTime;

    // Custom context menu
    QMenu *m_contextMenu;

    // Color scheme -- True if Qt Default and False if Dark
    bool m_colorScheme;

};

#endif // ADDITIONAL_SENSOR_DISPLAY_H
