#ifndef WIDGET_MUNK_POWER_SUPPLY_H
#define WIDGET_MUNK_POWER_SUPPLY_H

#include <QWidget>
#include <QMenu>

#include "../general_dialog_window.h"

#include "library_munk_power_supply/munk_power_supply.h"

#include "widget_segment_time_display.h"

namespace Ui {
class Widget_MunkPowerSupply;
}

class Widget_MunkPowerSupply : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_MunkPowerSupply(MunkPowerSupply* obj, QWidget *parent = 0);
    ~Widget_MunkPowerSupply();

public:
    registers_Munk::Register_PulseMode getPulseModeRegister() const;

    registers_Munk::SegmentTimeDetailed getSegmentRegister() const;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private slots:
    void on_Action_AddSegment_released();

    void slot_onCustomContextMenu(const QPoint &point);

    void slot_ParameterTransmissionUpdate(const int &transmitted, const int &required);

    void slot_SegmentDataModified();

    void slot_FaultCodeReceived();

    void slot_ClearFaultRequested();

    void slot_FaultStateCleared();

    void slot_SegmentExceptionReceived(const std::string &RW, const std::string &meaning);

    void on_radioButton_singlePulse_clicked(bool checked);

    void on_radioButton_continuousPulse_clicked(bool checked);

    void on_radioButton_specifiedPulses_clicked(bool checked);

    void on_spinBox_NumPulses_valueChanged(int arg1);

private:
    registers_Munk::Register_PulseMode getPulseMode() const;

public:
    void writeToJSON(QJsonObject &saveObject);

    void readFromJSON(const QJsonObject &openObject);

private:
    Ui::Widget_MunkPowerSupply *ui;
    bool windowHidden = true;

    MunkPowerSupply* munk;
};

#endif // WIDGET_MUNK_POWER_SUPPLY_H
