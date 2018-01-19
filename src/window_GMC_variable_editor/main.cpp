#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    MainWindow w;
    w.setWindowTitle(QString::fromStdString("Configure Galil Variables"));
    w.show();

    return a.exec();
}
