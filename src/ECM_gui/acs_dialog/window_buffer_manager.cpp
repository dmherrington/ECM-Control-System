#include "window_buffer_manager.h"
#include "ui_window_buffer_manager.h"

Window_BufferManager::Window_BufferManager(SPIIMotionController *motionControlObject, QWidget *parent) :
    GeneralDialogWindow(DialogWindowTypes::WINDOW_BUFFER_MANAGER,"SPII Buffer Manager",parent),
    ui(new Ui::Window_BufferManager)
{
    ui->setupUi(this);

    m_SPIIDevice = motionControlObject;

    connect(m_SPIIDevice, SIGNAL(signal_MCCommunicationUpdate(common::comms::CommunicationUpdate)),
            this, SLOT(slot_OnMCCommunicationUpdate(common::comms::CommunicationUpdate)));

    connect(m_SPIIDevice, SIGNAL(signal_MCBufferUpdate(Status_BufferState)),
            this, SLOT(slot_MCBufferStatusUpdate(Status_BufferState)));

}

Window_BufferManager::~Window_BufferManager()
{
    delete ui;
}

void Window_BufferManager::closeEvent(QCloseEvent *event)
{
    GeneralDialogWindow::closeEvent(event);
}

void Window_BufferManager::clearBufferData()
{
    //first delete the widget data
    for (auto it = m_BufferDescriptors.cbegin(); it != m_BufferDescriptors.cend() /* not hoisted */; /* no increment */)
    {
        it = m_BufferDescriptors.erase(it);
    }

    //then delete the list widget
    for(int stackedIndex = ui->stackedWidget_BufferContents->count(); stackedIndex >= 0; stackedIndex--)
    {
        //first delete the stacked index
        QWidget* widget = ui->stackedWidget_BufferContents->widget(stackedIndex);
        ui->stackedWidget_BufferContents->removeWidget(widget);
        widget->deleteLater();
    }

    //next delete the list widget
    ui->listWidget_Buffers->clear();

    //lastly, clear all of the old data
    m_BufferDescriptors.clear();
}

void Window_BufferManager::setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer)
{
    clearBufferData();

    //check that the count in question is greater than 0
    if(count <= 0)
        return;

    for(size_t index = 0; index < count; index++)
    {
        bool match = (index == dBuffer);
        Widget_BufferDescriptor* tableDescriptor = new Widget_BufferDescriptor(m_SPIIDevice, index, match);
        connect(tableDescriptor, SIGNAL(singal_DisplayBufferCode(const unsigned int&)),
                this, SLOT(slot_OnDisplayBufferContents(const unsigned int&)));

        //connect(tableDescriptor,SIGNAL(signal_ExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)),this,SLOT(slot_OnExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)));
        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(tableDescriptor->sizeHint());
        ui->listWidget_Buffers->addItem(newItem);
        ui->listWidget_Buffers->setItemWidget(newItem,tableDescriptor);
        m_BufferDescriptors.insert(std::pair<unsigned int, Widget_BufferDescriptor*>(index,tableDescriptor));
        ui->stackedWidget_BufferContents->addWidget(tableDescriptor->getBufferEditor());
    }

    m_BufferDescriptors.at(0)->setOpenInEditor(true);
    ui->stackedWidget_BufferContents->setCurrentIndex(0);

}

SPII_CurrentProgram Window_BufferManager::getDesiredBufferContents() const
{
    SPII_CurrentProgram bufferEditor;
    bufferEditor.setMaxBufferSize(m_BufferDescriptors.size());

    std::map<unsigned int, Widget_BufferDescriptor*>::const_iterator it = m_BufferDescriptors.cbegin();
    for(; it != m_BufferDescriptors.cend(); ++it)
    {
        Widget_BufferDescriptor* currentBufferDescriptor = it->second;
        BufferData currentData = currentBufferDescriptor->getBufferEditor()->getBufferData();
        if(currentData.isDBuffer())
            bufferEditor.setDBufferIndex(currentData.getBufferIndex());
        bufferEditor.updateBufferData(it->first, currentData);
    }

    return bufferEditor;
}

void Window_BufferManager::loadBufferContents(const SPII_CurrentProgram &desiredBufferContents)
{
    unsigned int correctDBuffer = 0;
    if(m_SPIIDevice->isDeviceConnected())
    {
        unsigned int connectedDBufferIndex = m_SPIIDevice->m_StateInterface->m_BufferManager->getDBufferIndex();
        if(connectedDBufferIndex != desiredBufferContents.getDBufferIndex())
            correctDBuffer = connectedDBufferIndex;
        else
            correctDBuffer = desiredBufferContents.getDBufferIndex();
    }
    setInitialBufferCount(desiredBufferContents.getBufferSize(), correctDBuffer);

    std::map<unsigned int, Widget_BufferDescriptor*>::iterator it = m_BufferDescriptors.begin();
    for(; it != m_BufferDescriptors.end(); ++it)
    {
        Widget_BufferDescriptor* currentBufferDescriptor = it->second;
        BufferData currentBufferData;
        desiredBufferContents.getBufferData(it->first,currentBufferData);
        currentBufferDescriptor->updateFromBufferData(currentBufferData);
    }
}

bool Window_BufferManager::isDisplayCurrentAndCompiled() const
{
    bool valid = true;

    std::map<unsigned int, Widget_BufferDescriptor*>::const_iterator it;

    for(it = m_BufferDescriptors.cbegin(); it != m_BufferDescriptors.cend(); ++it)
    {
        BufferData currentDeviceData;
        bool validRequest = m_SPIIDevice->m_StateInterface->m_BufferManager->getBufferData(it->first,currentDeviceData);

        if(validRequest)
        {
            if(currentDeviceData.isBufferCompiled() && currentDeviceData.isBufferCurrent())
            {
                Widget_BufferDescriptor* currentWidet = it->second;
                if(!currentWidet->getBufferEditor()->isAccurateReflection())
                {
                    valid = false;
                    break;
                }
            }
            else
            {
                valid = false;
                break;
            }
        }
        else
            valid = false;
    }

    return valid;
}

void Window_BufferManager::slot_OnMCCommunicationUpdate(const common::comms::CommunicationUpdate &update)
{
    switch (update.getUpdateType()) {
    case common::comms::CommunicationUpdate::UpdateTypes::CONNECTED:
    {
        unsigned int numAxis = 0, numBuffers = 0, dBufferIndex = 0;
        m_SPIIDevice->getSPIIProperties(numAxis, numBuffers, dBufferIndex);
        setInitialBufferCount(numBuffers + 1,dBufferIndex);
        break;
    }
    default:
        break;
    }
}

void Window_BufferManager::slot_OnDisplayBufferContents(const unsigned int &index)
{
    ui->stackedWidget_BufferContents->setCurrentIndex(static_cast<int>(index));
}


void Window_BufferManager::slot_MCBufferStatusUpdate(const Status_BufferState &state)
{
    m_BufferDescriptors.at(state.getBufferIndex())->updateFromBufferStatus(state);

    switch(state.getBufferStatus())
    {
        case Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD:
        case Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING:
    {
        std::string msg = "Error in Buffer: " + std::to_string(state.getBufferIndex()) + " at Line Number: " + std::to_string(state.getErrorLine());
        QMessageBox msgBox;
        msgBox.setWindowTitle("Buffer Manager");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(QString::fromStdString(msg));
        msgBox.setInformativeText(QString::fromStdString(state.getErrorString()));
        msgBox.exec();
        break;
    }
    default:
    {

    }
    }
}

void Window_BufferManager::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction("Open Buffer Configuration Files (*.prg)");
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_BufferManager::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction("prg");
    saveToFile(settingsPath);
}

void Window_BufferManager::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction("prg");
    saveToFile(settingsPath);
}

void Window_BufferManager::on_actionClose_triggered()
{
    GeneralDialogWindow::onCloseAction();
}

void Window_BufferManager::saveToFile(const QString &filePath)
{
    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject saveObject;
    QJsonArray bufferDataArray;

    std::map<unsigned int, Widget_BufferDescriptor*>::iterator it = m_BufferDescriptors.begin();
    for(; it != m_BufferDescriptors.end(); ++it)
    {
        Widget_BufferDescriptor* currentBufferDescriptor = it->second;
        BufferData currentData = currentBufferDescriptor->getBufferEditor()->getBufferData();

        QJsonObject operationObject;
        currentData.writeToJSON(operationObject);
        bufferDataArray.append(operationObject);
    }

    saveObject["BufferData"] = bufferDataArray;

    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}


void Window_BufferManager::openFromFile(const QString &filePath)
{
    QFile loadFile(filePath);
     if (!loadFile.open(QIODevice::ReadOnly)) return;

    clearBufferData();

    QTextStream in(&loadFile);
    QString programText = in.readAll();
    loadFile.close();

    BufferManager loadProgram = SPII_PrgHandle::parsePRG(programText);

    for(unsigned int bufferIndex = 0; bufferIndex < loadProgram.getBufferSize(); bufferIndex++)
    {
        BufferData loadBufferData;
        if(loadProgram.getBufferData(bufferIndex,loadBufferData))
        {
            Widget_BufferDescriptor* tableDescriptor = new Widget_BufferDescriptor(m_SPIIDevice, loadBufferData);
            connect(tableDescriptor, SIGNAL(singal_DisplayBufferCode(const unsigned int&)),
                    this, SLOT(slot_OnDisplayBufferContents(const unsigned int&)));
            QListWidgetItem* newItem = new QListWidgetItem();
            newItem->setSizeHint(tableDescriptor->sizeHint());
            ui->listWidget_Buffers->addItem(newItem);
            ui->listWidget_Buffers->setItemWidget(newItem,tableDescriptor);
            m_BufferDescriptors.insert(std::pair<unsigned int, Widget_BufferDescriptor*>(loadBufferData.getBufferIndex() ,tableDescriptor));
            ui->stackedWidget_BufferContents->addWidget(tableDescriptor->getBufferEditor());
        }
    }
    /*
    QByteArray loadData = loadFile.readAll();
    loadFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    QJsonObject jsonObject = loadDoc.object();

    QJsonArray bufferArray = jsonObject["BufferData"].toArray();

    if(!bufferArray.isEmpty())
    {
        for (int i = 0; i < bufferArray.size(); ++i) {
            QJsonObject bufferObject = bufferArray[i].toObject();
            BufferData newData;
            newData.readFromJSON(bufferObject);

            Widget_BufferDescriptor* tableDescriptor = new Widget_BufferDescriptor(m_SPIIDevice, newData);
            connect(tableDescriptor, SIGNAL(singal_DisplayBufferCode(const unsigned int&)),
                    this, SLOT(slot_OnDisplayBufferContents(const unsigned int&)));

            //connect(tableDescriptor,SIGNAL(signal_ExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)),this,SLOT(slot_OnExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)));

            QListWidgetItem* newItem = new QListWidgetItem();
            newItem->setSizeHint(tableDescriptor->sizeHint());
            ui->listWidget_Buffers->addItem(newItem);
            ui->listWidget_Buffers->setItemWidget(newItem,tableDescriptor);
            m_BufferDescriptors.insert(std::pair<unsigned int, Widget_BufferDescriptor*>(newData.getBufferIndex() ,tableDescriptor));
            ui->stackedWidget_BufferContents->addWidget(tableDescriptor->getBufferEditor());
        }
    }

    m_BufferDescriptors.at(0)->setOpenInEditor(true);
    ui->stackedWidget_BufferContents->setCurrentIndex(0);
    */

    //emit signal_LoadedConfigurationCollection(filePath.toStdString());
}

