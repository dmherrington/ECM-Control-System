#include "widget_variable_value.h"
#include "ui_widget_variable_value.h"

Widget_VariableValue::Widget_VariableValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_VariableValue)
{
    ui->setupUi(this);
}

Widget_VariableValue::~Widget_VariableValue()
{
    delete ui;
}
