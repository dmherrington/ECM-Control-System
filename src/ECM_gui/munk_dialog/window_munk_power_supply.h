#ifndef WINDOW_MUNK_POWER_SUPPLY_H
#define WINDOW_MUNK_POWER_SUPPLY_H

#include <QMainWindow>
#include <QSettings>

#include "library_munk_power_supply/munk_power_supply.h"

#include "widget_segment_time_display.h"

namespace Ui {
class Window_MunkPowerSupply;
}

class Window_MunkPowerSupply : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_MunkPowerSupply(MunkPowerSupply* obj, QWidget *parent = 0);
    ~Window_MunkPowerSupply();

    bool isWindowHidden() const;
protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private slots:
    void on_pushButton_AddSegment_released();
    void on_connectionUpdated(const common::comms::CommunicationConnection &connection);

    void on_actionClose_triggered();

    void on_pushButton_transmit_released();

private:
    MunkPowerSupply* munk;

    Ui::Window_MunkPowerSupply *ui;
    bool windowHidden = true;
};

#endif // WINDOW_MUNK_POWER_SUPPLY_H
