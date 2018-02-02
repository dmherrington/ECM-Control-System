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
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Private SLOTS related to events triggered from the munk library
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void slot_ConnectionStatusUpdate(const bool &open_close);

    void slot_CommunicationError(const std::string &type, const std::string &msg);

    void slot_CommunicationUpdate(const std::string &name, const std::string &msg);

    void slot_SegmentSetAck(const std::string &msg);

    void slot_SegmentException(const std::string &RW, const std::string &meaning);

    void slot_FaultCodeRecieved(const int &regNum, const std::string &msg);

    void slot_WriteProgressUpdated(const int &completed, const int &required);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Private SLOTS related to actions triggered directly from the GUI
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void widgetSegmentDisplay_dataUpdate(const std::list<DataParameter::SegmentTimeDataDetailed> &newData);

    void on_pushButton_AddSegment_released();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_Connection_triggered();

    void on_actionClose_Connection_triggered();

    void on_actionTransmit_To_Munk_triggered();

    void onGraphLegend();

    void on_pushButton_transmit_released();

    void on_actionExit_triggered();

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

    bool segmentUnlocked = false;
};

#endif // MAIN_WINDOW_H
