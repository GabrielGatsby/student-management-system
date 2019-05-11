#include "searchone.h"
#include "ui_searchone.h"
#include "register.h"
#include "hashtable.h"
#include <QByteArray>
#include <QString>
#include <QMessageBox>
#include <QDebug>
using namespace std;
searchone::searchone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchone)
{
    ui->setupUi(this);
}

searchone::~searchone()
{
    delete ui;
}

void searchone::on_pushButton_clicked()
{
    char *k;

        Student s;
         Register::studentHash.find(Register::userid, s);
         qDebug()<<s.getnumber();
         qDebug()<<Register::userid;
         QByteArray aa=ui->lineEdit->text().toLatin1();
         k=aa.data();
            Course *t = s.studentCourse;
            if(t==NULL)
            {
                int ret=QMessageBox::information(this,tr("提示"),tr("您没有选修课程"),QMessageBox::Ok);

            }
            else{
            while (t->next)
            {
                if (!strcmp(t->next->getcno(), k))
                {
                   // cout << t->next->getgrade() << endl;
                    if(t->next->getgrade()==-1)
                        int ret=QMessageBox::information(this,tr("提示"),tr("该课程暂时没有成绩，请等待期末考试！"),QMessageBox::Ok);
                     QString data = QString("%1").arg(t->next->getgrade());
                    ui->lineEdit_2->setText(data);
                    break;
                }
                else t = t->next;
            }
           if(t->next==NULL)
             int ret=QMessageBox::critical(this,tr("错误"),tr("您没有选该课程"),QMessageBox::Ok);
           }
}
