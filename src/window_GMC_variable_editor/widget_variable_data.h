#ifndef WIDGET_VARIABLE_DATA_H
#define WIDGET_VARIABLE_DATA_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

#include "library_galilMotionController/programs/program_profile_variable.h"

namespace Ui {
class WidgetVariableData;
}

class WidgetVariableData : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVariableData(QWidget *parent = 0);
    ~WidgetVariableData();

public:
    void read(const QJsonObject &jsonObject);
    void write(QJsonArray &jsonArray) const;
    void setVariableData(const ProgramProfileVariable &data);
    ProgramProfileVariable getProfileVariable() const;

public:

    void updateDisplayValues();
public:
    std::string getDisplayName() const;
    std::string getVariableName() const;
    double getDefaultValue() const;
    double getMaxValue() const;
    double getMinValue() const;

    void setDisplayName(const std::string &name);
    void setVariableName(const std::string &name);
    void setDefaultValue(const double &value);
    void setMaxValue(const double &value);
    void setMinValue(const double &value);

signals:
    void signalRemoveWidget(WidgetVariableData* var);
    void signalDataChanged();

private slots:
    void on_pushButton_removeVariable_clicked();

    void on_lineEdit_displayName_editingFinished();

    void on_lineEdit_varName_editingFinished();

    void on_doubleSpinBox_max_editingFinished();

    void on_doubleSpinBox_min_editingFinished();

    void on_doubleSpinBox_default_editingFinished();

private:
    Ui::WidgetVariableData *ui;

private:
    ProgramProfileVariable* variable;

};

#endif // WIDGET_VARIABLE_DATA_H
