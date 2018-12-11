#ifndef ECM_CONTROLLER_GUI_H
#define ECM_CONTROLLER_GUI_H

#include "gui_verison.h"

#include <QMainWindow>

#include "ECM_plot_collection.h"
#include "ECM_plot_identifier.h"

#include "galil_dialog/window_motion_control.h"

#include "misc_dialogs/window_profile_configuration.h"
#include "rigol_dialog/window_rigol_control.h"
#include "misc_dialogs/window_device_connections.h"
#include "misc_dialogs/window_custom_motion_commands.h"
#include "misc_dialogs/window_motion_profile.h"

#include "additional_sensor_display.h"
#include "common/threadmanager.h"
#include "common/timer.h"

#include "ECM_API/ecm_api.h"

#include "ui_ECM_controller_gui.h"

#include "general_dialog_window.h"

#include "common/hsm.h"
#include "ECM_API/states/state_ecm_components.h"

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
    void setupUploadCallbacks();

    void updateMCIndicators(const MotionProfileState &profileState);

private slots:
    void CreateSensorDisplays(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);
    Q_INVOKABLE void MarshalCreateSensorDisplay(const common::TupleSensorString &sensor, const common_data::SensorTypes &type);

/*
* Private Slots related to plottables
*/
private slots:
    void slot_NewlyAvailableRigolData(const common::TupleSensorString &sensor, const bool &val);
    void slot_AddPlottable(const common::TupleECMData &data, const bool &plot = false);
    void slot_RemovePlottable(const common::TupleECMData &data);
    void slot_DisplayActionTriggered();

    void slot_DeviceConnectionUpdate(const bool &connected);

/*
* Private Slots related to collection execution and initialization
*/
private slots:
    void slot_OnLoadedConfigurationCollection(const std::string &filePath);

    void slot_ExecutingOperation(const ExecuteOperationProperties &props);
    void slot_ExecutingConfiguration(const ExecutionProperties &props);

    void on_ExecuteProfileCollection(const ECMCommand_ExecuteCollection &collection);

private slots:
    void slot_NewProfileVariableData(const common::TupleProfileVariableString &variable, const common_data::MotionProfileVariableState &state);

    void slot_NewSensorData(const common::TupleSensorString &sensor, const common_data::SensorState &state);

    void slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged);


/*
* Private Slots related to the motion controller
*/
private slots:
    void slot_MCNewMotionState(const QString &state);

    void slot_MCNewDigitalInput(const StatusInputs &status);

    void slot_UpdateTouchoff(const bool &value);

    void slot_UpdateHomeIndicated(const bool &value);

    void slot_MCCommandError(const CommandType &type, const std::string &description);

/*
* Private Slots related to actions on the front GUI
*/
private slots:

    void on_pushButton_MotorEnable_released();

    void on_pushButton_MotorDisable_released();

    void on_pushButton_ResetHome_released();

    void on_pushButton_MoveHome_released();

    void on_actionClose_triggered();

/*
* Private Slots related to actions fired from the tools menu
*/
private slots:

    void slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility);

    void on_actionProfile_Configuration_triggered(bool checked);

    void on_actionMotion_Control_triggered(bool checked);

    void on_actionConnections_triggered(bool checked);

    void on_actionOscilliscope_triggered(bool checked);

    void on_actionCustom_Motion_Commands_triggered(bool checked);

    void on_actionOpen_Sensors_Window_triggered(bool checked);

    void on_actionClear_All_Data_triggered();

    void on_pushButton_Stop_released();


    void on_pushButton_RunAutomatedProfile_released();

    void on_pushButton_LoadAutomatedProfile_released();

private:
    QString loadFileDialog(const std::string &filePath, const std::string &nameFilter);

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

    ECM_API* m_API;

    Window_MotionControl* m_WindowMotionControl;
    Window_ProfileConfiguration* m_WindowProfileConfiguration;
    Window_RigolControl* m_WindowRigol;
    Window_DeviceConnections* m_WindowConnections;
    Window_CustomMotionCommands* m_WindowCustomMotionCommands;

private:
    void ProgressStateMachineStates();
    std::mutex m_Mutex_StateMachine;
    hsm::StateMachine* stateMachine;

private:
    EnvironmentTime operationStart;
    EnvironmentTime configurationStart;
    QTimer* elapsedConfigurationTimer;
    QTimer* elapsedOperationTimer;
private slots:
    void slot_OnUpdateElapsedOperationTime();
    void slot_OnUpdateElapsedConfigurationTime();
};

#endif // ECM_CONTROLLER_GUI_H
