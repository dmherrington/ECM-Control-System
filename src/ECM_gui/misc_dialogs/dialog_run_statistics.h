#ifndef DIALOG_RUN_STATISTICS_H
#define DIALOG_RUN_STATISTICS_H

#include <QDialog>

namespace Ui {
class Dialog_RunStatistics;
}

class Dialog_RunStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_RunStatistics(QWidget *parent = 0);
    ~Dialog_RunStatistics();

private:
    Ui::Dialog_RunStatistics *ui;
};

#endif // DIALOG_RUN_STATISTICS_H
