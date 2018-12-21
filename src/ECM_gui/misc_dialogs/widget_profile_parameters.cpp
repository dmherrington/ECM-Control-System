#include "widget_profile_parameters.h"
#include "ui_widget_profile_parameters.h"

Widget_ProfileParameters::Widget_ProfileParameters(ECM_API *apiObject, QWidget *parent) :
    Widget_AbstractProfile(ProfileOpType::OPERATION,0,parent),
    ui(new Ui::Widget_ProfileParameters)
{
    ui->setupUi(this);

    m_ScriptingVariables = new Widget_ScriptingVariables(apiObject->m_Galil);
    ui->frame_ScriptingVariables->layout()->addWidget(m_ScriptingVariables);

    m_MCTouchoff = new Widget_Touchoff(apiObject->m_Galil);
    ui->frame_Touchoff->layout()->addWidget(m_MCTouchoff);

    m_PumpControl = new Widget_PumpControl(apiObject->m_Pump);
    ui->frame_Pump->layout()->addWidget(m_PumpControl);

    m_PowerSupply = new Widget_MunkPowerSupply(apiObject->m_Munk);
    ui->frame_PowerSupply->layout()->addWidget(m_PowerSupply);

}

Widget_ProfileParameters::~Widget_ProfileParameters()
{
    delete m_ScriptingVariables;
    delete m_MCTouchoff;
    delete m_PumpControl;
    delete m_PowerSupply;

    delete ui;
}

ECMCommand_AbstractProfileConfigPtr Widget_ProfileParameters::getCurrentProfileConfiguration() const
{
    ECMCommand_ProfileConfigurationPtr currentConfiguration = std::make_shared<ECMCommand_ProfileConfiguration>();
    currentConfiguration->m_GalilOperation.fromProgram(this->m_ScriptingVariables->getDesiredProgram());
    currentConfiguration->m_GalilOperation.setProfileName(this->m_ScriptingVariables->getProfileName());

    currentConfiguration->m_Touchoff = this->m_MCTouchoff->getCurrentTouchoffConfig();

    currentConfiguration->m_ConfigPowerSupply.m_MunkPulseMode = this->m_PowerSupply->getPulseModeRegister();
    currentConfiguration->m_ConfigPowerSupply.m_MunkSegment = this->m_PowerSupply->getSegmentRegister();

    currentConfiguration->m_PumpParameters = this->m_PumpControl->getPumpProperties();

    return currentConfiguration;
}

void Widget_ProfileParameters::loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config)
{
    ECMCommand_ProfileConfigurationPtr castConfiguration = static_pointer_cast<ECMCommand_ProfileConfiguration>(config);

    this->m_MCTouchoff->loadFromTouchoffConfig(castConfiguration->m_Touchoff);
    this->m_PumpControl->loadFromPumpProperties(castConfiguration->m_PumpParameters);
    this->m_PowerSupply->loadFromConfig(castConfiguration->m_ConfigPowerSupply);
    this->m_ScriptingVariables->loadFromCurrentProgram(castConfiguration->m_GalilOperation, castConfiguration->getProfileName());
}


