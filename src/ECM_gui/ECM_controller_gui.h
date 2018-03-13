#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "ECM_plot_identifier.h"

#include "munk_power_supply.h"

#include "additional_sensor_display.h"
#include "common/threadmanager.h"
#include "common/timer.h"
namespace Ui {
class ECMControllerGUI;
}

class ECMControllerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ECMControllerGUI(QWidget *parent = 0);
    ~ECMControllerGUI();

private slots:
    void on_pushButton_released();
    void slot_NewSensorData(const common::TupleSensorString sensor, const data::SensorState state);

private:
    Ui::ECMControllerGUI *ui;

    ECMPlotCollection m_PlotCollection;

    CollectionDisplays m_SensorDisplays;

    AdditionalSensorDisplay *m_additionalSensorDisplay;

    MunkPowerSupply* testMunk;
};

#endif // ECM_CONTROLLER_GUI_H
