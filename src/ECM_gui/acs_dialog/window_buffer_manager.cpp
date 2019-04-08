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
    for(int stackedIndex = ui->stackedWidget_BufferContents->count(); stackedIndex > 0; stackedIndex--)
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
}

void Window_BufferManager::on_actionOpen_triggered()
{
    QString filePath = GeneralDialogWindow::onOpenAction();
    if(!filePath.isEmpty() && !filePath.isNull()){
        openFromFile(filePath);
    }
}

void Window_BufferManager::on_actionSave_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAction();
    saveToFile(settingsPath);
}

void Window_BufferManager::on_actionSave_As_triggered()
{
    QString settingsPath = GeneralDialogWindow::onSaveAsAction();
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

    //emit signal_LoadedConfigurationCollection(filePath.toStdString());
}

