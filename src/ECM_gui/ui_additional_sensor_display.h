/********************************************************************************
** Form generated from reading UI file 'additional_sensor_display.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITIONAL_SENSOR_DISPLAY_H
#define UI_ADDITIONAL_SENSOR_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdditionalSensorDisplay
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdditionalSensorDisplay)
    {
        if (AdditionalSensorDisplay->objectName().isEmpty())
            AdditionalSensorDisplay->setObjectName(QStringLiteral("AdditionalSensorDisplay"));
        AdditionalSensorDisplay->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdditionalSensorDisplay->sizePolicy().hasHeightForWidth());
        AdditionalSensorDisplay->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(AdditionalSensorDisplay);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        AdditionalSensorDisplay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdditionalSensorDisplay);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        AdditionalSensorDisplay->setMenuBar(menubar);
        statusbar = new QStatusBar(AdditionalSensorDisplay);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdditionalSensorDisplay->setStatusBar(statusbar);

        menubar->addAction(menuView->menuAction());

        retranslateUi(AdditionalSensorDisplay);

        QMetaObject::connectSlotsByName(AdditionalSensorDisplay);
    } // setupUi

    void retranslateUi(QMainWindow *AdditionalSensorDisplay)
    {
        AdditionalSensorDisplay->setWindowTitle(QApplication::translate("AdditionalSensorDisplay", "MainWindow", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("AdditionalSensorDisplay", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdditionalSensorDisplay: public Ui_AdditionalSensorDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITIONAL_SENSOR_DISPLAY_H
