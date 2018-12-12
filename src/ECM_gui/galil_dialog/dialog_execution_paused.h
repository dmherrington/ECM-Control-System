#ifndef DIALOG_EXECUTION_PAUSED_H
#define DIALOG_EXECUTION_PAUSED_H

#include <QDialog>

namespace Ui {
class Dialog_ExecutionPaused;
}

class Dialog_ExecutionPaused : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ExecutionPaused(QWidget *parent = nullptr);
    ~Dialog_ExecutionPaused();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void signal_HandleExecution(const bool &handle);

private:
    Ui::Dialog_ExecutionPaused *ui;
};

#endif // DIALOG_EXECUTION_PAUSED_H
