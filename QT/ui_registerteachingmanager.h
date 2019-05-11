/********************************************************************************
** Form generated from reading UI file 'registerteachingmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERTEACHINGMANAGER_H
#define UI_REGISTERTEACHINGMANAGER_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerteachingmanager
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;

    void setupUi(QDialog *registerteachingmanager)
    {
        if (registerteachingmanager->objectName().isEmpty())
            registerteachingmanager->setObjectName(QStringLiteral("registerteachingmanager"));
        registerteachingmanager->resize(430, 354);
        layoutWidget = new QWidget(registerteachingmanager);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 244, 200));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 6, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(registerteachingmanager);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 280, 75, 23));

        retranslateUi(registerteachingmanager);

        QMetaObject::connectSlotsByName(registerteachingmanager);
    } // setupUi

    void retranslateUi(QDialog *registerteachingmanager)
    {
        registerteachingmanager->setWindowTitle(QApplication::translate("registerteachingmanager", "\346\225\231\345\212\241\345\221\230\346\263\250\345\206\214", 0));
        label->setText(QApplication::translate("registerteachingmanager", "\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("registerteachingmanager", "\345\247\223\345\220\215", 0));
        label_3->setText(QApplication::translate("registerteachingmanager", "\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("registerteachingmanager", "\346\200\247\345\210\253\357\274\210\347\224\267/\345\245\263\357\274\211", 0));
        label_5->setText(QApplication::translate("registerteachingmanager", "\345\255\246\351\231\242", 0));
        label_7->setText(QApplication::translate("registerteachingmanager", "\345\255\246\345\216\206", 0));
        label_6->setText(QApplication::translate("registerteachingmanager", "\345\267\245\344\275\234\346\227\266\351\227\264", 0));
        pushButton->setText(QApplication::translate("registerteachingmanager", "\347\241\256\350\256\244\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class registerteachingmanager: public Ui_registerteachingmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERTEACHINGMANAGER_H
