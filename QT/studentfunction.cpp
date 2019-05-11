#include "studentfunction.h"
#include "ui_studentfunction.h"
#include "select.h"
#include "searchone.h"
#include "Welcome.h"
#include "searchall.h"
#include "hashtable.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <course.h>
#include <QTableView>
#include <QAxObject>
#include <QAxWidget>
#include <QDir>
#include <QFileDialog>
#include<sstream>
#include <QStandardItem>
#include "function.h"


using namespace std;
studentFunction::studentFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentFunction)
{
    ui->setupUi(this);
}

studentFunction::~studentFunction()
{
    delete ui;
}

void studentFunction::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}

void studentFunction::on_pushButton_2_clicked()//search one
{
    ui->stackedWidget->setCurrentIndex(2);

}


void studentFunction::on_pushButton_3_clicked()  //查询学分
{  ui->stackedWidget->setCurrentIndex(1);
    Student s;
     Welcome::studentHash.find(Welcome::userid, s);

        Course *t = s.studentCourse;
        float total=0;
        if(t==NULL)
        {
            int ret=QMessageBox::information(this,tr("提示"),tr("您没有选修课程"),QMessageBox::Ok);

        }
        else{
        while (t->next)
        {
            total+=t->next->getcredit();
            t = t->next;
        }
        QString data = QString("%1").arg(total);
        ui->lineEdit->clear();
       ui->lineEdit->setText(data);
        }
}
QStandardItemModel *studentFunction::tableModel;
void studentFunction::on_pushButton_4_clicked()   //searchall
{
    ui->stackedWidget->setCurrentIndex(3);

    studentFunction::tableModel= new QStandardItemModel();
    //QStandardItemModel *studentFunction::tableModel = new QStandardItemModel();

       studentFunction::tableModel->setColumnCount(5);
       studentFunction::tableModel->setHeaderData(0,Qt::Horizontal,tr("课程号"));
       studentFunction::tableModel->setHeaderData(1,Qt::Horizontal,tr("课程名"));
       studentFunction::tableModel->setHeaderData(2,Qt::Horizontal,tr("学分"));
       studentFunction::tableModel->setHeaderData(3,Qt::Horizontal,tr("教师号"));
       studentFunction::tableModel->setHeaderData(4,Qt::Horizontal,tr("成绩"));

       studentFunction::tableModel->setSortRole(1);


       Student s;
       int i=0;
       qDebug()<<Welcome::userid;
       Welcome::studentHash.find(Welcome::userid,s);
       qDebug()<<s.getnumber();

       Course *t=s.studentCourse;
       if(t==NULL)
       {
           int ret=QMessageBox::information(this,tr("提示"),tr("您没有选修课程"),QMessageBox::Ok);

       }
       else{
       while(t->next)
       {
         QString nn = QString(QLatin1String(t->next->getcno()));
           QStandardItem *cno=new QStandardItem(nn);
           studentFunction::tableModel->setItem(i,0,cno);


           //nn = QString(QLatin1String(t->next->getcname()));
           //QStandardItem *cname=new QStandardItem(nn);
           //studentFunction::tableModel->setItem(i,1,cname);
           string nnn = t->next->getcname();
           QString nnnn = str2qstr(nnn);
           QStandardItem *cname=new QStandardItem(nnnn);
           studentFunction::tableModel->setItem(i,1,cname);


            QString data = QString("%1").arg(t->next->getcredit());
            QStandardItem *credit=new QStandardItem(data);
            studentFunction::tableModel->setItem(i,2,credit);

            nn = QString(QLatin1String(t->next->gettno()));
            QStandardItem *tno=new QStandardItem(nn);
            studentFunction::tableModel->setItem(i,3,tno);

            data = QString("%1").arg(t->next->getgrade());
            QStandardItem *grade=new QStandardItem(data);
            studentFunction::tableModel->setItem(i,4,grade);

        t=t->next;
        i++;
       }
   }
       ui->stu_info->setModel(studentFunction::tableModel);
       ui->stu_info->setColumnWidth(0,120);
        ui->stu_info->setColumnWidth(1,120);
         ui->stu_info->setColumnWidth(2,120);
          ui->stu_info->setColumnWidth(3,120);
           ui->stu_info->setColumnWidth(4,120);
       ui->stu_info->verticalHeader()->hide();

     //  ui->stu_info->setColumnWidth(0,100);
       ui->stu_info->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void studentFunction::on_pushButton_6_clicked()  //searchone
{char *k;
 char *tno;
    Student s;
     Welcome::studentHash.find(Welcome::userid, s);
     QByteArray aa=ui->lineEdit_3->text().toLatin1();
     k=aa.data();
     QByteArray bb=ui->lineEdit_15->text().toLocal8Bit();
     tno=bb.data();
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
               if(!strcmp(t->next->gettno(),tno))
               {
               // cout << t->next->getgrade() << endl;
                if(t->next->getgrade()==-1)
    int ret=QMessageBox::information(this,tr("提示"),tr("该课程暂时没有成绩，请等待期末考试！"),QMessageBox::Ok);
                else{
                 QString data = QString("%1").arg(t->next->getgrade());
                ui->lineEdit_4->setText(data);
                }
                break;
               }
               else{
                   t=t->next;
               }
            }
            else t = t->next;
        }
       if(t->next==NULL)
         int ret=QMessageBox::critical(this,tr("错误"),tr("您没有选该课程"),QMessageBox::Ok);
       }

}



void studentFunction::on_pushButton_5_clicked()//select
{
    Course *c=new Course;
        Student s;
        QByteArray aa=ui->lineEdit_2->text().toLatin1();
         char* bb;
         bb=aa.data();
         QByteArray tno1=ui->lineEdit_5->text().toLatin1();
          char* tnochar;
          tnochar=tno1.data();
        if (!Welcome::CourseHash2.find(bb, *c))
           { int ret=QMessageBox::critical(this,tr("错误"),tr("课程号不存在"),QMessageBox::YesAll);
        }
        else {

            while(c!=NULL&&strcmp(c->gettno(),tnochar))
             {
                  c=c->next;
             }
            if(c==NULL)
                int ret=QMessageBox::critical(this,tr("错误"),tr("该教师没有这门课"),QMessageBox::YesAll);
            else{
            if (!Welcome::studentHash.find(Welcome::userid, s))
            {
                qDebug()<<Welcome::userid<<endl;
                int ret=QMessageBox::critical(this,tr("错误"),tr("学号不存在"),QMessageBox::YesAll);
            }
            else{
                Course *tt=Welcome::studentHash.find2(Welcome::userid).studentCourse;
               if(tt==NULL){
                Course *cc=new Course;
                cc->setcno(c->getcno());
                cc->setcname(c->getcname());
                cc->setcredit(c->getcredit());
                cc->setgrade(c->getgrade());
                cc->settno(c->gettno());

                cc->setsno(Welcome::userid);
                Welcome::studentHash.find2(Welcome::userid).add(cc);

                Welcome::CourseHash.insert(cc->getcno(),*cc);
                int ret =QMessageBox::information(this,tr("提示"),tr("选课成功"),QMessageBox::Ok);
               }
               else{
                   bool flag=true;
                   while(tt->next)
                   {
                       if(!strcmp(tt->next->getcno(),bb))
                       {
                        if(!strcmp(tt->next->gettno(),tnochar))
                        {
           int ret =QMessageBox::critical(this,tr("错误"),tr("您已经选了这门课，不可重复选课"),QMessageBox::Ok);
                        flag=false;
                        break;
                        }
                        else tt=tt->next;
                       }
                       else{
                           tt=tt->next;
                       }
                   }
                   if(flag)
                   {
                       Course *cc=new Course;
                       cc->setcno(c->getcno());
                       cc->setcname(c->getcname());
                       cc->setcredit(c->getcredit());
                       cc->setgrade(c->getgrade());
                       cc->settno(c->gettno());

                       cc->setsno(Welcome::userid);
                       Welcome::studentHash.find2(Welcome::userid).add(cc);

                       Welcome::CourseHash.insert(cc->getcno(),*cc);
                       int ret =QMessageBox::information(this,tr("提示"),tr("选课成功"),QMessageBox::Ok);
                   }
                }
            }
        }
}
}

void studentFunction::on_pushButton_7_clicked()//生成成绩单
{

    QString filepath=QFileDialog::getSaveFileName
            (NULL,QObject::tr("Save orbit"),"/untitled.xls",
             QObject::tr("Microsoft Office 2007 (*.xlsx)"));//获取保存路径
    QList<QVariant> allRowsData;//保存所有行数据
    allRowsData.clear();
    if(!filepath.isEmpty()){
        QAxObject *excel = new QAxObject("Excel.Application");//连接Excel控件
        excel->dynamicCall("SetVisible (bool Visible)",false);//不显示窗体
        excel->setProperty("DisplayAlerts", true);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
        QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
        workbooks->dynamicCall("Add");//新建一个工作簿
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
        QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
        QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1

        QList<QVariant> aaRowData;
        aaRowData.append(QVariant("课程号"));
       aaRowData.append(QVariant("课程名"));
        aaRowData.append(QVariant("学分"));
        aaRowData.append(QVariant("教师号"));
        aaRowData.append(QVariant("成绩"));
        allRowsData.append(QVariant(aaRowData));

        for(int row = 0; row < studentFunction::tableModel->rowCount(); row++)
        {
            qDebug()<<studentFunction::tableModel->rowCount();

            QList<QVariant> aRowData;//保存一行数据
           //  QModelIndex parentIndex = studentFunction::tableModel->index(QDir::currentPath());
             //  QModelIndex index = studentFunction::tableModel->index(row, 0);
                 //  QString text = studentFunction::tableModel->data(index, Qt::DisplayRole).toString();


            for(int column = 0; column < 3; column++)
            {QModelIndex index = studentFunction::tableModel->index(row,column);
                QString text = studentFunction::tableModel->data(index, Qt::DisplayRole).toString();
                aRowData.append(QVariant(text));
            }
            QModelIndex index = studentFunction::tableModel->index(row,3);
                  QString text ="'"+ studentFunction::tableModel->data(index, Qt::DisplayRole).toString();
                      aRowData.append(QVariant(text));
                  index = studentFunction::tableModel->index(row,4);
                    text =studentFunction::tableModel->data(index, Qt::DisplayRole).toString();
                      aRowData.append(QVariant(text));
            allRowsData.append(QVariant(aRowData));
        }


        string c_count = "A1:E";
        c_count.append(to_string(studentFunction::tableModel->rowCount()+1));//为了加上第一行，这里加一
        QAxObject *range = worksheet->querySubObject("Range(const QString )", c_count.c_str());
        range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));
        //存储所有数据到 excel 中,批量操作,速度极快
        range->querySubObject("Font")->setProperty("Size", 15);//设置字号


        worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 60);//调整第一行行高

        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));
        //保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;
    }
    QMessageBox::information(this,tr("提示"),tr("存储成功"),QMessageBox::Ok);
}

void studentFunction::on_pushButton_8_clicked()//退课
{
    QByteArray aa=ui->lineEdit_2->text().toLatin1();
     char* bb;
     bb=aa.data();
     QByteArray tno1=ui->lineEdit_5->text().toLatin1();
      char* tnochar;
      tnochar=tno1.data();
      Course *c;
      bool del=false;
    c=Welcome::studentHash.find2(Welcome::userid).studentCourse;
    if(c==NULL)
         int ret=QMessageBox::information(this,tr("提示"),tr("您没有选修该课程"),QMessageBox::Ok);
    else{
        while(c->next)
        {
            if(!strcmp(c->next->getcno(),bb))
            {
                if(!strcmp(c->next->gettno(),tnochar))
                {
                    del=true;
                    c->next=c->next->next;
                }
                else c=c->next;
            }
           else c=c->next;
        }
        if(del)
        {for(int i=0;i<Welcome::CourseHash.M;i++)
            {
                if(!strcmp(Welcome::CourseHash.HT[i].value().getsno(),Welcome::userid)&&
                        !strcmp(Welcome::CourseHash.HT[i].value().gettno(),tnochar))
                   { Welcome::CourseHash.HT[i].setKey(Welcome::CourseHash.TombStone);
                    break;
                }
            }

          int ret=QMessageBox::information(this,tr("提示"),tr("成功退课"),QMessageBox::Ok);
        }
        else
            int ret=QMessageBox::information(this,tr("提示"),tr("您没有选修该课程"),QMessageBox::Ok);
    }



}

void studentFunction::on_pushButton_9_clicked()//查询个人信息
{
    ui->stackedWidget->setCurrentIndex(4);
    Student s=Welcome::studentHash.find2(Welcome::userid);
    string nnn = s.getnumber();
    QString nnnn = str2qstr(nnn);
    ui->lineEdit_12->setText(nnnn);
    nnn=s.gettelephone();
    nnnn=str2qstr(nnn);
    ui->lineEdit_7->setText(nnnn);
    nnn=s.getname();
    nnnn=str2qstr(nnn);
    ui->lineEdit_13->setText(nnnn);
    nnn=s.getsex();
    nnnn=str2qstr(nnn);
    ui->lineEdit_14->setText(nnnn);
    nnn=s.getpassword();
    nnnn=str2qstr(nnn);
    ui->lineEdit_6->setText(nnnn);
    nnn=s.getinstitute();
    nnnn=str2qstr(nnn);
    ui->lineEdit_8->setText(nnnn);
}

void studentFunction::on_pushButton_10_clicked()
{

    QString str =ui->lineEdit_10->text();
   QByteArray ba = str.toLocal8Bit();
  char *mm = ba.data();
  Welcome::studentHash.find2(Welcome::userid).setpassword(mm);
  int ret=QMessageBox::information(this,tr("提示"),tr("修改成功"),QMessageBox::Ok);
}

void studentFunction::on_pushButton_11_clicked()
{

    QString str =ui->lineEdit_11->text();
   QByteArray ba = str.toLocal8Bit();
  char *mm = ba.data();
  Welcome::studentHash.find2(Welcome::userid).settelephone(mm);
  int ret=QMessageBox::information(this,tr("提示"),tr("修改成功"),QMessageBox::Ok);
}

void studentFunction::on_pushButton_12_clicked()
{
    QString str =ui->lineEdit_9->text();
   QByteArray ba = str.toLocal8Bit();
  char *mm = ba.data();
  Welcome::studentHash.find2(Welcome::userid).setinstitute(mm);
  int ret=QMessageBox::information(this,tr("提示"),tr("修改成功"),QMessageBox::Ok);
}
