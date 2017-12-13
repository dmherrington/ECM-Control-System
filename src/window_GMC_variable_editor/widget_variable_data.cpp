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

void WidgetVariableData::setDefaultValue(const double &value)
{
    this->def = value;
    ui->doubleSpinBox_default->setValue(this->min);
}
void WidgetVariableData::setMaxValue(const double &value)
{
    this->max = value;
    ui->doubleSpinBox_max->setValue(this->min);
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
}

void WidgetVariableData::on_lineEdit_varName_editingFinished()
{
    this->variableName = ui->lineEdit_varName->text().toStdString();
}

void WidgetVariableData::on_doubleSpinBox_max_editingFinished()
{
    this->max = ui->doubleSpinBox_max->value();
}

void WidgetVariableData::on_doubleSpinBox_min_editingFinished()
{
    this->min = ui->doubleSpinBox_min->value();
}

void WidgetVariableData::on_doubleSpinBox_default_editingFinished()
{
    this->def = ui->doubleSpinBox_default->value();
}

void WidgetVariableData::read(const QJsonObject &json)
{
    //    QJsonArray segmentDataArray = json["linearProfile"].toArray();
    //    QJsonObject arrayObject = segmentDataArray[0].toObject();
    //    this->setDepthofCut(arrayObject["depthOfCut"].toInt());
    //    this->setCutSpeed(arrayObject["cutSpeed"].toInt());
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
