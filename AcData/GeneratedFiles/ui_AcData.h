/********************************************************************************
** Form generated from reading UI file 'AcData.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACDATA_H
#define UI_ACDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_AcDataClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QChartView *widget;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget_6;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_led1;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AcDataClass)
    {
        if (AcDataClass->objectName().isEmpty())
            AcDataClass->setObjectName(QString::fromUtf8("AcDataClass"));
        AcDataClass->resize(1128, 871);
        centralWidget = new QWidget(AcDataClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QChartView(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(500, 350));

        gridLayout_5->addWidget(widget, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 75, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 1, 1, 2, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textBrowser = new QTextBrowser(widget_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(300, 200));

        gridLayout_3->addWidget(textBrowser, 0, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 35));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 35));
        pushButton_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(150, 35));
        pushButton_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(pushButton_3, 2, 0, 1, 1);


        gridLayout_3->addWidget(widget_3, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_2, 2, 0, 2, 1);

        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_4 = new QGridLayout(widget_6);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        radioButton_3 = new QRadioButton(widget_6);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(120, 50));

        gridLayout_4->addWidget(radioButton_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(widget_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(150, 50));

        gridLayout_4->addWidget(pushButton_5, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(153, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 50));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_led1 = new QLabel(widget_5);
        label_led1->setObjectName(QString::fromUtf8("label_led1"));
        label_led1->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(label_led1, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_4->addWidget(widget_5, 1, 0, 1, 4);


        gridLayout_5->addWidget(widget_6, 3, 1, 1, 1);

        AcDataClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AcDataClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1128, 23));
        AcDataClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AcDataClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AcDataClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AcDataClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AcDataClass->setStatusBar(statusBar);

        retranslateUi(AcDataClass);

        QMetaObject::connectSlotsByName(AcDataClass);
    } // setupUi

    void retranslateUi(QMainWindow *AcDataClass)
    {
        AcDataClass->setWindowTitle(QCoreApplication::translate("AcDataClass", "AcData", nullptr));
        pushButton->setText(QCoreApplication::translate("AcDataClass", "\345\274\200\345\247\213\347\233\221\346\265\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AcDataClass", "\345\201\234\346\255\242\347\233\221\346\265\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AcDataClass", "\351\200\200\345\207\272", nullptr));
        radioButton_3->setText(QCoreApplication::translate("AcDataClass", "\345\234\250\346\234\272\347\233\221\346\265\213", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AcDataClass", "\347\211\271\345\276\201\346\240\267\346\234\254\351\207\207\351\233\206", nullptr));
        label->setText(QCoreApplication::translate("AcDataClass", "\345\210\200\345\205\267\347\212\266\346\200\201\357\274\232", nullptr));
        label_led1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AcDataClass: public Ui_AcDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACDATA_H
