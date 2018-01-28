/********************************************************************************
** Form generated from reading UI file 'widget_segment_time_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SEGMENT_TIME_DISPLAY_H
#define UI_WIDGET_SEGMENT_TIME_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSegmentTimeDisplay
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *WidgetSegmentTimeDisplay)
    {
        if (WidgetSegmentTimeDisplay->objectName().isEmpty())
            WidgetSegmentTimeDisplay->setObjectName(QStringLiteral("WidgetSegmentTimeDisplay"));
        WidgetSegmentTimeDisplay->resize(160, 206);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSegmentTimeDisplay->sizePolicy().hasHeightForWidth());
        WidgetSegmentTimeDisplay->setSizePolicy(sizePolicy);
        WidgetSegmentTimeDisplay->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(WidgetSegmentTimeDisplay);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(2, 0, 2, 0);
        scrollArea = new QScrollArea(WidgetSegmentTimeDisplay);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setLineWidth(2);
        scrollArea->setMidLineWidth(2);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 154, 204));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(8, 0, 8, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(WidgetSegmentTimeDisplay);

        QMetaObject::connectSlotsByName(WidgetSegmentTimeDisplay);
    } // setupUi

    void retranslateUi(QWidget *WidgetSegmentTimeDisplay)
    {
        WidgetSegmentTimeDisplay->setWindowTitle(QApplication::translate("WidgetSegmentTimeDisplay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSegmentTimeDisplay: public Ui_WidgetSegmentTimeDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SEGMENT_TIME_DISPLAY_H
