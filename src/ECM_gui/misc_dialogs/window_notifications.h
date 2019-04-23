#ifndef WINDOW_NOTIFICATIONS_H
#define WINDOW_NOTIFICATIONS_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "widget_detailed_notification.h"

namespace Ui {
class Window_Notifications;
}

class Window_Notifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Notifications(QWidget *parent = nullptr);
    ~Window_Notifications();

    void addNewNotification(const common::NotificationUpdate &update);

private:
    Ui::Window_Notifications *ui;
};

#endif // WINDOW_NOTIFICATIONS_H
