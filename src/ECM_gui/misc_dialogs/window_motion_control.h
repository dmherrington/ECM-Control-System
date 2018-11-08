#ifndef WINDOW_MOTION_CONTROL_H
#define WINDOW_MOTION_CONTROL_H

#include <QMainWindow>

namespace Ui {
class Window_MotionControl;
}

class Window_MotionControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_MotionControl(QWidget *parent = 0);
    ~Window_MotionControl();

private:
    Ui::Window_MotionControl *ui;
};

#endif // WINDOW_MOTION_CONTROL_H
