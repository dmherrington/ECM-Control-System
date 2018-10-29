#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include "gui_verison.h"

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "ECM_plot_identifier.h"

#include "munk_dialog/window_munk_power_supply.h"
#include "pump_dialog/window_pump_control.h"
#include "rigol_dialog/window_rigol_control.h"
#include "misc_dialogs/window_device_connections.h"
#include "misc_dialogs/window_custom_motion_commands.h"
#include "misc_dialogs/window_touchoff.h"
#include "misc_dialogs/window_motion_profile.h"
#include "misc_dialogs/window_munk_temperature_status.h"

#include "additional_sensor_display.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "ECM_API/ecm_api.h"

#include "ui_ECM_controller_gui.h"

#include "general_dialog_window.h"

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
    void setupMachiningSequence(const std::string &partNumber, const std::string &serialNumber, const std::string &profileName,const bool &clearContents);

private slots:
    void CreateSensorDisplays(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);
    Q_INVOKABLE void MarshalCreateSensorDisplay(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);

private slots:
    void slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val);
    void slot_AddPlottable(const common::TupleECMData &data, const bool &plot = false);
    void slot_RemovePlottable(const common::TupleECMData &data);
    void slot_DisplayActionTriggered();
    void slot_UpdatedMotionProfileState(const MotionProfileState &state);
    void slot_MCCommandError(const CommandType &type, const std::string &description);
    void slot_MCTouchoffIndicated(const bool &indicated);

private slots:
    void slot_NewProfileVariableData(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state);

    void slot_NewSensorData(const common::TupleSensorString &sensor, const common_data::SensorState &state);

    void slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged);

    void slot_MCNewMotionState(const std::string &state);

    void slot_MCNewDigitalInput(const StatusInputs &status);

    void slot_MCNewProgramLabels(const ProgramLabelList &labels);

    void slot_MCNEWProgramVariableList(const ProgramVariableList &variables);

    void slot_UpdateHomeIndicated(const bool &value);

    void on_pushButton_MotorEnable_released();

    void on_pushButton_MotorDisable_released();

    void on_pushButton_ResetHome_released();

    void on_pushButton_MoveHome_released();

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

    void on_doubleSpinBox_CutSpeed_editingFinished();

    void on_spinBox_RetractPeriod_editingFinished();

    void on_spinBox_Pause_editingFinished();

    void on_actionClose_triggered();



    void slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility);

    void on_actionConnections_triggered(bool checked);

    void on_actionPump_triggered(bool checked);

    void on_actionPower_Supply_triggered(bool checked);

    void on_actionOscilliscope_triggered(bool checked);

    void on_actionTouchoff_triggered(bool checked);

    void on_actionMotion_Profile_triggered(bool checked);

    void on_actionCustom_Motion_Commands_triggered(bool checked);

    void on_actionOpen_Sensors_Window_triggered(bool checked);

    void on_actionClear_All_Data_triggered();



    void on_pushButton_RunExplicitProfile_released();

    void on_pushButton_RunAutomatedProfile_released();

    void on_pushButton_Stop_released();



    void slot_LockMotionButtons(const bool &lock);

    void on_pushButton_IncreaseJog_clicked();

    void on_pushButton_DecreaseJog_clicked();

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);

private:
    Ui::ECMControllerGUI *ui;

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

    QMap<common::TupleECMData, QAction*> m_PlottingActionMap;

    ECMPlotCollection m_PlotCollection;
    int counter = 0;
    ECM_API* m_API;

    Window_MunkPowerSupply* m_WindowMunk;
    Window_PumpControl* m_WindowPump;
    Window_RigolControl* m_WindowRigol;
    Window_DeviceConnections* m_WindowConnections;
    Window_CustomMotionCommands* m_WindowCustomMotionCommands;
    Window_Touchoff* m_WindowTouchoff;
    Window_MotionProfile* m_WindowMotionProfile;
};

#endif // ECM_CONTROLLER_GUI_H
