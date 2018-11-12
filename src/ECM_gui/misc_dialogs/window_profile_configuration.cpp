#include "window_profile_configuration.h"
#include "ui_window_profile_configuration.h"

Window_ProfileConfiguration::Window_ProfileConfiguration(ECM_API* apiObject, QWidget *parent) :
    GeneralDialogWindow(GeneralDialogWindow::DialogWindowTypes::WINDOW_OPERATION_CONFIGURATION,"Operation Configuration",parent),
    ui(new Ui::Window_ProfileConfiguration)
{
    ui->setupUi(this);
    m_API = apiObject;

    connect(ui->listWidget->model(),SIGNAL(rowsMoved(QModelIndex,int,int,QModelIndex,int)),this,SLOT(on_ListWidgetRowMoved()));
}

Window_ProfileConfiguration::~Window_ProfileConfiguration()
{
    delete ui;
}

void Window_ProfileConfiguration::on_actionOpen_triggered()
{

}

void Window_ProfileConfiguration::on_pushButton_AddOperation_released()
{
    Widget_ProfileParameters* operationParameters = new Widget_ProfileParameters(m_API);
    int tabIndex = ui->tabWidget_OperationParameters->addTab(operationParameters,"Test");
    operationParameters->setTabIndex(tabIndex);

    TableWidget_OperationDescriptor* tableDescriptor = new TableWidget_OperationDescriptor(operationParameters);
    tableDescriptor->setOperationIndex(tabIndex + 1);
    connect(tableDescriptor,SIGNAL(signal_OperationNameChanged(std::string,int)),this,SLOT(slot_OperationNameChanged(std::string,int)));

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(tableDescriptor->sizeHint());
    ui->listWidget->addItem(newItem);
    ui->listWidget->setItemWidget(newItem,tableDescriptor);

    this->m_MapOperations.insert(std::pair<QListWidgetItem*,TableWidget_OperationDescriptor*>(newItem,tableDescriptor));
}

void Window_ProfileConfiguration::on_pushButton_RemoveOperation_released()
{
    QList<QListWidgetItem*> selectedList = ui->listWidget->selectedItems();
}

void Window_ProfileConfiguration::slot_OperationNameChanged(const std::string &name, const int &index)
{
    ui->tabWidget_OperationParameters->setTabText(index,QString::fromStdString(name));
}

void Window_ProfileConfiguration::on_pushButton_OpenMotionScript_released()
{
    std::string extensionFilter = "Open TXT Files (*.txt);; Open DMC Files (*.dmc)";

    QString filePath = GeneralDialogWindow::onOpenAction(extensionFilter);
    ui->lineEdit_GalilScriptPath->setText(filePath);

    if(!filePath.isEmpty() && !filePath.isNull()){
        emit signal_LoadMotionProfile(filePath.toStdString());
    }
}

void Window_ProfileConfiguration::on_listWidget_customContextMenuRequested(const QPoint &pos)
{

}

void Window_ProfileConfiguration::on_ListWidgetRowMoved()
{
    //let us reorder all of the operation numbers
    for(int listIndex = 0; listIndex < ui->listWidget->count(); listIndex++)
    {
        QListWidgetItem* currentItem = ui->listWidget->item(listIndex);
        this->m_MapOperations.at(currentItem)->setOperationIndex(listIndex + 1);
    }
}

void Window_ProfileConfiguration::on_listWidget_itemClicked(QListWidgetItem *item)
{
    unsigned int currentTabIndex = this->m_MapOperations.at(item)->getAccompanyingProfile()->getTabIndex();
    ui->tabWidget_OperationParameters->setCurrentIndex(currentTabIndex);
}
