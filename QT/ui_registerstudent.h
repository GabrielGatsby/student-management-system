/********************************************************************************
** Form generated from reading UI file 'registerstudent.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERSTUDENT_H
#define UI_REGISTERSTUDENT_H

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

class Ui_registerstudent
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_5;

    void setupUi(QDialog *registerstudent)
    {
        if (registerstudent->objectName().isEmpty())
            registerstudent->setObjectName(QStringLiteral("registerstudent"));
        registerstudent->resize(400, 300);
        pushButton = new QPushButton(registerstudent);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 240, 93, 28));
        layoutWidget = new QWidget(registerstudent);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 227, 200));
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

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(registerstudent);

        QMetaObject::connectSlotsByName(registerstudent);
    } // setupUi

    void retranslateUi(QDialog *registerstudent)
    {
        registerstudent->setWindowTitle(QApplication::translate("registerstudent", "\345\255\246\347\224\237\346\263\250\345\206\214", 0));
        pushButton->setText(QApplication::translate("registerstudent", "ok", 0));
        lineEdit->setInputMask(QString());
        label->setText(QApplication::translate("registerstudent", "\345\255\246\345\217\267", 0));
        label_2->setText(QApplication::translate("registerstudent", "\345\247\223\345\220\215", 0));
        label_3->setText(QApplication::translate("registerstudent", "\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("registerstudent", "\346\200\247\345\210\253", 0));
        label_6->setText(QApplication::translate("registerstudent", "\346\211\213\346\234\272\345\217\267", 0));
        label_5->setText(QApplication::translate("registerstudent", "\345\255\246\351\231\242", 0));
    } // retranslateUi

};

namespace Ui {
    class registerstudent: public Ui_registerstudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERSTUDENT_H
