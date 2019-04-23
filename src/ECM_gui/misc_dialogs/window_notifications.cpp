#include "window_notifications.h"
#include "ui_window_notifications.h"

Window_Notifications::Window_Notifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_Notifications)
{
    ui->setupUi(this);
}

Window_Notifications::~Window_Notifications()
{
    delete ui;
}
