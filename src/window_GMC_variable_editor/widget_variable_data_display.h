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

public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    void addNewVariable();

signals:
    void signal_updatedProfileName(std::string &name);

private slots:
    void removeVariableWidget(WidgetVariableData* obj);

    void on_lineEdit_profileName_editingFinished();

    void on_pushButton_addVariable_clicked();

private:
    Ui::WidgetVariableDataDisplay *ui;

private:
    std::string profileName = "Default";

    std::vector<WidgetVariableData*> vectorData;

};

#endif // WIDGET_VARIABLE_DATA_DISPLAY_H
