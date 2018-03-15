#include "dialog_custom_commands.h"
#include "ui_dialog_custom_commands.h"

Dialog_CustomCommands::Dialog_CustomCommands(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CustomCommands)
{
    ui->setupUi(this);
}

Dialog_CustomCommands::~Dialog_CustomCommands()
{
    delete ui;
}
