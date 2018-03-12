/********************************************************************************
** Form generated from reading UI file 'ECM_controller_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECM_CONTROLLER_GUI_H
#define UI_ECM_CONTROLLER_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECMControllerGUI
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECMControllerGUI)
    {
        if (ECMControllerGUI->objectName().isEmpty())
            ECMControllerGUI->setObjectName(QStringLiteral("ECMControllerGUI"));
        ECMControllerGUI->resize(400, 300);
        menuBar = new QMenuBar(ECMControllerGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ECMControllerGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ECMControllerGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ECMControllerGUI->addToolBar(mainToolBar);
        centralWidget = new QWidget(ECMControllerGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ECMControllerGUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ECMControllerGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECMControllerGUI->setStatusBar(statusBar);

        retranslateUi(ECMControllerGUI);

        QMetaObject::connectSlotsByName(ECMControllerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ECMControllerGUI)
    {
        ECMControllerGUI->setWindowTitle(QApplication::translate("ECMControllerGUI", "ECMControllerGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECMControllerGUI: public Ui_ECMControllerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECM_CONTROLLER_GUI_H
