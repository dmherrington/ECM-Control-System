#include "widget_sofware_versioning.h"
#include "ui_widget_sofware_versioning.h"

Widget_SofwareVersioning::Widget_SofwareVersioning(const std::string &libraryName, const std::string &versionNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_SofwareVersioning)
{
    ui->setupUi(this);
    ui->label_libraryName->setText(QString::fromStdString(libraryName));
    ui->lineEdit_version->setText(QString::fromStdString(versionNumber));
}

Widget_SofwareVersioning::~Widget_SofwareVersioning()
{
    delete ui;
}
