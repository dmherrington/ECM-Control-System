#ifndef WINDOW_PUMP_CONTROL_H
#define WINDOW_PUMP_CONTROL_H

#include <QTimer>

#include "common/environment_time.h"

#include "../general_dialog_window.h"

#include "library_westinghouse510/westinghouse_510.h"

namespace Ui {
class Window_PumpControl;
}

class Window_PumpControl : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_PumpControl(Westinghouse510 *obj, QWidget *parent = 0);
    ~Window_PumpControl();

private:
    void closeEvent(QCloseEvent *event) override;

private:
    void setPumpFlowRate(const double &rate);

    void setPumpDelayTime(const double &time);

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

    void read(const QJsonObject &json);

    void write(QJsonObject &json) const;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private slots:

    void slot_PumpConnectionUpdate(const common::comms::CommunicationUpdate &update);

    void slot_updatedDelayTime(const double &value);

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

    void slot_PumpInitialized();

    void slot_PumpOperationalTimeout();

private slots:

    void on_pushButton_PumpRunning_released();

    void on_doubleSpinBox_flowRate_valueChanged(double arg1);

    void on_doubleSpinBox_delayTime_valueChanged(double arg1);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// Action events triggered from the menu bar
    ///////////////////////////////////////////////////////////////////////////////////////////////

    void on_actionClose_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::Window_PumpControl *ui;
    Westinghouse510* m_Pump;
    bool windowHidden = true;

private:
    QTimer* m_OperationsTimer;
    common::EnvironmentTime startTime;

};

#endif // WINDOW_PUMP_CONTROL_H
