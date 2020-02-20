#ifndef WIDGET_FRONT_PANEL_MOTION_CONTROL_H
#define WIDGET_FRONT_PANEL_MOTION_CONTROL_H

#include <QWidget>

#include "../general_dialog_window.h"

#include "widget_front_panel_axis_motion_control.h"

#include "library_SPIIMotionController/spii_motion_controller.h"


namespace Ui {
class WidgetFrontPanel_MotionControl;
}

class WidgetFrontPanel_MotionControl : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_MotionControl(const std::vector<MotorAxis> &axis, SPIIMotionController* motionControllerObject, QWidget *parent = nullptr);
    ~WidgetFrontPanel_MotionControl() override;

public:
    void updateAvailableAxes(const std::vector<MotorAxis> &axes);

private slots:

private:
    Ui::WidgetFrontPanel_MotionControl *ui;

    std::map<MotorAxis, WidgetFrontPanel_AxisMotionControl*> m_WidgetAxisControl;

    SPIIMotionController* m_MotionController;
};

#endif // WIDGET_FRONT_PANEL_MOTION_CONTROL_H

