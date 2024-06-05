/********************************************************************************
** Form generated from reading UI file 'history_data.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_DATA_H
#define UI_HISTORY_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <qwchartview.h>

QT_BEGIN_NAMESPACE

class Ui_history_data
{
public:
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actQuit;
    QAction *actZoomReset;
    QLabel *lab;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QWChartView *chartView;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_6;

    void setupUi(QWidget *history_data)
    {
        if (history_data->objectName().isEmpty())
            history_data->setObjectName(QString::fromUtf8("history_data"));
        history_data->resize(1159, 653);
        actZoomIn = new QAction(history_data);
        actZoomIn->setObjectName(QString::fromUtf8("actZoomIn"));
        actZoomOut = new QAction(history_data);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        actQuit = new QAction(history_data);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        actZoomReset = new QAction(history_data);
        actZoomReset->setObjectName(QString::fromUtf8("actZoomReset"));
        lab = new QLabel(history_data);
        lab->setObjectName(QString::fromUtf8("lab"));
        lab->setGeometry(QRect(25, 457, 16, 16));
        gridLayout_3 = new QGridLayout(history_data);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        chartView = new QWChartView(history_data);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setMinimumSize(QSize(0, 300));

        gridLayout_3->addWidget(chartView, 0, 1, 2, 3);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        widget = new QWidget(history_data);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(300, 200));

        gridLayout_2->addWidget(textBrowser, 0, 0, 4, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 35));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 35));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(150, 35));

        gridLayout_2->addWidget(pushButton_3, 2, 1, 1, 1);


        gridLayout_3->addWidget(widget, 2, 0, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(103, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        widget_2 = new QWidget(history_data);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(widget_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_4, 0, 2, 1, 1);

        radioButton_2 = new QRadioButton(widget_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_5, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 2);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);


        gridLayout_3->addWidget(widget_2, 2, 3, 1, 2);


        retranslateUi(history_data);

        QMetaObject::connectSlotsByName(history_data);
    } // setupUi

    void retranslateUi(QWidget *history_data)
    {
        history_data->setWindowTitle(QCoreApplication::translate("history_data", "history_data", nullptr));
        actZoomIn->setText(QCoreApplication::translate("history_data", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("history_data", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("history_data", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("history_data", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("history_data", "\351\200\200\345\207\272", nullptr));
        actZoomReset->setText(QCoreApplication::translate("history_data", "\345\216\237\345\247\213\345\260\272\345\257\270", nullptr));
#if QT_CONFIG(tooltip)
        actZoomReset->setToolTip(QCoreApplication::translate("history_data", "\345\216\237\345\247\213\345\260\272\345\257\270", nullptr));
#endif // QT_CONFIG(tooltip)
        lab->setText(QString());
        pushButton->setText(QCoreApplication::translate("history_data", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("history_data", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("history_data", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        radioButton->setText(QCoreApplication::translate("history_data", "\346\226\260\345\210\200\346\240\267\346\234\254\351\207\207\351\233\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("history_data", "\346\270\205\347\251\272\346\226\260\345\210\200\346\240\267\346\234\254", nullptr));
        radioButton_2->setText(QCoreApplication::translate("history_data", "\345\264\251\345\210\203\346\240\267\346\234\254\351\207\207\351\233\206", nullptr));
        pushButton_5->setText(QCoreApplication::translate("history_data", "\346\270\205\347\251\272\345\264\251\345\210\203\346\240\267\346\234\254", nullptr));
        pushButton_6->setText(QCoreApplication::translate("history_data", "\350\256\255\347\273\203\346\250\241\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history_data: public Ui_history_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_DATA_H
