#include "searchall.h"
#include "ui_searchall.h"
#include "register.h"
#include "hashtable.h"
#include "student.h"
#include <QString>
#include <course.h>
#include <QDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAxObject>
#include <QAxWidget>
#include <QDir>

#include <QFileDialog>
#include<sstream>
#include <QStandardItem>

QStandardItemModel *searchall::tableModel;
searchall::searchall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchall)
{
    ui->setupUi(this);

    tableModel= new QStandardItemModel();
    //QStandardItemModel *tableModel = new QStandardItemModel();

       tableModel->setColumnCount(5);
       tableModel->setHeaderData(0,Qt::Horizontal,tr("课程号"));
       tableModel->setHeaderData(1,Qt::Horizontal,tr("课程名"));
       tableModel->setHeaderData(2,Qt::Horizontal,tr("学分"));
       tableModel->setHeaderData(3,Qt::Horizontal,tr("教师号"));
       tableModel->setHeaderData(4,Qt::Horizontal,tr("成绩"));

       tableModel->setSortRole(1);


       Student s;
       int i=0;
       qDebug()<<Register::userid;
       Register::studentHash.find(Register::userid,s);
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
           tableModel->setItem(i,0,cno);
           nn = QString(QLatin1String(t->next->getcname()));
           QStandardItem *cname=new QStandardItem(nn);
           tableModel->setItem(i,1,cname);
            QString data = QString("%1").arg(t->next->getcredit());
            QStandardItem *credit=new QStandardItem(data);
            tableModel->setItem(i,2,credit);
            nn = QString(QLatin1String(t->next->gettno()));
            QStandardItem *tno=new QStandardItem(nn);
            tableModel->setItem(i,3,tno);
            data = QString("%1").arg(t->next->getgrade());
            QStandardItem *grade=new QStandardItem(data);
            tableModel->setItem(i,4,grade);

        t=t->next;
        i++;
       }
   }
       ui->stu_info->setModel(tableModel);
       ui->stu_info->setColumnWidth(0,120);
        ui->stu_info->setColumnWidth(1,120);
         ui->stu_info->setColumnWidth(2,120);
          ui->stu_info->setColumnWidth(3,120);
           ui->stu_info->setColumnWidth(4,120);
       ui->stu_info->verticalHeader()->hide();

     //  ui->stu_info->setColumnWidth(0,100);
       ui->stu_info->setSelectionBehavior(QAbstractItemView::SelectRows);


}

searchall::~searchall()
{
    delete ui;
}



void searchall::on_pushButton_clicked()
{

    QString filepath=QFileDialog::getSaveFileName(NULL,QObject::tr("Save orbit"),"/untitled.xls",QObject::tr("Microsoft Office 2007 (*.xlsx)"));//获取保存路径
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

        for(int row = 0; row < tableModel->rowCount(); row++)
        {
            qDebug()<<tableModel->rowCount();

            QList<QVariant> aRowData;//保存一行数据
           //  QModelIndex parentIndex = tableModel->index(QDir::currentPath());
             //  QModelIndex index = tableModel->index(row, 0);
                 //  QString text = tableModel->data(index, Qt::DisplayRole).toString();


            for(int column = 0; column < 5; column++)
            {QModelIndex index = tableModel->index(row,column);
                QString text = tableModel->data(index, Qt::DisplayRole).toString();
                aRowData.append(QVariant(text));
            }
            allRowsData.append(QVariant(aRowData));
        }


        string c_count = "A1:E";
        c_count.append(to_string(tableModel->rowCount()+1));//为了加上第一行，这里加一
        QAxObject *range = worksheet->querySubObject("Range(const QString )", c_count.c_str());
        range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
        range->querySubObject("Font")->setProperty("Size", 15);//设置字号

        /*QAxObject *font = cell->querySubObject("Font");
        font->setProperty("Name", itemFont.family());  //设置单元格字体
        font->setProperty("Bold", itemFont.bold());  //设置单元格字体加粗
        font->setProperty("Size", itemFont.pixelSize());  //设置单元格字体大小
        font->setProperty("Italic",itemFont.italic());  //设置单元格字体斜体
        font->setProperty("Underline", itemFont.underline());  //设置单元格下划线
        font->setProperty("Color", item->foreground().color());  //设置单元格字体颜色*/
        worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 60);//调整第一行行高

        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;
    }
    QMessageBox::information(this,tr("提示"),tr("存储成功"),QMessageBox::Ok);
}
