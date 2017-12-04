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

    /////////////////////////////////////////////////////////////////////////
    /// GENERAL MODULE MENU EVENTS
    /////////////////////////////////////////////////////////////////////////

    //!
    //! \brief on_actionSave_Program_triggered
    //!
    void on_actionSave_Program_triggered();

    //!
    //! \brief on_actionSave_As_Program_triggered
    //!
    void on_actionSave_As_Program_triggered();

    //!
    //! \brief on_actionLoad_Program_triggered
    //!
    void on_actionLoad_Program_triggered();

    /////////////////////////////////////////////////////////////////////////
    /// GENERAL MODULE MANUAL CONTOL BOX EVENTS
    /////////////////////////////////////////////////////////////////////////

    //!
    //! \brief event indicating the user wants to begin performing
    //! a jog manuever away from the machining surface.
    //!
    void on_pushButton_IncreaseJog_pressed();

    //!
    //! \brief event indicating the user wants to cease performing
    //! a jog manuever away from the machining surface.
    //!
    void on_pushButton_IncreaseJog_released();

    //!
    //! \brief event indicating the user wants to begin performing
    //! a jog manuever towards the machining surface.
    //!
    void on_pushButton_DecreaseJog_pressed();

    //!
    //! \brief event indicating the user wants to cease performing
    //! a jog manuever towards the machining surface.
    //!
    void on_pushButton_DecreaseJog_released();


    //!
    //! \brief event indicating the user wants to step
    //! the relative amount away from the machining surface.
    //! The distance is equal to the spin box.
    //!
    void on_pushButton_IncreaseRelativeMove_clicked();

    //!
    //! \brief signal event indicating the user wants to step
    //! the relative amount towards the machining surface.
    //! The distance is equal to the spin box.
    //!
    void on_pushButton_DecreaseRelativeMove_clicked();

private:
    Ui::MainWindow *ui;

private:
    galilMotionController* m_Galil;

};

#endif // MAINWINDOW_H
