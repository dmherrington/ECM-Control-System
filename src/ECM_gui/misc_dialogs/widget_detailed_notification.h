#ifndef WIDGET_DETAILED_NOTIFICATION_H
#define WIDGET_DETAILED_NOTIFICATION_H

#include <QWidget>
#include <QListWidgetItem>

#include "common/environment_time.h"
#include "common/notification_update.h"

namespace Ui {
class Widget_DetailedNotification;
}

class Widget_DetailedNotification : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_DetailedNotification(QWidget *parent = 0);
    ~Widget_DetailedNotification();

    void setNotification(const common::NotificationUpdate &notice);

public:
    void setAssociatedWidget(QListWidgetItem* item)
    {
        m_QListWidgetItem = item;
    }
    QListWidgetItem* getAssociatedWidget() const
    {
        return m_QListWidgetItem;
    }
private:
    void setNotificationType(const common::NotificationUpdate::NotificationTypes &type);
    void setNotificationTime(const common::EnvironmentTime &noticeTime);
    void setNotificationMessage(const common::NotificationUpdate::NotificationTypes &type, const std::string &msg);

private:
    Ui::Widget_DetailedNotification *ui;
    QListWidgetItem* m_QListWidgetItem;
};


#endif // WIDGET_DETAILED_NOTIFICATION_H
