#include "touchoff_widget_axis_value.h"
#include "ui_touchoff_widget_axis_value.h"

TouchoffWidget_AxisValue::TouchoffWidget_AxisValue(const MotorAxis &axis, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchoffWidget_AxisValue)
{
    ui->setupUi(this);

    this->currentAxis = axis;
    ui->label_Axis->setText(QString::fromStdString(AxisToString(axis)));
}

TouchoffWidget_AxisValue::~TouchoffWidget_AxisValue()
{
    delete ui;
}

void TouchoffWidget_AxisValue::executingAutomatedSequence(const bool &shouldBlock)
{
    ui->doubleSpinBox_TouchoffRef->blockSignals(shouldBlock);
    ui->doubleSpinBox_TouchoffGap->blockSignals(shouldBlock);

    ui->doubleSpinBox_TouchoffRef->setDisabled(shouldBlock);
    ui->doubleSpinBox_TouchoffGap->setDisabled(shouldBlock);

    ui->pushButton_Run->setDisabled(shouldBlock);

    ui->radioButton_DirectionP->setDisabled(shouldBlock);
    ui->radioButton_DirectionM->setDisabled(shouldBlock);

}

void TouchoffWidget_AxisValue::setAxisValue(const double &refValue, const double &gapValue)
{
    //We are going to allow the this to feedback on signal changed, allowing the it to hit the motion controller
    ui->doubleSpinBox_TouchoffRef->setValue(refValue);
    ui->doubleSpinBox_TouchoffGap->setValue(gapValue);
}

void TouchoffWidget_AxisValue::setRefValue(const double &refValue)
{
    //We are going to allow the this to feedback on signal changed, allowing the it to hit the motion controller
    ui->doubleSpinBox_TouchoffRef->setValue(refValue);
}

void TouchoffWidget_AxisValue::getAxisValue(double &refValue, double &gapValue) const
{
    refValue = ui->doubleSpinBox_TouchoffRef->value();
    gapValue = ui->doubleSpinBox_TouchoffGap->value();
}

int TouchoffWidget_AxisValue::getAxisDirection() const
{
    int directionFlag = 0;
    if(ui->radioButton_DirectionP->isChecked())
        directionFlag = 1;
    else
        directionFlag = -1;

    return directionFlag;
}

void TouchoffWidget_AxisValue::on_doubleSpinBox_TouchoffRef_editingFinished()
{
    emit signal_AxisValueChanged();
}

void TouchoffWidget_AxisValue::on_pushButton_Run_released()
{
    emit signal_PushButtonRun(this->currentAxis);
}

void TouchoffWidget_AxisValue::updatedMotionProfileState(const MotionProfileState &state)
{
    if(state.getProfileState()->getType() == MotionProfile::ProfileType::TOUCHOFF)
    {
        ProfileState_Touchoff* castState = (ProfileState_Touchoff*)state.getProfileState().get();

        switch (castState->getCurrentCode()) {
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_POSITIONAL:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_INCONSISTENT:
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ERROR_TOUCHING:
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,0,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::SEARCHING:
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,255,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::FINISHED:
            ui->widget_LEDTouchoffStatus->setColor(QColor(0,255,0));
            break;
        case ProfileState_Touchoff::TOUCHOFFProfileCodes::ABORTED:
            ui->widget_LEDTouchoffStatus->setColor(QColor(255,0,0));
            break;
        default:
            break;
        }
    }
}
