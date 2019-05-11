#include "welcome.h"
#include "ui_welcome.h"
#include "function.h"
#include "student.h"
#include "teacher.h"
#include "teachingmanager.h"
#include "teacherinterface.h"
#include "teachingmanagerinterface.h"
#include<string>
#include<QDebug>
#include<fstream>
#include<QMessageBox>
#include <QByteArray>
#include<QDebug>
#include <QMessageBox>
#include <string>
#include "studentfunction.h"
#include <iostream>
#include <fstream>
#include "course.h"
#include"registerstudent.h"
#include"registerteacher.h"
#include"registerteachingmanager.h"
#include "studentquitshcool.h"
hashdict<Student> Welcome::studentHash(10000,"0000");
  hashdict<Course>Welcome::CourseHash(10000,"0000");
  hashdict<Course>Welcome::CourseHash2(10000,"0000");
  char Welcome::userid[20];
  bool Welcome::judge;

string extern_zhanghao;

void initials()
{
    fstream instuf("student.txt", ios::in | ios::out );
    if (!instuf)
        qDebug() << "student.txt打不开";
    qDebug()<<"student.dat初始化"<<endl;
   fstream outstuf("student.dat", ios::in|ios::out | ios::binary);
    if (!outstuf)
        cout << "student.dat打不开";
    else {

       char number[20];
        char name[20];
        char password[20];
        char sex[5];
        char institute[20];
        char telephone[20];
        Student s;
        instuf>>number>>name>>password>>sex>>institute>>telephone;
        s.setnumber(number);
       s.setsex(sex);
       s.setname(name);
       s.setpassword(password);
       s.setinstitute(institute);
       s.settelephone(telephone);
       while(!endStudent(s))
       {   qDebug()<<s.getname();
           outstuf.write((char*)&s,sizeof(Student));
           instuf>>number>>name>>password>>sex>>institute>>telephone;
           s.setnumber(number);
            s.setname(name);
          s.setsex(sex);
          s.setpassword(password);
          s.setinstitute(institute);
          s.settelephone(telephone);
       }
       /* outstuf.write((char*)&a,sizeof(Student));
         outstuf.write((char*)&b,sizeof(Student));
          outstuf.write((char*)&c,sizeof(Student));
           outstuf.write((char*)&d,sizeof(Student));
            outstuf.write((char*)&e,sizeof(Student));*/
    }
    Student s1;
    outstuf.write((char*)&s1, sizeof(Student));
    outstuf.close();


}

void initialc()
{
    qDebug()<<"初始化course.dat"<<endl;

    fstream instuf("course.txt", ios::in | ios::out );
    if (!instuf)
        qDebug() << "xixi";
    fstream outstuf("course.dat", ios::in | ios::out | ios::binary);
    if (!outstuf)
        qDebug() << "hhaa";
    else {


        char cno[20];
        char cname[50];
        float credit;
        char sno[20];
        char tno[20];
        float grade;
        instuf>>cno>>cname>>credit>>sno>>tno>>grade;
        Course c(cno,cname,credit,sno,tno,grade);
        while(!endCourse(c))
        {   qDebug()<<"初始化course.dat 1条";
            //qDebug()<<c.getcname();
            outstuf.write((char*)&c,sizeof(Course));
             instuf>>cno>>cname>>credit>>sno>>tno>>grade;
             c.setcno(cno);
             c.setcname(cname);
             c.setsno(sno);
             c.setcredit(credit);
             c.setgrade(grade);
             c.settno(tno);
        }
    }
    Course ccc;

    outstuf.write((char*)&ccc, sizeof(Course));
    outstuf.close();
}
void inc() {//课程表
    qDebug()<<"初始化course2.dat"<<endl;

    fstream instuf("course2.txt", ios::in | ios::out );
    if (!instuf)
        qDebug() << "Course2txt打不开";
    fstream outstuf("course2.dat", ios::in | ios::out | ios::binary);
    if (!outstuf)
        qDebug() << "Course2dat打不开";
    else {


        char cno[20];
        char cname[50];
        float credit;
        char sno[20];
        char tno[20];
        float grade;
        instuf>>cno>>cname>>credit>>sno>>tno>>grade;
        Course c(cno,cname,credit,sno,tno,grade);
        while(!endCourse(c))
        {   qDebug()<<"初始化course2.dat 1条";
           // qDebug()<<c.getcname();
            outstuf.write((char*)&c,sizeof(Course));
             instuf>>cno>>cname>>credit>>sno>>tno>>grade;
             c.setcno(cno);
             c.setcname(cname);
             c.setsno(sno);
             c.setcredit(credit);
             c.setgrade(grade);
             c.settno(tno);
        }
    }
    Course ccc;

    outstuf.write((char*)&ccc, sizeof(Course));
    outstuf.close();
}
bool endStudent(Student& s) {
    if (!strcmp(s.getname(), "mark"))
        return true;
    else return false;
}
bool endCourse(Course& s) {
    if (!strcmp(s.getcname(), "mark"))
        return true;
    else return false;
}
void  makeStudent() {
    fstream f;
    f.open("student.dat");
    Student s;
    f.read((char*)&s, sizeof(Student));
    while (!endStudent(s))
    {
        s.studentCourse=NULL;
        Welcome::studentHash.insert(s.getnumber(), s);
        f.read((char*)&s, sizeof(Student));

    }
    f.close();
}
void addcourse()
{
    fstream f;
    Course *c=new Course;
    f.open("course.dat",ios::in);
    f.read((char*)c, sizeof(Course));

    while (!endCourse(*c))
    {
        c->next=NULL;
        Student obj;
        Welcome::studentHash.find(c->getsno(), obj);

        if (!strcmp(obj.getname(), "mark"))
            qDebug() << "没有该学生"<<endl;
        else {
            Welcome::studentHash.find2(c->getsno()).add(c);
        qDebug()<<"成功插入"<<endl;
        }
        c = new Course;

        f.read((char*)c, sizeof(Course));

    }
}

void  makeCourse() {
    fstream f;
    f.open("course.dat");
    Course s;
    f.read((char*)&s, sizeof(Course));
    while (!endCourse(s))
    {
        s.next=NULL;
        Welcome::CourseHash.insert(s.getcno(), s);
        f.read((char*)&s, sizeof(Course));

    }
    f.close();

}
void  makeCourse2() {
    fstream f;
    f.open("course2.dat");
    Course *s=new Course;
    f.read((char*)s, sizeof(Course));
    while (!endCourse(*s))
    {
        Course temp;
        s->next=NULL;
        if(Welcome::CourseHash2.find(s->getcno(),temp))
        {
            Course *t;
            t=&Welcome::CourseHash2.find2(s->getcno());
            while(t->next)
            {
                t=t->next;
            }
            t->next=s;
        }
        else{
        Welcome::CourseHash2.insert(s->getcno(), *s);
        }
        s=new Course;
        f.read((char*)s, sizeof(Course));
    }
    f.close();

}
void showstu(){
    for(int i=0;i<Welcome::studentHash.M;i++)
    {
        if(strcmp(Welcome::studentHash.HT[i].key(),Welcome::studentHash.EMPTYKEY))
        {qDebug()<<Welcome::studentHash.HT[i].value().getnumber();
            if(Welcome::studentHash.HT[i].value().studentCourse==NULL)
                ;
            else{
                Course *t=Welcome::studentHash.HT[i].value().studentCourse;
                while(t->next)
                {
                    qDebug()<<t->next->getcno();
                    t=t->next;
                }
            }
        }
    }
}

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    //初始页面

   /*initialc();
   initials();
   inc();*/
    makeStudent();
        makeCourse();
        makeCourse2();
        addcourse();
        showstu();
 Welcome::judge=false;
    ui->stackedWidget->setCurrentIndex(0);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_radioButton_clicked()//选择学生
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Welcome::on_radioButton_2_clicked()//选择教师
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Welcome::on_radioButton_3_clicked()//选择教务员
{
    ui->stackedWidget->setCurrentIndex(0);
}

//学生登录按钮
void Welcome::on_pushButton_clicked()
{
    Student obj;

    QByteArray ba=ui->lineEdit->text().toLatin1();
    char *bb=ba.data();
    strcpy_s(Welcome::userid,bb);
            bool b = Welcome::studentHash.find(Welcome::userid, obj);
            if(b==1)

            {

               QByteArray aa=ui->lineEdit_2->text().toLatin1();
                 char* ch;
                ch=aa.data();
                if (strcmp(obj.getpassword(),ch))
                int ret=QMessageBox::critical(this,tr("错误"),tr("密码错误"),QMessageBox::Ok);
                else {
                   Welcome::judge=true;
                    studentFunction *w=new studentFunction;
                    w->show();
                }
            }
        else int ret=QMessageBox::critical(this,tr("错误"),tr("用户名错误"),QMessageBox::Ok);

}

//教师登录按钮
void Welcome::on_pushButton_2_clicked()
{
    string zhanghao = qstr2str(ui->lineEdit_3->text());
    string mima = qstr2str(ui->lineEdit_4->text());
    string zhanghao_2;
    string mima_2;

    ifstream inf("teacher.dat",ios::in);
    int flag = 0;//判断账号密码是否正确标志
    Teacher tc;
    do{
        inf.read((char*)&tc, sizeof(Teacher));
        if("mark"!=QString::fromLocal8Bit(tc.getnumber())){
            zhanghao_2 = tc.getnumber();
            if(!zhanghao_2.compare(zhanghao)){
                flag = 1;//表示有此账号
                mima_2 = tc.getpassword();
                if(!mima_2.compare(mima)){
                    flag = 2;//表示账号密码完全正确
                }
                break;
            }
        }


    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getnumber()));
    inf.close();



    if(flag==0){
        QMessageBox::critical(this,tr("错误"),tr("没有找到该账号"),QMessageBox::YesAll);
    }

    if(flag==1){
        QMessageBox::critical(this,tr("错误"),tr("密码错误"),QMessageBox::YesAll);
    }

    if(flag==2){
        extern_zhanghao = zhanghao;
        TeacherInterface* w = new TeacherInterface();
        w->show();
    }


}

//教务员登录按钮
void Welcome::on_pushButton_3_clicked()
{
    string zhanghao = qstr2str(ui->lineEdit_5->text());
    string mima = qstr2str(ui->lineEdit_6->text());
    string zhanghao_2;
    string mima_2;

    ifstream inf("teachingmanager.dat",ios::in);
    int flag = 0;//判断账号密码是否正确标志
    TeachingManager tc;
    do{
        inf.read((char*)&tc, sizeof(TeachingManager));
        if("mark"!=QString::fromLocal8Bit(tc.getnumber())){
            zhanghao_2 = tc.getnumber();
            if(!zhanghao_2.compare(zhanghao)){
                flag = 1;//表示有此账号
                mima_2 = tc.getpassword();
                if(!mima_2.compare(mima)){
                    flag = 2;//表示账号密码完全正确
                }
                break;
            }
        }


    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getnumber()));
    inf.close();



    if(flag==0){
        QMessageBox::critical(this,tr("错误"),tr("没有找到该账号"),QMessageBox::YesAll);
    }

    if(flag==1){
        QMessageBox::critical(this,tr("错误"),tr("密码错误"),QMessageBox::YesAll);
    }

    if(flag==2){
        extern_zhanghao = zhanghao;

        TeachingManagerInterface* w = new TeachingManagerInterface();
        w->show();
    }

}

void Welcome::on_pushButton_4_clicked()
{
    Welcome::judge=true;
  registerstudent *w=new registerstudent;
    w->show();
}

void Welcome::on_Welcome_rejected()
{
    if(judge){
    fstream f("student.dat");
        qDebug()<<"写入";
        for(int i=0;i<Welcome::studentHash.M;i++)
        {

            if(strcmp(Welcome::studentHash.HT[i].key(),Welcome::studentHash.EMPTYKEY)&&
                    strcmp(Welcome::studentHash.HT[i].key(),Welcome::studentHash.TombStone))
                f.write((char*)&Welcome::studentHash.HT[i].value(),sizeof(Student));
        }
        Student s;
        f.write((char*)&s,sizeof(Student));
        f.close();

       f.open("course.dat");
            qDebug()<<"写入";
            for(int i=0;i<Welcome::CourseHash.M;i++)
            {

                if(strcmp(Welcome::CourseHash.HT[i].key(),Welcome::CourseHash.EMPTYKEY)&&
                        strcmp(Welcome::CourseHash.HT[i].key(),Welcome::CourseHash.TombStone)
                        )
                    f.write((char*)&Welcome::CourseHash.HT[i].value(),sizeof(Course));
            }
            Course s3;
            f.write((char*)&s3,sizeof(Course));
            f.close();

          f.open("course2.dat");
                 qDebug()<<"写入";
                 for(int i=0;i<Welcome::CourseHash2.M;i++)
                 {

                     if(strcmp(Welcome::CourseHash2.HT[i].key(),Welcome::CourseHash2.EMPTYKEY)&&
                             strcmp(Welcome::CourseHash2.HT[i].key(),Welcome::CourseHash2.TombStone))
                     {f.write((char*)&Welcome::CourseHash2.HT[i].value(),sizeof(Course));
                         Course *t=Welcome::CourseHash2.HT[i].value().next;
                         while(t)
                         {
                             qDebug()<<"course2写入dat（链表）";
                             f.write((char*)t,sizeof(Course));
                             t=t->next;
                         }
                     }
                 }

                 f.write((char*)&s3,sizeof(Course));
                 f.close();
    }

}

void Welcome::on_pushButton_5_clicked()
{

    registerteacher *w=new registerteacher;
      w->show();
}

void Welcome::on_pushButton_6_clicked()
{

    registerteachingmanager *w=new registerteachingmanager;
      w->show();
}

void Welcome::on_pushButton_7_clicked()
{
    Welcome::judge=true;
    studentQuitShcool *w=new studentQuitShcool;
    w->show();
}
