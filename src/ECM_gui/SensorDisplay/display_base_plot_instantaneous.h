#ifndef DISPLAY_BASE_PLOT_INSTANTANEOUS_H
#define DISPLAY_BASE_PLOT_INSTANTANEOUS_H

#include <QWidget>
#include <QTableWidgetItem>

#include "I_sensor_display.h"

#include "data/observation/observation_scalar.h"

#include "../ECM_plot_collection.h"

namespace Ui {
class DisplayBasePlotInstantaneous;
}

class DisplayBasePlotInstantaneous : public QWidget, public ISensorDisplay
{
    Q_OBJECT

public:
    explicit DisplayBasePlotInstantaneous(const common::TupleSensorString &measurementType, const ECMPlotCollection *sourceCollection, QWidget *parent = 0);
    ~DisplayBasePlotInstantaneous();

    //!
    //! \brief Add a row to the instantaneous reading table
    //! \param key Key of addition to make future lookup's quicker
    //! \param name Name of reading
    //!
    void AddInstantaneousRow(const int key, const QString &name);


    //!
    //! \brief Change the name of an instantanoues reading
    //! \param key Key of row to changed
    //! \param value Value to change to
    //!
    void ChangeInstantaniousName(const int key, const QString &name);


    //!
    //! \brief Change the value of an instantanoues reading
    //! \param key Key of row to changed
    //! \param value Value to change to
    //!
    void ChangeInstantaniousReading(const int key, const QString &value);


    //!
    //! \brief Method to update any information that is not contained in a plot for the sensor
    //! \param sensor Tuple describing the sensor
    //! \param sensorData Sensor data to update
    //!
    virtual void UpdateNonPlottedData(const common::TupleSensorString &sensor, const data::SensorState &sensorData);


    /**
     * @brief setOriginTime Set the "zero" time of the plot
     * @param originTime Desired origin time of the plot
     */
    void setOriginTime(const QDateTime &originTime) override;


    //!
    //! \brief Change the mode of any plot in the sensor display
    //!
    //! Does nothing if no plot is present
    //! \param newMode New mode to change to
    //!
    virtual void ChangePlotMode(const graphing::PlotHandler::PlotMode newMode);


    //!
    //! \brief Set the plots of dimensions to be displayed by this object
    //!
    //! \param plotList List of plot objects
    //!
    void setPlotData(const QList<std::shared_ptr<data::observation::IPlotComparable> > &plotList);


    virtual QWidget* getWidget();

protected:


    //!
    //! \brief Add an expression to plot in the graph
    //! \param expr Expression to plot
    //! \param color Color to plot
    //!
    void AddExpressionPlot(const std::string &expr, const QColor &color);

public slots:

    /**
     * @brief UpdateAxis Slot to fire to update the x-axis range whenever plots are updated
     * @param leftWindow Minimum x-axis range value
     * @param rightWindow Maximum x-axis range value
     */
    virtual void UpdateAxis(QDateTime leftWindow, QDateTime rightWindow);

    //!
    //! \brief Slot to fire when current time of test changes
    //! \param new current time
    //!
    virtual void CurrentTime(const QDateTime &currentTime);


    //!
    //! \brief The data container this object pulls its plotted data from has been updated
    //!
    virtual void PlottedDataUpdated();


    //!
    //! \brief Changes color scheme between Qt Default and Dark
    //! \param True indicates Qt Default and False indicates Dark
    //!
    virtual void ChangeColorScheme(bool scheme);

private slots:
    void on_pushButton_Grid_clicked();

    void on_pushButton_Legend_clicked();

    void on_pushButton_GridSpacing_clicked();

    void on_pushButton_yWindow_clicked();

private:

    bool ToggleGrid();
    bool ToggleLegend();

protected:
    Ui::DisplayBasePlotInstantaneous *ui;

    common::TupleSensorString m_Measurement;

private:

    QHash<int, QTableWidgetItem*> m_InstantNameCellHash;
    QHash<int, QTableWidgetItem*> m_InstantValueCellHash;

    QDateTime m_rangeLow;
    QDateTime m_rangeHigh;

    QList<std::shared_ptr<data::observation::IPlotComparable> > m_PlotData;

    QDateTime m_OriginTime;

protected:
    const ECMPlotCollection *m_sourceCollection;
};

#endif // DISPLAY_BASE_PLOT_INSTANTANEOUS_H
