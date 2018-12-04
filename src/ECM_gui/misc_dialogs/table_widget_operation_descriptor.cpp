#include "table_widget_operation_descriptor.h"
#include "ui_table_widget_operation_descriptor.h"

TableWidget_OperationDescriptor::TableWidget_OperationDescriptor(Widget_ProfileParameters* operationParameters, QWidget *parentWidget) :
    QWidget(parentWidget),
    ui(new Ui::TableWidget_OperationDescriptor)
{
    ui->setupUi(this);

    this->m_OperationParameters = operationParameters;

    ui->lineEdit_OperationName->setText(QString::fromStdString(this->operationName));
    ui->spinBox_OperationOrder->setValue(this->operationIndex);
}

TableWidget_OperationDescriptor::~TableWidget_OperationDescriptor()
{
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

void TableWidget_OperationDescriptor::setShouldHomeIndicateAutomatically(const bool &indicate)
{
    this->indicateHome = indicate;
}

void TableWidget_OperationDescriptor::newlyAvailableProgramLabels(const ProgramLabelList &labels)
{
    this->m_OperationParameters->m_ScriptingVariables->updateProgramLabels(labels);
}

Widget_ProfileParameters* TableWidget_OperationDescriptor::getAccompanyingProfile()
{
    return this->m_OperationParameters;
}

void TableWidget_OperationDescriptor::on_lineEdit_OperationName_textChanged(const QString &arg1)
{
    this->operationName = arg1.toStdString();
    emit signal_OperationNameChanged(this->operationName, this->m_OperationParameters->getTabIndex());
}

ECMCommand_ProfileConfiguration TableWidget_OperationDescriptor::getCurrentProfileConfiguration() const
{
    ECMCommand_ProfileConfiguration currentConfiguration;
    currentConfiguration.setOperationIndex(this->getOperationIndex());
    currentConfiguration.setOperationName(this->getOperationName());
    currentConfiguration.setProfileExecution(this->shouldOperationBeUsed());
    currentConfiguration.m_GalilOperation.fromProgram(this->m_OperationParameters->m_ScriptingVariables->getDesiredProgram());
    currentConfiguration.m_GalilOperation.setProfileName(this->m_OperationParameters->m_ScriptingVariables->getProfileName());
    currentConfiguration.setIndicateHomeAutomatically(this->indicateHome);

    currentConfiguration.m_Touchoff = this->m_OperationParameters->m_MCTouchoff->getCurrentTouchoffConfig();

    currentConfiguration.m_ConfigPowerSupply.m_MunkPulseMode = this->m_OperationParameters->m_PowerSupply->getPulseModeRegister();
    currentConfiguration.m_ConfigPowerSupply.m_MunkSegment = this->m_OperationParameters->m_PowerSupply->getSegmentRegister();

    currentConfiguration.m_PumpParameters = this->m_OperationParameters->m_PumpControl->getPumpProperties();

    return currentConfiguration;
    //emit signal_ExecuteExplicitProfile(this->m_OperationParamters);
}

void TableWidget_OperationDescriptor::loadFromProfileConfiguration(const ECMCommand_ProfileConfiguration &config)
{
    this->setOperationIndex(config.getOperationIndex());
    this->setOperationName(config.getOperationName());
    this->setOperationUsage(config.shouldProfileExecute());

    this->m_OperationParameters->m_MCTouchoff->loadFromTouchoffConfig(config.m_Touchoff);
    this->m_OperationParameters->m_PumpControl->loadFromPumpProperties(config.m_PumpParameters);
    this->m_OperationParameters->m_PowerSupply->loadFromConfig(config.m_ConfigPowerSupply);
    this->m_OperationParameters->m_ScriptingVariables->loadFromCurrentProgram(config.m_GalilOperation);
}

void TableWidget_OperationDescriptor::on_pushButton_ExecuteExplicitOp_released()
{
    ECMCommand_ProfileConfiguration executeConfig = this->getCurrentProfileConfiguration();
    emit signal_ExecuteExplicitProfileConfig(executeConfig);
}

void TableWidget_OperationDescriptor::on_checkBox_EnableOperation_toggled(bool checked)
{
    useOperation = checked;
}
