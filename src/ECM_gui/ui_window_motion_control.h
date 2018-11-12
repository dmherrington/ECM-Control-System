/********************************************************************************
** Form generated from reading UI file 'window_motion_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MOTION_CONTROL_H
#define UI_WINDOW_MOTION_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_ManualControl
{
public:
    QWidget *centralwidget;
    QFrame *frame_MaunalControl;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QLabel *label_ManualControl;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit_MachinePosition;
    QGridLayout *gridLayout_6;
    QLabel *label_ManualControl_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_IncreaseJog;
    QSpinBox *spinBox_Jog;
    QPushButton *pushButton_DecreaseJog;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ManualControl_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_SetpControlInner;
    QPushButton *pushButton_IncreaseRelativeMove;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_RelativeMove;
    QSpinBox *spinBox_RelativeMoveSpeed;
    QPushButton *pushButton_DecreaseRelativeMove;
    QSpacerItem *horizontalSpacer_9;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_ManualControl)
    {
        if (Window_ManualControl->objectName().isEmpty())
            Window_ManualControl->setObjectName(QStringLiteral("Window_ManualControl"));
        Window_ManualControl->resize(370, 305);
        Window_ManualControl->setMinimumSize(QSize(370, 305));
        Window_ManualControl->setMaximumSize(QSize(370, 305));
        centralwidget = new QWidget(Window_ManualControl);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame_MaunalControl = new QFrame(centralwidget);
        frame_MaunalControl->setObjectName(QStringLiteral("frame_MaunalControl"));
        frame_MaunalControl->setGeometry(QRect(10, 10, 350, 250));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_MaunalControl->sizePolicy().hasHeightForWidth());
        frame_MaunalControl->setSizePolicy(sizePolicy);
        frame_MaunalControl->setMinimumSize(QSize(350, 250));
        frame_MaunalControl->setMaximumSize(QSize(350, 300));
        frame_MaunalControl->setFrameShape(QFrame::Box);
        frame_MaunalControl->setFrameShadow(QFrame::Plain);
        frame_MaunalControl->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_MaunalControl);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_ManualControl = new QLabel(frame_MaunalControl);
        label_ManualControl->setObjectName(QStringLiteral("label_ManualControl"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ManualControl->sizePolicy().hasHeightForWidth());
        label_ManualControl->setSizePolicy(sizePolicy1);
        label_ManualControl->setMinimumSize(QSize(0, 32));
        label_ManualControl->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ManualControl->setFont(font);
        label_ManualControl->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ManualControl, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(frame_MaunalControl);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(130, 25));
        label->setMaximumSize(QSize(130, 25));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);

        horizontalLayout_5->addWidget(label);

        lineEdit_MachinePosition = new QLineEdit(frame_MaunalControl);
        lineEdit_MachinePosition->setObjectName(QStringLiteral("lineEdit_MachinePosition"));
        lineEdit_MachinePosition->setMinimumSize(QSize(190, 25));
        lineEdit_MachinePosition->setMaximumSize(QSize(190, 25));
        lineEdit_MachinePosition->setFont(font1);
        lineEdit_MachinePosition->setAlignment(Qt::AlignCenter);
        lineEdit_MachinePosition->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_MachinePosition);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_ManualControl_3 = new QLabel(frame_MaunalControl);
        label_ManualControl_3->setObjectName(QStringLiteral("label_ManualControl_3"));
        sizePolicy1.setHeightForWidth(label_ManualControl_3->sizePolicy().hasHeightForWidth());
        label_ManualControl_3->setSizePolicy(sizePolicy1);
        label_ManualControl_3->setFont(font);
        label_ManualControl_3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_ManualControl_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_7 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_IncreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseJog->setObjectName(QStringLiteral("pushButton_IncreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseJog->setSizePolicy(sizePolicy);
        pushButton_IncreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseJog->setMaximumSize(QSize(130, 16777215));
        QFont font2;
        font2.setPointSize(12);
        pushButton_IncreaseJog->setFont(font2);

        verticalLayout->addWidget(pushButton_IncreaseJog);

        spinBox_Jog = new QSpinBox(frame_MaunalControl);
        spinBox_Jog->setObjectName(QStringLiteral("spinBox_Jog"));
        sizePolicy.setHeightForWidth(spinBox_Jog->sizePolicy().hasHeightForWidth());
        spinBox_Jog->setSizePolicy(sizePolicy);
        spinBox_Jog->setMinimumSize(QSize(130, 30));
        spinBox_Jog->setFont(font1);
        spinBox_Jog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Jog->setMinimum(1);
        spinBox_Jog->setMaximum(10000);
        spinBox_Jog->setSingleStep(10);
        spinBox_Jog->setValue(3000);

        verticalLayout->addWidget(spinBox_Jog);

        pushButton_DecreaseJog = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseJog->setObjectName(QStringLiteral("pushButton_DecreaseJog"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseJog->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseJog->setSizePolicy(sizePolicy);
        pushButton_DecreaseJog->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseJog->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseJog->setFont(font2);

        verticalLayout->addWidget(pushButton_DecreaseJog);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_ManualControl_4 = new QLabel(frame_MaunalControl);
        label_ManualControl_4->setObjectName(QStringLiteral("label_ManualControl_4"));
        sizePolicy1.setHeightForWidth(label_ManualControl_4->sizePolicy().hasHeightForWidth());
        label_ManualControl_4->setSizePolicy(sizePolicy1);
        label_ManualControl_4->setFont(font);
        label_ManualControl_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_ManualControl_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        verticalLayout_SetpControlInner = new QVBoxLayout();
        verticalLayout_SetpControlInner->setObjectName(QStringLiteral("verticalLayout_SetpControlInner"));
        pushButton_IncreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_IncreaseRelativeMove->setObjectName(QStringLiteral("pushButton_IncreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_IncreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_IncreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_IncreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_IncreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_IncreaseRelativeMove->setFont(font2);

        verticalLayout_SetpControlInner->addWidget(pushButton_IncreaseRelativeMove);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox_RelativeMove = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMove->setObjectName(QStringLiteral("spinBox_RelativeMove"));
        sizePolicy.setHeightForWidth(spinBox_RelativeMove->sizePolicy().hasHeightForWidth());
        spinBox_RelativeMove->setSizePolicy(sizePolicy);
        spinBox_RelativeMove->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMove->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMove->setFont(font1);
        spinBox_RelativeMove->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMove->setMaximum(100000);
        spinBox_RelativeMove->setSingleStep(100);
        spinBox_RelativeMove->setValue(2000);

        horizontalLayout->addWidget(spinBox_RelativeMove);

        spinBox_RelativeMoveSpeed = new QSpinBox(frame_MaunalControl);
        spinBox_RelativeMoveSpeed->setObjectName(QStringLiteral("spinBox_RelativeMoveSpeed"));
        spinBox_RelativeMoveSpeed->setMinimumSize(QSize(65, 30));
        spinBox_RelativeMoveSpeed->setMaximumSize(QSize(65, 16777215));
        spinBox_RelativeMoveSpeed->setFont(font1);
        spinBox_RelativeMoveSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_RelativeMoveSpeed->setMaximum(5000);
        spinBox_RelativeMoveSpeed->setSingleStep(10);
        spinBox_RelativeMoveSpeed->setValue(1000);

        horizontalLayout->addWidget(spinBox_RelativeMoveSpeed);


        verticalLayout_SetpControlInner->addLayout(horizontalLayout);

        pushButton_DecreaseRelativeMove = new QPushButton(frame_MaunalControl);
        pushButton_DecreaseRelativeMove->setObjectName(QStringLiteral("pushButton_DecreaseRelativeMove"));
        sizePolicy.setHeightForWidth(pushButton_DecreaseRelativeMove->sizePolicy().hasHeightForWidth());
        pushButton_DecreaseRelativeMove->setSizePolicy(sizePolicy);
        pushButton_DecreaseRelativeMove->setMinimumSize(QSize(130, 30));
        pushButton_DecreaseRelativeMove->setMaximumSize(QSize(130, 16777215));
        pushButton_DecreaseRelativeMove->setFont(font2);

        verticalLayout_SetpControlInner->addWidget(pushButton_DecreaseRelativeMove);


        horizontalLayout_2->addLayout(verticalLayout_SetpControlInner);

        horizontalSpacer_9 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout_5, 2, 1, 1, 1);

        Window_ManualControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_ManualControl);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 370, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Window_ManualControl->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_ManualControl);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_ManualControl->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());

        retranslateUi(Window_ManualControl);

        QMetaObject::connectSlotsByName(Window_ManualControl);
    } // setupUi

    void retranslateUi(QMainWindow *Window_ManualControl)
    {
        Window_ManualControl->setWindowTitle(QApplication::translate("Window_ManualControl", "MainWindow", nullptr));
        label_ManualControl->setText(QApplication::translate("Window_ManualControl", "Manual Control", nullptr));
        label->setText(QApplication::translate("Window_ManualControl", "Current Position (um):", nullptr));
        label_ManualControl_3->setText(QApplication::translate("Window_ManualControl", "Jog  (um/sec)", nullptr));
        pushButton_IncreaseJog->setText(QApplication::translate("Window_ManualControl", "INCREASE", nullptr));
        pushButton_DecreaseJog->setText(QApplication::translate("Window_ManualControl", "DECREASE", nullptr));
        label_ManualControl_4->setText(QApplication::translate("Window_ManualControl", "Step (um | um/sec)", nullptr));
        pushButton_IncreaseRelativeMove->setText(QApplication::translate("Window_ManualControl", "INCREASE", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_RelativeMoveSpeed->setToolTip(QApplication::translate("Window_ManualControl", "Testing1", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        spinBox_RelativeMoveSpeed->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton_DecreaseRelativeMove->setText(QApplication::translate("Window_ManualControl", "DECREASE", nullptr));
        menuFile->setTitle(QApplication::translate("Window_ManualControl", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Window_ManualControl", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Window_ManualControl", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("Window_ManualControl", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_ManualControl: public Ui_Window_ManualControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MOTION_CONTROL_H
