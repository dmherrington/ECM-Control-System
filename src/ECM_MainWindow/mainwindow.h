#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSerialPort>

#include <QByteArray>
#include <QString>
#include <QtDebug>
#include <iostream>
#include <QMainWindow>
#include <vector>
#include <limits.h>

#include "widget_segment_time_data.h"
#include "library_munk_power_supply/munk_power_supply.h"
#include "library_munk_power_supply/data_registers/segment_time_general.h"


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
    void on_pushButton_ConnectSerialPort_released();

    void on_pushButton_ConfigureSerialPort_released();

    void on_pushButton_GenerateValid_released();

    void on_pushButton_GenerateInvalid_released();

    void onNewCurrentData(const DataParameter::SegmentCurrentSetpoint &currentSetpointREV, const DataParameter::SegmentCurrentSetpoint &currentSetpointFWD);
    void onNewVoltageData(const DataParameter::SegmentVoltageSetpoint &voltageSetpointREV, const DataParameter::SegmentVoltageSetpoint &voltageSetpointFWD);
    void onNewGeneralData(const DataParameter::SegmentTimeGeneral &segmentTime);
    void on_pushButton_SendRevI_released();

    void on_pushButton_SendFI_released();

    void on_pushButton_SendRV_released();

    void on_pushButton_SendFV_released();

    void on_pushButton_SendData_released();

private:
    Ui::MainWindow *ui;

    MunkPowerSupply *m_PowerSupply;

    DataParameter::SegmentCurrentSetpoint *iFWD;
    DataParameter::SegmentCurrentSetpoint *iREV;
    DataParameter::SegmentVoltageSetpoint *vFWD;
    DataParameter::SegmentVoltageSetpoint *vREV;
    DataParameter::SegmentTimeGeneral *genData;

};

#endif // MAINWINDOW_H
