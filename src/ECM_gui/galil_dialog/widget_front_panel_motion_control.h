#ifndef WIDGET_FRONT_PANEL_MOTION_CONTROL_H
#define WIDGET_FRONT_PANEL_MOTION_CONTROL_H

#include <QWidget>

#include "library_galilMotionController/galil_motion_controller.h"
#include "../general_dialog_window.h"

namespace Ui {
class WidgetFrontPanel_MotionControl;
}

class WidgetFrontPanel_MotionControl : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_MotionControl(GalilMotionController* galilObject, QWidget *parent = nullptr);
    ~WidgetFrontPanel_MotionControl() override;

public:
    int getCurrentJogSpeed() const;

private:
    void lockMotionButtons(const bool &lock);

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

    void slot_MCNewMotionState(const ECM::Galil::GalilState &state, const QString &stateString);

private:
    Ui::WidgetFrontPanel_MotionControl *ui;

    GalilMotionController* m_Galil;
};

#endif // WIDGET_FRONT_PANEL_MOTION_CONTROL_H

