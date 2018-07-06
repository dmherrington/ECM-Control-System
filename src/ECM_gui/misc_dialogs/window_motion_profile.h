#ifndef WINDOW_MOTION_PROFILE_H
#define WINDOW_MOTION_PROFILE_H

#include <QMainWindow>

namespace Ui {
class Window_MotionProfile;
}

class Window_MotionProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_MotionProfile(QWidget *parent = 0);
    ~Window_MotionProfile();

private:
    Ui::Window_MotionProfile *ui;
};

#endif // WINDOW_MOTION_PROFILE_H
