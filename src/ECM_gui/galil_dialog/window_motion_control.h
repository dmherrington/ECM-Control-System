#ifndef WINDOW_MOTION_CONTROL_H
#define WINDOW_MOTION_CONTROL_H

#include "library_galilMotionController/galil_motion_controller.h"

#include "../general_dialog_window.h"

namespace Ui {
class Window_MotionControl;
}

class Window_MotionControl : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_MotionControl(GalilMotionController* galilObject, QWidget *parent = 0);
    ~Window_MotionControl();

public:
    int getCurrentJogSpeed() const;

private:
    void lockMotionButtons(const bool &lock);

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

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
    Ui::Window_MotionControl *ui;

    GalilMotionController* m_Galil;
};


#endif // WINDOW_MOTION_CONTROL_H
