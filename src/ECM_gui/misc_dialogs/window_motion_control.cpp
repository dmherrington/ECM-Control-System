#include "window_motion_control.h"
#include "ui_window_motion_control.h"

Window_MotionControl::Window_MotionControl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_MotionControl)
{
    ui->setupUi(this);
}

Window_MotionControl::~Window_MotionControl()
{
    delete ui;
}
