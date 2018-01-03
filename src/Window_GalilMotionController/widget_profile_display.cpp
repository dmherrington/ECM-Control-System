#include "widget_profile_display.h"
#include "ui_widgetprofiledisplay.h"

WidgetProfileDisplay::WidgetProfileDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetProfileDisplay)
{
    ui->setupUi(this);
}

WidgetProfileDisplay::~WidgetProfileDisplay()
{
    delete ui;
}
