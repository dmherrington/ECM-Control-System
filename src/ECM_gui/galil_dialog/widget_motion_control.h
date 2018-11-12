#ifndef WIDGET_MOTION_CONTROL_H
#define WIDGET_MOTION_CONTROL_H

#include <QWidget>

#include "library_galilMotionController/galil_motion_controller.h"

namespace Ui {
class Widget_MotionControl;
}

class Widget_MotionControl : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_MotionControl(GalilMotionController* galilObject, QWidget *parent = 0);
    ~Widget_MotionControl();

public:
    int getCurrentJogSpeed() const;

private slots:
    void on_pushButton_IncreaseJog_pressed();

    void on_pushButton_IncreaseJog_released();

    void on_pushButton_DecreaseJog_pressed();

    void on_pushButton_DecreaseJog_released();

    void on_pushButton_IncreaseRelativeMove_released();

    void on_pushButton_DecreaseRelativeMove_released();

private slots:
    void slot_NewPositionalData(const common::TuplePositionalString &tuple, const common_data::MachinePositionalState &state, const bool &valueChanged);

    void slot_LockMotionButtons(const bool &lock);


private:
    Ui::Widget_MotionControl *ui;

    GalilMotionController* m_Galil;
};

#endif // WIDGET_MOTION_CONTROL_H
