#ifndef WIDGET_AXIS_HORIZONTAL_CONTROL_H
#define WIDGET_AXIS_HORIZONTAL_CONTROL_H

#include <QWidget>

#include "widget_abstract_axis_control.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Widget_AxisHorizontalControl;
}

class Widget_AxisHorizontalControl : public QWidget, public Widget_AbstractAxisControl
{
    Q_OBJECT

public:
    explicit Widget_AxisHorizontalControl(const MotorAxis &axis, SPIIMotionController *motionObject, QWidget *parent = nullptr);
    ~Widget_AxisHorizontalControl() override;

private:
    void lockAllMotionButtons(const bool &shouldLock) override;

    void lockRelativeMove(const bool &shouldLock) override;

    void lockJogMove(const bool &shouldLock) override;

private slots:
    void on_pushButton_IncreaseJog_pressed();

    void on_pushButton_IncreaseJog_released();

    void on_pushButton_DecreaseJog_pressed();

    void on_pushButton_DecreaseJog_released();

    void on_pushButton_IncreaseRelativeMove_released();

    void on_pushButton_DecreaseRelativeMove_released();

private:
    Ui::Widget_AxisHorizontalControl *ui;

    MotorAxis pertinentAxis;

    SPIIMotionController* m_MotionController;
};

#endif // WIDGET_AXIS_HORIZONTAL_CONTROL_H
