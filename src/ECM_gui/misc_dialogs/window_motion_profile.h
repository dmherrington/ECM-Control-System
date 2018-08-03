#ifndef WINDOW_MOTION_PROFILE_H
#define WINDOW_MOTION_PROFILE_H

#include <QMainWindow>

#include "../general_dialog_window.h"

#include "code_edit_widget.h"

#include "library_galilMotionController/galil_motion_controller.h"

namespace Ui {
class Window_MotionProfile;
}

class Window_MotionProfile : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_MotionProfile(GalilMotionController* obj, QWidget *parent = 0);
    ~Window_MotionProfile();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private slots:
    void on_actionClose_triggered();

    void slot_MCNewProgramAvailable(const ProgramGeneric &program);

    void on_codeTextEdit_textChanged();

    void on_pushButton_UploadProgram_released();

    void on_pushButton_DownloadProgram_released();

private:
    Ui::Window_MotionProfile *ui;
    GalilMotionController* m_MotionController;
    bool windowHidden = true;
};

#endif // WINDOW_MOTION_PROFILE_H
