#include "teachingmanagerinterface.h"
#include "ui_teachingmanagerinterface.h"
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include <QAxObject>
#include <QAxWidget>
#include <QFileDialog>
#include <QObject>
#include<QMessageBox>
#include "myhashmap.h"
#include "course.h"
#include "student.h"
#include "teacher.h"
#include "teachingmanager.h"
#include "function.h"

using namespace std;

extern string extern_zhanghao;

static TeachingManager thisisyou;

static myhashmap<string,Student> tstudent;


TeachingManagerInterface::TeachingManagerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeachingManagerInterface)
{
    ui->setupUi(this);
    //初始页面
    ui->stackedWidget->setCurrentIndex(0);

    //设置统计界面的表格
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<"学号"<<"姓名"<<"联系方式";
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    tstudent.clear();
    //把信息输入哈希表
    ifstream inf;
    KVpair<string,Student>* kt_s;
    inf.open("student.dat",ios::in);
    Student ts;
    do{
        inf.read((char*)&ts,sizeof(Student));
        if("mark"!=QString::fromLocal8Bit(ts.getnumber())){
            string st = ts.getnumber();
            kt_s = new KVpair<string,Student>(st,ts);
            tstudent.insert(kt_s);
        }
    }while(inf&&"mark"!=QString::fromLocal8Bit(ts.getnumber()));
    inf.close();


    //显示欢迎
    inf.open("teachingmanager.dat",ios::in);
    do{
        inf.read((char*)&thisisyou, sizeof(TeachingManager));
        if("mark"!=QString::fromLocal8Bit(thisisyou.getnumber())){
            string zhanghao_2 = thisisyou.getnumber();
            if(!zhanghao_2.compare(extern_zhanghao)){
                break;
            }
        }


    }while(inf&&"mark"!=QString::fromLocal8Bit(thisisyou.getnumber()));
    inf.close();
    string tinsititute = thisisyou.getinstitute();
    string tname = thisisyou.getname();
    ui->label_4->setText("欢迎"+str2qstr(tinsititute)+" "+str2qstr(tname)+"老师");


}



TeachingManagerInterface::~TeachingManagerInterface()
{
    delete ui;
}

//某一学生联系方式页面按钮
void TeachingManagerInterface::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//某一学生联系方式按钮
void TeachingManagerInterface::on_pushButton_3_clicked()
{
    //清空原来的姓名、联系方式内容
    ui->lineEdit_2->clear();//清楚名字
    ui->lineEdit_3->clear();//清楚联系方式

    string tnumber = qstr2str(ui->lineEdit->text());
    KVpair<string,Student>* find = tstudent.search(tnumber);

    if(find){
        string tname = find->getElem().getname();
        string ttelephone = find->getElem().gettelephone();
        ui->lineEdit_2->setText(str2qstr(tname));
        ui->lineEdit_3->setText(str2qstr(ttelephone));
        QMessageBox::information(this,tr("提示"),tr("查询成功"),QMessageBox::Ok);

    }
    else{
        QMessageBox::critical(this,tr("错误"),tr("没有该学号的学生"),QMessageBox::YesAll);
    }

}



//所有学生联系方式页面按钮
void TeachingManagerInterface::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//所有学生联系方式按钮
void TeachingManagerInterface::on_pushButton_4_clicked()
{

    //设置表格
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<"学号"<<"姓名"<<"联系方式";
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //数据记录于表格
    int count = 0;
    ifstream inf;
    inf.open("student.dat",ios::in|ios::binary);
    Student stu;
    do{
        inf.read((char*)&stu,sizeof(Student));
        if("mark"!=QString::fromLocal8Bit(stu.getnumber())){
            string ttinsititute = stu.getinstitute();
            string tinsititute = thisisyou.getinstitute();
            if(!tinsititute.compare(ttinsititute)){
                count++;
                string tnumber = stu.getnumber();
                string tname = stu.getname();
                string ttelephone = stu.gettelephone();
                ui->tableWidget->setRowCount(count);
                ui->tableWidget->setItem(count-1,0,new QTableWidgetItem(str2qstr(tnumber)));
                ui->tableWidget->setItem(count-1,1,new QTableWidgetItem(str2qstr(tname)));
                ui->tableWidget->setItem(count-1,2,new QTableWidgetItem(str2qstr(ttelephone)));
            }

        }
    }while(inf&&"mark"!=QString::fromLocal8Bit(stu.getnumber()));
    inf.close();
    if(count == 0){
        QMessageBox::information(this,tr("提示"),tr("你的院系暂无学生资料"),QMessageBox::Ok);
    }

}

void TeachingManagerInterface::on_pushButton_6_clicked()//存储学生联系方式表格按钮
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
        aaRowData.append(QVariant("学号"));
        aaRowData.append(QVariant("姓名"));
        aaRowData.append(QVariant("联系方式"));
        allRowsData.append(QVariant(aaRowData));

        for(int row = 0; row < ui->tableWidget->rowCount(); row++)
        {
            QList<QVariant> aRowData;//保存一行数据
            QString tabnum = "’"+ui->tableWidget->item(row,0)->text();
            aRowData.append(QVariant(tabnum));
            for(int column = 1; column < 3; column++)
            {
                aRowData.append(QVariant(ui->tableWidget->item(row,column)->text()));
            }
            allRowsData.append(QVariant(aRowData));
        }


        string c_count = "A1:C";
        c_count.append(to_string(ui->tableWidget->rowCount()+1));//为了加上第一行，这里加一
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



void TeachingManagerInterface::on_pushButton_5_clicked()//修改密码界面按键
{
    ui->stackedWidget->setCurrentIndex(2);
}

void TeachingManagerInterface::on_pushButton_13_clicked()//修改密码按钮
{
    fstream passchange;
    passchange.open("teachingmanager.dat",ios::in|ios::out);
    TeachingManager tc;
    int flag = 0; //判断有无此账号
    do{
        passchange.read((char*)&tc,sizeof(TeachingManager));
        if("mark"!=QString::fromLocal8Bit(tc.getnumber())){
            if(!extern_zhanghao.compare(tc.getnumber())){//找到了当前账号
                flag = 1;
                string oldpassword = qstr2str(ui->lineEdit_20->text());
                if(!oldpassword.compare(tc.getpassword())){//旧密码输入正确
                    string newpassword_1 = qstr2str(ui->lineEdit_21->text());
                    string newpassword_2 = qstr2str(ui->lineEdit_22->text());
                    if(!newpassword_1.compare(newpassword_2)){//新密码输入正确
                        flag = 1;//修改密码成功
                        char newpassword_3[20];
                        strcpy_s(newpassword_3,newpassword_1.c_str());
                        tc.setpassword(newpassword_3);
                        passchange.seekp(-long(sizeof(TeachingManager)),ios::cur);
                        passchange.write((char*)&tc, sizeof(TeachingManager));
                        QMessageBox::information(this,tr("提示"),tr("修改密码成功"),QMessageBox::Ok);
                        break;
                    }
                    else{//新密码输入错误
                        QMessageBox::critical(this,tr("错误"),tr("两次新密码输入不同"),QMessageBox::YesAll);
                        break;
                    }
                }
                else{
                    QMessageBox::critical(this,tr("错误"),tr("旧密码输入错误"),QMessageBox::YesAll);
                    break;
                }
            }
        }
    }while(passchange&&"mark"!=QString::fromLocal8Bit(tc.getnumber()));

    if(flag == 0){
        QMessageBox::critical(this,tr("错误"),tr("没有此账号，可能是有人删除或修改了dat文件"),QMessageBox::YesAll);
    }

}

