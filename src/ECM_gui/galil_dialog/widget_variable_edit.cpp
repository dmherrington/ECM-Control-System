#include "widget_variable_edit.h"
#include "ui_widget_variable_edit.h"

Widget_VariableEdit::Widget_VariableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_VariableEdit)
{
    ui->setupUi(this);
}

Widget_VariableEdit::~Widget_VariableEdit()
{
    delete ui;
}
