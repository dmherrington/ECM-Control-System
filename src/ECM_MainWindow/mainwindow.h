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

private:
    Ui::MainWindow *ui;

    MunkPowerSupply *m_PowerSupply;
};

#endif // MAINWINDOW_H
