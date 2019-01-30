#ifndef WIDGET_VARIABLE_VALUE_H
#define WIDGET_VARIABLE_VALUE_H

#include <QWidget>

namespace Ui {
class Widget_VariableValue;
}

class Widget_VariableValue : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_VariableValue(QWidget *parent = 0);
    ~Widget_VariableValue();

private:
    Ui::Widget_VariableValue *ui;
};

#endif // WIDGET_VARIABLE_VALUE_H
