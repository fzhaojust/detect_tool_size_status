/********************************************************************************
** Form generated from reading UI file 'Data_analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_ANALYSIS_H
#define UI_DATA_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Data_analysis
{
public:
    QGridLayout *gridLayout_2;
    QChartView *widget;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Data_analysis)
    {
        if (Data_analysis->objectName().isEmpty())
            Data_analysis->setObjectName(QString::fromUtf8("Data_analysis"));
        Data_analysis->resize(935, 546);
        gridLayout_2 = new QGridLayout(Data_analysis);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QChartView(Data_analysis);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        widget_2 = new QWidget(Data_analysis);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(500, 50));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 35));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 35));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(120, 35));

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);


        gridLayout_2->addWidget(widget_2, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 2, 1, 1);


        retranslateUi(Data_analysis);

        QMetaObject::connectSlotsByName(Data_analysis);
    } // setupUi

    void retranslateUi(QWidget *Data_analysis)
    {
        Data_analysis->setWindowTitle(QApplication::translate("Data_analysis", "Data_analysis", nullptr));
        pushButton->setText(QApplication::translate("Data_analysis", "Open", nullptr));
        pushButton_2->setText(QApplication::translate("Data_analysis", "Close", nullptr));
        pushButton_3->setText(QApplication::translate("Data_analysis", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Data_analysis: public Ui_Data_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_ANALYSIS_H
