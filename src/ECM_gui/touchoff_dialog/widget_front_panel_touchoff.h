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

private:
    void transmitTouchoffReference();

    void transmitTouchoffGap();

private slots:

    void slot_AxisValueChanged();

    void on_pushButton_ExecuteTouchoff_released();

    void on_pushButton_TouchoffRef_released();

    void slot_UpdateMotionProfileState(const MotionProfileState &state);

    void on_pushButton_TouchoffGap_released();


private:
    Ui::WidgetFrontPanel_Touchoff *ui;
    SPIIMotionController* m_MotionController;

    std::map<MotorAxis,TouchoffWidget_AxisValue*> m_TouchoffRefValues;
    std::map<MotorAxis,TouchoffWidget_AxisValue*> m_TouchoffGapValues;

};

#endif // WIDGET_FRONT_PANEL_TOUCHOFF_H
