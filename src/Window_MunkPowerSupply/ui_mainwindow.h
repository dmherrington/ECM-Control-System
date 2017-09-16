/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_8;
    QComboBox *comboBox_RW;
    QLabel *label_3;
    QSpinBox *spinBox_address;
    QSpinBox *spinBox_nosegments;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_lvl;
    QLabel *label_5;
    QComboBox *comboBox_scaler;
    QLabel *label_6;
    QSpinBox *spinBox_time;
    QLabel *label_4;
    QComboBox *comboBox_polarity;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_generatemsg;
    QLabel *label_7;
    QTextEdit *textEdit_OutputMessage;
    QLabel *OutputMsg;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(355, 284);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 300, 254));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        comboBox_RW = new QComboBox(layoutWidget);
        comboBox_RW->setObjectName(QStringLiteral("comboBox_RW"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_RW);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBox_address = new QSpinBox(layoutWidget);
        spinBox_address->setObjectName(QStringLiteral("spinBox_address"));
        spinBox_address->setMinimum(1);
        spinBox_address->setMaximum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_address);

        spinBox_nosegments = new QSpinBox(layoutWidget);
        spinBox_nosegments->setObjectName(QStringLiteral("spinBox_nosegments"));
        spinBox_nosegments->setMinimum(1);
        spinBox_nosegments->setMaximum(16);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_nosegments);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, label);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        comboBox_lvl = new QComboBox(layoutWidget);
        comboBox_lvl->setObjectName(QStringLiteral("comboBox_lvl"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBox_lvl);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        comboBox_scaler = new QComboBox(layoutWidget);
        comboBox_scaler->setObjectName(QStringLiteral("comboBox_scaler"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBox_scaler);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        spinBox_time = new QSpinBox(layoutWidget);
        spinBox_time->setObjectName(QStringLiteral("spinBox_time"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBox_time);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_polarity = new QComboBox(layoutWidget);
        comboBox_polarity->setObjectName(QStringLiteral("comboBox_polarity"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, comboBox_polarity);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_generatemsg = new QPushButton(layoutWidget);
        pushButton_generatemsg->setObjectName(QStringLiteral("pushButton_generatemsg"));

        verticalLayout->addWidget(pushButton_generatemsg);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setScaledContents(true);

        verticalLayout->addWidget(label_7);

        textEdit_OutputMessage = new QTextEdit(layoutWidget);
        textEdit_OutputMessage->setObjectName(QStringLiteral("textEdit_OutputMessage"));

        verticalLayout->addWidget(textEdit_OutputMessage);

        OutputMsg = new QLabel(layoutWidget);
        OutputMsg->setObjectName(QStringLiteral("OutputMsg"));

        verticalLayout->addWidget(OutputMsg);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 355, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_8->setBuddy(spinBox_address);
        label_3->setBuddy(spinBox_address);
        label->setBuddy(spinBox_nosegments);
        label_6->setBuddy(spinBox_time);
        label_4->setBuddy(comboBox_polarity);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Read/Write", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Address", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Segment", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Level", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Scaler", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Polarity", Q_NULLPTR));
        pushButton_generatemsg->setText(QApplication::translate("MainWindow", "Generate Message", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Output Message:", Q_NULLPTR));
        OutputMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
