#ifndef WIDGET_BUFFER_EDITOR_H
#define WIDGET_BUFFER_EDITOR_H

#include <QWidget>

#include "library_SPIIMotionController/buffers/buffer_data.h"

namespace Ui {
class Widget_BufferEditor;
}

class Widget_BufferEditor : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_BufferEditor(const unsigned int &bufferIndex = 0, const bool &isDBuffer = false, QWidget *parent = nullptr);
    ~Widget_BufferEditor();

public:
    void updateFromBufferData(const BufferData* data);

private slots:
    void on_lineEdit_BufferName_textChanged(const QString &arg1);

private:
    void updateCurrentLED(const bool &current);

    void updateCompiledLED(const bool &compiled);

    void updateBufferName(const std::string &name = "", const bool &isDBuffer = false);

    void updateBufferIndex(const unsigned int &index);

    void updateCodeText(const std::string &programText);

private:
    Ui::Widget_BufferEditor *ui;

    bool lockBufferName = false;

};

#endif // WIDGET_BUFFER_EDITOR_H
