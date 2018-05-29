#ifndef WINDOW_PUMP_CONTROL_H
#define WINDOW_PUMP_CONTROL_H

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
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

signals:
    void signal_DialogWindowVisibilty(const DialogWindowTypes &type, const bool &visibility) override;

private slots:

    void slot_PumpConnectionUpdate(const common::comms::CommunicationConnection &value);

    void slot_updatedDelayTime(const double &value);

    void slot_updatedPumpOn(const bool &value);

    void slot_updatedFlowRate(const double &value);

    void slot_updatedStartTime();

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

};

#endif // WINDOW_PUMP_CONTROL_H
