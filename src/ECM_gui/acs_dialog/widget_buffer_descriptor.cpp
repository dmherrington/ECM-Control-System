#include "widget_buffer_descriptor.h"
#include "ui_widget_buffer_descriptor.h"

Widget_BufferDescriptor::Widget_BufferDescriptor(const unsigned int &bufferIndex, const bool &isDBuffer,
                                                 QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BufferDescriptor)
{
    ui->setupUi(this);

    m_BufferEditor = new Widget_BufferEditor(bufferIndex, isDBuffer);
}

Widget_BufferDescriptor::~Widget_BufferDescriptor()
{
    delete ui;
}

void Widget_BufferDescriptor::setOpenInEditor(const bool &open)
{
    this->isOpen = open;
}

bool Widget_BufferDescriptor::isOpenInEditor() const
{
    return this->isOpen;
}

Widget_BufferEditor* Widget_BufferDescriptor::getBufferEditor() const
{
    return this->m_BufferEditor;
}
