#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QByteArray>
#include <QString>
#include <QtDebug>
#include <iostream>
#include <QMainWindow>
#include <vector>

typedef unsigned int WORD;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    WORD CRC16(const int &cnt);

private:
    Ui::MainWindow *ui;
    char Buffer[128];
};

#endif // MAINWINDOW_H
