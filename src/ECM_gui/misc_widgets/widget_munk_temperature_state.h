#ifndef WIDGET_MUNK_TEMPERATURE_STATE_H
#define WIDGET_MUNK_TEMPERATURE_STATE_H

#include <QWidget>

namespace Ui {
class Widget_MunkTemperatureState;
}

class Widget_MunkTemperatureState : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_MunkTemperatureState(QWidget *parent = 0);
    ~Widget_MunkTemperatureState();

private:
    Ui::Widget_MunkTemperatureState *ui;
};

#endif // WIDGET_MUNK_TEMPERATURE_STATE_H
