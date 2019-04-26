#ifndef WINDOW_BUFFER_MANAGER_H
#define WINDOW_BUFFER_MANAGER_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QMessageBox>

#include "widget_buffer_descriptor.h"

#include "../general_dialog_window.h"

#include "library_SPIIMotionController/spii_motion_controller.h"
#include "library_SPIIMotionController/buffers/spii_prg_handle.h"

namespace Ui {
class Window_BufferManager;
}

class Window_BufferManager : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_BufferManager(SPIIMotionController* motionControlObject, QWidget *parent = nullptr);
    ~Window_BufferManager() override;

private:
    void closeEvent(QCloseEvent *event) override;

public:
    bool isDisplayCurrentAndCompiled() const;

    void setInitialBufferCount(const unsigned int &count, const unsigned int &dBuffer);

    SPII_CurrentProgram getDesiredBufferContents() const;

    void loadBufferContents(const SPII_CurrentProgram &desiredBufferContents);

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility) override;

private:

    void clearBufferData();

    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private slots:
    void slot_OnMCCommunicationUpdate(const common::comms::CommunicationUpdate &update);
    void slot_OnDisplayBufferContents(const unsigned int &index);

    void slot_MCBufferStatusUpdate(const Status_BufferState &state);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_pushButton_Sync_released();

private:
    Ui::Window_BufferManager *ui;

    SPIIMotionController* m_SPIIDevice;

    std::map<unsigned int, Widget_BufferDescriptor*> m_BufferDescriptors;
};

#endif // WINDOW_BUFFER_MANAGER_H
