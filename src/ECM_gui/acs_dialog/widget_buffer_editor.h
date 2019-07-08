#ifndef WIDGET_BUFFER_EDITOR_H
#define WIDGET_BUFFER_EDITOR_H

#include <QWidget>

#include "library_SPIIMotionController/spii_motion_controller.h"
#include "library_SPIIMotionController/buffers/buffer_data.h"
#include "library_SPIIMotionController/commands/spii_command_upload_program_buffer.h"

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
    void updateFromBufferData(const BufferData &data, bool &current, bool &compiled);

    std::string getCurrentBufferName() const;

    unsigned int getBufferIndex() const;

    void updateProgramText(const std::string &text);

public:
    void updateCurrentLED(const bool &current);

    void updateCompiledLED(const bool &compiled);

    void updateBufferName(const std::string &name = "");

    void updateBufferIndex(const unsigned int &index);

public:
    BufferData getBufferData() const;

    bool isAccurateReflection() const;

    void doesProgramMatch(bool &current, bool &compiled);

private:
    void updateCurrentLineCount();

private slots:

    void on_lineEdit_BufferName_textChanged(const QString &arg1);

    void on_codeTextEdit_textChanged();

    void on_pushButton_Upload_released();

    void on_pushButton_Download_released();

    void on_pushButton_Execute_released();

    void on_pushButton_Clear_released();

signals:
    void signal_BufferNameChanged(const std::string &name);

    void signal_BufferUpdatedLineCount(const int &count);

    void signal_BufferCurrent(const bool &current);

private:
    Ui::Widget_BufferEditor *ui;

    SPIIMotionController* m_SPIIDevice;

    BufferData* m_EditData; //! Holds the data that we know is previous in the ACS

    bool lockBufferName = false;

    int previousLineCount = -1;
};

#endif // WIDGET_BUFFER_EDITOR_H
