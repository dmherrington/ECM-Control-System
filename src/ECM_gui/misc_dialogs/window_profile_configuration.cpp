#include "window_profile_configuration.h"
#include "ui_window_profile_configuration.h"

Window_ProfileConfiguration::Window_ProfileConfiguration(ECM_API* apiObject, QWidget *parent) :
    GeneralDialogWindow(GeneralDialogWindow::DialogWindowTypes::WINDOW_OPERATION_CONFIGURATION,"Operation Configuration",parent),
    ui(new Ui::Window_ProfileConfiguration),
    previousItem(nullptr)
{
    ui->setupUi(this);
    m_API = apiObject;

    m_WindowBufferManager = new Window_BufferManager(m_API->m_MotionController);
    m_WindowBufferManager->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);

    connect(m_WindowBufferManager,SIGNAL(signal_DialogWindowVisibilty(GeneralDialogWindow::DialogWindowTypes,bool)),
            this,SLOT(slot_ChangedWindowVisibility(GeneralDialogWindow::DialogWindowTypes,bool)));
//    connect(m_WindowBufferManager,SIGNAL(signal_BufferManagerSynchronization),
//            this,SLOT(slot_SynchronizationRequest()));

    connect(ui->listWidget->model(),SIGNAL(rowsMoved(QModelIndex,int,int,QModelIndex,int)),this,SLOT(on_ListWidgetRowMoved()));
}

Window_ProfileConfiguration::~Window_ProfileConfiguration()
{
    delete ui;
}

void Window_ProfileConfiguration::closeEvent(QCloseEvent *event)
{
    m_WindowBufferManager->close();
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
                ECMCommand_AbstractProfileConfigPtr operationConfiguration = currentOp->getCurrentProfileConfiguration();
                executeCollection.insertProfile(operationConfiguration);
            }
        }
    }
    executeCollection.setHomeShouldIndicate(ui->checkBox_ShouldHomeBeIndicated->isChecked());

    //The current motion script needs to go here
    SPII_CurrentProgram desiredBufferContents = m_WindowBufferManager->getDesiredBufferContents();
    executeCollection.setDesiredBufferSuite(desiredBufferContents);

    return executeCollection;
}

void Window_ProfileConfiguration::updateConfigurationPath(const std::string &path)
{
    ui->lineEdit_ConfugrationPath->setText(QString::fromStdString(path));
}

TableWidget_OperationDescriptor* Window_ProfileConfiguration::addOperation(const ProfileOpType &type, const unsigned int &index, const std::string &operationName)
{
    std::string opName = "";
    if(operationName.empty())
        opName = "Operation "  + std::to_string(index);
    else
        opName = operationName;

    Widget_AbstractProfile* operationalProfile;
    switch (type) {
    case ProfileOpType::OPERATION:
    {
        operationalProfile = new Widget_ProfileParameters(m_API);
        operationalProfile->setTabIndex(index);
        int tabIndex = ui->tabWidget_OperationParameters->addTab(operationalProfile,QString::fromStdString(opName));
        ui->tabWidget_OperationParameters->setCurrentIndex(tabIndex);
        break;
    }
    case ProfileOpType::PAUSE:
    {
        operationalProfile = new Widget_PauseParameters();
        operationalProfile->setTabIndex(index);
        int tabIndex = ui->tabWidget_OperationParameters->addTab(operationalProfile,QString::fromStdString(opName));
        ui->tabWidget_OperationParameters->setCurrentIndex(tabIndex);
        break;
    }
    default:
        break;
    }

    TableWidget_OperationDescriptor* tableDescriptor = new TableWidget_OperationDescriptor(operationalProfile);
    tableDescriptor->setOperationIndex(index + 1);
    tableDescriptor->setOperationName(opName);

    connect(tableDescriptor,SIGNAL(signal_OperationNameChanged(std::string,uint)),this,SLOT(slot_OperationNameChanged(std::string,uint)));
    connect(tableDescriptor,SIGNAL(signal_ExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)),this,SLOT(slot_OnExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)));
    //tableDescriptor->newlyAvailableProgramLabels(m_API->m_MotionController->stateInterface->galilProgram->getLabelList());

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setSizeHint(tableDescriptor->sizeHint());
    ui->listWidget->addItem(newItem);
    ui->listWidget->setItemWidget(newItem,tableDescriptor);

    this->m_MapOperations.insert(std::pair<QListWidgetItem*,TableWidget_OperationDescriptor*>(newItem,tableDescriptor));

    return tableDescriptor;
}

void Window_ProfileConfiguration::slot_OnExecuteExplicitProfileConfig(const ECMCommand_AbstractProfileConfigPtr config)
{
    ECMCommand_ExecuteCollection newExecutionCollection;
    newExecutionCollection.insertProfile(config);

    //The current motion script needs to go here
    SPII_CurrentProgram desiredBufferContents = m_WindowBufferManager->getDesiredBufferContents();
    newExecutionCollection.setDesiredBufferSuite(desiredBufferContents);

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

void Window_ProfileConfiguration::slot_MCNewProgramLabels(const Operation_VariableList &labels)
{
    std::map<QListWidgetItem*,TableWidget_OperationDescriptor*>::iterator it = m_MapOperations.begin();

    //    for (; it!=m_MapOperations.end(); ++it)
    //    {
    //        TableWidget_OperationDescriptor* currentOp = it->second;
    //        currentOp->newlyAvailableProgramLabels(labels);
    //    }
}

void Window_ProfileConfiguration::on_pushButton_AddOperation_released()
{
    std::string currentOpString = this->ui->comboBox_ProfileType->currentText().toStdString();
    ProfileOpType desiredOpType = ProfileOpTypeFromString(currentOpString);
    this->addOperation(desiredOpType, static_cast<unsigned int>(ui->tabWidget_OperationParameters->count()));
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
    if(previousItem == item)
    {
        this->previousItem = nullptr;
        ui->listWidget->clearSelection();
    }
    else
    {
        this->previousItem = item;
        unsigned int currentTabIndex = this->m_MapOperations.at(item)->getAccompanyingProfile()->getTabIndex();
        ui->tabWidget_OperationParameters->setCurrentIndex(currentTabIndex);
    }
}

void Window_ProfileConfiguration::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction("Open Buffer Configuration Files (*.profileConfig)");
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_ProfileConfiguration::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction("profileConfig");
    saveToFile(settingsPath);
}

void Window_ProfileConfiguration::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction("profileConfig");
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
                ECMCommand_AbstractProfileConfigPtr operationConfig = currentOp->getCurrentProfileConfiguration();
                QJsonObject operationObject;
                operationConfig->writeToJSON(operationObject);
                segmentDataArray.append(operationObject);
            }
        }
    }

    saveObject["configData"] = segmentDataArray;
    saveObject["configureHome"] = ui->checkBox_ShouldHomeBeIndicated->isChecked();
    SPII_CurrentProgram desiredBufferContents = m_WindowBufferManager->getDesiredBufferContents();
    desiredBufferContents.writeToJSON(saveObject, false);
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

    QJsonArray configArray = jsonObject["configData"].toArray();

    SPII_CurrentProgram loadBufferContents;
    loadBufferContents.readFromJSON(jsonObject);
    m_WindowBufferManager->loadBufferContents(loadBufferContents);

    //Let us first setup the configuration
    if(!configArray.isEmpty())
    {
        ECMCommand_ProfileCollection profileCollection;
        profileCollection.collectionWasLoaded(true,filePath.toStdString());

        for (int i = 0; i < configArray.size(); ++i) {
            ECMCommand_AbstractProfileConfigPtr loadConfig;
            QJsonObject operationObject = configArray[i].toObject();
            ProfileOpType opType = static_cast<ProfileOpType>(operationObject["opType"].toInt());

            if(opType == ProfileOpType::OPERATION)
            {
                loadConfig = std::make_shared<ECMCommand_ProfileConfiguration>();
                ECMCommand_ProfileConfigurationPtr castLoadConfig = static_pointer_cast<ECMCommand_ProfileConfiguration>(loadConfig);
                castLoadConfig->readFromJSON(operationObject);
                //                castLoadConfig->m_GalilOperation.setProgramLoaded(true,filePath.toStdString());
            }
            else if(opType == ProfileOpType::PAUSE)
            {
                loadConfig = std::make_shared<ECMCommand_ProfilePause>();
                ECMCommand_ProfilePausePtr castLoadConfig = static_pointer_cast<ECMCommand_ProfilePause>(loadConfig);
                castLoadConfig->readFromJSON(operationObject);
            }
            else
            {
                break;
            }

            TableWidget_OperationDescriptor* currentWidget = this->addOperation(opType, loadConfig->getOperationIndex() - 1, loadConfig->getOperationName());
            currentWidget->loadFromProfileConfiguration(loadConfig);

            //Object will contain all of the profiles used for the profile
            profileCollection.insertProfile(loadConfig);
        }
    }

    emit signal_LoadedConfigurationCollection(filePath.toStdString());
}

void Window_ProfileConfiguration::setIndicateHome(const bool &checked)
{
    ui->checkBox_ShouldHomeBeIndicated->setChecked(checked);
}

void Window_ProfileConfiguration::slot_ChangedWindowVisibility(const GeneralDialogWindow::DialogWindowTypes &type, const bool visibility)
{
    switch (type) {
    case GeneralDialogWindow::DialogWindowTypes::WINDOW_BUFFER_MANAGER:
        ui->actionMotion_Profile->setChecked(visibility);
        break;
    default:
        std::cout<<"On slot_ChangedWindowVisibility called with unrecognized dialog window type."<<std::endl;
        break;
    }
}

void Window_ProfileConfiguration::on_actionMotion_Profile_triggered(bool checked)
{
        if(checked)
            m_WindowBufferManager->show();
        else
            m_WindowBufferManager->hide();
}

void Window_ProfileConfiguration::on_actionNew_triggered(bool checked)
{
    UNUSED(checked);
    ui->lineEdit_ConfugrationPath->clear();
    clearExistingOperations();
}

bool Window_ProfileConfiguration::checkBufferContents(bool &shouldUpload)
{
    bool continueExecution = true;

    bool windowDisplaysAccurately = m_WindowBufferManager->isDisplayCurrentAndCompiled();

    if(!windowDisplaysAccurately) //the window does not accurately reflect what is currently aboard the ACS
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The script associated with this script does not match currently what is aboard the galil unit.");
        msgBox.setInformativeText("Do you want the script to be automatically uploaded? This will cause the homing routine to execute.");
        QAbstractButton* pButtonAccept = msgBox.addButton(tr("Accept"), QMessageBox::AcceptRole);
        QAbstractButton* pButtonReject = msgBox.addButton(tr("Reject"), QMessageBox::RejectRole);
        msgBox.exec();

        if(msgBox.clickedButton() == pButtonAccept)
        {
            shouldUpload = true;
            continueExecution = true;
        }
        else if(msgBox.clickedButton() == pButtonReject)

        {
            continueExecution = false;
        }
    }
    return continueExecution;
}

void Window_ProfileConfiguration::on_pushButton_OpenMotionScript_released()
{

}

void Window_ProfileConfiguration::on_pushButton_UploadCurrentBuffers_released()
{

}

void Window_ProfileConfiguration::on_pushButton_SyncCurrentBuffers_released()
{
    m_API->m_MotionController->executeSynchronizationRequest();
}
