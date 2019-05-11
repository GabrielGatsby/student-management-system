/********************************************************************************
** Form generated from reading UI file 'studentquitshcool.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTQUITSHCOOL_H
#define UI_STUDENTQUITSHCOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentQuitShcool
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *studentQuitShcool)
    {
        if (studentQuitShcool->objectName().isEmpty())
            studentQuitShcool->setObjectName(QStringLiteral("studentQuitShcool"));
        studentQuitShcool->resize(400, 300);
        layoutWidget = new QWidget(studentQuitShcool);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 80, 291, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);


        retranslateUi(studentQuitShcool);

        QMetaObject::connectSlotsByName(studentQuitShcool);
    } // setupUi

    void retranslateUi(QWidget *studentQuitShcool)
    {
        studentQuitShcool->setWindowTitle(QApplication::translate("studentQuitShcool", "\345\255\246\347\224\237\351\200\200\345\255\246", 0));
        label->setText(QApplication::translate("studentQuitShcool", "\345\255\246\345\217\267", 0));
        label_2->setText(QApplication::translate("studentQuitShcool", "\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("studentQuitShcool", "\347\241\256\350\256\244\346\263\250\351\224\200", 0));
    } // retranslateUi

};

namespace Ui {
    class studentQuitShcool: public Ui_studentQuitShcool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTQUITSHCOOL_H
