#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QtSerialPort>

#include <iostream>

#include "qcustomplot.h"

#include "library_munk_power_supply/munk_power_supply.h"
#include "widget_segment_time_data.h"

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
    void on_pushButton_released();

    void widgetSegmentDisplay_dataUpdate(const std::list<DataParameter::SegmentTimeDataDetailed> &newData);

    void onOpen();
    void onSave();
    void onSaveAs();
    void onExit();

    void onGraphLegend();

    void on_pushButton_transmit_released();

private:
    Ui::MainWindow *ui;

    MunkPowerSupply *m_PowerSupply;

    QString m_FilePath;
};

#endif // MAIN_WINDOW_H
