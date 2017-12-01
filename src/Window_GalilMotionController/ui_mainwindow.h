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
<<<<<<< HEAD
=======
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
<<<<<<< HEAD
=======
#include <QtWidgets/QSpinBox>
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
<<<<<<< HEAD
    QAction *actionSave_Program;
    QAction *actionSave_As_Program;
    QAction *actionLoad_Program;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuGalil;
=======
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QFrame *frame_ProfileOptions;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl_2;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_6;
    QLabel *label_3;
    QSpinBox *spinBox_CutDepth;
    QLabel *label;
    QSpinBox *spinBox_RetractDistance;
    QLabel *label_2;
    QSpinBox *spinBox_RetractFrequency;
    QLabel *label_4;
    QSpinBox *spinBox_CutSpeed;
    QPushButton *pushButton_RunProfile;
    QPushButton *pushButton_SetInitialGap;
    QSpinBox *spinBox_Jog_6;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_ManualControl;
    QPushButton *pushButton_IncreaseJog;
    QPushButton *pushButton_IncreaseRelativeMove;
    QSpinBox *spinBox_Jog;
    QSpinBox *spinBox_RelativeMove;
    QPushButton *pushButton_DecreaseJog;
    QPushButton *pushButton_DecreaseRelativeMove;
    QPushButton *pushButton_SetHome;
    QPushButton *pushButton_SetHome_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
<<<<<<< HEAD
        MainWindow->resize(854, 589);
        actionSave_Program = new QAction(MainWindow);
        actionSave_Program->setObjectName(QStringLiteral("actionSave_Program"));
        actionSave_As_Program = new QAction(MainWindow);
        actionSave_As_Program->setObjectName(QStringLiteral("actionSave_As_Program"));
        actionLoad_Program = new QAction(MainWindow);
        actionLoad_Program->setObjectName(QStringLiteral("actionLoad_Program"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);
=======
        MainWindow->resize(907, 321);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame_ProfileOptions = new QFrame(centralWidget);
        frame_ProfileOptions->setObjectName(QStringLiteral("frame_ProfileOptions"));
        frame_ProfileOptions->setMinimumSize(QSize(450, 250));
        frame_ProfileOptions->setFrameShape(QFrame::Box);
        frame_ProfileOptions->setFrameShadow(QFrame::Plain);
        frame_ProfileOptions->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_ProfileOptions);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl_2 = new QLabel(frame_ProfileOptions);
        label_ManualControl_2->setObjectName(QStringLiteral("label_ManualControl_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_ManualControl_2->sizePolicy().hasHeightForWidth());
        label_ManualControl_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl_2->setFont(font);
        label_ManualControl_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(frame_ProfileOptions);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(120, 0));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_CutDepth = new QSpinBox(frame_ProfileOptions);
        spinBox_CutDepth->setObjectName(QStringLiteral("spinBox_CutDepth"));
        spinBox_CutDepth->setMinimumSize(QSize(110, 30));
        spinBox_CutDepth->setFont(font1);
        spinBox_CutDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinBox_CutDepth);

        label = new QLabel(frame_ProfileOptions);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setFont(font1);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label);

        spinBox_RetractDistance = new QSpinBox(frame_ProfileOptions);
        spinBox_RetractDistance->setObjectName(QStringLiteral("spinBox_RetractDistance"));
        spinBox_RetractDistance->setMinimumSize(QSize(110, 30));
        spinBox_RetractDistance->setFont(font1);
        spinBox_RetractDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, spinBox_RetractDistance);

        label_2 = new QLabel(frame_ProfileOptions);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setFont(font1);

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBox_RetractFrequency = new QSpinBox(frame_ProfileOptions);
        spinBox_RetractFrequency->setObjectName(QStringLiteral("spinBox_RetractFrequency"));
        spinBox_RetractFrequency->setMinimumSize(QSize(110, 30));
        spinBox_RetractFrequency->setFont(font1);
        spinBox_RetractFrequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, spinBox_RetractFrequency);

        label_4 = new QLabel(frame_ProfileOptions);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 0));
        label_4->setFont(font1);

        formLayout_6->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBox_CutSpeed = new QSpinBox(frame_ProfileOptions);
        spinBox_CutSpeed->setObjectName(QStringLiteral("spinBox_CutSpeed"));
        spinBox_CutSpeed->setMinimumSize(QSize(110, 30));
        spinBox_CutSpeed->setFont(font1);
        spinBox_CutSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, spinBox_CutSpeed);


        gridLayout_3->addLayout(formLayout_6, 0, 0, 2, 1);

        pushButton_RunProfile = new QPushButton(frame_ProfileOptions);
        pushButton_RunProfile->setObjectName(QStringLiteral("pushButton_RunProfile"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_RunProfile->sizePolicy().hasHeightForWidth());
        pushButton_RunProfile->setSizePolicy(sizePolicy1);
        pushButton_RunProfile->setMinimumSize(QSize(180, 30));
        pushButton_RunProfile->setFont(font1);

        gridLayout_3->addWidget(pushButton_RunProfile, 0, 1, 1, 1);

        pushButton_SetInitialGap = new QPushButton(frame_ProfileOptions);
        pushButton_SetInitialGap->setObjectName(QStringLiteral("pushButton_SetInitialGap"));
        sizePolicy1.setHeightForWidth(pushButton_SetInitialGap->sizePolicy().hasHeightForWidth());
        pushButton_SetInitialGap->setSizePolicy(sizePolicy1);
        pushButton_SetInitialGap->setMinimumSize(QSize(180, 30));
        pushButton_SetInitialGap->setFont(font1);

        gridLayout_3->addWidget(pushButton_SetInitialGap, 1, 1, 1, 1);

        spinBox_Jog_6 = new QSpinBox(frame_ProfileOptions);
        spinBox_Jog_6->setObjectName(QStringLiteral("spinBox_Jog_6"));
        spinBox_Jog_6->setMinimumSize(QSize(180, 30));
        spinBox_Jog_6->setFont(font1);
        spinBox_Jog_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(spinBox_Jog_6, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_ProfileOptions, 0, 0, 1, 1);

        frame_MaunalControl = new QFrame(centralWidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        sizePolicy1.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy1);
        frame_MaunalControl->setMinimumSize(QSize(350, 250));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_MaunalControl);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label_ManualControl = new QLabel(frame_MaunalControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        sizePolicy.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ManualControl, 0, 0, 1, 2);

        pushButton_IncreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseJog->setObjectName(QStringLiteral("pushButton_IncreaseJog"));
        sizePolicy1.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy1);
        pushButton_IncreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseJog->setFont(font1);

        gridLayout->addWidget(pushButton_IncreaseJog, 1, 0, 1, 1);

        pushButton_IncreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QStringLiteral("pushButton_IncreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_IncreaseRelativeMove->setFont(font1);

        gridLayout->addWidget(pushButton_IncreaseRelativeMove, 1, 1, 1, 1);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy1.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy1);
        spinBox_Jog->setMinimumSize(QSize(112, 30));
        spinBox_Jog->setFont(font1);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(spinBox_Jog, 2, 0, 1, 1);

        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy1.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy1);
        spinBox_RelativeMove->setMinimumSize(QSize(112, 30));
        spinBox_RelativeMove->setFont(font1);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(spinBox_RelativeMove, 2, 1, 1, 1);

        pushButton_DecreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseJog->setObjectName(QStringLiteral("pushButton_DecreaseJog"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy1);
        pushButton_DecreaseJog->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseJog->setFont(font1);

        gridLayout->addWidget(pushButton_DecreaseJog, 3, 0, 1, 1);

        pushButton_DecreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy1.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy1);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(112, 30));
        pushButton_DecreaseRelativeMove->setFont(font1);

        gridLayout->addWidget(pushButton_DecreaseRelativeMove, 3, 1, 1, 1);

        pushButton_SetHome = new QPushButton(frame_MaunalControl);
        pushButton_SetHome->setObjectName(QStringLiteral("pushButton_SetHome"));
        sizePolicy1.setHeightForWidth(pushButton_SetHome->sizePolicy().hasHeightForWidth());
        pushButton_SetHome->setSizePolicy(sizePolicy1);
        pushButton_SetHome->setMinimumSize(QSize(112, 30));
        pushButton_SetHome->setFont(font1);

        gridLayout->addWidget(pushButton_SetHome, 4, 0, 1, 1);

        pushButton_SetHome_2 = new QPushButton(frame_MaunalControl);
        pushButton_SetHome_2->setObjectName(QStringLiteral("pushButton_SetHome_2"));
        sizePolicy1.setHeightForWidth(pushButton_SetHome_2->sizePolicy().hasHeightForWidth());
        pushButton_SetHome_2->setSizePolicy(sizePolicy1);
        pushButton_SetHome_2->setMinimumSize(QSize(112, 30));
        pushButton_SetHome_2->setFont(font1);

        gridLayout->addWidget(pushButton_SetHome_2, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_MaunalControl, 0, 1, 1, 1);
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
<<<<<<< HEAD
        menuBar->setGeometry(QRect(0, 0, 854, 22));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        menuBar->setNativeMenuBar(true);
        menuGalil = new QMenu(menuBar);
        menuGalil->setObjectName(QStringLiteral("menuGalil"));
        MainWindow->setMenuBar(menuBar);
=======
        menuBar->setGeometry(QRect(0, 0, 907, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGalil->menuAction());
        menuGalil->addAction(actionSave_Program);
        menuGalil->addAction(actionSave_As_Program);
        menuGalil->addAction(actionLoad_Program);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
<<<<<<< HEAD
        actionSave_Program->setText(QApplication::translate("MainWindow", "Save Program", Q_NULLPTR));
        actionSave_As_Program->setText(QApplication::translate("MainWindow", "Save_As Program", Q_NULLPTR));
        actionLoad_Program->setText(QApplication::translate("MainWindow", "Load Program", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        menuGalil->setTitle(QApplication::translate("MainWindow", "Galil", Q_NULLPTR));
=======
        label_ManualControl_2->setText(QApplication::translate("MainWindow", "Profile Optons", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Cut Depth", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Retract Distance", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Retract Frequency", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Cut Speed", Q_NULLPTR));
        pushButton_RunProfile->setText(QApplication::translate("MainWindow", "Run Profile", Q_NULLPTR));
        pushButton_SetInitialGap->setText(QApplication::translate("MainWindow", "Set Initial Gap", Q_NULLPTR));
        label_ManualControl->setText(QApplication::translate("MainWindow", "Manual Control", Q_NULLPTR));
        pushButton_IncreaseJog->setText(QApplication::translate("MainWindow", "INCREASE", Q_NULLPTR));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("MainWindow", "INCREASE", Q_NULLPTR));
        pushButton_DecreaseJog->setText(QApplication::translate("MainWindow", "DECREASE", Q_NULLPTR));
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("MainWindow", "DECREASE", Q_NULLPTR));
        pushButton_SetHome->setText(QApplication::translate("MainWindow", "Set Home", Q_NULLPTR));
        pushButton_SetHome_2->setText(QApplication::translate("MainWindow", "Move To Home", Q_NULLPTR));
>>>>>>> 6626490dbde491e8f3ecad2c48b28f0dd9141ccd
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
