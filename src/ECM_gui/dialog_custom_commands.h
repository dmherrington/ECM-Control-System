#ifndef DIALOG_CUSTOM_COMMANDS_H
#define DIALOG_CUSTOM_COMMANDS_H

#include <QDialog>

namespace Ui {
class Dialog_CustomCommands;
}

class Dialog_CustomCommands : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CustomCommands(QWidget *parent = 0);
    ~Dialog_CustomCommands();

private:
    Ui::Dialog_CustomCommands *ui;
};

#endif // DIALOG_CUSTOM_COMMANDS_H
