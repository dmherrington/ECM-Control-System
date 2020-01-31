#ifndef WIDGET_PROFILE_PARAMETERS_H
#define WIDGET_PROFILE_PARAMETERS_H

#include <QWidget>

#include "ECM_API/ecm_api.h"

#include "acs_dialog/widget_scripting_variables.h"
#include "acs_dialog/widget_touchoff.h"
#include "pump_dialog/widget_pump_control.h"
#include "munk_dialog/widget_munk_power_supply.h"

#include "widget_abstract_profile.h"

namespace Ui {
class Widget_ProfileParameters;
}

class Widget_ProfileParameters : public Widget_AbstractProfile
{

public:
    explicit Widget_ProfileParameters(ECM_API* apiObject, QWidget *parent = 0);

    ~Widget_ProfileParameters();

public:
    ECMCommand_AbstractProfileConfigPtr getCurrentProfileConfiguration() const override;

    void loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config) override;

public:
    void setExpandedMunkDriverModes(const bool &expandModes);

private:
    Ui::Widget_ProfileParameters *ui;

public:
    Widget_ScriptingVariables* m_ScriptingVariables;
    Widget_Touchoff* m_MCTouchoff;
    Widget_PumpControl* m_PumpControl;
    Widget_MunkPowerSupply* m_PowerSupply;
};

#endif // WIDGET_PROFILE_PARAMETERS_H
