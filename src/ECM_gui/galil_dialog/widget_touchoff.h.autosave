#ifndef WIDGET_TOUCHOFF_H
#define WIDGET_TOUCHOFF_H

#include <QWidget>

#include "library_SPIIMotionController/spii_motion_controller.h"
#include "common/configs/configuration_touchoff.h"

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
    void setTouchoffRef(const double &value);

    void setTouchoffGap(const double &value);

    void setTouchoffUtilization(const bool &execute);

private slots:

    void on_pushButton_TouchoffRef_released();

    void on_doubleSpinBox_TouchoffRef_valueChanged(double arg1);

    void on_doubleSpinBox_InitialGap_valueChanged(double arg1);

    void on_checkBox_ReferenceOldPosition_toggled(bool val);

private:
    Ui::Widget_Touchoff *ui;

    SPIIMotionController* m_Galil;

};

#endif // WIDGET_TOUCHOFF_H
