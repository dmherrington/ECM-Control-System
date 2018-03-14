#ifndef DIALOG_PUMP_CONTROL_H
#define DIALOG_PUMP_CONTROL_H

#include <QDialog>

namespace Ui {
class Dialog_PumpControl;
}

class Dialog_PumpControl : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_PumpControl(QWidget *parent = 0);
    ~Dialog_PumpControl();

private:
    Ui::Dialog_PumpControl *ui;
};

#endif // DIALOG_PUMP_CONTROL_H
