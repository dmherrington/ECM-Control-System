#include "window_buffer_manager.h"
#include "ui_window_buffer_manager.h"

Window_BufferManager::Window_BufferManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_BufferManager)
{
    ui->setupUi(this);
}

Window_BufferManager::~Window_BufferManager()
{
    delete ui;
}

void Window_BufferManager::setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer)
{
    //clear all of the old data
    m_BufferDescriptors.clear();
    for(size_t index = 0; index < count; index++)
    {
        bool match = (index == dBuffer);
        Widget_BufferDescriptor* tableDescriptor = new Widget_BufferDescriptor(index, match);
        //connect(tableDescriptor,SIGNAL(signal_ExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)),this,SLOT(slot_OnExecuteExplicitProfileConfig(ECMCommand_AbstractProfileConfigPtr)));
        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(tableDescriptor->sizeHint());
        ui->listWidget_Buffers->addItem(newItem);
        ui->listWidget_Buffers->setItemWidget(newItem,tableDescriptor);
        m_BufferDescriptors.insert(std::pair<unsigned int, Widget_BufferDescriptor*>(index,tableDescriptor));
    }
}
