/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTreeWidget *treeWidget;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_8;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(932, 832);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 30, 851, 781));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 851, 71));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(23);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(-1, 69, 851, 41));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 120, 161, 28));
        QFont font2;
        font2.setPointSize(15);
        pushButton_6->setFont(font2);
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(190, 120, 161, 28));
        pushButton_7->setFont(font2);
        treeWidget = new QTreeWidget(widget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(420, 290, 431, 471));
        treeWidget->setHeaderHidden(true);
        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 150, 391, 611));
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(550, 120, 161, 28));
        pushButton_8->setFont(font2);
        plainTextEdit_2 = new QPlainTextEdit(widget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(420, 160, 431, 101));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 140, 54, 12));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 270, 91, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\347\274\226\350\257\221\345\216\237\347\220\206\345\256\236\351\252\2143  author\357\274\232\346\235\216\350\276\276\350\211\257", nullptr));
        label->setText(QApplication::translate("Widget", "\345\256\236\351\252\214\344\270\211\357\274\232TINY\346\211\251\345\205\205\350\257\255\350\250\200\347\232\204\350\257\255\346\263\225\346\240\221\347\224\237\346\210\220", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\247\223\345\220\215\357\274\232\346\235\216\350\276\276\350\211\257 \347\217\255\347\272\247\357\274\232\350\256\241\347\247\2211\347\217\255 \345\255\246\345\217\267\357\274\23220203231004", nullptr));
        pushButton_6->setText(QApplication::translate("Widget", "\344\270\212\344\274\240\346\272\220\347\250\213\345\272\217", nullptr));
        pushButton_7->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\346\272\220\347\250\213\345\272\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "\346\240\221\345\275\242\347\273\223\346\236\204", nullptr));
        pushButton_8->setText(QApplication::translate("Widget", "\347\224\237\346\210\220\350\257\255\346\263\225\346\240\221", nullptr));
        label_3->setText(QApplication::translate("Widget", "\347\224\237\346\210\220\347\212\266\346\200\201", nullptr));
        label_4->setText(QApplication::translate("Widget", "\350\257\255\346\263\225\346\240\221\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
