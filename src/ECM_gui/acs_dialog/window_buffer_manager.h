#ifndef WINDOW_BUFFER_MANAGER_H
#define WINDOW_BUFFER_MANAGER_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>

#include "widget_buffer_descriptor.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Window_BufferManager;
}

class Window_BufferManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_BufferManager(SPIIMotionController* motionControlObject, QWidget *parent = nullptr);
    ~Window_BufferManager();

public:
    void setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer);

private slots:
    void slot_OnMCCommunicationUpdate(const common::comms::CommunicationUpdate &update);
    void slot_OnDisplayBufferContents(const unsigned int &index);

    void slot_MCBufferStatusUpdate(const Status_BufferState &state);
private:
    Ui::Window_BufferManager *ui;

    SPIIMotionController* m_SPIIDevice;

    std::map<unsigned int, Widget_BufferDescriptor*> m_BufferDescriptors;
};

#endif // WINDOW_BUFFER_MANAGER_H
