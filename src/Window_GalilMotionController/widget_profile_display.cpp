#include "widget_profile_display.h"
#include "ui_widget_profile_display.h"

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

void WidgetProfileDisplay::loadProfile(const ProgramGenericProfile &profile)
{
    this->ui->doubleSpinBox_PGain->setValue(profile.profileGain->getGainValue(GainType::PGain));
    this->ui->doubleSpinBox_IGain->setValue(profile.profileGain->getGainValue(GainType::IGain));
    this->ui->doubleSpinBox_DGain->setValue(profile.profileGain->getGainValue(GainType::DGain));

    std::map<std::string,ProgramProfileVariable> profileVariables = profile.getVariableMap();
    std::map<std::string,ProgramProfileVariable>::const_iterator it;
    for(it = profileVariables.begin(); it != profileVariables.end(); ++it)
    {
        WidgetProfileVariableDisplay* variable = new WidgetProfileVariableDisplay();
        variable->loadProfileVariable(it->second);
        this->ui->verticalLayout_Variables->addWidget(variable);
    }
    this->ui->verticalLayout_Variables->addStretch();
    //QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    //this->ui->verticalLayout_Variables->addItem(spacer);
    this->adjustSize();
}
