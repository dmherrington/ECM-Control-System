#ifndef WIDGET_BUFFER_EDITOR_H
#define WIDGET_BUFFER_EDITOR_H

#include <QWidget>

#include "library_SPIIMotionController/spii_motion_controller.h"
#include "library_SPIIMotionController/buffers/buffer_data.h"
#include "library_SPIIMotionController/commands/spii_command_upload_program.h"

namespace Ui {
class Widget_BufferEditor;
}

class Widget_BufferEditor : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_BufferEditor(SPIIMotionController* motionControlObject,
                                 const unsigned int &bufferIndex = 0, const bool &isDBuffer = false,
                                 QWidget *parent = nullptr);
    ~Widget_BufferEditor();

public:
    void updateFromBufferData(const BufferData* data);

    std::string getCurrentBufferName() const;

    unsigned int getBufferIndex() const;

private slots:

    void on_lineEdit_BufferName_textChanged(const QString &arg1);

    void on_codeTextEdit_textChanged();

    void on_pushButton_Upload_released();

    void on_pushButton_Download_released();

    void on_pushButton_Execute_released();

    void on_pushButton_Clear_released();

private:
    void updateCurrentLED(const bool &current);

    void updateCompiledLED(const bool &compiled);

    void updateBufferName(const std::string &name = "");

    void updateBufferIndex(const unsigned int &index);

    void updateCodeText(const std::string &programText);

signals:
    void signal_BufferNameChanged(const std::string &name);
    void signal_BufferUpdatedLineCount(const unsigned int &count);

private:
    Ui::Widget_BufferEditor *ui;

    SPIIMotionController* m_SPIIDevice;

    BufferData* m_EditData;

    bool lockBufferName = false;

    unsigned int previousLineCount = 0;
};

#endif // WIDGET_BUFFER_EDITOR_H
