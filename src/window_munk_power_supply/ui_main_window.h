/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plot_handler.h"
#include "widget_segment_time_display.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionGraph_Legend;
    QAction *actionOpen_Connection;
    QAction *actionClose_Connection;
    QAction *actionTransmit_To_Munk;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_comPort;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_connect;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_transmit;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    graphing::PlotHandler *graphWidget;
    QSpacerItem *verticalSpacer;
    WidgetSegmentTimeDisplay *segmentWidget;
    QSpacerItem *verticalSpacer_6;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(665, 334);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(650, 0));
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionGraph_Legend = new QAction(MainWindow);
        actionGraph_Legend->setObjectName(QStringLiteral("actionGraph_Legend"));
        actionOpen_Connection = new QAction(MainWindow);
        actionOpen_Connection->setObjectName(QStringLiteral("actionOpen_Connection"));
        actionClose_Connection = new QAction(MainWindow);
        actionClose_Connection->setObjectName(QStringLiteral("actionClose_Connection"));
        actionTransmit_To_Munk = new QAction(MainWindow);
        actionTransmit_To_Munk->setObjectName(QStringLiteral("actionTransmit_To_Munk"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        comboBox_comPort = new QComboBox(centralWidget);
        comboBox_comPort->setObjectName(QStringLiteral("comboBox_comPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_comPort->sizePolicy().hasHeightForWidth());
        comboBox_comPort->setSizePolicy(sizePolicy1);
        comboBox_comPort->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(comboBox_comPort, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(80, 0));
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        sizePolicy1.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy1);
        pushButton_connect->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(pushButton_connect, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        pushButton_transmit = new QPushButton(centralWidget);
        pushButton_transmit->setObjectName(QStringLiteral("pushButton_transmit"));
        sizePolicy1.setHeightForWidth(pushButton_transmit->sizePolicy().hasHeightForWidth());
        pushButton_transmit->setSizePolicy(sizePolicy1);
        pushButton_transmit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(pushButton_transmit, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(13, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        graphWidget = new graphing::PlotHandler(centralWidget);
        graphWidget->setObjectName(QStringLiteral("graphWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphWidget->sizePolicy().hasHeightForWidth());
        graphWidget->setSizePolicy(sizePolicy2);
        graphWidget->setMinimumSize(QSize(300, 200));

        gridLayout_2->addWidget(graphWidget, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(10, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        segmentWidget = new WidgetSegmentTimeDisplay(centralWidget);
        segmentWidget->setObjectName(QStringLiteral("segmentWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(segmentWidget->sizePolicy().hasHeightForWidth());
        segmentWidget->setSizePolicy(sizePolicy3);
        segmentWidget->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(segmentWidget, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(10, 37, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_3->addItem(verticalSpacer_6, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionGraph_Legend);
        menuHelp->addAction(actionOpen_Connection);
        menuHelp->addAction(actionClose_Connection);
        menuHelp->addSeparator();
        menuHelp->addAction(actionTransmit_To_Munk);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionGraph_Legend->setText(QApplication::translate("MainWindow", "Graph Legend", nullptr));
        actionOpen_Connection->setText(QApplication::translate("MainWindow", "Open Connection", nullptr));
        actionClose_Connection->setText(QApplication::translate("MainWindow", "Close Connection", nullptr));
        actionTransmit_To_Munk->setText(QApplication::translate("MainWindow", "Transmit To Munk", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "ADD", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "CONNECT", nullptr));
        pushButton_transmit->setText(QApplication::translate("MainWindow", "TRANSMIT", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
