#ifndef WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H
#define WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H

#include <QWidget>

#include "../general_dialog_window.h"

#include "widget_axis_vertical_control.h"
#include "widget_axis_horizontal_control.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class WidgetFrontPanel_AxisMotionControl;
}

class WidgetFrontPanel_AxisMotionControl : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_AxisMotionControl(const MotorAxis &axis, SPIIMotionController* motionControlObject, QWidget *parent = nullptr);
    ~WidgetFrontPanel_AxisMotionControl() override;

public:
    int getCurrentJogSpeed() const;

private:
    void lockMotionButtons(const bool &lock);


private slots:
    void slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged);

    void slot_LockMotionButtons(const bool &lock);

    void slot_MCNewMotionState(const ECM::SPII::SPIIState &state, const QString &stateString);

private:
    Ui::WidgetFrontPanel_AxisMotionControl *ui;

    Widget_AbstractAxisControl* m_ControlWidget;

    MotorAxis pertinentAxis;

    SPIIMotionController* m_MotionController;
};
#endif // WIDGET_FRONT_PANEL_AXIS_MOTION_CONTROL_H
