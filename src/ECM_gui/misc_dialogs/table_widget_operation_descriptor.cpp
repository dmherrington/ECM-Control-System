#include "table_widget_operation_descriptor.h"
#include "ui_table_widget_operation_descriptor.h"

TableWidget_OperationDescriptor::TableWidget_OperationDescriptor(Widget_ProfileParameters* operationParameters, QWidget *parentWidget) :
    QWidget(parentWidget),
    ui(new Ui::TableWidget_OperationDescriptor)
{
    ui->setupUi(this);

    this->m_OperationParamters = operationParameters;

    ui->lineEdit_ProfileName->setText(QString::fromStdString(this->operationName));
    ui->spinBox_OperationOrder->setValue(this->operationIndex);
}

TableWidget_OperationDescriptor::~TableWidget_OperationDescriptor()
{
    delete ui;
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

Widget_ProfileParameters* TableWidget_OperationDescriptor::getAccompanyingProfile()
{
    return this->m_OperationParamters;
}

void TableWidget_OperationDescriptor::on_lineEdit_ProfileName_textChanged(const QString &arg1)
{
    this->operationName = arg1.toStdString();
    emit signal_OperationNameChanged(this->operationName, this->m_OperationParamters->getTabIndex());
}

void TableWidget_OperationDescriptor::on_pushButton_ExecuteExplicitOp_released()
{
    //emit signal_ExecuteExplicitProfile(this->m_OperationParamters);
}
