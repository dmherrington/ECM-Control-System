#ifndef WINDOW_TOUCHOFF_H
#define WINDOW_TOUCHOFF_H

#include <QMainWindow>

#include "../general_dialog_window.h"

#include "common/commands/command_components.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Window_Touchoff;
}

class Window_Touchoff : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_Touchoff(SPIIMotionController* obj, QWidget *parent = 0);
    ~Window_Touchoff();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private:
    void transmitTouchoffReference();

    void transmitTouchoffGap();


private slots:
    void slot_UpdateMotionProfileState(const MotionProfileState &state);

private slots:
    void on_actionClose_triggered();

    void on_pushButton_ExecuteTouchoff_released();

    void on_pushButton_TouchoffRef_released();

    void on_pushButton_TouchoffGap_released();

    void on_doubleSpinBox_TouchoffRefX_editingFinished();

    void on_doubleSpinBox_TouchoffRefY_editingFinished();

    void on_doubleSpinBox_TouchoffRefZ_editingFinished();

    void on_doubleSpinBox_InitialGapX_editingFinished();

    void on_doubleSpinBox_InitialGapY_editingFinished();

    void on_doubleSpinBox_InitialGapZ_editingFinished();

private:
    Ui::Window_Touchoff *ui;
    SPIIMotionController* m_MotionController;
};

#endif // WINDOW_TOUCHOFF_H
