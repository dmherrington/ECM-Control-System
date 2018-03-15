#ifndef DIALOG_PUMP_CONTROL_H
#define DIALOG_PUMP_CONTROL_H

#include <QDialog>
#include "library_westinghouse510/westinghouse_510.h"

namespace Ui {
class Dialog_PumpControl;
}

class Dialog_PumpControl : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_PumpControl(const westinghousePump::Westinghouse510* ref, QWidget *parent = 0);
    ~Dialog_PumpControl();

signals:
    void signal_updatePumpRunning(const bool &value);

    void signal_updatePumpFlowRate(const double &value);

    void signal_updatePumpDelayTime(const double &value);

private slots:
    void slot_updatedDelayTime(const double &value);

    void slot_updatedConnection();

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

    void slot_updatedStartTime();

private slots:

    void on_pushButton_PumpRunning_released();

    void on_doubleSpinBox_flowRate_editingFinished();

    void on_doubleSpinBox_delayTime_editingFinished();

private:
    Ui::Dialog_PumpControl *ui;
    const westinghousePump::Westinghouse510* m_pump;
};

#endif // DIALOG_PUMP_CONTROL_H
