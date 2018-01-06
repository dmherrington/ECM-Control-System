#include "widget_profile_variable_display.h"
#include "ui_widget_profile_variable_display.h"

WidgetProfileVariableDisplay::WidgetProfileVariableDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetProfileVariableDisplay)
{
    ui->setupUi(this);
    this->currentValue = 0.0;
}

WidgetProfileVariableDisplay::~WidgetProfileVariableDisplay()
{
    delete ui;
}

void WidgetProfileVariableDisplay::loadProfileVariable(const SettingsProfileVariable variable)
{
    this->ui->label_displayName->setText(QString::fromStdString(variable->getDisplayName()));
    this->ui->doubleSpinBox_desiredValue->setMaximum(variable->getMaxValue());
    this->ui->doubleSpinBox_desiredValue->setMinimum(variable->getMinValue());
    this->ui->doubleSpinBox_desiredValue->setValue(variable->getDefaultValue());
}

void WidgetProfileVariableDisplay::on_doubleSpinBox_desiredValue_editingFinished()
{
    this->currentValue = this->ui->doubleSpinBox_desiredValue->value();
}
