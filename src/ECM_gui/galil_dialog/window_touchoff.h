#ifndef WINDOW_TOUCHOFF_H
#define WINDOW_TOUCHOFF_H

#include <QMainWindow>

#include "../general_dialog_window.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Window_Touchoff;
}

class Window_Touchoff : public GeneralDialogWindow
{
    Q_OBJECT

public:
    explicit Window_Touchoff(GalilMotionController* obj, QWidget *parent = 0);
    ~Window_Touchoff();

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes &type, const bool &visibility);

private:
    void saveToFile(const QString &filePath);

    void openFromFile(const QString &filePath);

private slots:
    void on_actionClose_triggered();

    void on_pushButton_ExecuteTouchoff_released();

    void on_pushButton_TouchoffRef_released();

    void slot_UpdateMotionProfileState(const MotionProfileState &state);

    void on_pushButton_TouchoffGap_released();

    void on_doubleSpinBox_TouchoffRef_valueChanged(double arg1);

    void on_doubleSpinBox_InitialGap_valueChanged(double arg1);

private:
    Ui::Window_Touchoff *ui;
    GalilMotionController* m_MotionController;
};

#endif // WINDOW_TOUCHOFF_H
