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

void Widget_DetailedNotification::setNotification(const common::NotificationUpdate &notice)
{
    setNotificationType(notice.getUpdateType());
    setNotificationTime(notice.getNotificationTime());
    setNotificationMessage(notice.getUpdateType(), notice.getSourceName() + ":" + notice.getPeripheralMessage());
}


void Widget_DetailedNotification::setNotificationType(const common::NotificationUpdate::NotificationTypes &type)
{
    switch (type) {
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL:
    {
        //ui->lineEdit_NotificationType->setText("GENERAL");
        break;
    }
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_ALERT:
    {
        //ui->lineEdit_NotificationType->setText("ALERT");
        break;
    }
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR:
    {
        //ui->lineEdit_NotificationType->setText("ERROR");
        break;
    }
    }
}

void Widget_DetailedNotification::setNotificationTime(const common::EnvironmentTime &noticeTime)
{
    ui->lineEdit_Time->setText(QString::fromStdString(noticeTime.timeString()));

}
void Widget_DetailedNotification::setNotificationMessage(const common::NotificationUpdate::NotificationTypes &type, const std::string &msg)
{
    ui->plainTextEdit_Message->setPlainText(QString::fromStdString(msg));

    QPalette p = ui->lineEdit_Time->palette();

    switch (type) {
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_GENERAL:
    {
        break;
    }
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_ALERT:
    {
        p.setColor(QPalette::Base, QColor(255,165,0));
        ui->lineEdit_Time->setPalette(p);
        ui->lineEdit_Time->show();
        break;
    }
    case common::NotificationUpdate::NotificationTypes::NOTIFICATION_ERROR:
    {
        p.setColor(QPalette::Base, Qt::red);
        ui->lineEdit_Time->setPalette(p);
        ui->lineEdit_Time->show();
        break;
    }
    }
}
