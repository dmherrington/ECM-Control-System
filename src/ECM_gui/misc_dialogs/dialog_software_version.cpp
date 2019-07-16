#include "dialog_software_version.h"
#include "ui_dialog_software_version.h"

Dialog_SoftwareVersion::Dialog_SoftwareVersion(const std::map<std::string, std::string> &swMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SoftwareVersion)
{
    ui->setupUi(this);

    std::map<std::string,std::string>::const_iterator versionIt = swMap.begin();

    for(;versionIt != swMap.end(); ++versionIt)
    {
        Widget_SofwareVersioning* Widget_SWVersion = new Widget_SofwareVersioning(versionIt->first,versionIt->second);
        ui->verticalLayout_SWMap->addWidget(Widget_SWVersion); //this will not cause a memory leak as the add widget manages ownership of the object
    }
}

Dialog_SoftwareVersion::~Dialog_SoftwareVersion()
{
    delete ui;
}
