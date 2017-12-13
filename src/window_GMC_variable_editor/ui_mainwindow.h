/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AddMotionProfile;
    QPushButton *pushButton_RemoveMotionProfile;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolBox *toolBox;
    QWidget *page_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 306);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(680, 0));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/images/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/open_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_AddMotionProfile = new QPushButton(centralWidget);
        pushButton_AddMotionProfile->setObjectName(QStringLiteral("pushButton_AddMotionProfile"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("images/add_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddMotionProfile->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_AddMotionProfile);

        pushButton_RemoveMotionProfile = new QPushButton(centralWidget);
        pushButton_RemoveMotionProfile->setObjectName(QStringLiteral("pushButton_RemoveMotionProfile"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RemoveMotionProfile->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_RemoveMotionProfile);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMinimumSize(QSize(650, 0));
        QFont font;
        font.setPointSize(10);
        toolBox->setFont(font);
        toolBox->setFrameShape(QFrame::NoFrame);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 650, 183));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));

        horizontalLayout_2->addWidget(toolBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionSave_As->setText(QApplication::translate("MainWindow", "Save_As", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        pushButton_AddMotionProfile->setText(QApplication::translate("MainWindow", "Add Motion Profile", Q_NULLPTR));
        pushButton_RemoveMotionProfile->setText(QApplication::translate("MainWindow", "Remove Motion Profile", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
