#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "additional_sensor_display.h"

namespace Ui {
class ECMControllerGUI;
}

class ECMControllerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ECMControllerGUI(QWidget *parent = 0);
    ~ECMControllerGUI();

private:
    Ui::ECMControllerGUI *ui;

    // Additional sensor display form
    ECMPlotCollection m_PlotCollection;
    AdditionalSensorDisplay *m_additionalSensorDisplay;
};

#endif // ECM_CONTROLLER_GUI_H
