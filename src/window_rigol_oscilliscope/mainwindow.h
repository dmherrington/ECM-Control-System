#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "widget_channel_measurements.h"
#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "library_rigol_oscilloscope/commands/measure/rigol_measurement_queue.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_AddMeasurement_released();

private:
    Ui::MainWindow *ui;
    commands_Rigol::RigolMeasurementQueue queue;

    std::map<AvailableChannels, WidgetChannelMeasurements*> mapWidgets;
    RigolOscilliscope* rigolInterface;
};

#endif // MAINWINDOW_H
