#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "ECM_plot_identifier.h"

#include "munk_dialog/window_munk_power_supply.h"
#include "pump_dialog/window_pump_control.h"
#include "rigol_dialog/window_rigol_control.h"
#include "misc_dialogs/dialog_connections.h"
#include "misc_dialogs/dialog_custom_commands.h"
#include "misc_dialogs/window_touchoff.h"

#include "additional_sensor_display.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "ECM_API/ecm_api.h"

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
    void CreateSensorDisplays(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);
    Q_INVOKABLE void MarshalCreateSensorDisplay(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);

private slots:
    void slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val);
private slots:
    void slot_NewSensorData(const common::TupleSensorString sensor, const common_data::SensorState state);

    void slot_UpdateHomeIndicated(const bool &value);

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

    void on_actionConnections_triggered();

    void on_actionPump_triggered();

    void on_actionPower_Supply_triggered();

    void on_actionOscilliscope_triggered();

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);

private:

    //! Map of sensors whose displays have been created
    QMap<common::TupleSensorString, bool> m_CreatedSensors;

    //! Additional sensor display form
    AdditionalSensorDisplay *m_additionalSensorDisplay;

    //! Collection of sensor displays to show in GUI window
    CollectionDisplays m_SensorDisplays;

    //! Boolean indicating active sensor
    bool m_DisplaySensor;

    //! Active Sensor TupleString
    common::TupleSensorString m_ActiveSensor;


    Ui::ECMControllerGUI *ui;

    ECMPlotCollection m_PlotCollection;

    ECM_API* m_API;

    Window_MunkPowerSupply* m_WindowMunk;
    Window_PumpControl* m_WindowPump;
    Window_RigolControl* m_WindowRigol;
    Dialog_Connections* m_DialogConnections;
    Dialog_CustomCommands* m_DialogCustomCommands;
    Window_Touchoff* m_WindowTouchoff;
};

#endif // ECM_CONTROLLER_GUI_H
