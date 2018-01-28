#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QtSerialPort>
#include <QDialog>

#include <iostream>

#include "qcustomplot.h"

#include "library_munk_power_supply/munk_power_supply.h"
#include "widget_segment_time_data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_released();

    void widgetSegmentDisplay_dataUpdate(const std::list<DataParameter::SegmentTimeDataDetailed> &newData);

    void slot_SerialPortStatus(const bool &open_close, const std::string &errorString);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Private SLOTS related to events triggered from the munk library
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void slot_ConnectionStatusUpdate(const bool &open_close);

    void slot_CommunicationError();

    void slot_CommunicationUpdate();

    void slot_SegmentSetAck();

    void slot_SegmentException();

    void slot_FaultCodeRecieved();


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Private SLOTS related to actions triggered directly from the GUI
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_Connection_triggered();

    void on_actionClose_Connection_triggered();

    void on_actionTransmit_To_Munk_triggered();

    void onGraphLegend();

private:
    QString saveAsFileDialog(const std::string &filePath, const std::string &suffix);
    QString loadFileDialog(const std::string &filePath, const std::string &suffix);
    QString getMunkSegmentsPath();
    void saveSettings(const QString &path);
    void loadMunkPowerSegment(const QString &path);

private:
    QString munkSegmentsPath;
    QString munkCurrentFile;

    Ui::MainWindow *ui;

    MunkPowerSupply *m_PowerSupply;

    QString m_FilePath;
};

#endif // MAIN_WINDOW_H
