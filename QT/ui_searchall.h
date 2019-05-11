/********************************************************************************
** Form generated from reading UI file 'searchall.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHALL_H
#define UI_SEARCHALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchall
{
public:
    QTableView *stu_info;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *searchall)
    {
        if (searchall->objectName().isEmpty())
            searchall->setObjectName(QStringLiteral("searchall"));
        searchall->resize(811, 441);
        stu_info = new QTableView(searchall);
        stu_info->setObjectName(QStringLiteral("stu_info"));
        stu_info->setGeometry(QRect(0, 0, 602, 441));
        pushButton = new QPushButton(searchall);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 90, 121, 28));
        lineEdit = new QLineEdit(searchall);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(660, 170, 113, 21));

        retranslateUi(searchall);

        QMetaObject::connectSlotsByName(searchall);
    } // setupUi

    void retranslateUi(QWidget *searchall)
    {
        searchall->setWindowTitle(QApplication::translate("searchall", "Form", 0));
        pushButton->setText(QApplication::translate("searchall", "\347\224\237\346\210\220excel\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class searchall: public Ui_searchall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHALL_H
