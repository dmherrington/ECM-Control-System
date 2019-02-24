#include "table_widget_operation_descriptor.h"
#include "ui_table_widget_operation_descriptor.h"

TableWidget_OperationDescriptor::TableWidget_OperationDescriptor(Widget_AbstractProfile* operationalProfile, QWidget *parentWidget) :
    QWidget(parentWidget),
    ui(new Ui::TableWidget_OperationDescriptor)
{
    ui->setupUi(this);

    this->m_AbstractOperation = operationalProfile;

    ui->lineEdit_OperationName->setText(QString::fromStdString(this->operationName));
    ui->spinBox_OperationOrder->setValue(this->operationIndex);
}

TableWidget_OperationDescriptor::~TableWidget_OperationDescriptor()
{
    delete m_AbstractOperation;

    delete ui;
}

void TableWidget_OperationDescriptor::setOperationUsage(const bool &use)
{
    this->useOperation = use;
    ui->checkBox_EnableOperation->setChecked(use);
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
    ui->lineEdit_OperationName->setText(QString::fromStdString(this->operationName));
}

std::string TableWidget_OperationDescriptor::getOperationName() const
{
    return this->operationName;
}

//void TableWidget_OperationDescriptor::newlyAvailableProgramLabels(const ProgramLabelList &labels)
//{
//    switch (this->m_AbstractOperation->getProfileType()) {
//    case ProfileOpType::OPERATION:
//    {
//        this->m_AbstractOperation->as<Widget_ProfileParameters>()->m_ScriptingVariables->updateProgramLabels(labels);
//        break;
//    }
//    default:
//        break;
//    }
//}

Widget_AbstractProfile* TableWidget_OperationDescriptor::getAccompanyingProfile()
{
    return this->m_AbstractOperation;
}

void TableWidget_OperationDescriptor::on_lineEdit_OperationName_textChanged(const QString &arg1)
{
    this->operationName = arg1.toStdString();
    emit signal_OperationNameChanged(this->operationName, this->m_AbstractOperation->getTabIndex());
}

ECMCommand_AbstractProfileConfigPtr TableWidget_OperationDescriptor::getCurrentProfileConfiguration() const
{
    ECMCommand_AbstractProfileConfigPtr currentConfig = this->m_AbstractOperation->getCurrentProfileConfiguration();

    currentConfig->setOperationIndex(this->getOperationIndex());
    currentConfig->setOperationName(this->getOperationName());
    currentConfig->setProfileExecution(this->shouldOperationBeUsed());

    return currentConfig;
}

void TableWidget_OperationDescriptor::loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config)
{
    this->setOperationIndex(config->getOperationIndex());
    this->setOperationName(config->getOperationName());
    this->setOperationUsage(config->shouldProfileExecute());

    this->m_AbstractOperation->loadFromProfileConfiguration(config);
}

void TableWidget_OperationDescriptor::on_pushButton_ExecuteExplicitOp_released()
{
    ECMCommand_AbstractProfileConfigPtr executeConfig = this->getCurrentProfileConfiguration();
    emit signal_ExecuteExplicitProfileConfig(executeConfig);
}

void TableWidget_OperationDescriptor::on_checkBox_EnableOperation_toggled(bool checked)
{
    useOperation = checked;
}
