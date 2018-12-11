#include "window_profile_configuration.h"
#include "ui_window_profile_configuration.h"

Window_ProfileConfiguration::Window_ProfileConfiguration(ECM_API* apiObject, QWidget *parent) :
    GeneralDialogWindow(GeneralDialogWindow::DialogWindowTypes::WINDOW_OPERATION_CONFIGURATION,"Operation Configuration",parent),
    ui(new Ui::Window_ProfileConfiguration)
{
    ui->setupUi(this);
    m_API = apiObject;

    m_WindowMotionProfile = new Window_MotionProfile(m_API->m_Galil);
    m_WindowMotionProfile->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);
    connect(m_WindowMotionProfile,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));

    connect(ui->listWidget->model(),SIGNAL(rowsMoved(QModelIndex,int,int,QModelIndex,int)),this,SLOT(on_ListWidgetRowMoved()));
}

Window_ProfileConfiguration::~Window_ProfileConfiguration()
{
    delete ui;
}

void Window_ProfileConfiguration::closeEvent(QCloseEvent *event)
{
    m_WindowMotionProfile->close();
    GeneralDialogWindow::closeEvent(event);
}

void Window_ProfileConfiguration::on_actionClose_triggered()
{
    m_WindowMotionProfile->close();
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

ECMCommand_ExecuteCollection Window_ProfileConfiguration::getCurrentCollection() const
{

    ECMCommand_ExecuteCollection executeCollection;
    for (size_t index = 1; index <= m_MapOperations.size(); index++)
    {
        std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::const_iterator it = m_MapOperations.begin();

        for (; it!=m_MapOperations.end(); ++it)
        {
            TableWidget_OperationDescriptor* currentOp = it->second;

            if(currentOp->getOperationIndex() == index)
            {
                ECMCommand_ProfileConfiguration operationConfiguration = currentOp->getCurrentProfileConfiguration();
                executeCollection.insertProfile(operationConfiguration);
            }
        }
    }
    executeCollection.setHomeShouldIndicate(ui->checkBox_ShouldHomeBeIndicated->isChecked());

    return executeCollection;
}

void Window_ProfileConfiguration::updateConfigurationPath(const std::string &path)
{
    ui->lineEdit_ConfugrationPath->setText(QString::fromStdString(path));
}

TableWidget_OperationDescriptor* Window_ProfileConfiguration::addOperation(const unsigned int &index, const std::string &operationName)
{
    Widget_ProfileParameters* operationParameters = new Widget_ProfileParameters(m_API);
    std::string opName = "";
    if(operationName.empty())
        opName = "Operation "  + std::to_string(index);
    else
        opName = operationName;

    ui->tabWidget_OperationParameters->addTab(operationParameters,QString::fromStdString(opName));
    operationParameters->setTabIndex(index);

    TableWidget_OperationDescriptor* tableDescriptor = new TableWidget_OperationDescriptor(operationParameters);
    tableDescriptor->setOperationIndex(index + 1);
    tableDescriptor->setOperationName(opName);

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
    this->addOperation(static_cast<unsigned int>(ui->tabWidget_OperationParameters->count()));
}

void Window_ProfileConfiguration::on_pushButton_RemoveOperation_released()
{
    QList<QListWidgetItem*> selectedList = ui->listWidget->selectedItems();
    QList<QListWidgetItem*>::iterator iteratorListWidget = selectedList.begin();

    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator iteratorMapOperations;

    for (; iteratorListWidget!=selectedList.end(); ++iteratorListWidget)
    {

        iteratorMapOperations = m_MapOperations.find(*iteratorListWidget);

        if(iteratorMapOperations != m_MapOperations.end())
        {
            TableWidget_OperationDescriptor* tableWidget = iteratorMapOperations->second;
            ui->tabWidget_OperationParameters->removeTab(tableWidget->getAccompanyingProfile()->getTabIndex());
            delete iteratorMapOperations->second;
            m_MapOperations.erase(iteratorMapOperations);
        }

        delete ui->listWidget->takeItem(ui->listWidget->row(*iteratorListWidget));
    }


    for (iteratorMapOperations = m_MapOperations.begin(); iteratorMapOperations != m_MapOperations.end(); ++iteratorMapOperations)
    {
        TableWidget_OperationDescriptor* tableWidget = iteratorMapOperations->second;
        int tabIndex = ui->tabWidget_OperationParameters->indexOf(tableWidget->getAccompanyingProfile());
        tableWidget->getAccompanyingProfile()->setTabIndex(static_cast<unsigned int>(tabIndex));
    }

    //let us reorder all of the operation numbers
    for(int listIndex = 0; listIndex < ui->listWidget->count(); listIndex++)
    {
        QListWidgetItem* currentItem = ui->listWidget->item(listIndex);
        this->m_MapOperations.at(currentItem)->setOperationIndex(listIndex + 1);
    }

    if(ui->listWidget->count() <=0)
    {
        ui->tabWidget_OperationParameters->clear();
    }

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
    saveObject["configureHome"] = ui->checkBox_ShouldHomeBeIndicated->isChecked();
    saveObject["galilScript"] = QString::fromStdString(m_WindowMotionProfile->getCurrentGalilScript());
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

    this->setIndicateHome(jsonObject["configureHome"].toBool());
    m_WindowMotionProfile->setFilePath(filePath.toStdString());
    m_WindowMotionProfile->setProgramText(jsonObject["galilScript"].toString().toStdString());

    QJsonArray configArray = jsonObject["configData"].toArray();

    if(!configArray.isEmpty())
    {
        ECMCommand_ProfileCollection profileCollection;
        profileCollection.collectionWasLoaded(true,filePath.toStdString());

        for (int i = 0; i < configArray.size(); ++i) {
            QJsonObject operationObject = configArray[i].toObject();

            ECMCommand_ProfileConfiguration loadConfig;
            loadConfig.readFromJSON(operationObject);
            loadConfig.m_GalilOperation.setProgramLoaded(true,filePath.toStdString());

            TableWidget_OperationDescriptor* currentWidget = this->addOperation(loadConfig.getOperationIndex(), loadConfig.getOperationName());
            currentWidget->loadFromProfileConfiguration(loadConfig);

            //Object will contain all of the profiles used for the profile
            profileCollection.insertProfile(loadConfig);
        }
    }
    emit signal_LoadedProfileCollection(filePath.toStdString());
}

void Window_ProfileConfiguration::setIndicateHome(const bool &checked)
{
    ui->checkBox_ShouldHomeBeIndicated->setChecked(checked);
}

void Window_ProfileConfiguration::slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility)
{
    switch (type) {
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_MOTION_PROFILE:
        ui->actionMotion_Profile->setChecked(visibility);
        break;
    default:
        std::cout<<"On slot_ChangedWindowVisibility called with unrecognized dialog window type."<<std::endl;
        break;
    }
}

/*
void Window_ProfileConfiguration::on_checkBox_ShouldHomeBeIndicated_toggled(bool checked)
{
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

    for (; it!=m_MapOperations.end(); ++it)
    {
        TableWidget_OperationDescriptor* currentOperation = it->second;
        currentOperation->setShouldHomeIndicateAutomatically(checked);
    }
}
*/

void Window_ProfileConfiguration::on_actionMotion_Profile_triggered(bool checked)
{
    if(checked)
        m_WindowMotionProfile->show();
    else
        m_WindowMotionProfile->hide();
}
