#ifndef WIDGET_NOTIFICATION_H
#define WIDGET_NOTIFICATION_H

#include <QWidget>
#include <QListWidgetItem>

#include "widget_detailed_notification.h"
#include "ECM_API/ecm_api.h"

namespace Ui {
class Widget_Notification;
}

class Widget_Notification : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Notification(const ECM_API* apiObject, QWidget *parent = 0);
    ~Widget_Notification();

private slots:
    void slot_NewNotification(const common::NotificationUpdate &update);

public:
    void addNewNotification(const common::NotificationUpdate &update);

private:
    Ui::Widget_Notification *ui;

    const ECM_API* m_API;
};

#endif // WIDGET_NOTIFICATION_H
