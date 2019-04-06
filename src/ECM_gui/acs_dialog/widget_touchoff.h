#ifndef WIDGET_TOUCHOFF_H
#define WIDGET_TOUCHOFF_H

#include <QWidget>

#include "common/configs/configuration_touchoff.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Widget_Touchoff;
}

class Widget_Touchoff : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Touchoff(SPIIMotionController* motionControlObject, QWidget *parent = 0);
    ~Widget_Touchoff();

public:

    void loadFromTouchoffConfig(const Configuration_Touchoff &config);

    Configuration_Touchoff getCurrentTouchoffConfig() const;

public:
    void setTouchoffUtilization(const bool &execute);

public:
    std::map<MotorAxis, double> getTouchoffRefMap() const;
    std::map<MotorAxis, double> getTouchoffGapMap() const;

private slots:

    void on_pushButton_TouchoffRef_released();

    void on_doubleSpinBox_TouchoffRef_valueChanged(double arg1);

    void on_doubleSpinBox_InitialGap_valueChanged(double arg1);

    void on_checkBox_ReferenceOldPosition_toggled(bool val);

private:
    Ui::Widget_Touchoff *ui;

    SPIIMotionController* m_MotionController;

};

#endif // WIDGET_TOUCHOFF_H
