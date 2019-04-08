#ifndef WIDGET_BUFFER_DESCRIPTOR_H
#define WIDGET_BUFFER_DESCRIPTOR_H

#include <QWidget>
#include <QJsonObject>

#include "library_SPIIMotionController/buffers/buffer_data.h"
#include "library_SPIIMotionController/communications/comms_marshaler.h"

#include "widget_buffer_editor.h"

namespace Ui {
class Widget_BufferDescriptor;
}

class Widget_BufferDescriptor : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_BufferDescriptor(SPIIMotionController *motionControlObject, const unsigned int &bufferIndex = 0, const bool &isDBuffer = false, QWidget *parent = nullptr);

    Widget_BufferDescriptor(SPIIMotionController *motionControlObject, const BufferData &data, QWidget *parent = nullptr);

    ~Widget_BufferDescriptor();

public:
    void setOpenInEditor(const bool &open);
    bool isOpenInEditor() const;

    Widget_BufferEditor* getBufferEditor() const;

    void updateBufferIndex(const unsigned int &index);

    void updateFromBufferStatus(const Status_BufferState &state);

private:
    void updateCurrentLED(const bool &current);

    void updateCompiledLED(const bool &compiled);

signals:
    void singal_DisplayBufferCode(const unsigned int &index);

private slots:
    void slot_UpdateBufferName(const std::string &name);
    void slot_UpdateBufferLineCount(const int &count);

    void on_pushButton_DisplayBuffer_released();

private:
    Ui::Widget_BufferDescriptor *ui;

private:
    Widget_BufferEditor* m_BufferEditor;

    bool isOpen = false;
};

#endif // WIDGET_BUFFER_DESCRIPTOR_H
