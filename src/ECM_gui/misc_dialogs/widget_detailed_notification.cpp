#include "widget_detailed_notification.h"
#include "ui_widget_detailed_notification.h"

Widget_DetailedNotification::Widget_DetailedNotification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_DetailedNotification)
{
    ui->setupUi(this);
}

Widget_DetailedNotification::~Widget_DetailedNotification()
{
    delete ui;
}
