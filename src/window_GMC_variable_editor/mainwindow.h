#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include <cstddef>

#include "widget_variable_data_display.h"

#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QString saveAsFileDialog(const std::string &filePath, const std::string &suffix);
    QString loadFileDialog(const std::string &filePath, const std::string &suffix);
    QString getSettingsPath();
    void saveSettings();


private slots:

    void on_pushButton_AddMotionProfile_clicked();

    void on_pushButton_RemoveMotionProfile_clicked();

    void slot_updatedProfileName(std::string &name);

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    QString settingsPath;
    std::map<std::string, WidgetVariableDataDisplay*> mapData;
};

#endif // MAINWINDOW_H
