#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include "gclib.h"

#include "library_galilMotionController/galil_motion_controller.h"

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
    void on_actionSave_Program_triggered();

    void on_actionSave_As_Program_triggered();

    void on_actionLoad_Program_triggered();

private:
    Ui::MainWindow *ui;

private:
    galilMotionController* m_Galil;

};

#endif // MAINWINDOW_H
