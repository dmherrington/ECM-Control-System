#include "window_buffer_manager.h"
#include "ui_window_buffer_manager.h"

Window_BufferManager::Window_BufferManager(SPIIMotionController *motionControlObject, QWidget *parent) :
    QMainWindow(parent),
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

void Window_BufferManager::setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer)
{
    for(size_t stackedIndex = ui->stackedWidget_BufferContents->count(); stackedIndex > 0; stackedIndex--)
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
    ui->stackedWidget_BufferContents->setCurrentIndex(index);
}


void Window_BufferManager::slot_MCBufferStatusUpdate(const Status_BufferState &state)
{

}
