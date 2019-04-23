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

void Widget_DetailedNotification::setDetailedNotification(const Detailed_Notification &notice)
{
    setNotificationType(notice.getUpdateType());
    setNotificationTime();
    setNotificationMessage(notice.getUpdateType(), notice.getPeripheralMessage());
}


void Widget_DetailedNotification::setNotificationType(const common::NotificationUpdate::UpdateTypes &type)
{
    switch (type) {
    case common::NotificationUpdate::UpdateTypes::ALERT:
    {
        break;
    }
    case common::NotificationUpdate::UpdateTypes::ERROR:
    {
        break;
    }
    case common::NotificationUpdate::UpdateTypes::NOTIFICATION:
    {
        break;
    }
    }
}
void Widget_DetailedNotification::setNotificationTime()
{

}
void Widget_DetailedNotification::setNotificationMessage(const common::NotificationUpdate::UpdateTypes &type, const std::string &msg)
{
    ui->plainTextEdit_Message->setPlainText(QString::fromStdString(msg));
    switch (type) {
    case common::NotificationUpdate::UpdateTypes::ALERT:
    {
        break;
    }
    case common::NotificationUpdate::UpdateTypes::ERROR:
    {
        break;
    }
    case common::NotificationUpdate::UpdateTypes::NOTIFICATION:
    {
        break;
    }
    }
}
