#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QDebug>
#include "library_munk_power_supply_global.h"
#include <QMainWindow>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void setupUiElements();

public slots:

     void generateMessage();

private slots:
     void on_pushButton_generatemsg_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
