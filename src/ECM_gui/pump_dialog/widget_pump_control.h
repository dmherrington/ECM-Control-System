#ifndef WIDGET_PUMP_CONTROL_H
#define WIDGET_PUMP_CONTROL_H

#include <QWidget>
#include <QJsonArray>
#include <QTimer>

#include "common/environment_time.h"

#include "../general_dialog_window.h"

#include "library_westinghouse510/westinghouse_510.h"
#include "library_westinghouse510/command_pump_properties.h"

namespace Ui {
class Widget_PumpControl;
}

class Widget_PumpControl : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_PumpControl(Westinghouse510* pumpObject, QWidget *parent = 0);
    ~Widget_PumpControl();

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

public:
    void loadFromPumpProperties(const Command_PumpProperties &config);

    Command_PumpProperties getPumpProperties() const;

private:
    void setPumpFlowRate(const double &rate);

    void setPumpDelayTime(const double &time);

    void setWaitForPumpDelay(const bool &wait);

    void setUtilizePump(const bool &use);

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private slots:

    void slot_updatedDelayTime(const double &value);

    void slot_updatedFlowRate(const double &value);

private slots:

    void on_doubleSpinBox_flowRate_valueChanged(double arg1);

    void on_doubleSpinBox_delayTime_valueChanged(double arg1);

private:
    Ui::Widget_PumpControl *ui;
    Westinghouse510* m_Pump;
};

#endif // WIDGET_PUMP_CONTROL_H
