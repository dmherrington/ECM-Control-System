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

void Window_ProfileConfiguration::closeEvent(QCloseEvent *event)
{
    GeneralDialogWindow::closeEvent(event);
}

void Window_ProfileConfiguration::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}


void Window_ProfileConfiguration::executingProfileIndex(const unsigned int &index)
{
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

    for (; it!=m_MapOperations.end(); ++it)
    {
        TableWidget_OperationDescriptor* currentOp = it->second;
        if(currentOp->getOperationIndex() == index)
        {
            ui->tabWidget_OperationParameters->setCurrentWidget(currentOp->getAccompanyingProfile());
        }
        else{
            //currentOp->getAccompanyingProfile()->getTabIndex();
        }
    }
}

void Window_ProfileConfiguration::updateConfigurationPath(const std::string &path)
{
    ui->lineEdit_ConfugrationPath->setText(QString::fromStdString(path));
}

TableWidget_OperationDescriptor* Window_ProfileConfiguration::addOperation(const unsigned int &index)
{
    Widget_ProfileParameters* operationParameters = new Widget_ProfileParameters(m_API);
    ui->tabWidget_OperationParameters->addTab(operationParameters,"Test");
    operationParameters->setTabIndex(index);

    TableWidget_OperationDescriptor* tableDescriptor = new TableWidget_OperationDescriptor(operationParameters);
    tableDescriptor->setOperationIndex(index + 1);
    QString operationName = "Operation " + QString::number(index);
    tableDescriptor->setOperationName(operationName.toStdString());
    ui->tabWidget_OperationParameters->setTabText(index,operationName);

    connect(tableDescriptor,SIGNAL(signal_OperationNameChanged(std::string,uint)),this,SLOT(slot_OperationNameChanged(std::string,uint)));
    connect(tableDescriptor,SIGNAL(signal_ExecuteExplicitProfileConfig(ECMCommand_ProfileConfiguration)),this,SLOT(slot_OnExecuteExplicitProfileConfig(ECMCommand_ProfileConfiguration)));
    tableDescriptor->newlyAvailableProgramLabels(m_API->m_Galil->stateInterface->galilProgram->getLabelList());

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(tableDescriptor->sizeHint());
    ui->listWidget->addItem(newItem);
    ui->listWidget->setItemWidget(newItem,tableDescriptor);

    this->m_MapOperations.insert(std::pair<QListWidgetItem*,TableWidget_OperationDescriptor*>(newItem,tableDescriptor));

    return tableDescriptor;
}

void Window_ProfileConfiguration::slot_OnExecuteExplicitProfileConfig(const ECMCommand_ProfileConfiguration &config)
{
    ECMCommand_ExecuteCollection newExecutionCollection;
    newExecutionCollection.insertProfile(config);
    newExecutionCollection.setHomeShouldIndicate(ui->checkBox_ShouldHomeBeIndicated->isChecked());
    emit signal_ExecuteProfileCollection(newExecutionCollection);
}

void Window_ProfileConfiguration::clearExistingOperations()
{
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

    for (; it!=m_MapOperations.end(); ++it)
    {
        delete it->second;
    }
    ui->tabWidget_OperationParameters->clear();
    ui->listWidget->clear();
    m_MapOperations.clear();
}

void Window_ProfileConfiguration::slot_MCNewProgramLabels(const ProgramLabelList &labels)
{
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

    for (; it!=m_MapOperations.end(); ++it)
    {
        TableWidget_OperationDescriptor* currentOp = it->second;
        currentOp->newlyAvailableProgramLabels(labels);
    }
}

void Window_ProfileConfiguration::on_pushButton_AddOperation_released()
{
    this->addOperation(ui->tabWidget_OperationParameters->count());
}

void Window_ProfileConfiguration::on_pushButton_RemoveOperation_released()
{
    QList<QListWidgetItem*> selectedList = ui->listWidget->selectedItems();
}

void Window_ProfileConfiguration::slot_OperationNameChanged(const std::string &name, const unsigned int &index)
{
    ui->tabWidget_OperationParameters->setTabText(index,QString::fromStdString(name));
}

void Window_ProfileConfiguration::on_pushButton_OpenMotionScript_released()
{
    std::string extensionFilter = "Open TXT Files (*.txt);; Open DMC Files (*.dmc)";

    QString filePath = GeneralDialogWindow::onOpenAction(extensionFilter);

    if(!filePath.isEmpty() && !filePath.isNull()){
        ui->lineEdit_GalilScriptPath->setText(filePath);
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

void Window_ProfileConfiguration::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_ProfileConfiguration::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_ProfileConfiguration::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
    saveToFile(settingsPath);
}

void Window_ProfileConfiguration::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    this->updateConfigurationPath(filePath.toStdString());

    QJsonObject saveObject;
    QJsonArray segmentDataArray;

    for (size_t index = 1; index <= m_MapOperations.size(); index++)
    {
        std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

        for (; it!=m_MapOperations.end(); ++it)
        {
            TableWidget_OperationDescriptor* currentOp = it->second;

            if(currentOp->getOperationIndex() == index)
            {
                ECMCommand_ProfileConfiguration operationConfiguration = currentOp->getCurrentProfileConfiguration();
                QJsonObject operationObject;
                operationConfiguration.writeToJSON(operationObject);
                segmentDataArray.append(operationObject);
            }
        }
    }

    saveObject["configData"] = segmentDataArray;
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}


void Window_ProfileConfiguration::openFromFile(const QString &filePath)
{
    QFile loadFile(filePath);
     if (!loadFile.open(QIODevice::ReadOnly)) return;

    this->updateConfigurationPath(filePath.toStdString());

    clearExistingOperations();

    QByteArray loadData = loadFile.readAll();
    loadFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    QJsonObject jsonObject = loadDoc.object();
    QJsonArray configArray = jsonObject["configData"].toArray();

    ECMCommand_ProfileCollection profileCollection;

    for (int i = 0; i < configArray.size(); ++i) {
        QJsonObject operationObject = configArray[i].toObject();

        ECMCommand_ProfileConfiguration loadConfig;
        loadConfig.readFromJSON(operationObject);
        loadConfig.m_GalilOperation.setProgramLoaded(true,filePath.toStdString());

        TableWidget_OperationDescriptor* currentWidget = this->addOperation(loadConfig.getOperationIndex());
        currentWidget->loadFromProfileConfiguration(loadConfig);

        //Object will contain all of the profiles used for the profile
        profileCollection.insertProfile(loadConfig);
    }
}