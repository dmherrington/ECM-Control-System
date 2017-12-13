#ifndef WIDGET_VARIABLE_DATA_DISPLAY_H
#define WIDGET_VARIABLE_DATA_DISPLAY_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

#include <iostream>

#include "widget_variable_data.h"

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

public:
    void read(const QJsonArray &jsonArray);
    void write(QJsonObject &json) const;

public:
    WidgetVariableData* addNewVariable();

signals:
    void signal_updatedProfileName(std::string &name);

private slots:
    void removeVariableWidget(WidgetVariableData* obj);

    void on_lineEdit_profileName_editingFinished();

    void on_pushButton_addVariable_clicked();

    void on_dataChanged();

private:
    Ui::WidgetVariableDataDisplay *ui;

private:
    std::string profileName = "Default";
    bool _hasDataChanged = false;
    std::vector<WidgetVariableData*> vectorData;

};

#endif // WIDGET_VARIABLE_DATA_DISPLAY_H
