#include "table_widget_operation_descriptor.h"
#include "ui_table_widget_operation_descriptor.h"

TableWidget_OperationDescriptor::TableWidget_OperationDescriptor(Widget_ProfileParameters* operationParameters, QWidget *parentWidget) :
    QWidget(parentWidget),
    ui(new Ui::TableWidget_OperationDescriptor)
{
    ui->setupUi(this);

    this->m_OperationParameters = operationParameters;

    ui->lineEdit_ProfileName->setText(QString::fromStdString(this->operationName));
    ui->spinBox_OperationOrder->setValue(this->operationIndex);
}

TableWidget_OperationDescriptor::~TableWidget_OperationDescriptor()
{
    delete ui;
}

void TableWidget_OperationDescriptor::setOperationUsage(const bool &use)
{
    this->useOperation = use;
}

bool TableWidget_OperationDescriptor::shouldOperationBeUsed() const
{
    return this->useOperation;
}

void TableWidget_OperationDescriptor::setOperationIndex(const unsigned int &index)
{
    this->operationIndex = index;
    ui->spinBox_OperationOrder->setValue(this->operationIndex);
}

unsigned int TableWidget_OperationDescriptor::getOperationIndex() const
{
    return this->operationIndex;
}

void TableWidget_OperationDescriptor::setOperationName(const std::string &name)
{
    this->operationName = name;
    ui->lineEdit_ProfileName->setText(QString::fromStdString(this->operationName));
}

std::string TableWidget_OperationDescriptor::getOperationName() const
{
    return this->operationName;
}

void TableWidget_OperationDescriptor::newlyAvailableProgramLabels(const ProgramLabelList &labels)
{
    this->m_OperationParameters->m_ScriptingVariables->updateProgramLabels(labels);
}

Widget_ProfileParameters* TableWidget_OperationDescriptor::getAccompanyingProfile()
{
    return this->m_OperationParameters;
}

void TableWidget_OperationDescriptor::writeToJSON(QJsonObject &obj)
{
    m_OperationParameters->writeToJSON(obj);
}

void TableWidget_OperationDescriptor::readFromJSON(const QJsonObject &obj)
{
    m_OperationParameters->readFromJSON(obj);
}

void TableWidget_OperationDescriptor::on_lineEdit_ProfileName_textChanged(const QString &arg1)
{
    this->operationName = arg1.toStdString();
    emit signal_OperationNameChanged(this->operationName, this->m_OperationParameters->getTabIndex());
}

void TableWidget_OperationDescriptor::on_pushButton_ExecuteExplicitOp_released()
{
    ECMCommand_ProfileConfiguration newSingleProfile;
    newSingleProfile.m_GalilOperation.setOperationName(this->operationName);
    newSingleProfile.m_GalilOperation.setProfileName(this->m_OperationParameters->m_ScriptingVariables->getProfileName());
    newSingleProfile.m_GalilOperation.setVariableList(this->m_OperationParameters->m_ScriptingVariables->getVariableList());

    newSingleProfile.m_MunkPulseMode = this->m_OperationParameters->m_PowerSupply->getPulseModeRegister();
    newSingleProfile.m_MunkSegment = this->m_OperationParameters->m_PowerSupply->getSegmentRegister();

    //newSingleProfile.m_PumpParameters = this->m_OperationParameters->m_PumpControl->getPumpProperties();

    //emit signal_ExecuteExplicitProfile(this->m_OperationParamters);
}

void TableWidget_OperationDescriptor::on_checkBox_EnableOperation_toggled(bool checked)
{
    useOperation = checked;
}
