#ifndef WIDGET_FRONT_PANEL_PUMP_CONTROL_H
#define WIDGET_FRONT_PANEL_PUMP_CONTROL_H

#include <QWidget>

#include "common/environment_time.h"

#include "../general_dialog_window.h"

#include "library_westinghouse510/westinghouse_510.h"
#include "library_westinghouse510/command_pump_properties.h"

namespace Ui {
class WidgetFrontPanel_PumpControl;
}

class WidgetFrontPanel_PumpControl : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_PumpControl(Westinghouse510* pumpObject, QWidget *parent = nullptr);
    ~WidgetFrontPanel_PumpControl();

public:
    void loadFromPumpProperties(const Command_PumpProperties &config);

private:
    void setPumpFlowRate(const double &rate);

    void setPumpDelayTime(const double &time);

private slots:

    void slot_updatedDelayTime(const double &value);

    void slot_updatedFlowRate(const double &value);

private slots:

    void on_doubleSpinBox_flowRate_valueChanged(double arg1);

    void on_doubleSpinBox_delayTime_valueChanged(double arg1);

private:
    Ui::WidgetFrontPanel_PumpControl *ui;
    Westinghouse510* m_Pump;
};

#endif // WIDGET_FRONT_PANEL_PUMP_CONTROL_H
