#include "select.h"
#include "ui_select.h"
#include "course.h"
#include "student.h"
#include "register.h"
#include <QDebug>
#include "hashtable.h"
#include <QMessageBox>
select::select(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select)
{
    ui->setupUi(this);
}

select::~select()
{
    delete ui;
}

void select::on_pushButton_clicked()
{

    Course *c=new Course;
        Student s;
        QByteArray aa=ui->lineEdit->text().toLatin1();
         char* bb;
         bb=aa.data();

        if (!Register::CourseHash2.find(bb, *c))
            int ret=QMessageBox::critical(this,tr("错误"),tr("课程不存在"),QMessageBox::YesAll);
        else {
            if (!Register::studentHash.find(Register::userid, s))
            {
                qDebug()<<Register::userid<<endl;
                int ret=QMessageBox::critical(this,tr("错误"),tr("学号不存在"),QMessageBox::YesAll);
            }
            else {
                c->setsno(Register::userid);
                Register::studentHash.find2(Register::userid).add(c);

                Register::CourseHash.insert(c->getcno(),*c);
                int ret =QMessageBox::information(this,tr("提示"),tr("选课成功"),QMessageBox::Ok);

            }
        }
}
