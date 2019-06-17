#ifndef TOUCHOFF_WIDGET_AXIS_VALUE_H
#define TOUCHOFF_WIDGET_AXIS_VALUE_H

#include <QWidget>

#include "common/axis_definitions.h"

namespace Ui {
class TouchoffWidget_AxisValue;
}

class TouchoffWidget_AxisValue : public QWidget
{
    Q_OBJECT

public:
    explicit TouchoffWidget_AxisValue(const MotorAxis &axis, QWidget *parent = 0);
    ~TouchoffWidget_AxisValue();

    double getAxisValue() const;

    void setAxisValue(const double &value);

signals:
    void signal_AxisValueChanged();

private slots:
    void on_doubleSpinBox_TouchoffRef_editingFinished();

private:
    Ui::TouchoffWidget_AxisValue *ui;

    MotorAxis currentAxis;

    double axisValue = 0.0;
};

#endif // TOUCHOFF_WIDGET_AXIS_VALUE_H
