#ifndef TOUCHOFF_WIDGET_AXIS_VALUE_H
#define TOUCHOFF_WIDGET_AXIS_VALUE_H

#include <QWidget>

#include "common/axis_definitions.h"
#include "common/commands/command_variable.h"

namespace Ui {
class TouchoffWidget_AxisValue;
}

class TouchoffWidget_AxisValue : public QWidget
{
    Q_OBJECT

public:
    explicit TouchoffWidget_AxisValue(const MotorAxis &axis, QWidget *parent = 0);
    ~TouchoffWidget_AxisValue();

    void getAxisValue(double &refValue, double &gapValue) const;

    int getAxisDirection() const;

    void setAxisValue(const double &refValue, const double &gapValue);

    void setRefValue(const double &refValue);

    void executingAutomatedSequence(const bool &shouldBlock);

signals:
    void signal_AxisValueChanged();

    void signal_PushButtonRun(const MotorAxis &axis);

private slots:
    void on_doubleSpinBox_TouchoffRef_editingFinished();

    void on_pushButton_Run_released();

private:
    Ui::TouchoffWidget_AxisValue *ui;

    MotorAxis currentAxis;
};

#endif // TOUCHOFF_WIDGET_AXIS_VALUE_H
