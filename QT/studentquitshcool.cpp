#include "studentquitshcool.h"
#include "ui_studentquitshcool.h"
#include "welcome.h"
#include "hashtable.h"
#include <QMessageBox>
using namespace std;
studentQuitShcool::studentQuitShcool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentQuitShcool)
{
    ui->setupUi(this);
}

studentQuitShcool::~studentQuitShcool()
{
    delete ui;
}

void studentQuitShcool::on_pushButton_clicked()
{
    std::string str = ui->lineEdit->text().toStdString();
    const char* ch = str.c_str();
     str = ui->lineEdit_2->text().toStdString();
    const char* ph = str.c_str();
    char sno[20];
    char password[20];
    strcpy_s(sno,ch);
    strcpy_s(password,ph);
    Student t;
    if(Welcome::studentHash.find(sno,t))
    {
        if(strcmp(password,t.getpassword()))
        {
            int ret=QMessageBox::critical(this,tr("错误"),tr("密码错误"),QMessageBox::Ok);
        }
        else{
            Welcome::studentHash.remove(sno);
            for(int i=0;i<Welcome::CourseHash.M;i++)
            {
                if(!strcmp(Welcome::CourseHash.HT[i].value().getsno(),sno))
                    Welcome::CourseHash.HT[i].setKey(Welcome::CourseHash.TombStone);
            }
            int ret=QMessageBox::information(this,tr("提示"),tr("退学成功"),QMessageBox::Ok);
        }
    }
    else{
        int ret=QMessageBox::critical(this,tr("错误"),tr("学号不存在"),QMessageBox::Ok);
    }
}
