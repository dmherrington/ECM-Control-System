#include "window_profile_configuration.h"
#include "ui_window_profile_configuration.h"

Window_ProfileConfiguration::Window_ProfileConfiguration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_ProfileConfiguration)
{
    ui->setupUi(this);
}

Window_ProfileConfiguration::~Window_ProfileConfiguration()
{
    delete ui;
}
