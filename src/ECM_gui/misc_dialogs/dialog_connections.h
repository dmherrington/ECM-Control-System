#ifndef DIALOG_CONNECTIONS_H
#define DIALOG_CONNECTIONS_H

#include <QDialog>

namespace Ui {
class Dialog_Connections;
}

class Dialog_Connections : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Connections(QWidget *parent = 0);
    ~Dialog_Connections();

private:
    Ui::Dialog_Connections *ui;
};

#endif // DIALOG_CONNECTIONS_H
