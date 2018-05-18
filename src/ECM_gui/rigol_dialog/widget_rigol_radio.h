#ifndef WIDGET_RIGOL_RADIO_H
#define WIDGET_RIGOL_RADIO_H

#include <QWidget>

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"

namespace Ui {
class Widget_RigolRadio;
}

class Widget_RigolRadio : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_RigolRadio(QWidget *parent = 0);
    ~Widget_RigolRadio();

public:
    void setRadioButton(const data_Rigol::MeasurementTypes &measurement, const bool &value);
    void resetRadioButtons();

signals:
    void signal_onRadioButtonChange(const data_Rigol::MeasurementTypes &measurement, const bool &value);

private slots:
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

private:
    Ui::Widget_RigolRadio *ui;
};

#endif // WIDGET_RIGOL_RADIO_H
