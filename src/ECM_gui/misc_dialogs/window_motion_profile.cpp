#include "window_motion_profile.h"
#include "ui_window_motion_profile.h"

Window_MotionProfile::Window_MotionProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MotionProfile)
{
    ui->setupUi(this);
}

Window_MotionProfile::~Window_MotionProfile()
{
    delete ui;
}
