#ifndef WINDOW_MUNK_TEMPERATURE_STATUS_H
#define WINDOW_MUNK_TEMPERATURE_STATUS_H

#include <QMainWindow>

#include "../misc_widgets/widget_munk_temperature_state.h"

namespace Ui {
class Window_MunkTemperatureStatus;
}

class Window_MunkTemperatureStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_MunkTemperatureStatus(QWidget *parent = 0);
    ~Window_MunkTemperatureStatus();

private:
    Ui::Window_MunkTemperatureStatus *ui;
};

#endif // WINDOW_MUNK_TEMPERATURE_STATUS_H
