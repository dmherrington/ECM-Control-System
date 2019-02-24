#ifndef WIDGET_BUFFER_DESCRIPTOR_H
#define WIDGET_BUFFER_DESCRIPTOR_H

#include <QWidget>

#include "library_SPIIMotionController/buffers/buffer_data.h"

#include "widget_buffer_editor.h"

namespace Ui {
class Widget_BufferDescriptor;
}

class Widget_BufferDescriptor : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_BufferDescriptor(const unsigned int &bufferIndex = 0, const bool &isDBuffer = false, QWidget *parent = nullptr);
    ~Widget_BufferDescriptor();

public:
    void setOpenInEditor(const bool &open);
    bool isOpenInEditor() const;

    Widget_BufferEditor* getBufferEditor() const;

private:
    Ui::Widget_BufferDescriptor *ui;

private:
    Widget_BufferEditor* m_BufferEditor;

    BufferData* m_Data;

    bool isOpen = false;
};

#endif // WIDGET_BUFFER_DESCRIPTOR_H
