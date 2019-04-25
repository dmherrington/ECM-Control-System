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

    connect(m_BufferEditor, SIGNAL(signal_BufferUpdatedLineCount(const int &)),
            this, SLOT(slot_UpdateBufferLineCount(const int&)));

    connect(m_BufferEditor, SIGNAL(signal_BufferCurrent(const bool &)),
            this, SLOT(slot_BufferCurrent(const bool&)));

    slot_UpdateBufferName(m_BufferEditor->getCurrentBufferName());

    updateBufferIndex(bufferIndex);
}

Widget_BufferDescriptor::Widget_BufferDescriptor(SPIIMotionController *motionControlObject, const BufferData &data, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget_BufferDescriptor)
{
    ui->setupUi(this);

    updateBufferIndex(data.getBufferIndex());

    m_BufferEditor = new Widget_BufferEditor(motionControlObject, data.getBufferIndex(), data.isDBuffer());

    connect(m_BufferEditor, SIGNAL(signal_BufferNameChanged(const std::string&)),
            this, SLOT(slot_UpdateBufferName(const std::string&)));

    connect(m_BufferEditor, SIGNAL(signal_BufferUpdatedLineCount(const int &)),
            this, SLOT(slot_UpdateBufferLineCount(const int&)));

    connect(m_BufferEditor, SIGNAL(signal_BufferCurrent(const bool &)),
            this, SLOT(slot_BufferCurrent(const bool&)));

    bool current, compiled;
    m_BufferEditor->updateFromBufferData(data, current, compiled);

    updateCurrentLED(current);
    updateCompiledLED(compiled);
    //slot_UpdateBufferName(m_BufferEditor->getCurrentBufferName());
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

void Widget_BufferDescriptor::slot_BufferCurrent(const bool &current)
{
    updateCurrentLED(current);
}

void Widget_BufferDescriptor::updateCurrentLED(const bool &current)
{
    if(current)
        ui->led_ProgramChanged->setColor(QColor(0,255,0));
    else
        ui->led_ProgramChanged->setColor(QColor(255,0,0));
    m_BufferEditor->updateCurrentLED(current);
}

void Widget_BufferDescriptor::updateCompiledLED(const bool &compiled)
{
    if(compiled)
        ui->led_ProgramCompiled->setColor(QColor(0,255,0));
    else
        ui->led_ProgramCompiled->setColor(QColor(255,0,0));
    m_BufferEditor->updateCompiledLED(compiled);
}

void Widget_BufferDescriptor::slot_UpdateBufferName(const std::string &name)
{
    ui->label_BufferName->setText(QString::fromStdString(name));
}

void Widget_BufferDescriptor::slot_UpdateBufferLineCount(const int &count)
{
    ui->label_Lines->setText(QString::number(count));
}

void Widget_BufferDescriptor::on_pushButton_DisplayBuffer_released()
{
    emit singal_DisplayBufferCode(m_BufferEditor->getBufferIndex());
}

void Widget_BufferDescriptor::updateFromBufferData(const BufferData &data)
{
    bool current, compiled;
    m_BufferEditor->updateFromBufferData(data,current,compiled);
    updateCurrentLED(current);
    updateCompiledLED(compiled);
}

void Widget_BufferDescriptor::updateFromBufferStatus(const Status_BufferState &state)
{
    switch (state.getBufferStatus()) {
    case Status_BufferState::ENUM_BUFFERSTATE::CLEARED:
    {
        m_BufferEditor->updateProgramText("");
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::COMPILED:
    {
        m_BufferEditor->updateProgramText(state.getProgramString());
        updateCurrentLED(true);
        updateCompiledLED(true);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::CURRENT:
    {
        m_BufferEditor->updateProgramText(state.getProgramString());
        updateCurrentLED(true);
        updateCompiledLED(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_COMPILING:
    {
        updateCurrentLED(true);
        updateCompiledLED(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::ERROR_UPLOAD:
    {
        updateCurrentLED(false);
        updateCompiledLED(false);
        break;
    }
    case Status_BufferState::ENUM_BUFFERSTATE::UNKNOWN:
    {
        break;
    }
    default:
        break;
    }
}
