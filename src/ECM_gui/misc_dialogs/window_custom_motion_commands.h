#ifndef WINDOW_CUSTOM_MOTION_COMMANDS_H
#define WINDOW_CUSTOM_MOTION_COMMANDS_H

#include <QMainWindow>

#include "../general_dialog_window.h"

#include "library_galilMotionController/galil_motion_controller.h"

namespace Ui {
class Window_CustomMotionCommands;
}

class Window_CustomMotionCommands : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_CustomMotionCommands(GalilMotionController* obj, QWidget *parent = 0);
    ~Window_CustomMotionCommands();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private slots:
    void on_actionClose_triggered();

    void on_pushButton_TransmitMotionCommand_released();

    void slot_onMotionResponseReceived(const std::string &commandText, const std::string &text);

    void slot_ShowRepsonseTextEditContextMenu(const QPoint &pos);

    void slot_ClearResponseTextEdit();

private:
    Ui::Window_CustomMotionCommands *ui;
    GalilMotionController* m_MotionController;
    bool windowHidden = true;
};
#endif // WINDOW_CUSTOM_MOTION_COMMANDS_H
