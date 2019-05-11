/********************************************************************************
** Form generated from reading UI file 'select.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H

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

class Ui_select
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *select)
    {
        if (select->objectName().isEmpty())
            select->setObjectName(QStringLiteral("select"));
        select->resize(400, 300);
        pushButton = new QPushButton(select);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 130, 93, 28));
        layoutWidget = new QWidget(select);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 100, 252, 23));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        retranslateUi(select);

        QMetaObject::connectSlotsByName(select);
    } // setupUi

    void retranslateUi(QWidget *select)
    {
        select->setWindowTitle(QApplication::translate("select", "Form", 0));
        pushButton->setText(QApplication::translate("select", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("select", "\350\257\276\347\250\213\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class select: public Ui_select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
