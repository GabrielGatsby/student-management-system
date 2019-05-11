/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *register)
    {
        if (register->objectName().isEmpty())
            register->setObjectName(QStringLiteral("register"));
        register->resize(400, 300);
        widget = new QWidget(register);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 252, 198));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 2);


        retranslateUi(register);
        QObject::connect(buttonBox, SIGNAL(accepted()), register, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), register, SLOT(reject()));

        QMetaObject::connectSlotsByName(register);
    } // setupUi

    void retranslateUi(QDialog *register)
    {
        register->setWindowTitle(QApplication::translate("register", "Dialog", 0));
        label->setText(QApplication::translate("register", "\345\255\246\345\217\267", 0));
        label_2->setText(QApplication::translate("register", "\345\247\223\345\220\215", 0));
        label_3->setText(QApplication::translate("register", "\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("register", "\346\200\247\345\210\253", 0));
        label_5->setText(QApplication::translate("register", "\345\255\246\351\231\242", 0));
        label_6->setText(QApplication::translate("register", "\346\211\213\346\234\272\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class register: public Ui_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
