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

void Widget_VariableDescriptor::setVariableValue(const double &value)
{
    ui->doubleSpinBox_VariableValue->setValue(value);
}

std::string Widget_VariableDescriptor::getVariableName() const
{
    return this->variableName;
}

void Widget_VariableDescriptor::getVariableProperties(std::string &name, double &value) const
{
    name = this->variableName;
    value = ui->doubleSpinBox_VariableValue->value();
}

Widget_VariableDescriptor::~Widget_VariableDescriptor()
{
    delete ui;
}

void Widget_VariableDescriptor::on_doubleSpinBox_VariableValue_valueChanged(double arg1)
{
    UNUSED(arg1);
}
