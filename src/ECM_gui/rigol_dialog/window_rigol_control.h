#ifndef WINDOW_RIGOL_CONTROL_H
#define WINDOW_RIGOL_CONTROL_H

#include <QMainWindow>

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"

namespace Ui {
class Window_RigolControl;
}

class Window_RigolControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_RigolControl(RigolOscilliscope* obj, QWidget *parent = 0);
    ~Window_RigolControl();

    bool isWindowHidden() const;

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

signals:
    void signal_RigolHideWindow();

private slots:
    void  slot_OscilliscopeConnectionUpdate(const common::comms::CommunicationConnection &value);

private slots:
    void on_pushButton_Done_released();

    void on_radioButton_AMP_toggled(bool checked);
    void on_radioButton_AVG_toggled(bool checked);
    void on_radioButton_BASE_toggled(bool checked);
    void on_radioButton_FDELAY_toggled(bool checked);
    void on_radioButton_FPHASE_toggled(bool checked);
    void on_radioButton_FREQUENCY_toggled(bool checked);
    void on_radioButton_FTIME_toggled(bool checked);
    void on_radioButton_MAREA_toggled(bool checked);
    void on_radioButton_MAX_toggled(bool checked);
    void on_radioButton_MIN_toggled(bool checked);
    void on_radioButton_MPAREA_toggled(bool checked);
    void on_radioButton_NDUTY_toggled(bool checked);
    void on_radioButton_NWIDTH_toggled(bool checked);
    void on_radioButton_OVERSHOOT_toggled(bool checked);
    void on_radioButton_PDUTY_toggled(bool checked);
    void on_radioButton_PERIOD_toggled(bool checked);
    void on_radioButton_PRESHOOT_toggled(bool checked);
    void on_radioButton_PWIDTH_toggled(bool checked);
    void on_radioButton_RDELAY_toggled(bool checked);
    void on_radioButton_RMS_toggled(bool checked);
    void on_radioButton_RPHASE_toggled(bool checked);
    void on_radioButton_RTIME_toggled(bool checked);
    void on_radioButton_VPP_toggled(bool checked);
    void on_radioButton_VTOP_toggled(bool checked);

    void on_comboBox_Channel_currentIndexChanged(const QString &arg1);

    void on_actionClose_triggered();

private:
    void setRadioButton(const data_Rigol::MeasurementTypes &measurement, const bool &value);
    void resetRadioButtons();

private:
    Ui::Window_RigolControl *ui;
    RigolOscilliscope* m_Rigol;
    bool windowHidden = true;
};

#endif // WINDOW_RIGOL_CONTROL_H
