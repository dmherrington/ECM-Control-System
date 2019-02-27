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

void Widget_BufferEditor::updateFromBufferData(const BufferData* data)
{

}

std::string Widget_BufferEditor::getCurrentBufferName() const
{
    return ui->lineEdit_BufferName->text().toStdString();
}

unsigned int Widget_BufferEditor::getBufferIndex() const
{
    return this->m_EditData->getBufferIndex();
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

void Widget_BufferEditor::updateCodeText(const std::string &programText)
{
    ui->codeTextEdit->clear();
}


void Widget_BufferEditor::on_lineEdit_BufferName_textChanged(const QString &arg1)
{
    updateBufferName(arg1.toStdString());
}

void Widget_BufferEditor::on_codeTextEdit_textChanged()
{
    unsigned int currentLineCount = static_cast<unsigned int>(ui->codeTextEdit->document()->lineCount());
    if(previousLineCount != currentLineCount)
    {
        previousLineCount = currentLineCount;
        emit signal_BufferUpdatedLineCount(previousLineCount);
    }
}

void Widget_BufferEditor::on_pushButton_Upload_released()
{
    std::string programString = ui->codeTextEdit->toPlainText().toStdString();
    SPIICommand_UploadProgramPtr commandUploadProgram = std::make_shared<SPIICommand_UploadProgram>();
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

}
