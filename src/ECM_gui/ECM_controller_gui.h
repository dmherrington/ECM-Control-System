#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "ECM_plot_identifier.h"

#include "munk_dialog/window_munk_power_supply.h"

#include "library_munk_power_supply/munk_power_supply.h"
#include "library_galilMotionController/galil_motion_controller.h"
#include "library_sensoray/sensoray.h"
#include "library_rigol_oscilloscope/rigol_oscilliscope.h"
#include "library_westinghouse510/westinghouse_510.h"

#include "additional_sensor_display.h"
#include "common/threadmanager.h"
#include "common/timer.h"
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
    bool maybeSave();
private slots:
    void slot_NewSensorData(const common::TupleSensorString sensor, const common_data::SensorState state);

    void on_pushButton_MotorEnable_released();

    void on_pushButton_MotorDisable_released();

    void on_pushButton_ResetHome_released();

    void on_pushButton_MoveHome_released();

    void on_pushButton_RunProfile_released();

    void on_pushButton_UploadProgram_released();

    void on_pushButton_DownloadProgram_released();

    void on_pushButton_EstablishTouchoff_released();


    void on_pushButton_IncreaseJog_pressed();

    void on_pushButton_IncreaseJog_released();

    void on_pushButton_DecreaseJog_pressed();

    void on_pushButton_DecreaseJog_released();

    void on_pushButton_IncreaseRelativeMove_released();

    void on_pushButton_DecreaseRelativeMove_released();




    void on_doubleSpinBox_CutDepth_editingFinished();

    void on_doubleSpinBox_RetractDistance_editingFinished();

    void on_doubleSpinBox_StepSize_editingFinished();

    void on_spinBox_RetractSpeed_editingFinished();

    void on_spinBox_PlungeSpeed_editingFinished();

    void on_spinBox_CutSpeed_editingFinished();

    void on_spinBox_RetractPeriod_editingFinished();

    void on_spinBox_Pause_editingFinished();

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);

private:
    Ui::ECMControllerGUI *ui;

    ECMPlotCollection m_PlotCollection;

    CollectionDisplays m_SensorDisplays;

    AdditionalSensorDisplay *m_additionalSensorDisplay;

    Window_MunkPowerSupply* m_WindowMunk;

    MunkPowerSupply* m_Munk;
    GalilMotionController* m_Galil;
    Sensoray* m_Sensoray;
    RigolOscilliscope* m_Rigol;
    Westinghouse510* m_Pump;

};

#endif // ECM_CONTROLLER_GUI_H
