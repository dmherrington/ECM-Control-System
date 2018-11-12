#ifndef WIDGET_PROFILE_PARAMETERS_H
#define WIDGET_PROFILE_PARAMETERS_H

#include <QWidget>

#include "ECM_API/ecm_api.h"

#include "galil_dialog/widget_scripting_variables.h"
#include "galil_dialog/widget_touchoff.h"
#include "pump_dialog/widget_pump_control.h"
#include "munk_dialog/widget_munk_power_supply.h"

namespace Ui {
class Widget_ProfileParameters;
}

class Widget_ProfileParameters : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_ProfileParameters(ECM_API* apiObject, QWidget *parent = 0);
    ~Widget_ProfileParameters();

public:
    void setTabIndex(const unsigned int &index);

    unsigned int getTabIndex() const;

private:
    Ui::Widget_ProfileParameters *ui;

    Widget_ScriptingVariables* m_ScriptingVariables;
    Widget_Touchoff* m_MCTouchoff;
    Widget_PumpControl* m_PumpControl;
    Widget_MunkPowerSupply* m_PowerSupply;

    unsigned int tabIndex = 0;
};

#endif // WIDGET_PROFILE_PARAMETERS_H
