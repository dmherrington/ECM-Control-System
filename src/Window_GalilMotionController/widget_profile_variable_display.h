#ifndef WIDGET_PROFILE_VARIABLE_DISPLAY_H
#define WIDGET_PROFILE_VARIABLE_DISPLAY_H

#include <QWidget>

#include "library_galilMotionController/settings/settings_profile_variable.h"

namespace Ui {
class WidgetProfileVariableDisplay;
}

class WidgetProfileVariableDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetProfileVariableDisplay(QWidget *parent = 0);
    ~WidgetProfileVariableDisplay();

    void loadProfileVariable(const SettingsProfileVariable variable);

private slots:
    void on_doubleSpinBox_desiredValue_editingFinished();

private:
    Ui::WidgetProfileVariableDisplay *ui;
    double currentValue;

};

#endif // WIDGET_PROFILE_VARIABLE_DISPLAY_H
