#include "widget_variable_data.h"
#include "ui_widget_variable_data.h"

WidgetVariableData::WidgetVariableData(QWidget *parent) :
    QWidget(parent),ui(new Ui::WidgetVariableData)
{
    ui->setupUi(this);
    variable = new ProgramProfileVariable();
}

WidgetVariableData::~WidgetVariableData()
{
    delete ui;
    delete variable;
    variable = nullptr;
}

std::string WidgetVariableData::getDisplayName() const
{
    return this->variable->getDisplayName();
}
std::string WidgetVariableData::getVariableName() const
{
    return this->variable->getVariableName();
}
double WidgetVariableData::getDefaultValue() const
{
    return this->variable->getDefaultValue();
}
double WidgetVariableData::getMaxValue() const
{
    return this->variable->getMaxValue();
}
double WidgetVariableData::getMinValue() const
{
    return this->variable->getMinValue();
}

void WidgetVariableData::setDisplayName(const std::string &name)
{
    variable->setDisplayName(name);
    ui->lineEdit_displayName->setText(QString::fromStdString(name));
}
void WidgetVariableData::setVariableName(const std::string &name)
{
    variable->setVariableName(name);
    ui->lineEdit_varName->setText(QString::fromStdString(name));
}
void WidgetVariableData::setDefaultValue(const double &value)
{
    variable->setDefaultValue(value);
    ui->doubleSpinBox_default->setValue(variable->getDefaultValue());
}
void WidgetVariableData::setMaxValue(const double &value)
{
    variable->setMaxValue(value);
    ui->doubleSpinBox_max->setValue(variable->getMaxValue());
}
void WidgetVariableData::setMinValue(const double &value)
{
    variable->setMinValue(value);
    ui->doubleSpinBox_min->setValue(variable->getMinValue());
}

void WidgetVariableData::on_pushButton_removeVariable_clicked()
{
    emit(signalRemoveWidget(this));
}

void WidgetVariableData::on_lineEdit_displayName_editingFinished()
{
    variable->setDisplayName(ui->lineEdit_displayName->text().toStdString());
    emit signalDataChanged();
}

void WidgetVariableData::on_lineEdit_varName_editingFinished()
{
    variable->setVariableName(ui->lineEdit_varName->text().toStdString());
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_max_editingFinished()
{
    variable->setMaxValue(ui->doubleSpinBox_max->value());
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_min_editingFinished()
{
    variable->setMinValue(ui->doubleSpinBox_min->value());
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_default_editingFinished()
{
    variable->setDefaultValue(ui->doubleSpinBox_default->value());
    emit signalDataChanged();
}

void WidgetVariableData::updateDisplayValues()
{
    this->blockSignals(true);
    ui->lineEdit_displayName->setText(QString::fromStdString(variable->getDisplayName()));
    ui->lineEdit_varName->setText(QString::fromStdString(variable->getVariableName()));
    ui->doubleSpinBox_default->setValue(variable->getDefaultValue());
    ui->doubleSpinBox_max->setValue(variable->getMaxValue());
    ui->doubleSpinBox_min->setValue(variable->getMinValue());
    this->blockSignals(false);
}

void WidgetVariableData::read(const QJsonObject &jsonObject)
{
    this->variable->read(jsonObject);
    this->updateDisplayValues();
}

void WidgetVariableData::write(QJsonArray &jsonArray) const
{
    variable->write(jsonArray);
}

void WidgetVariableData::setVariableData(const ProgramProfileVariable &data)
{
    *variable = data;
    this->updateDisplayValues();
}

ProgramProfileVariable WidgetVariableData::getProfileVariable() const
{
    ProgramProfileVariable newVariable(*this->variable);
    return newVariable;
}

