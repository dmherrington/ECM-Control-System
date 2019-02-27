#include "widget_buffer_descriptor.h"
#include "ui_widget_buffer_descriptor.h"

Widget_BufferDescriptor::Widget_BufferDescriptor(SPIIMotionController *motionControlObject, const unsigned int &bufferIndex, const bool &isDBuffer,
                                                 QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BufferDescriptor)
{

    ui->setupUi(this);

    m_BufferEditor = new Widget_BufferEditor(motionControlObject, bufferIndex, isDBuffer);

    connect(m_BufferEditor, SIGNAL(signal_BufferNameChanged(const std::string&)),
            this, SLOT(slot_UpdateBufferName(const std::string&)));

    connect(m_BufferEditor, SIGNAL(signal_BufferUpdatedLineCount(const unsigned int &)),
            this, SLOT(slot_UpdateBufferLineCount(const unsigned int&)));

    slot_UpdateBufferName(m_BufferEditor->getCurrentBufferName());

    updateBufferIndex(bufferIndex);
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

void Widget_BufferDescriptor::updateBufferIndex(const unsigned int &index)
{
    ui->label_BufferIndex->setText(QString::number(index));
}

void Widget_BufferDescriptor::slot_UpdateBufferName(const std::string &name)
{
    ui->label_BufferName->setText(QString::fromStdString(name));
}

void Widget_BufferDescriptor::slot_UpdateBufferLineCount(const unsigned int &count)
{
    ui->label_Lines->setText(QString::number(count));
}

void Widget_BufferDescriptor::on_pushButton_DisplayBuffer_released()
{
    emit singal_DisplayBufferCode(m_BufferEditor->getBufferIndex());
}

void Widget_BufferDescriptor::updateFromBufferStatus(const Status_BufferState &state)
{
    switch (state.getBufferStatus()) {
    case Status_BufferState::ENUM_BUFFERSTATE::CLEARED:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::COMPILED:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::CURRENT:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::UNKNOWN:
    {
        ui->codeTextEdit->clear();
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    default:
        break;
    }
}
