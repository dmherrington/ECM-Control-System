#ifndef WINDOW_NOTIFICATIONS_H
#define WINDOW_NOTIFICATIONS_H

#include <QMainWindow>

namespace Ui {
class Window_Notifications;
}

class Window_Notifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Notifications(QWidget *parent = 0);
    ~Window_Notifications();

private:
    Ui::Window_Notifications *ui;
};

#endif // WINDOW_NOTIFICATIONS_H
