#include "widget_buffer_editor.h"
#include "ui_widget_buffer_editor.h"

Widget_BufferEditor::Widget_BufferEditor(const unsigned int &bufferIndex, const bool &isDBuffer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BufferEditor)
{
    ui->setupUi(this);

    updateBufferIndex(bufferIndex);


}

Widget_BufferEditor::~Widget_BufferEditor()
{
    delete ui;
}

void Widget_BufferEditor::updateFromBufferData(const BufferData* data)
{

}

void Widget_BufferEditor::updateCurrentLED(const bool &current)
{

}

void Widget_BufferEditor::updateCompiledLED(const bool &compiled)
{

}

void Widget_BufferEditor::updateBufferName(const std::string &name, const bool &isDBuffer)
{
    std::string currentBufferName = "";
    if(isDBuffer)
    {
        lockBufferName = true;
        currentBufferName = "DBuffer";
    }
    else
    {
        if(!lockBufferName)
            currentBufferName = name;
    }
    ui->lineEdit_BufferName->setText(QString::fromStdString(name));
}

void Widget_BufferEditor::updateBufferIndex(const unsigned int &index)
{
    ui->label_BuferIndex->setText(QString::number(index));
}

void Widget_BufferEditor::updateCodeText(const std::string &programText)
{
    ui->codeTextEdit->clear();
}

void Widget_BufferEditor::on_lineEdit_BufferName_textChanged(const QString &arg1)
{
    updateBufferName(arg1.toStdString());
}
