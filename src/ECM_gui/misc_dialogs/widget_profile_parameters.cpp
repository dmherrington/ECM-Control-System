#include "widget_profile_parameters.h"
#include "ui_widget_profile_parameters.h"

Widget_ProfileParameters::Widget_ProfileParameters(ECM_API *apiObject, QWidget *parent) :
    QWidget(parent),
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
    delete ui;
}

void Widget_ProfileParameters::setTabIndex(const unsigned int &index)
{
    this->tabIndex = index;
}

unsigned int Widget_ProfileParameters::getTabIndex() const
{
    return this->tabIndex;
}

void Widget_ProfileParameters::writeToJSON(QJsonObject &object)
{
    m_ScriptingVariables->writeToJSON(object);
    m_MCTouchoff->writeToJSON(object);
    m_PowerSupply->writeToJSON(object);
    m_PumpControl->writeToJSON(object);
}

void Widget_ProfileParameters::readFromJSON(const QJsonObject &obj)
{
    m_ScriptingVariables->readFromJSON(obj);
    m_MCTouchoff->readFromJSON(obj);
    m_PowerSupply->readFromJSON(obj);
    m_PumpControl->readFromJSON(obj);
}
