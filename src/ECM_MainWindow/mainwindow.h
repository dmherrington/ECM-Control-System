#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QByteArray>
#include <QString>
#include <QtDebug>
#include <iostream>
#include <QMainWindow>
#include <vector>
#include <limits.h>
#include "library_munk_power_supply/munk_power_supply.h"

#include "library_munk_power_supply/data_registers/segment_times.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
