#ifndef WIDGET_VARIABLE_DESCRIPTOR_H
#define WIDGET_VARIABLE_DESCRIPTOR_H

#include <QWidget>

#include "common/common.h"

namespace Ui {
class Widget_VariableDescriptor;
}

class Widget_VariableDescriptor : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_VariableDescriptor(const std::string &name, const double &value, QWidget *parent = nullptr);
    ~Widget_VariableDescriptor();

    void setVariableValue(const double &value);

    std::string getVariableName() const;

    void getVariableProperties(std::string &name, double &value) const;

signals:
    void signal_UpdatedVariableValue(const std::string name, const double &value);

private slots:
    void on_doubleSpinBox_VariableValue_valueChanged(double arg1);

private:
    Ui::Widget_VariableDescriptor *ui;

    std::string variableName;
};

#endif // WIDGET_VARIABLE_DESCRIPTOR_H
