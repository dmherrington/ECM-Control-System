/********************************************************************************
** Form generated from reading UI file 'window_motion_profile.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MOTION_PROFILE_H
#define UI_WINDOW_MOTION_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_MotionProfile
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_MotionProfile)
    {
        if (Window_MotionProfile->objectName().isEmpty())
            Window_MotionProfile->setObjectName(QStringLiteral("Window_MotionProfile"));
        Window_MotionProfile->resize(800, 600);
        menubar = new QMenuBar(Window_MotionProfile);
        menubar->setObjectName(QStringLiteral("menubar"));
        Window_MotionProfile->setMenuBar(menubar);
        centralwidget = new QWidget(Window_MotionProfile);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Window_MotionProfile->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Window_MotionProfile);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_MotionProfile->setStatusBar(statusbar);

        retranslateUi(Window_MotionProfile);

        QMetaObject::connectSlotsByName(Window_MotionProfile);
    } // setupUi

    void retranslateUi(QMainWindow *Window_MotionProfile)
    {
        Window_MotionProfile->setWindowTitle(QApplication::translate("Window_MotionProfile", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_MotionProfile: public Ui_Window_MotionProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MOTION_PROFILE_H
