#ifndef WIDGET_ABSTRACT_AXIS_CONTROL_H
#define WIDGET_ABSTRACT_AXIS_CONTROL_H

#include <QWidget>

class Widget_AbstractAxisControl {

public:
    explicit Widget_AbstractAxisControl() = default;
    virtual ~Widget_AbstractAxisControl() = default;

public:

    virtual void lockAllMotionButtons(const bool &shouldLock) = 0;
    virtual void lockRelativeMove(const bool &shouldLock) = 0;
    virtual void lockJogMove(const bool &shouldLock) = 0;
};

#endif // WIDGET_ABSTRACT_AXIS_CONTROL_H
