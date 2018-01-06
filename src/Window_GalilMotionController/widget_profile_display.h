#ifndef WIDGET_PROFILE_DISPLAY_H
#define WIDGET_PROFILE_DISPLAY_H

#include <QWidget>

#include <widget_profile_variable_display.h>

#include "library_galilMotionController/settings/settings_generic_profile.h"

namespace Ui {
class WidgetProfileDisplay;
}

class WidgetProfileDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetProfileDisplay(QWidget *parent = 0);
    ~WidgetProfileDisplay();

    void loadProfile(const SettingsGenericProfile* profile);

private:
    Ui::WidgetProfileDisplay *ui;
    SettingsGenericProfile* settingsProfile;
};

#endif // WIDGET_PROFILE_DISPLAY_H
