#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include "gclib.h"

#include "widget_profile_display.h"
#include "widget_profile_variable_display.h"

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

    void on_actionSave_Current_Parameters_triggered();

    void on_actionSave_As_Current_Parameters_triggered();

    void on_actionLoad_Parameters_triggered();

    void on_pushButton_MotorEnable_clicked();

    void on_pushButton_CMDSend_clicked();

    void on_pushButton_MotorDisable_clicked();

    void on_pushButton_RunProfile_clicked();

    void on_pushButton_UploadProgram_clicked();

    void on_pushButton_DownloadProgram_clicked();

    void on_actionOpen_Connection_triggered();

    void on_actionClose_Connection_triggered();

    void on_action_LoadProfile_triggered();

private:
    QString loadFileDialog(const std::string &filePath, const std::string &suffix);
    QString saveAsFileDialog(const std::string &filePath, const std::string &suffix);

    void clearProfileTabs();
private:
    Ui::MainWindow *ui;

private:
    GalilMotionController* m_Galil;
    std::string profilePath;
    std::map<std::string,WidgetProfileDisplay*> m_ProfileDisplay;

};

#endif // MAINWINDOW_H
