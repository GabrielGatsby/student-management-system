#include "registerstudent.h"
#include "ui_registerstudent.h"
#include <fstream>
#include <iostream>
#include "student.h"
#include <string>
#include <QString>
#include "welcome.h"
#include <QMessageBox>
#include "hashtable.h"
using namespace std;
registerstudent::registerstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerstudent)
{
    ui->setupUi(this);
}

registerstudent::~registerstudent()
{
    delete ui;
}



void registerstudent::on_pushButton_clicked()
{ char telephone1[20];
    char number1[20];
    char name1[20];
    char password1[20];
    char sex1[5];
    char institute1[20];
    QRegExp rx("男|女");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_4->setValidator(pReg);

    QRegExp regx("[1-9][0-9]+$");
       QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
       ui->lineEdit->setValidator(validator);

       QRegExp regx1("[1-9][0-9]+$");
          QValidator *validator1 = new QRegExpValidator(regx1, ui->lineEdit_6 );
       ui->lineEdit_6->setValidator(validator1);
    std::string str = ui->lineEdit->text().toStdString();
    const char* number = str.c_str();
     str = ui->lineEdit_2->text().toStdString();
   const  char* name = str.c_str();
    str = ui->lineEdit_3->text().toStdString();
   const char* password = str.c_str();
   str = ui->lineEdit_4->text().toStdString();
  const char* sex = str.c_str();
  str = ui->lineEdit_5->text().toStdString();
 const char* institute = str.c_str();
 str = ui->lineEdit_6->text().toStdString();
const char* telephone = str.c_str();
if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||
        ui->lineEdit_4->text().isEmpty()||ui->lineEdit_5->text().isEmpty()||
        ui->lineEdit_6->text().isEmpty())
     int ret=QMessageBox::critical(this,tr("错误"),tr("每个信息必须填写"),QMessageBox::Ok);
else{
strcpy_s(number1,number);
strcpy_s(telephone1,telephone);
strcpy_s(name1,name);
strcpy_s(password1,password);
strcpy_s(sex1,sex);
strcpy_s(institute1,institute);
    Student a(number1, name1, password1, sex1, institute1, telephone1);
    Student test;
    if(Welcome::studentHash.find(number1,test))
         int ret=QMessageBox::critical(this,tr("错误"),tr("该学号已存在"),QMessageBox::Ok);
    else{
    Welcome::studentHash.insert(number1,a);
    int ret=QMessageBox::information(this,tr("提示"),tr("注册成功"),QMessageBox::Ok);
}
}
}

