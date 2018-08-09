#ifndef DIALOG_CUSTOM_COMMANDS_H
#define DIALOG_CUSTOM_COMMANDS_H

#include <QDialog>

#include "../general_dialog_window.h"

namespace Ui {
class Dialog_CustomCommands;
}

class Dialog_CustomCommands : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Dialog_CustomCommands(GalilMotionController* obj, QWidget *parent = 0);
    ~Dialog_CustomCommands();

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
    Ui::Dialog_CustomCommands *ui;
    GalilMotionController* m_MotionController;
    bool windowHidden = true;
};

#endif // DIALOG_CUSTOM_COMMANDS_H
