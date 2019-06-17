#include "touchoff_widget_axis_value.h"
#include "ui_touchoff_widget_axis_value.h"

TouchoffWidget_AxisValue::TouchoffWidget_AxisValue(const MotorAxis &axis, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchoffWidget_AxisValue)
{
    ui->setupUi(this);

    this->currentAxis = axis;
}

TouchoffWidget_AxisValue::~TouchoffWidget_AxisValue()
{
    delete ui;
}

double TouchoffWidget_AxisValue::getAxisValue() const
{
    return this->axisValue;
}

void TouchoffWidget_AxisValue::setAxisValue(const double &value)
{
    //We are going to allow the this to feedback on signal changed, allowing the it to hit the motion controller
    ui->doubleSpinBox_TouchoffRef->setValue(value);
}

void TouchoffWidget_AxisValue::on_doubleSpinBox_TouchoffRef_editingFinished()
{
    this->axisValue = this->ui->doubleSpinBox_TouchoffRef->value();
    emit signal_AxisValueChanged();
}
