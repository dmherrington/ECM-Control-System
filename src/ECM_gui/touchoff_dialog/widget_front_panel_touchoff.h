#ifndef WIDGET_FRONT_PANEL_TOUCHOFF_H
#define WIDGET_FRONT_PANEL_TOUCHOFF_H

#include <QWidget>

#include "../general_dialog_window.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

#include "touchoff_widget_axis_value.h"

namespace Ui {
class WidgetFrontPanel_Touchoff;
}

class WidgetFrontPanel_Touchoff : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_Touchoff(const std::vector<MotorAxis> &applicableAxis, SPIIMotionController* obj, QWidget *parent = nullptr);

    ~WidgetFrontPanel_Touchoff() override;

    void executingAutomatedSequence(const bool &shouldBlock);

public:
    void updateAvailableAxes(const std::vector<MotorAxis> &axes);

private:
    void transmitTouchoffParameters(const MotorAxis &axis);

private slots:

    void slot_AxisValueChanged();

    void slot_OnRunPushButton(const MotorAxis &axis);

    void on_pushButton_ExecuteTouchoff_released();

    void on_pushButton_TouchoffRef_released();

    void slot_UpdateMotionProfileState(const MotionProfileState &state);

    void on_pushButton_TouchoffGap_released();


private:
    Ui::WidgetFrontPanel_Touchoff *ui;
    SPIIMotionController* m_MotionController;

    std::map<MotorAxis,TouchoffWidget_AxisValue*> m_TouchoffValues;
};

#endif // WIDGET_FRONT_PANEL_TOUCHOFF_H
