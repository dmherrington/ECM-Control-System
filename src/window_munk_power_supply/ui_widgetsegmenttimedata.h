/********************************************************************************
** Form generated from reading UI file 'widgetsegmenttimedata.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSEGMENTTIMEDATA_H
#define UI_WIDGETSEGMENTTIMEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSegmentTimeData
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_SegmentName;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_Mode;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Voltage;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_Current;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Time;
    QPushButton *pushButton;

    void setupUi(QWidget *WidgetSegmentTimeData)
    {
        if (WidgetSegmentTimeData->objectName().isEmpty())
            WidgetSegmentTimeData->setObjectName(QStringLiteral("WidgetSegmentTimeData"));
        WidgetSegmentTimeData->resize(185, 216);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSegmentTimeData->sizePolicy().hasHeightForWidth());
        WidgetSegmentTimeData->setSizePolicy(sizePolicy);
        WidgetSegmentTimeData->setMaximumSize(QSize(185, 216));
        WidgetSegmentTimeData->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#1d1d1d;\n"
"}\n"
"\n"
"QMenuBar{\n"
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
"background-color:qlineargradient"
                        "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
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
"\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x"
                        "1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
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
        gridLayout_2 = new QGridLayout(WidgetSegmentTimeData);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(WidgetSegmentTimeData);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_SegmentName = new QLabel(frame);
        label_SegmentName->setObjectName(QStringLiteral("label_SegmentName"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_SegmentName->sizePolicy().hasHeightForWidth());
        label_SegmentName->setSizePolicy(sizePolicy1);
        label_SegmentName->setMinimumSize(QSize(110, 0));
        label_SegmentName->setMaximumSize(QSize(141, 16777215));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_SegmentName->setFont(font);
        label_SegmentName->setFrameShape(QFrame::Panel);
        label_SegmentName->setFrameShadow(QFrame::Sunken);
        label_SegmentName->setLineWidth(3);
        label_SegmentName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_SegmentName, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(43, 0));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_Mode = new QComboBox(frame);
        comboBox_Mode->setObjectName(QStringLiteral("comboBox_Mode"));
        sizePolicy.setHeightForWidth(comboBox_Mode->sizePolicy().hasHeightForWidth());
        comboBox_Mode->setSizePolicy(sizePolicy);
        comboBox_Mode->setMinimumSize(QSize(90, 0));
        comboBox_Mode->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_Mode);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(43, 0));
        label_2->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        doubleSpinBox_Voltage = new QDoubleSpinBox(frame);
        doubleSpinBox_Voltage->setObjectName(QStringLiteral("doubleSpinBox_Voltage"));
        doubleSpinBox_Voltage->setEnabled(true);
        sizePolicy.setHeightForWidth(doubleSpinBox_Voltage->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Voltage->setSizePolicy(sizePolicy);
        doubleSpinBox_Voltage->setMinimumSize(QSize(90, 0));
        doubleSpinBox_Voltage->setMaximumSize(QSize(80, 16777215));
        QFont font1;
        font1.setPointSize(10);
        doubleSpinBox_Voltage->setFont(font1);
        doubleSpinBox_Voltage->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Voltage->setDecimals(2);
        doubleSpinBox_Voltage->setMaximum(40);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_Voltage);


        gridLayout->addLayout(formLayout_2, 2, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(43, 0));
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        doubleSpinBox_Current = new QDoubleSpinBox(frame);
        doubleSpinBox_Current->setObjectName(QStringLiteral("doubleSpinBox_Current"));
        sizePolicy.setHeightForWidth(doubleSpinBox_Current->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Current->setSizePolicy(sizePolicy);
        doubleSpinBox_Current->setMinimumSize(QSize(90, 0));
        doubleSpinBox_Current->setMaximumSize(QSize(80, 16777215));
        doubleSpinBox_Current->setFont(font1);
        doubleSpinBox_Current->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Current->setDecimals(2);
        doubleSpinBox_Current->setMaximum(2000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_Current);


        gridLayout->addLayout(formLayout_3, 3, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(43, 0));
        label_4->setAlignment(Qt::AlignCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBox_Time = new QDoubleSpinBox(frame);
        doubleSpinBox_Time->setObjectName(QStringLiteral("doubleSpinBox_Time"));
        doubleSpinBox_Time->setEnabled(true);
        sizePolicy.setHeightForWidth(doubleSpinBox_Time->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Time->setSizePolicy(sizePolicy);
        doubleSpinBox_Time->setMinimumSize(QSize(90, 0));
        doubleSpinBox_Time->setMaximumSize(QSize(80, 16777215));
        doubleSpinBox_Time->setFont(font1);
        doubleSpinBox_Time->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Time->setDecimals(1);
        doubleSpinBox_Time->setMinimum(0.1);
        doubleSpinBox_Time->setMaximum(1270);
        doubleSpinBox_Time->setSingleStep(0.1);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_Time);


        gridLayout->addLayout(formLayout_4, 4, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(110, 0));
        pushButton->setMaximumSize(QSize(141, 16777215));
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(WidgetSegmentTimeData);

        QMetaObject::connectSlotsByName(WidgetSegmentTimeData);
    } // setupUi

    void retranslateUi(QWidget *WidgetSegmentTimeData)
    {
        WidgetSegmentTimeData->setWindowTitle(QApplication::translate("WidgetSegmentTimeData", "Form", nullptr));
        label_SegmentName->setText(QApplication::translate("WidgetSegmentTimeData", "Segment # 8", nullptr));
        label->setText(QApplication::translate("WidgetSegmentTimeData", "Mode", nullptr));
        label_2->setText(QApplication::translate("WidgetSegmentTimeData", "Voltage", nullptr));
        label_3->setText(QApplication::translate("WidgetSegmentTimeData", "Current", nullptr));
        label_4->setText(QApplication::translate("WidgetSegmentTimeData", "Time", nullptr));
        pushButton->setText(QApplication::translate("WidgetSegmentTimeData", "REMOVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSegmentTimeData: public Ui_WidgetSegmentTimeData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSEGMENTTIMEDATA_H
