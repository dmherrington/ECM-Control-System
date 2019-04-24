#ifndef WIDGET_NOTIFICATION_H
#define WIDGET_NOTIFICATION_H

#include <QWidget>
#include <QListWidgetItem>

#include "widget_detailed_notification.h"

namespace Ui {
class Widget_Notification;
}

class Widget_Notification : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Notification(QWidget *parent = 0);
    ~Widget_Notification();

public:
    void addNewNotification(const common::NotificationUpdate &update);

private:
    Ui::Widget_Notification *ui;
};

#endif // WIDGET_NOTIFICATION_H
