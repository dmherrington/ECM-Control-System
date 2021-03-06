#ifndef WIDGET_SCRIPTING_VARIABLES_H
#define WIDGET_SCRIPTING_VARIABLES_H

#include <QWidget>

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

    void loadFromCurrentProgram(const GalilCurrentProgram &program, const std::string &profileName = "", const bool &useLoadedVars = true);

    std::string getProfileName() const;

    BufferManager getDesiredProgram() const;

    ProgramVariableList getVariableList() const;

public:
    void setProfileName(const std::string &name);

    void updateProgramLabels(const ProgramLabelList &list);

    void updateProgramVariables(const ProgramVariableList &list);

private slots:

    void on_doubleSpinBox_CutDepth_editingFinished();

    void on_doubleSpinBox_RetractDistance_editingFinished();

    void on_doubleSpinBox_StepSize_editingFinished();

    void on_spinBox_RetractSpeed_editingFinished();

    void on_spinBox_PlungeSpeed_editingFinished();

    void on_doubleSpinBox_CutSpeed_editingFinished();

    void on_spinBox_RetractPeriod_editingFinished();

    void on_spinBox_Pause_editingFinished();


private:
    Ui::Widget_ScriptingVariables *ui;

    SPIIMotionController* m_Galil;

    GalilCurrentProgram m_OperationalProgram;
};

#endif // WIDGET_SCRIPTING_VARIABLES_H
