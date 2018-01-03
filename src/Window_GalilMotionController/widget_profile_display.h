#ifndef WIDGET_PROFILE_DISPLAY_H
#define WIDGET_PROFILE_DISPLAY_H

#include <QWidget>

namespace Ui {
class WidgetProfileDisplay;
}

class WidgetProfileDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetProfileDisplay(QWidget *parent = 0);
    ~WidgetProfileDisplay();

private:
    Ui::WidgetProfileDisplay *ui;
};

#endif // WIDGET_PROFILE_DISPLAY_H
