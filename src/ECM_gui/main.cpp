#include "ECM_controller_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ECMControllerGUI w;
    w.show();
    return a.exec();
}
