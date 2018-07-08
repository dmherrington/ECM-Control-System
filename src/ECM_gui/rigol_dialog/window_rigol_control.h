#ifndef WINDOW_RIGOL_CONTROL_H
#define WINDOW_RIGOL_CONTROL_H

#include "../general_dialog_window.h"

#include "ui_window_rigol_control.h"
#include "widget_rigol_radio.h"

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"

namespace Ui {
class Window_RigolControl;
}

class Window_RigolControl : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_RigolControl(RigolOscilliscope* obj, QWidget *parent = 0);
    ~Window_RigolControl();

private:
    void closeEvent(QCloseEvent *event) override;

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

signals:
    void signal_DialogWindowVisibilty(const DialogWindowTypes &type, const bool &visibility) override;

private slots:
    void slot_OscilliscopeConnectionUpdate(const common::comms::CommunicationUpdate &value);

    void slot_onRadioButtonChange(const data_Rigol::MeasurementTypes &measurement, const bool &checked);

    void slot_onLoadComplete();

private slots:
    void on_pushButton_Done_released();

    void on_comboBox_Channel_currentIndexChanged(const QString &arg1);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// Action events triggered from the menu bar
    ///////////////////////////////////////////////////////////////////////////////////////////////

    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::Window_RigolControl *ui;
    RigolOscilliscope* m_Rigol;
    bool windowHidden = true;

    bool previouslyLoad = false;
    QString loggingPath;
    QString previousSettingsPath;
    QString currentSettingsPath;
};

#endif // WINDOW_RIGOL_CONTROL_H
