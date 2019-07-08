#ifndef WIDGET_SCRIPTING_VARIABLES_H
#define WIDGET_SCRIPTING_VARIABLES_H

#include <QWidget>

#include "widget_variable_descriptor.h"

#include "library_SPIIMotionController/spii_motion_controller.h"

namespace Ui {
class Widget_ScriptingVariables;
}

class Widget_ScriptingVariables : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_ScriptingVariables(SPIIMotionController* motionControllerObject, QWidget *parent = 0);

    ~Widget_ScriptingVariables();

public:

    void loadFromProfileConfiguration(const Operation_VariableList &vars, const std::string &profileName = "");

    void loadFromCurrentProgram(const Operation_LabelList &labels, const Operation_VariableList &vars, const std::string &profileName = "", const bool &useLoadedVars = true);

    std::string getProfileName() const;

    Operation_VariableList getVariableList() const;

public:
    void setProfileName(const std::string &name);

    void updateProgramLabels(const Operation_LabelList &list);

    void updateProgramVariables(const Operation_VariableList &list, const bool &restoreVariables = true);

private:
    void clearVariableTable();

private slots:

    void slot_onNewlyAvailableLabels(const Operation_LabelList &labels);

    void slot_onNewlyAvailableUserVariables(const Operation_VariableList &vars);

private:
    Ui::Widget_ScriptingVariables *ui;

    SPIIMotionController* m_MotionController;

    std::map<std::string, Widget_VariableDescriptor*> m_VariableDescriptors;

    Operation_VariableList m_ConfiguredVariables;
};

#endif // WIDGET_SCRIPTING_VARIABLES_H
