#ifndef WIDGET_DETAILED_NOTIFICATION_H
#define WIDGET_DETAILED_NOTIFICATION_H

#include <QWidget>
#include <QListWidgetItem>

#include "common/notification_update.h"

class Detailed_Notification : public common::NotificationUpdate
{
public:
    Detailed_Notification():
        common::NotificationUpdate()
    {

    }
    Detailed_Notification(const common::NotificationUpdate &update):
        common::NotificationUpdate (update)
    {

    }

    ~Detailed_Notification() = default;

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
    QListWidgetItem* m_QListWidgetItem;

};

namespace Ui {
class Widget_DetailedNotification;
}

class Widget_DetailedNotification : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_DetailedNotification(QWidget *parent = 0);
    ~Widget_DetailedNotification();

    void setDetailedNotification(const Detailed_Notification &notice);

private:
    void setNotificationType(const common::NotificationUpdate::UpdateTypes &type);
    void setNotificationTime();
    void setNotificationMessage(const common::NotificationUpdate::UpdateTypes &type, const std::string &msg);

private:
    Ui::Widget_DetailedNotification *ui;
};


#endif // WIDGET_DETAILED_NOTIFICATION_H
