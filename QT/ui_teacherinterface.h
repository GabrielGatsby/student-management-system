/********************************************************************************
** Form generated from reading UI file 'teacherinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERINTERFACE_H
#define UI_TEACHERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherInterface
{
public:
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_24;
    QWidget *page_2;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QLabel *label_11;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLabel *label_13;
    QLineEdit *lineEdit_11;
    QLabel *label_14;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_14;
    QLabel *label_25;
    QWidget *page_3;
    QLabel *label_15;
    QLineEdit *lineEdit_13;
    QPushButton *pushButton_7;
    QWidget *page_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_9;
    QWidget *page_5;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_11;
    QWidget *page_6;
    QLabel *label_6;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QPushButton *pushButton_13;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;

    void setupUi(QDialog *TeacherInterface)
    {
        if (TeacherInterface->objectName().isEmpty())
            TeacherInterface->setObjectName(QStringLiteral("TeacherInterface"));
        TeacherInterface->resize(1000, 700);
        pushButton = new QPushButton(TeacherInterface);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 191, 101));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        stackedWidget = new QStackedWidget(TeacherInterface);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 0, 741, 751));
        QFont font1;
        font1.setPointSize(12);
        stackedWidget->setFont(font1);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 70, 471, 81));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 80, 201, 61));
        label_3->setFont(font);
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 220, 171, 51));
        label_4->setFont(font);
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(240, 210, 471, 71));
        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(240, 320, 471, 71));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 330, 211, 41));
        label_5->setFont(font);
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 540, 331, 71));
        pushButton_2->setFont(font);
        label_24 = new QLabel(page);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(70, 360, 151, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 40, 141, 41));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 191, 31));
        lineEdit_5 = new QLineEdit(page_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(220, 40, 341, 41));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(490, 230, 111, 31));
        lineEdit_7 = new QLineEdit(page_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(610, 240, 113, 20));
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(95, 140, 341, 411));
        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(610, 190, 113, 20));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(490, 190, 81, 16));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(490, 280, 91, 31));
        lineEdit_8 = new QLineEdit(page_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(610, 290, 113, 20));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(490, 340, 91, 21));
        lineEdit_9 = new QLineEdit(page_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(610, 340, 113, 20));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(490, 390, 101, 21));
        lineEdit_10 = new QLineEdit(page_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(610, 390, 113, 20));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(490, 440, 111, 21));
        lineEdit_11 = new QLineEdit(page_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(610, 440, 113, 20));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(490, 480, 111, 31));
        lineEdit_12 = new QLineEdit(page_2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(610, 490, 113, 20));
        pushButton_14 = new QPushButton(page_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(540, 600, 111, 31));
        label_25 = new QLabel(page_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(210, 560, 211, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_15 = new QLabel(page_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(270, 110, 161, 31));
        label_15->setFont(font);
        lineEdit_13 = new QLineEdit(page_3);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(140, 160, 391, 41));
        pushButton_7 = new QPushButton(page_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(230, 280, 201, 51));
        pushButton_7->setFont(font);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_16 = new QLabel(page_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(210, 30, 381, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_16->setFont(font2);
        label_17 = new QLabel(page_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(90, 110, 131, 51));
        label_17->setFont(font);
        label_18 = new QLabel(page_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(90, 170, 131, 41));
        label_18->setFont(font);
        label_19 = new QLabel(page_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(90, 230, 131, 41));
        label_19->setFont(font);
        lineEdit_14 = new QLineEdit(page_4);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(230, 110, 411, 41));
        lineEdit_15 = new QLineEdit(page_4);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(230, 170, 411, 41));
        lineEdit_16 = new QLineEdit(page_4);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(230, 230, 411, 41));
        pushButton_9 = new QPushButton(page_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(170, 560, 191, 51));
        pushButton_9->setFont(font);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label = new QLabel(page_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 140, 151, 41));
        label->setFont(font);
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 151, 41));
        label_2->setFont(font);
        lineEdit_4 = new QLineEdit(page_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(240, 60, 381, 51));
        lineEdit_19 = new QLineEdit(page_5);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(240, 140, 371, 51));
        pushButton_11 = new QPushButton(page_5);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(490, 250, 171, 41));
        pushButton_11->setFont(font);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_6 = new QLabel(page_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 80, 171, 41));
        label_6->setFont(font);
        label_22 = new QLabel(page_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(90, 170, 161, 41));
        label_22->setFont(font);
        label_23 = new QLabel(page_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(90, 270, 171, 51));
        label_23->setFont(font);
        lineEdit_20 = new QLineEdit(page_6);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(280, 90, 311, 41));
        lineEdit_21 = new QLineEdit(page_6);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setGeometry(QRect(280, 190, 311, 41));
        lineEdit_22 = new QLineEdit(page_6);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));
        lineEdit_22->setGeometry(QRect(280, 280, 311, 41));
        pushButton_13 = new QPushButton(page_6);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(470, 400, 111, 41));
        pushButton_13->setFont(font);
        stackedWidget->addWidget(page_6);
        pushButton_3 = new QPushButton(TeacherInterface);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 190, 191, 91));
        pushButton_3->setFont(font);
        pushButton_5 = new QPushButton(TeacherInterface);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 490, 91, 23));
        pushButton_6 = new QPushButton(TeacherInterface);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 280, 191, 81));
        pushButton_6->setFont(font);
        pushButton_8 = new QPushButton(TeacherInterface);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 360, 191, 81));
        pushButton_8->setFont(font);
        pushButton_10 = new QPushButton(TeacherInterface);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(0, 100, 191, 91));
        pushButton_10->setFont(font);
        pushButton_12 = new QPushButton(TeacherInterface);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(0, 440, 191, 81));
        pushButton_12->setFont(font);

        retranslateUi(TeacherInterface);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(TeacherInterface);
    } // setupUi

    void retranslateUi(QDialog *TeacherInterface)
    {
        TeacherInterface->setWindowTitle(QApplication::translate("TeacherInterface", "\350\200\201\345\270\210\346\202\250\345\245\275", 0));
        pushButton->setText(QApplication::translate("TeacherInterface", "\346\267\273\345\212\240\346\210\226\344\277\256\346\224\271\345\255\246\347\224\237\346\210\220\347\273\251", 0));
        label_3->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\255\246\345\217\267", 0));
        label_4->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215", 0));
        label_5->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\344\277\256\346\224\271\346\210\226\346\267\273\345\212\240\347\232\204\346\210\220\347\273\251", 0));
        pushButton_2->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244", 0));
        label_24->setText(QApplication::translate("TeacherInterface", "\357\274\210\346\210\220\347\273\251\346\227\240\350\257\267\350\276\223\345\205\245-1\357\274\211", 0));
        pushButton_4->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244\346\237\245\350\257\242", 0));
        label_7->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\347\232\204\350\257\276\347\250\213\345\220\215:", 0));
        label_9->setText(QApplication::translate("TeacherInterface", "\346\234\211\346\210\220\347\273\251\347\232\204\344\272\272\346\225\260", 0));
        label_8->setText(QApplication::translate("TeacherInterface", "\346\200\273\344\272\272\346\225\260", 0));
        label_10->setText(QApplication::translate("TeacherInterface", "\345\271\263\345\235\207\345\210\206", 0));
        label_11->setText(QApplication::translate("TeacherInterface", "\346\234\200\351\253\230\345\210\206", 0));
        label_12->setText(QApplication::translate("TeacherInterface", "\346\234\200\344\275\216\345\210\206", 0));
        label_13->setText(QApplication::translate("TeacherInterface", "\344\270\215\345\217\212\346\240\274\344\272\272\346\225\260", 0));
        label_14->setText(QApplication::translate("TeacherInterface", "\345\217\212\346\240\274\347\216\207", 0));
        pushButton_14->setText(QApplication::translate("TeacherInterface", "\345\255\230\345\202\250\350\241\250\346\240\274", 0));
        label_25->setText(QApplication::translate("TeacherInterface", "\351\231\204\346\263\250\357\274\232-1\344\273\243\350\241\250\346\210\220\347\273\251\346\232\202\346\227\240", 0));
        label_15->setText(QApplication::translate("TeacherInterface", "\345\210\240\351\231\244\350\257\276\347\250\213\347\232\204\345\220\215\345\255\227", 0));
        pushButton_7->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244\345\210\240\351\231\244", 0));
        label_16->setText(QApplication::translate("TeacherInterface", "\350\257\267\346\267\273\345\212\240\351\234\200\346\267\273\345\212\240\350\257\276\347\250\213\347\232\204\344\277\241\346\201\257", 0));
        label_17->setText(QApplication::translate("TeacherInterface", "\345\210\235\345\247\213\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        label_18->setText(QApplication::translate("TeacherInterface", "\345\210\235\345\247\213\350\257\276\347\250\213\345\220\215\345\255\227", 0));
        label_19->setText(QApplication::translate("TeacherInterface", "\345\210\235\345\247\213\350\257\276\347\250\213\345\255\246\345\210\206", 0));
        pushButton_9->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244\346\267\273\345\212\240", 0));
        label->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215\357\274\232", 0));
        pushButton_11->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244\345\210\240\351\231\244", 0));
        label_6->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201\357\274\232", 0));
        label_22->setText(QApplication::translate("TeacherInterface", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        label_23->setText(QApplication::translate("TeacherInterface", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton_13->setText(QApplication::translate("TeacherInterface", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
        pushButton_3->setText(QApplication::translate("TeacherInterface", "\346\237\245\350\257\242\350\257\276\347\250\213\346\210\220\347\273\251\344\277\241\346\201\257", 0));
        pushButton_5->setText(QApplication::translate("TeacherInterface", "\351\207\215\347\275\256\345\220\204\347\247\215\344\277\241\346\201\257", 0));
        pushButton_6->setText(QApplication::translate("TeacherInterface", " \345\210\240\351\231\244\350\257\276\347\250\213", 0));
        pushButton_8->setText(QApplication::translate("TeacherInterface", "\346\267\273\345\212\240\350\257\276\347\250\213", 0));
        pushButton_10->setText(QApplication::translate("TeacherInterface", "\345\210\240\351\231\244\345\255\246\347\224\237\346\210\220\347\273\251", 0));
        pushButton_12->setText(QApplication::translate("TeacherInterface", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class TeacherInterface: public Ui_TeacherInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERINTERFACE_H
