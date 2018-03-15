#ifndef DIALOG_PUMP_CONTROL_H
#define DIALOG_PUMP_CONTROL_H

#include <QDialog>
#include "library_westinghouse510/westinghouse_510.h"

namespace Ui {
class Dialog_PumpControl;
}

class Dialog_PumpControl : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_PumpControl(QWidget *parent = 0, const westinghousePump::Westinghouse510* ref);
    ~Dialog_PumpControl();

private:
    Ui::Dialog_PumpControl *ui;
    westinghousePump::Westinghouse510* m_pump;
};

#endif // DIALOG_PUMP_CONTROL_H
