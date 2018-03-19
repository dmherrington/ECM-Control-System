#ifndef WINDOW_TOUCHOFF_H
#define WINDOW_TOUCHOFF_H

#include <QMainWindow>

#include "library_galilMotionController/galil_motion_controller.h"

namespace Ui {
class Window_Touchoff;
}

class Window_Touchoff : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Touchoff(GalilMotionController* obj, QWidget *parent = 0);
    ~Window_Touchoff();

    bool isWindowHidden() const;

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private slots:
    void on_actionClose_triggered();

    void on_pushButton_ExecuteTouchoff_released();

    void slot_UpdateMotionProfileState(const MotionProfileState &state);

    void on_pushButton_TouchoffRef_released();

    void on_pushButton_RunTouchoff_released();

private:
    Ui::Window_Touchoff *ui;
    GalilMotionController* m_MotionController;
    bool windowHidden = true;
};

#endif // WINDOW_TOUCHOFF_H
