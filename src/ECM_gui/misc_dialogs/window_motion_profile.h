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
    explicit Window_MotionProfile(GalilMotionController* galilObj, QWidget *parent = 0);
    ~Window_MotionProfile();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility) override;

public:
    void setFilePath(const std::string &path);

    void setProgramText(const std::string &programText);

public:
    void openGalilScript();
    void uploadGalilScript();
    void downloadGalilScript();
    std::string getCurrentGalilScript() const;

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

    void updateStatusLED(const QColor &color);

private slots:
    void on_actionClose_triggered();

    void on_actionOpen_triggered();

private slots:
    void on_codeTextEdit_textChanged();

    void on_pushButton_UploadProgram_released();

    void on_pushButton_DownloadProgram_released();


    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::Window_MotionProfile *ui;
    SPIIMotionController* m_MotionController;
    bool windowHidden = true;
};

#endif // WINDOW_MOTION_PROFILE_H
