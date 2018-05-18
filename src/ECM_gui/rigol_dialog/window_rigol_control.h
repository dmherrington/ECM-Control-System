#ifndef WINDOW_RIGOL_CONTROL_H
#define WINDOW_RIGOL_CONTROL_H

#include <QMainWindow>
#include "ui_window_rigol_control.h"
#include "widget_rigol_radio.h"

#include "library_rigol_oscilloscope/rigol_oscilliscope.h"

namespace Ui {
class Window_RigolControl;
}

class Window_RigolControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_RigolControl(RigolOscilliscope* obj, QWidget *parent = 0);
    ~Window_RigolControl();

    bool isWindowHidden() const;

protected:
    void readSettings();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

signals:
    void signal_onRigolWindowChanged(const bool &visible);

private slots:
    void slot_OscilliscopeConnectionUpdate(const common::comms::CommunicationConnection &value);

    void slot_onRadioButtonChange(const data_Rigol::MeasurementTypes &measurement, const bool &checked);

    void slot_onLoadComplete();

private slots:
    void on_pushButton_Done_released();

    void on_comboBox_Channel_currentIndexChanged(const QString &arg1);

    void on_actionClose_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_triggered();

private:
    QString loadFileDialog(const std::string &filePath, const std::string &suffix);
    QString saveAsFileDialog(const std::string &filePath, const std::string &suffix);
    void getSettingsPath(std::string &filePath) const;

private:
    Ui::Window_RigolControl *ui;
    RigolOscilliscope* m_Rigol;
    bool windowHidden = true;

    bool previouslyLoad = false;
    QString loggingPath;
    QString previousSettingsPath;
    QString currentSettingsPath;
};

#endif // WINDOW_RIGOL_CONTROL_H
