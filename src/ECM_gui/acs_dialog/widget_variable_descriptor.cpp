#include "widget_variable_descriptor.h"
#include "ui_widget_variable_descriptor.h"

Widget_VariableDescriptor::Widget_VariableDescriptor(const std::string &name, const double &value, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_VariableDescriptor)
{
    ui->setupUi(this);

    variableName = name;
    ui->label_VariableName->setText(QString::fromStdString(name));
    ui->doubleSpinBox_VariableValue->setValue(value);
}

void Widget_VariableDescriptor::getVariableProperties(std::string &name, double &value)
{
    name = this->variableName;

}

Widget_VariableDescriptor::~Widget_VariableDescriptor()
{
    delete ui;
}

void Widget_VariableDescriptor::on_doubleSpinBox_VariableValue_valueChanged(double arg1)
{
    UNUSED(arg1);
}
