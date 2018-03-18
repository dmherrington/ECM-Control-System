#include "window_touchoff.h"
#include "ui_window_touchoff.h"

Window_Touchoff::Window_Touchoff(GalilMotionController *obj, QWidget *parent) :
    QMainWindow(parent),
    m_MotionController(obj),
    ui(new Ui::Window_Touchoff)
{
    ui->setupUi(this);
}

Window_Touchoff::~Window_Touchoff()
{
    delete ui;
}

bool Window_Touchoff::isWindowHidden() const
{
    return windowHidden;
}

void Window_Touchoff::readSettings()
{
    QSettings settings("Touchoff Window", "ECM Application");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void Window_Touchoff::closeEvent(QCloseEvent *event)
{
    QSettings settings("Touchoff Window", "ECM Application");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void Window_Touchoff::hideEvent(QHideEvent *event)
{
    windowHidden = true;
}

void Window_Touchoff::showEvent(QShowEvent *event)
{
    windowHidden = false;
}

void Window_Touchoff::on_actionClose_triggered()
{
    this->hide();
}
