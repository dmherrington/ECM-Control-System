#ifndef WIDGET_FRONT_PANEL_TOUCHOFF_H
#define WIDGET_FRONT_PANEL_TOUCHOFF_H

#include <QWidget>

#include "../general_dialog_window.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class WidgetFrontPanel_Touchoff;
}

class WidgetFrontPanel_Touchoff : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_Touchoff(SPIIMotionController* obj, QWidget *parent = nullptr);
    ~WidgetFrontPanel_Touchoff() override;

private slots:
    void on_pushButton_ExecuteTouchoff_released();

    void on_pushButton_TouchoffRef_released();

    void slot_UpdateMotionProfileState(const MotionProfileState &state);

    void on_pushButton_TouchoffGap_released();

    void on_doubleSpinBox_TouchoffRef_valueChanged(double arg1);

    void on_doubleSpinBox_InitialGap_valueChanged(double arg1);

private:
    Ui::WidgetFrontPanel_Touchoff *ui;
    SPIIMotionController* m_MotionController;
};

#endif // WIDGET_FRONT_PANEL_TOUCHOFF_H
