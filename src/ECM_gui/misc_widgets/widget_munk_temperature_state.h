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
    explicit Widget_MunkTemperatureState(const unsigned int &boardNumber, QWidget *parent = 0);
    ~Widget_MunkTemperatureState();

public:
    void updateTemperatures(const double &temperature1, const double &temperature2);
    void updateTemperature1(const double &temperature);
    void updateTemperature2(const double &temperature);

private:
    Ui::Widget_MunkTemperatureState *ui;
};

#endif // WIDGET_MUNK_TEMPERATURE_STATE_H
