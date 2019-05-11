#include "registerteachingmanager.h"
#include "ui_registerteachingmanager.h"
#include <fstream>
#include <string>
#include<sstream>
#include<QMessageBox>
#include "myhashmap.h"
#include "teachingmanager.h"
#include "function.h"
using namespace std;

static myhashmap<string,TeachingManager> tteach;

registerteachingmanager::registerteachingmanager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerteachingmanager)
{
    ui->setupUi(this);
    //格式限制
    QRegExp rx("男|女");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_4->setValidator(pReg);


    tteach.clear();
    //把信息输入哈希表
    ifstream inf;
    inf.open("teachingmanager.dat",ios::in);
    TeachingManager ts;
    do{
        inf.read((char*)&ts,sizeof(TeachingManager));
        if("mark"!=QString::fromLocal8Bit(ts.getnumber())){
            string st = ts.getnumber();
            KVpair<string,TeachingManager>* kt_s = new KVpair<string,TeachingManager>(st,ts);
            tteach.insert(kt_s);
        }
    }while(inf&&"mark"!=QString::fromLocal8Bit(ts.getnumber()));
    inf.close();
}

registerteachingmanager::~registerteachingmanager()
{
    delete ui;
}

void registerteachingmanager::on_pushButton_clicked()
{
    string tno = qstr2str(ui->lineEdit->text());
    KVpair<string,TeachingManager> *find = tteach.search(tno);
    if(find){
        QMessageBox::critical(this,tr("错误"),tr("已有该教务员账号"),QMessageBox::YesAll);
    }
    else{
        char ttno[20];
        strcpy_s(ttno,tno.c_str());
        string tname = qstr2str(ui->lineEdit_2->text());
        char ttname[20];
        strcpy_s(ttname,tname.c_str());
        string tpassword = qstr2str(ui->lineEdit_3->text());
        char ttpassword[20];
        strcpy_s(ttpassword,tpassword.c_str());
        string tsex = qstr2str(ui->lineEdit_4->text());
        char ttsex[5];
        strcpy_s(ttsex,tsex.c_str());
        string tinsititute = qstr2str(ui->lineEdit_5->text());
        char ttinsititute[20];
        strcpy_s(ttinsititute,tinsititute.c_str());
        int worktime = ui->lineEdit_6->text().toInt();
        string teducation = qstr2str(ui->lineEdit_7->text());;
        char tteducation[20];
        strcpy_s(tteducation,teducation.c_str());
        TeachingManager reg(ttno,ttname,ttpassword,ttsex,ttinsititute,worktime,tteducation);


        //加入哈希表
        KVpair<string,TeachingManager> *ins = new KVpair<string,TeachingManager>(tno,reg);
        tteach.insert(ins);

        //添加入dat
        fstream iof;
        iof.open("teachingmanager.dat",ios::in|ios::out);
        iof.seekg(-long(sizeof(TeachingManager)),ios::end);
        TeachingManager endteach;
        iof.read((char*)&endteach,sizeof(TeachingManager));
        iof.seekp(-long(sizeof(TeachingManager)),ios::end);
        iof.write((char*)&reg,sizeof(TeachingManager));
        iof.write((char*)&endteach,sizeof(TeachingManager));
        //


        QMessageBox::information(this,tr("提示"),tr("教务员注册成功"),QMessageBox::Ok);
    }
}
