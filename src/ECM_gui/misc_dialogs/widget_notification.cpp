#include "widget_notification.h"
#include "ui_widget_notification.h"

Widget_Notification::Widget_Notification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Notification)
{
    ui->setupUi(this);
}

Widget_Notification::~Widget_Notification()
{
    delete ui;
}

void Widget_Notification::addNewNotification(const common::NotificationUpdate &update)
{
    Widget_DetailedNotification* widgetDetailedNotification = new Widget_DetailedNotification();
    widgetDetailedNotification->setNotification(update);

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(widgetDetailedNotification->sizeHint());
    widgetDetailedNotification->setAssociatedWidget(newItem);

    ui->listWidget_Notifications->addItem(newItem);
    ui->listWidget_Notifications->setItemWidget(newItem,widgetDetailedNotification);
}
