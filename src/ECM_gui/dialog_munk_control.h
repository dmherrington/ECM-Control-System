#ifndef DIALOG_MUNK_CONTROL_H
#define DIALOG_MUNK_CONTROL_H

#include <QDialog>

namespace Ui {
class Dialog_MunkControl;
}

class Dialog_MunkControl : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_MunkControl(QWidget *parent = 0);
    ~Dialog_MunkControl();

private:
    Ui::Dialog_MunkControl *ui;
};

#endif // DIALOG_MUNK_CONTROL_H
