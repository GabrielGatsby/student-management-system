/********************************************************************************
** Form generated from reading UI file 'teachingmanagerinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHINGMANAGERINTERFACE_H
#define UI_TEACHINGMANAGERINTERFACE_H

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

class Ui_TeachingManagerInterface
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QWidget *page_2;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QPushButton *pushButton_6;
    QLabel *label_5;
    QWidget *page_3;
    QLabel *label_22;
    QLineEdit *lineEdit_21;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit_20;
    QLabel *label_6;
    QLabel *label_23;
    QLineEdit *lineEdit_22;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QLabel *label_4;

    void setupUi(QDialog *TeachingManagerInterface)
    {
        if (TeachingManagerInterface->objectName().isEmpty())
            TeachingManagerInterface->setObjectName(QStringLiteral("TeachingManagerInterface"));
        TeachingManagerInterface->resize(1000, 700);
        stackedWidget = new QStackedWidget(TeachingManagerInterface);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(320, 60, 611, 561));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 111, 31));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 40, 291, 41));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 140, 281, 41));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 230, 111, 31));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 140, 111, 31));
        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 240, 291, 41));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 360, 241, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 310, 161, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setBold(true);
        font.setWeight(75);
        pushButton_4->setFont(font);
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(50, 70, 511, 192));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 310, 151, 41));
        pushButton_6->setFont(font);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(340, 270, 221, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_22 = new QLabel(page_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(80, 180, 121, 41));
        label_22->setFont(font);
        lineEdit_21 = new QLineEdit(page_3);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setGeometry(QRect(230, 190, 311, 41));
        pushButton_13 = new QPushButton(page_3);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(420, 400, 111, 41));
        pushButton_13->setFont(font);
        lineEdit_20 = new QLineEdit(page_3);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(230, 90, 311, 41));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 80, 131, 41));
        label_6->setFont(font);
        label_23 = new QLabel(page_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(80, 270, 131, 51));
        label_23->setFont(font);
        lineEdit_22 = new QLineEdit(page_3);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));
        lineEdit_22->setGeometry(QRect(230, 280, 311, 41));
        stackedWidget->addWidget(page_3);
        pushButton = new QPushButton(TeachingManagerInterface);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 200, 191, 51));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(TeachingManagerInterface);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 300, 191, 51));
        pushButton_2->setFont(font);
        pushButton_5 = new QPushButton(TeachingManagerInterface);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 400, 191, 51));
        pushButton_5->setFont(font);
        label_4 = new QLabel(TeachingManagerInterface);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 120, 221, 41));
        label_4->setFont(font);

        retranslateUi(TeachingManagerInterface);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TeachingManagerInterface);
    } // setupUi

    void retranslateUi(QDialog *TeachingManagerInterface)
    {
        TeachingManagerInterface->setWindowTitle(QApplication::translate("TeachingManagerInterface", "\350\200\201\345\270\210\346\202\250\345\245\275", 0));
        label->setText(QApplication::translate("TeachingManagerInterface", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("TeachingManagerInterface", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0));
        label_3->setText(QApplication::translate("TeachingManagerInterface", "\345\255\246\347\224\237\345\247\223\345\220\215\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("TeachingManagerInterface", "\347\241\256\350\256\244\346\237\245\350\257\242", 0));
        pushButton_4->setText(QApplication::translate("TeachingManagerInterface", "\347\241\256\350\256\244\346\237\245\350\257\242", 0));
        pushButton_6->setText(QApplication::translate("TeachingManagerInterface", "\345\255\230\345\202\250\350\241\250\346\240\274", 0));
        label_5->setText(QApplication::translate("TeachingManagerInterface", "\351\231\204\346\263\250\357\274\232-1\344\273\243\350\241\250\350\201\224\347\263\273\346\226\271\345\274\217\346\232\202\346\227\240", 0));
        label_22->setText(QApplication::translate("TeachingManagerInterface", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton_13->setText(QApplication::translate("TeachingManagerInterface", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
        label_6->setText(QApplication::translate("TeachingManagerInterface", "\350\257\267\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201\357\274\232", 0));
        label_23->setText(QApplication::translate("TeachingManagerInterface", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton->setText(QApplication::translate("TeachingManagerInterface", "\346\237\245\350\257\242\346\237\220\344\270\200\345\255\246\347\224\237\350\201\224\347\263\273\346\226\271\345\274\217", 0));
        pushButton_2->setText(QApplication::translate("TeachingManagerInterface", "\346\237\245\350\257\242\346\211\200\346\234\211\346\234\254\347\263\273\345\255\246\347\224\237\350\201\224\347\263\273\346\226\271\345\274\217", 0));
        pushButton_5->setText(QApplication::translate("TeachingManagerInterface", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("TeachingManagerInterface", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TeachingManagerInterface: public Ui_TeachingManagerInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHINGMANAGERINTERFACE_H
