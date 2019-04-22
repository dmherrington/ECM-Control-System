#include "widget_buffer_editor.h"
#include "ui_widget_buffer_editor.h"

Widget_BufferEditor::Widget_BufferEditor(SPIIMotionController *motionControlObject, const unsigned int &bufferIndex, const bool &isDBuffer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BufferEditor)
{
    ui->setupUi(this);
    m_SPIIDevice = motionControlObject;

    m_EditData = new BufferData(bufferIndex,isDBuffer);

    updateBufferIndex(bufferIndex);
    std::string bufferName = "Buffer #" + std::to_string(bufferIndex);
    updateBufferName(bufferName);
}

Widget_BufferEditor::~Widget_BufferEditor()
{
    delete ui;
}

void Widget_BufferEditor::updateFromBufferData(const BufferData &data, bool &current, bool &compiled)
{
    updateProgramText(data.getProgramString());
    updateBufferName(data.getBufferName());
    doesProgramMatch(current, compiled);
}

std::string Widget_BufferEditor::getCurrentBufferName() const
{
    return ui->lineEdit_BufferName->text().toStdString();
}

unsigned int Widget_BufferEditor::getBufferIndex() const
{
    return this->m_EditData->getBufferIndex();
}

void Widget_BufferEditor::updateProgramText(const std::string &text)
{
    bool oldState = ui->codeTextEdit->blockSignals(true);
    ui->codeTextEdit->clear();
    ui->codeTextEdit->document()->setPlainText(QString::fromStdString(text));
    ui->codeTextEdit->blockSignals(oldState);

    updateCurrentLineCount();

    m_EditData->setProgramString(text);
}

void Widget_BufferEditor::updateCurrentLED(const bool &current)
{
    if(current)
        ui->led_ProgramCurrent->setColor(QColor(0,255,0));
    else
        ui->led_ProgramCurrent->setColor(QColor(255,0,0));
}

void Widget_BufferEditor::updateCompiledLED(const bool &compiled)
{
    if(compiled)
        ui->led_ProgramCompiled->setColor(QColor(0,255,0));
    else
        ui->led_ProgramCompiled->setColor(QColor(255,0,0));
}

void Widget_BufferEditor::updateBufferName(const std::string &name)
{
    ui->lineEdit_BufferName->setText(QString::fromStdString(m_EditData->setBufferName(name)));
    emit signal_BufferNameChanged(m_EditData->getBufferName());
}

void Widget_BufferEditor::updateBufferIndex(const unsigned int &index)
{
    ui->label_BufferIndexNumber->setText(QString::number(index));
}

BufferData Widget_BufferEditor::getBufferData() const
{
    return *m_EditData;
}

void Widget_BufferEditor::updateCurrentLineCount()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();
    unsigned int currentLineCount = 0;
    if(!programString.empty())
        currentLineCount = static_cast<unsigned int>(ui->codeTextEdit->document()->lineCount());

    if(previousLineCount != static_cast<int>(currentLineCount))
    {
        previousLineCount = static_cast<int>(currentLineCount);
        emit signal_BufferUpdatedLineCount(previousLineCount);
    }
}

void Widget_BufferEditor::on_lineEdit_BufferName_textChanged(const QString &arg1)
{
    updateBufferName(arg1.toStdString());
}

bool Widget_BufferEditor::isAccurateReflection() const
{
    BufferData currentBufferData;
    if(m_SPIIDevice->m_StateInterface->m_BufferManager->getBufferData(m_EditData->getBufferIndex(),currentBufferData))
    {
        return currentBufferData.doesBufferAccuratelyReflect(*m_EditData);
    }
    return false;
}

void Widget_BufferEditor::doesProgramMatch(bool &current, bool &compiled)
{
    bool accurateReflection = isAccurateReflection();

    if(!accurateReflection)
    {
        current = false; compiled = false;
        m_EditData->setBufferCurrent(false);
        updateCurrentLED(false);
        m_EditData->setBufferCompiled(false);
        updateCompiledLED(false);
    }
    else
    {
        BufferData currentBufferData;
        m_SPIIDevice->m_StateInterface->m_BufferManager->getBufferData(m_EditData->getBufferIndex(),currentBufferData);

        current = currentBufferData.isBufferCurrent();
        updateCurrentLED(current);
        m_EditData->setBufferCurrent(current);

        compiled = currentBufferData.isBufferCompiled();
        updateCompiledLED(compiled);
        m_EditData->setBufferCompiled(compiled);
    }
}

void Widget_BufferEditor::on_codeTextEdit_textChanged()
{
    updateCurrentLineCount();

    std::string programString = ui->codeTextEdit->toPlainText().toStdString();
    m_EditData->setProgramString(programString);

    bool current, compiled;
    doesProgramMatch(current, compiled);

    emit signal_BufferCurrent(current);
}

void Widget_BufferEditor::on_pushButton_Upload_released()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();
    SPIICommand_UploadProgramBufferPtr commandUploadProgram = std::make_shared<SPIICommand_UploadProgramBuffer>();
    commandUploadProgram->setCurrentScript(programString);
    commandUploadProgram->setBufferIndex(m_EditData->getBufferIndex());

    m_SPIIDevice->executeCommand(commandUploadProgram);
}

void Widget_BufferEditor::on_pushButton_Download_released()
{

}

void Widget_BufferEditor::on_pushButton_Execute_released()
{

}

void Widget_BufferEditor::on_pushButton_Clear_released()
{
    ui->codeTextEdit->clear();

    SPIICommand_UploadProgramBufferPtr commandUploadProgram = std::make_shared<SPIICommand_UploadProgramBuffer>();
    commandUploadProgram->setCurrentScript("");
    commandUploadProgram->setBufferIndex(m_EditData->getBufferIndex());

    m_SPIIDevice->executeCommand(commandUploadProgram);
}
