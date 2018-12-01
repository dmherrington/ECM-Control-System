#ifndef WINDOW_MUNK_POWER_SUPPLY_H
#define WINDOW_MUNK_POWER_SUPPLY_H

#include "../general_dialog_window.h"

#include "library_munk_power_supply/munk_power_supply.h"

#include "widget_segment_time_display.h"

namespace Ui {
class Window_MunkPowerSupply;
}

class Window_MunkPowerSupply : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_MunkPowerSupply(MunkPowerSupply* obj, QWidget *parent = 0);
    ~Window_MunkPowerSupply();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private slots:
    void on_pushButton_AddSegment_released();
    void on_connectionUpdated(const common::comms::CommunicationUpdate &connection);

    void on_pushButton_transmit_released();

    void slot_ParameterTransmissionUpdate(const int &transmitted, const int &required);

    void slot_SegmentDataModified();

    void slot_FaultCodeReceived();

    void slot_ClearFaultRequested();

    void slot_FaultStateCleared();

    void slot_SegmentExceptionReceived(const std::string &RW, const std::string &meaning);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /// Action events triggered from the menu bar
    ///////////////////////////////////////////////////////////////////////////////////////////////

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_radioButton_singlePulse_clicked(bool checked);

    void on_radioButton_continuousPulse_clicked(bool checked);

    void on_radioButton_specifiedPulses_clicked(bool checked);

    void on_spinBox_NumPulses_valueChanged(int arg1);

private:
    registers_Munk::Register_PulseMode getPulseMode() const;

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private:
    Ui::Window_MunkPowerSupply *ui;
    bool windowHidden = true;

    MunkPowerSupply* munk;
};

#endif // WINDOW_MUNK_POWER_SUPPLY_H