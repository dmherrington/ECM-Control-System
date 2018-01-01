#ifndef WIDGET_VARIABLE_DATA_DISPLAY_H
#define WIDGET_VARIABLE_DATA_DISPLAY_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

#include <iostream>

#include "widget_variable_data.h"
#include "library_galilMotionController/settings/settings_generic_profile.h"

namespace Ui {
class WidgetVariableDataDisplay;
}

class WidgetVariableDataDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVariableDataDisplay(QWidget *parent = 0);
    ~WidgetVariableDataDisplay();

public:
    std::string getProfileName() const;
    void setProfileName(const std::string &name);

    void setDataChanged(const bool &changed);
    bool hasDataChanged();

    SettingsGenericProfile getProfile() const;

public:
    void read(const QJsonArray &jsonArray);
    void write(QJsonObject &json) const;
    void updateProfile(const SettingsGenericProfile &data);

public:
    WidgetVariableData* addNewVariable();

    std::vector<std::string> getDisplayNames() const;
    std::vector<std::string> getVariableNames() const;

private:
    void updateRendering();

signals:
    void signal_updatedProfileName(std::string &name);

private slots:
    void removeVariableWidget(WidgetVariableData* obj);

    void on_lineEdit_profileName_editingFinished();

    void on_lineEdit_profileLabel_editingFinished();

    void on_pushButton_addVariable_clicked();

    void on_dataChanged();

    void on_doubleSpinBox_PGain_editingFinished();

    void on_doubleSpinBox_IGain_editingFinished();

    void on_doubleSpinBox_DGain_editingFinished();


private:
    Ui::WidgetVariableDataDisplay *ui;

private:
    SettingsGenericProfile* profile;

    bool _hasDataChanged = false;
    std::vector<WidgetVariableData*> vectorData;

};

#endif // WIDGET_VARIABLE_DATA_DISPLAY_H
