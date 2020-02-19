/********************************************************************************
** Form generated from reading UI file 'dialog_run_statistics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_RUN_STATISTICS_H
#define UI_DIALOG_RUN_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_RunStatistics
{
public:
    QGridLayout *gridLayout;
    QLabel *label_dailyTime;
    QLineEdit *lineEdit_dailyTime;
    QLabel *label_totalTime;
    QLineEdit *lineEdit_totalTime;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_RunStatistics)
    {
        if (Dialog_RunStatistics->objectName().isEmpty())
            Dialog_RunStatistics->setObjectName(QString::fromUtf8("Dialog_RunStatistics"));
        Dialog_RunStatistics->resize(368, 153);
        Dialog_RunStatistics->setStyleSheet(QString::fromUtf8("QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, "
                        "217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"background-color: rgb(204, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), "
                        "stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        gridLayout = new QGridLayout(Dialog_RunStatistics);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_dailyTime = new QLabel(Dialog_RunStatistics);
        label_dailyTime->setObjectName(QString::fromUtf8("label_dailyTime"));
        QFont font;
        font.setPointSize(12);
        label_dailyTime->setFont(font);
        label_dailyTime->setStyleSheet(QString::fromUtf8("QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, "
                        "217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"QPushButton{\n"
"border-style:solid;\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"background-color: rgb(204, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargrad"
                        "ient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        label_dailyTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_dailyTime, 0, 0, 1, 1);

        lineEdit_dailyTime = new QLineEdit(Dialog_RunStatistics);
        lineEdit_dailyTime->setObjectName(QString::fromUtf8("lineEdit_dailyTime"));
        lineEdit_dailyTime->setEnabled(false);
        lineEdit_dailyTime->setMinimumSize(QSize(350, 30));
        lineEdit_dailyTime->setFont(font);
        lineEdit_dailyTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_dailyTime, 1, 0, 1, 1);

        label_totalTime = new QLabel(Dialog_RunStatistics);
        label_totalTime->setObjectName(QString::fromUtf8("label_totalTime"));
        label_totalTime->setFont(font);
        label_totalTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_totalTime, 2, 0, 1, 1);

        lineEdit_totalTime = new QLineEdit(Dialog_RunStatistics);
        lineEdit_totalTime->setObjectName(QString::fromUtf8("lineEdit_totalTime"));
        lineEdit_totalTime->setEnabled(false);
        lineEdit_totalTime->setMinimumSize(QSize(350, 30));
        lineEdit_totalTime->setFont(font);
        lineEdit_totalTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_totalTime, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog_RunStatistics);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setMinimumSize(QSize(120, 0));
        QFont font1;
        font1.setPointSize(14);
        buttonBox->setFont(font1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(Dialog_RunStatistics);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_RunStatistics, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_RunStatistics, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_RunStatistics);
    } // setupUi

    void retranslateUi(QDialog *Dialog_RunStatistics)
    {
        Dialog_RunStatistics->setWindowTitle(QApplication::translate("Dialog_RunStatistics", "Dialog", nullptr));
        label_dailyTime->setText(QApplication::translate("Dialog_RunStatistics", "The current software runtime is:", nullptr));
        lineEdit_dailyTime->setText(QApplication::translate("Dialog_RunStatistics", "0 HRS : 0 MINS : 0 SECS", nullptr));
        label_totalTime->setText(QApplication::translate("Dialog_RunStatistics", "The current total machine operational time is:", nullptr));
        lineEdit_totalTime->setText(QApplication::translate("Dialog_RunStatistics", "0 HRS : 0 MINS : 0 SECS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_RunStatistics: public Ui_Dialog_RunStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_RUN_STATISTICS_H
