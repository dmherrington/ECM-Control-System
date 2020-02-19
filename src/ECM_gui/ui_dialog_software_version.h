/********************************************************************************
** Form generated from reading UI file 'dialog_software_version.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SOFTWARE_VERSION_H
#define UI_DIALOG_SOFTWARE_VERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_SoftwareVersion
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_SWMap;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_SoftwareVersion)
    {
        if (Dialog_SoftwareVersion->objectName().isEmpty())
            Dialog_SoftwareVersion->setObjectName(QString::fromUtf8("Dialog_SoftwareVersion"));
        Dialog_SoftwareVersion->resize(332, 282);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_SoftwareVersion->sizePolicy().hasHeightForWidth());
        Dialog_SoftwareVersion->setSizePolicy(sizePolicy);
        Dialog_SoftwareVersion->setMinimumSize(QSize(332, 282));
        Dialog_SoftwareVersion->setMaximumSize(QSize(332, 282));
        layoutWidget = new QWidget(Dialog_SoftwareVersion);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 334, 275));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        frame = new QFrame(layoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(332, 200));
        frame->setMaximumSize(QSize(332, 200));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_SWMap = new QVBoxLayout();
        verticalLayout_SWMap->setObjectName(QString::fromUtf8("verticalLayout_SWMap"));

        gridLayout_2->addLayout(verticalLayout_SWMap, 1, 0, 1, 1);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_SoftwareVersion);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SoftwareVersion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SoftwareVersion, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SoftwareVersion);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SoftwareVersion)
    {
        Dialog_SoftwareVersion->setWindowTitle(QApplication::translate("Dialog_SoftwareVersion", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog_SoftwareVersion", "Current Deployed Software Versions:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SoftwareVersion: public Ui_Dialog_SoftwareVersion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SOFTWARE_VERSION_H
