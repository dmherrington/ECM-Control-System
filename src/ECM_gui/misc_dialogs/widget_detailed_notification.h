#ifndef WIDGET_DETAILED_NOTIFICATION_H
#define WIDGET_DETAILED_NOTIFICATION_H

#include <QWidget>

namespace Ui {
class Widget_DetailedNotification;
}

class Widget_DetailedNotification : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_DetailedNotification(QWidget *parent = 0);
    ~Widget_DetailedNotification();

private:
    Ui::Widget_DetailedNotification *ui;
};

#endif // WIDGET_DETAILED_NOTIFICATION_H
