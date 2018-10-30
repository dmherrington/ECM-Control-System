#ifndef WINDOW_MUNK_TEMPERATURE_STATUS_H
#define WINDOW_MUNK_TEMPERATURE_STATUS_H

#include <QMainWindow>

#include "../misc_widgets/widget_munk_temperature_state.h"

#include "library_munk_power_supply/munk_power_supply.h"

namespace Ui {
class Window_MunkTemperatureStatus;
}

class Window_MunkTemperatureStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_MunkTemperatureStatus(const MunkPowerSupply *obj, QWidget *parent = 0);
    ~Window_MunkTemperatureStatus();

public:
    void updateBoardCount(const unsigned int &count);

private slots:
    void updateTemperatureStatus(const response_Munk::State_TemperatureBoard &data);

private:
    Ui::Window_MunkTemperatureStatus *ui;

    const MunkPowerSupply* m_PowerSupply;

    std::map<unsigned int, Widget_MunkTemperatureState*> m_StateWidgets;
};

#endif // WINDOW_MUNK_TEMPERATURE_STATUS_H
