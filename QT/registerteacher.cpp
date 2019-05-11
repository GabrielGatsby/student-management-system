#include "registerteacher.h"
#include "ui_registerteacher.h"
#include <fstream>
#include <string>
#include<sstream>
#include<QMessageBox>
#include "myhashmap.h"
#include "teacher.h"
#include "function.h"
using namespace std;

static myhashmap<string,Teacher> tteacher;

registerteacher::registerteacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerteacher)
{
    ui->setupUi(this);
    //格式限制
    QRegExp rx("男|女");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_4->setValidator(pReg);

    tteacher.clear();
    //把信息输入哈希表
    ifstream inf;
    inf.open("teacher.dat",ios::in);
    Teacher ts;
    do{
        inf.read((char*)&ts,sizeof(Teacher));
        if("mark"!=QString::fromLocal8Bit(ts.getnumber())){
            string st = ts.getnumber();
            KVpair<string,Teacher>* kt_s = new KVpair<string,Teacher>(st,ts);
            tteacher.insert(kt_s);
        }
    }while(inf&&"mark"!=QString::fromLocal8Bit(ts.getnumber()));
    inf.close();
}

registerteacher::~registerteacher()
{
    delete ui;
}

void registerteacher::on_pushButton_clicked()
{
    string tno = qstr2str(ui->lineEdit->text());
    KVpair<string,Teacher> *find = tteacher.search(tno);
    if(find){
        QMessageBox::critical(this,tr("错误"),tr("已有该教师账号"),QMessageBox::YesAll);
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
        Teacher reg(ttno,ttname,ttpassword,ttsex,ttinsititute,worktime,tteducation);


        //加入哈希表
        KVpair<string,Teacher> *ins = new KVpair<string,Teacher>(tno,reg);
        tteacher.insert(ins);

        //添加入dat
        fstream iof;
        iof.open("teacher.dat",ios::in|ios::out);
        iof.seekg(-long(sizeof(Teacher)),ios::end);
        Teacher endteacher;
        iof.read((char*)&endteacher,sizeof(Teacher));
        iof.seekp(-long(sizeof(Teacher)),ios::end);
        iof.write((char*)&reg,sizeof(Teacher));
        iof.write((char*)&endteacher,sizeof(Teacher));
        //


        QMessageBox::information(this,tr("提示"),tr("教师注册成功"),QMessageBox::Ok);
    }
}
