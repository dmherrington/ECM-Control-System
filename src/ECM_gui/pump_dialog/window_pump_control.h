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
    explicit Window_PumpControl(Westinghouse510 *obj, QWidget *parent = 0);
    ~Window_PumpControl();

    bool isWindowHidden() const;

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private slots:
    void slot_updatedDelayTime(const double &value);

    void slot_updatedConnection();

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

    void slot_updatedStartTime();

private slots:

    void on_pushButton_PumpRunning_released();

    void on_doubleSpinBox_flowRate_valueChanged(double arg1);

    void on_doubleSpinBox_delayTime_valueChanged(double arg1);

private:
    Ui::Window_PumpControl *ui;
    Westinghouse510* m_Pump;
    bool windowHidden = true;

};

#endif // WINDOW_PUMP_CONTROL_H
