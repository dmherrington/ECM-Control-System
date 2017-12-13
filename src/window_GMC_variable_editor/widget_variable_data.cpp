#include "widget_variable_data.h"
#include "ui_widget_variable_data.h"

WidgetVariableData::WidgetVariableData(QWidget *parent) :
    QWidget(parent),ui(new Ui::WidgetVariableData)
{
    ui->setupUi(this);
}

WidgetVariableData::~WidgetVariableData()
{
    delete ui;
}

std::string WidgetVariableData::getDisplayName() const
{
    return this->displayName;
}
std::string WidgetVariableData::getVariableName() const
{
    return this->variableName;
}
double WidgetVariableData::getDefaultValue() const
{
    return this->def;
}
double WidgetVariableData::getMaxValue() const
{
    return this->max;
}
double WidgetVariableData::getMinValue() const
{
    return this->min;
}

void WidgetVariableData::setDisplayName(const std::string &name)
{
    this->displayName = name;
    ui->lineEdit_displayName->setText(QString::fromStdString(name));
}
void WidgetVariableData::setVariableName(const std::string &name)
{
    this->variableName = name;
    ui->lineEdit_varName->setText(QString::fromStdString(name));
}
void WidgetVariableData::setDefaultValue(const double &value)
{
    this->def = value;
    ui->doubleSpinBox_default->setValue(this->def);
}
void WidgetVariableData::setMaxValue(const double &value)
{
    this->max = value;
    ui->doubleSpinBox_max->setValue(this->max);
}
void WidgetVariableData::setMinValue(const double &value)
{
    this->min = value;
    ui->doubleSpinBox_min->setValue(this->min);
}

void WidgetVariableData::on_pushButton_removeVariable_clicked()
{
    emit(signalRemoveWidget(this));
}

void WidgetVariableData::on_lineEdit_displayName_editingFinished()
{
    this->displayName = ui->lineEdit_displayName->text().toStdString();
    emit signalDataChanged();
}

void WidgetVariableData::on_lineEdit_varName_editingFinished()
{
    this->variableName = ui->lineEdit_varName->text().toStdString();
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_max_editingFinished()
{
    this->max = ui->doubleSpinBox_max->value();
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_min_editingFinished()
{
    this->min = ui->doubleSpinBox_min->value();
    emit signalDataChanged();
}

void WidgetVariableData::on_doubleSpinBox_default_editingFinished()
{
    this->def = ui->doubleSpinBox_default->value();
    emit signalDataChanged();
}

void WidgetVariableData::read(const QJsonObject &jsonObject)
{
    this->blockSignals(true);
    this->setDisplayName(jsonObject["DisplayName"].toString().toStdString());
    this->setVariableName(jsonObject["VariableName"].toString().toStdString());
    this->setMaxValue(jsonObject["MaxValue"].toDouble());
    this->setMinValue(jsonObject["MinValue"].toDouble());
    this->setDefaultValue(jsonObject["DefaultValue"].toDouble());
    this->blockSignals(false);
}
void WidgetVariableData::write(QJsonArray &jsonArray) const
{
    QJsonObject variableDataObject;
    variableDataObject.insert("DisplayName",QJsonValue::fromVariant(QString::fromStdString(displayName)));
    variableDataObject.insert("VariableName",QJsonValue::fromVariant(QString::fromStdString(variableName)));
    variableDataObject["MaxValue"] = max;
    variableDataObject["MinValue"] = min;
    variableDataObject["DefaultValue"] = def;
    jsonArray.append(variableDataObject);
}
