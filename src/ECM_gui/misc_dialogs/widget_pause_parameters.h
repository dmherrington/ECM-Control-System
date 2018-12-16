#ifndef WIDGET_PAUSE_PARAMETERS_H
#define WIDGET_PAUSE_PARAMETERS_H

#include <QWidget>

#include "ECM_API/ecm_api.h"

#include "widget_abstract_profile.h"

namespace Ui {
class Widget_PauseParameters;
}

class Widget_PauseParameters : public Widget_AbstractProfile
{

public:
    explicit Widget_PauseParameters(QWidget *parent = 0);

    ~Widget_PauseParameters();

public:
    ECMCommand_AbstractProfileConfigPtr getCurrentProfileConfiguration() const override;

    void loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config) override;

private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_finite_toggled(bool checked);

    void on_radioButton_infinite_toggled(bool checked);

private:
    Ui::Widget_PauseParameters *ui;
};

#endif // WIDGET_PAUSE_PARAMETERS_H
