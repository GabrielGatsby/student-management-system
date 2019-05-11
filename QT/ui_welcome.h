/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QStackedWidget *stackedWidget;
    QWidget *student;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_3;
    QWidget *teacher;
    QPushButton *pushButton;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *teachingmanager;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_10;
    QRadioButton *radioButton;

    void setupUi(QDialog *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(637, 434);
        stackedWidget = new QStackedWidget(Welcome);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 130, 254, 161));
        student = new QWidget();
        student->setObjectName(QStringLiteral("student"));
        widget = new QWidget(student);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 40, 234, 106));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_3->addWidget(lineEdit_5, 0, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 2, 1, 1, 1);

        stackedWidget->addWidget(student);
        teacher = new QWidget();
        teacher->setObjectName(QStringLiteral("teacher"));
        pushButton = new QPushButton(teacher);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 110, 171, 31));
        widget1 = new QWidget(teacher);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 40, 234, 71));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        stackedWidget->addWidget(teacher);
        teachingmanager = new QWidget();
        teachingmanager->setObjectName(QStringLiteral("teachingmanager"));
        widget2 = new QWidget(teachingmanager);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 30, 234, 106));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 2, 1, 1, 1);

        stackedWidget->addWidget(teachingmanager);
        radioButton_2 = new QRadioButton(Welcome);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(250, 380, 71, 16));
        radioButton_3 = new QRadioButton(Welcome);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(350, 380, 89, 16));
        pushButton_4 = new QPushButton(Welcome);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(520, 150, 81, 28));
        pushButton_5 = new QPushButton(Welcome);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 190, 81, 31));
        pushButton_6 = new QPushButton(Welcome);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(520, 240, 81, 31));
        pushButton_7 = new QPushButton(Welcome);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(520, 290, 81, 28));
        label_10 = new QLabel(Welcome);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 40, 501, 71));
        radioButton = new QRadioButton(Welcome);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(140, 380, 61, 16));

        retranslateUi(Welcome);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QDialog *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "\346\254\242\350\277\216\344\275\277\347\224\250\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        label_8->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\264\246\345\217\267</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\257\206\347\240\201</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("Welcome", "\347\241\256\350\256\244", 0));
        pushButton->setText(QApplication::translate("Welcome", "\347\241\256\350\256\244", 0));
        label_2->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\264\246\345\217\267</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\257\206\347\240\201</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\264\246\345\217\267</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\257\206\347\240\201</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("Welcome", "\347\241\256\350\256\244", 0));
        radioButton_2->setText(QApplication::translate("Welcome", "\346\225\231\345\270\210", 0));
        radioButton_3->setText(QApplication::translate("Welcome", "\346\225\231\345\212\241\345\221\230", 0));
        pushButton_4->setText(QApplication::translate("Welcome", "\345\255\246\347\224\237\346\263\250\345\206\214", 0));
        pushButton_5->setText(QApplication::translate("Welcome", "\346\225\231\345\270\210\346\263\250\345\206\214", 0));
        pushButton_6->setText(QApplication::translate("Welcome", "\346\225\231\345\212\241\345\221\230\346\263\250\345\206\214", 0));
        pushButton_7->setText(QApplication::translate("Welcome", "\345\255\246\347\224\237\346\263\250\351\224\200", 0));
        label_10->setText(QApplication::translate("Welcome", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237\347\231\273\345\275\225</span></p></body></html>", 0));
        radioButton->setText(QApplication::translate("Welcome", "\345\255\246\347\224\237", 0));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
