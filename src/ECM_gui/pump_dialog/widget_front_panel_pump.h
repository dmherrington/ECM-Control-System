#ifndef WIDGET_FRONT_PANEL_PUMP_H
#define WIDGET_FRONT_PANEL_PUMP_H

#include <QTimer>
#include <QWidget>

#include "common/environment_time.h"

#include "../general_dialog_window.h"

#include "library_westinghouse510/westinghouse_510.h"

namespace Ui {
class WidgetFrontPanel_Pump;
}

class WidgetFrontPanel_Pump : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_Pump(Westinghouse510 *obj, QWidget *parent = 0);
    ~WidgetFrontPanel_Pump();

    void executingAutomatedSequence(const bool &shouldBlock);

private:
    void setPumpFlowRate(const double &rate);

    void setPumpDelayTime(const double &time);

private slots:

    void slot_updatedDelayTime(const double &value);

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

private slots:

    void on_pushButton_PumpRunning_released();

    void on_doubleSpinBox_flowRate_valueChanged(double arg1);

    void on_doubleSpinBox_delayTime_valueChanged(double arg1);

private:
    Ui::WidgetFrontPanel_Pump *ui;
    Westinghouse510* m_Pump;

    bool hasTransmitted = false;
};

#endif // WIDGET_FRONT_PANEL_PUMP_H
