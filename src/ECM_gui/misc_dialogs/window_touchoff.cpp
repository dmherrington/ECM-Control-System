#include "window_touchoff.h"
#include "ui_window_touchoff.h"

Window_Touchoff::Window_Touchoff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_Touchoff)
{
    ui->setupUi(this);
}

Window_Touchoff::~Window_Touchoff()
{
    delete ui;
}
