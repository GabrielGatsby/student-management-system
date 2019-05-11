/********************************************************************************
** Form generated from reading UI file 'searchone.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHONE_H
#define UI_SEARCHONE_H

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

class Ui_searchone
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *searchone)
    {
        if (searchone->objectName().isEmpty())
            searchone->setObjectName(QStringLiteral("searchone"));
        searchone->resize(400, 300);
        pushButton = new QPushButton(searchone);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 130, 93, 28));
        widget = new QWidget(searchone);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 50, 242, 55));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(searchone);

        QMetaObject::connectSlotsByName(searchone);
    } // setupUi

    void retranslateUi(QWidget *searchone)
    {
        searchone->setWindowTitle(QApplication::translate("searchone", "Form", 0));
        pushButton->setText(QApplication::translate("searchone", "\346\237\245\350\257\242\346\210\220\347\273\251", 0));
        label->setText(QApplication::translate("searchone", "\350\257\276\347\250\213\345\217\267", 0));
        label_2->setText(QApplication::translate("searchone", "\346\202\250\347\232\204\346\210\220\347\273\251", 0));
    } // retranslateUi

};

namespace Ui {
    class searchone: public Ui_searchone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHONE_H
