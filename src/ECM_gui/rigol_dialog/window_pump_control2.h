#ifndef WINDOW_PUMP_CONTROL_H
#define WINDOW_PUMP_CONTROL_H

#include <QMainWindow>
#include "library_westinghouse510/westinghouse_510.h"

namespace Ui {
class Window_PumpControl;
}

class Window_PumpControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog_PumpControl(const Westinghouse510* obj, QWidget *parent = 0);
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
    Ui::Window_PumpControl *ui;
    const Westinghouse510* m_pump;
};

#endif // WINDOW_PUMP_CONTROL_H
