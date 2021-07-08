#ifndef WIDGET_FRONT_PANEL_PUMP_H
#define WIDGET_FRONT_PANEL_PUMP_H

#include <QTimer>
#include <QWidget>
#include <sstream>

#include "common/environment_time.h"

#include "data/sensors/sensor_conductivity.h"
#include "data/sensors/sensor_ph.h"

#include "../general_dialog_window.h"

#include "library_westinghouse510/westinghouse_510.h"

#include "library_plc/plc.h"

#include "library_sensoray/sensoray.h"

namespace Ui {
class WidgetFrontPanel_Pump;
}

class WidgetFrontPanel_Pump : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFrontPanel_Pump(Westinghouse510 *pumpObj, PLC *plcObj, Sensoray *sensObj, QWidget *parent = nullptr);

    ~WidgetFrontPanel_Pump();

    void executingAutomatedSequence(const bool &shouldBlock);

private:
    void setPumpFlowRate(const double &rate);

    void setPumpDelayTime(const double &time);

private slots:

    void slot_updatedDelayTime(const double &value);

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

    void slot_NewSensorValue(const common::TupleSensorString &sensorTuple, const common_data::SensorState &data);

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
