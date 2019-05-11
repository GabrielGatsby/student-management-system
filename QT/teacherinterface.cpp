#include "teacherinterface.h"
#include "ui_teacherinterface.h"
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

static myhashmap<string,Course> tcourse;

static vector<Course> telsecourse;

static myhashmap<string,Course> tcourse2;

static vector<Course> telsecourse2;

static myhashmap<string,Student> tstudent;

//写入course.dat
void writecourse1(){
    //写入course.dat
    KVpair<string,Course>* kvpair;
    ofstream of("course.dat",ios::out|ios::binary);
    for(int i = 0; i <telsecourse.size();i++){
        of.write((char*)&telsecourse[i],sizeof(Course));
    }

    for(int i = 0 ; i< tcourse.getMaximum();i++){
        kvpair = tcourse.getPlace(i);
        if(kvpair&&!kvpair->isTombstone())
            while(kvpair){
                of.write((char*)&kvpair->getElem(),sizeof(Course));
                kvpair = kvpair->next;
        }
    }
    Course inc("mark","mark",0.0,"mark","mark",-1);
    of.write((char*)&inc,sizeof(Course));
    of.close();
    //
}

//写入course2.dat
void writecourse2(){
    //写入course2.dat
    ofstream of("course2.dat",ios::out|ios::binary);
    for(int i = 0; i <telsecourse2.size();i++){
        of.write((char*)&telsecourse2[i],sizeof(Course));
    }

    KVpair<string,Course>* kvpair;
    for(int i = 0 ; i< tcourse2.getMaximum();i++){
        kvpair = tcourse2.getPlace(i);
        if(kvpair&&!kvpair->isTombstone())
            while(kvpair){
                of.write((char*)&kvpair->getElem(),sizeof(Course));
                kvpair = kvpair->next;
        }
    }
    Course inc("mark","mark",0.0,"mark","mark",-1);
    of.write((char*)&inc,sizeof(Course));
    of.close();
    //
}

TeacherInterface::TeacherInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherInterface)
{
    ui->setupUi(this);
    //格式限制
    QRegExp rx("-1|100|([0-9]{0,2}[\.][0-9])");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_3->setValidator(pReg);

    //初始页面
    ui->stackedWidget->setCurrentIndex(0);

    //设置统计界面的表格
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<"学号"<<"姓名"<<"成绩";
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    tcourse.clear();
    telsecourse.clear();
    tcourse2.clear();
    telsecourse2.clear();
    tstudent.clear();
    //把信息输入哈希表

    //course
    KVpair<string,Course>* kt;
    ifstream inf("course.dat",ios::in);
    Course tc;
    do{
        inf.read((char*)&tc, sizeof(Course));
        if("mark"!=QString::fromLocal8Bit(tc.getcno())){
            string ttno = tc.gettno();
            if(!ttno.compare(extern_zhanghao)){//判断是否是本教师课程
                string st = tc.getcname();
                kt = new KVpair<string,Course>(st,tc);
                tcourse.insert(kt);
            }
            else{
                telsecourse.push_back(tc);
            }
        }

    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getcno()));
    inf.close();

    //course2
    KVpair<string,Course>* kt2;
    ifstream inf2("course2.dat",ios::in);
    Course tc2;
    do{
        inf2.read((char*)&tc2, sizeof(Course));
        if("mark"!=QString::fromLocal8Bit(tc2.getcno())){
            string ttno = tc2.gettno();
            if(!ttno.compare(extern_zhanghao)){//判断是否是本教师课程
                string st2 = tc2.getcname();
                kt2 = new KVpair<string,Course>(st2,tc2);
                tcourse2.insert(kt2);
            }
            else{
                telsecourse2.push_back(tc2);
            }
        }

    }while(inf2&&"mark"!=QString::fromLocal8Bit(tc2.getcno()));
    inf2.close();

    //student
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



}

TeacherInterface::~TeacherInterface()
{
    delete ui;
}

//修改添加成绩界面按钮
void TeacherInterface::on_pushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);

}

//修改添加成绩按钮
void TeacherInterface::on_pushButton_2_clicked()
{

    string tsno;
    string tcname;
    float tgrade;

    tsno = qstr2str(ui->lineEdit->text());
    tcname = qstr2str(ui->lineEdit_2->text());
    tgrade = ui->lineEdit_3->text().toFloat();

    KVpair<string,Course>* find;
    find = tcourse.search(tcname);

    int flag = 0;//立旗

    if(find&&(!find->isTombstone())){
        while(find){
            if(!tsno.compare(find->getElem().getsno())){
                flag = 1;//course有此课程，有此学号学生的成绩
                find->getElem().setgrade(tgrade);
                QMessageBox::information(this,tr("提示"),tr("修改学生成绩成功"),QMessageBox::Ok);

                //写入course.dat
                writecourse1();

                break;
            }

            find=find->next;
        }

        if(flag == 0){
            flag = 2;//course有此课程，无此学号学生的成绩

            //判断student是否存在该学生
            KVpair<string,Student>* find_2;
            string tnumber = qstr2str(ui->lineEdit->text());
            find_2 = tstudent.search(tnumber);
            if(find_2){
                flag = 4;//course有课程，student有这个学生
                KVpair<string,Course>* temp = tcourse.search(tcname);
                char ttsno[20];
                strcpy_s(ttsno,tsno.c_str());
                Course ic(temp->getElem().getcno(),temp->getElem().getcname(),
                          temp->getElem().getcredit(),ttsno,temp->getElem().gettno(),tgrade);
                string st = temp->getElem().getcname();
                KVpair<string, Course> *kt = new KVpair<string,Course>(st,ic);
                tcourse.insert(kt);

                QMessageBox::information(this,tr("提示"),tr("添加学生成绩成功"),QMessageBox::Ok);

                //写入course.dat
                writecourse1();
            }
            else{
                flag = 5;//course有课程，student没有这个学生
                QMessageBox::critical(this,tr("错误"),tr("学生表中没有该学生"),QMessageBox::YesAll);
            }

        }

    }
    else{
        flag = 3;//course没有此课程
        KVpair<string,Course>* find2;
        find2 = tcourse2.search(tcname);
        if(find2){//course2有课程

            //判断student是否存在该学生
            KVpair<string,Student>* find_2;
            string tnumber = qstr2str(ui->lineEdit->text());
            find_2 = tstudent.search(tnumber);
            if(find_2){
                flag = 6;//course2有课程，student有这个学生
                char ttsno[20];
                strcpy_s(ttsno,tsno.c_str());
                Course ic(find2->getElem().getcno(),find2->getElem().getcname(),
                          find2->getElem().getcredit(),ttsno,find2->getElem().gettno(),tgrade);
                string st = find2->getElem().getcname();
                KVpair<string, Course> *kt = new KVpair<string,Course>(st,ic);
                tcourse.insert(kt);
                QMessageBox::information(this,tr("提示"),tr("添加学生成绩成功"),QMessageBox::Ok);

                //写入course.dat
                writecourse1();

            }

            else{
                flag = 7;//course2有课程，student没有这个学生
                QMessageBox::critical(this,tr("错误"),tr("学生表中没有该学生"),QMessageBox::YesAll);
            }
        }
        else{
            QMessageBox::critical(this,tr("错误"),tr("没有找到该课程"),QMessageBox::YesAll);
        }
    }








}

//查询统计界面按钮
void TeacherInterface::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//查询统计按钮
void TeacherInterface::on_pushButton_4_clicked()
{
    //统计平均分数，最低分，最高分
    float min = 1000;//最低分
    float max = 0;//最高分
    float sum = 0;//总分
    float count = 0;//总人数
    int truecount = 0;//有成绩的人数
    float avg = 0;//平均成绩
    float unsixty = 0;//不及格人数


    //设置表格
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<"学号"<<"姓名"<<"成绩";
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //统计的数据先置零
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();


    string tcname;
    tcname = qstr2str(ui->lineEdit_5->text());


    KVpair<string,Course>* find;
    find = tcourse.search(tcname);


    if(find){
        while(find){
            //统计数据
            if(find->getElem().getgrade()>=0){


                if(find->getElem().getgrade()<min ){
                    min = find->getElem().getgrade();
                }
                if(find->getElem().getgrade() > max ){
                    max = find->getElem().getgrade();
                }

                if(find->getElem().getgrade()<60){
                    unsixty++;
                }


                sum+=find->getElem().getgrade();
                count++;
            }

            truecount++;

            //数据记录于表格
            ui->tableWidget->setRowCount(truecount);
            string tablesno = find->getElem().getsno();//学生学号
            stringstream ttablegrade;
            ttablegrade<<find->getElem().getgrade();
            string tablegrade = ttablegrade.str();//学生成绩
            KVpair<string,Student>* find_2;
            find_2 = tstudent.search(tablesno);
            if(find_2){

                //写表格
                string tablename = find_2->getElem().getname();//学生姓名
                ui->tableWidget->setItem(truecount-1,0,new QTableWidgetItem(str2qstr(tablesno)));
                ui->tableWidget->setItem(truecount-1,1,new QTableWidgetItem(str2qstr(tablename)));
                ui->tableWidget->setItem(truecount-1,2,new QTableWidgetItem(str2qstr(tablegrade)));
            }


                find=find->next;//指针下移
        }

        avg = sum/count;

        QString qavg = QString("%1").arg(avg);
        QString qcount = QString("%1").arg(count);
        QString qtruecount = QString("%1").arg(truecount);
        QString qmax = QString("%1").arg(max);
        QString qmin = QString("%1").arg(min);
        QString qunsixty = QString("%1").arg(unsixty);
        QString qunsixtypre = QString("%1").arg((count-unsixty)/count);

        ui->lineEdit_6->setText(qtruecount);
        ui->lineEdit_7->setText(qcount);
        ui->lineEdit_8->setText(qavg);
        ui->lineEdit_9->setText(qmax);
        ui->lineEdit_10->setText(qmin);
        ui->lineEdit_11->setText(qunsixty);
        ui->lineEdit_12->setText(qunsixtypre);

    }

    else{
        find = tcourse2.search(tcname);
        if(find){
            QMessageBox::critical(this,tr("提示"),tr("有此课程但没有学生"),QMessageBox::YesAll);
        }
        else{
            QMessageBox::critical(this,tr("错误"),tr("没有找到该课程"),QMessageBox::YesAll);
        }
    }



}


void TeacherInterface::on_pushButton_14_clicked()//存储表格按钮
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
        aaRowData.append(QVariant("成绩"));
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



//删除课程界面按钮
void TeacherInterface::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//删除课程按钮
void TeacherInterface::on_pushButton_7_clicked()
{
    string tcname = qstr2str(ui->lineEdit_13->text());
    int flag = 0;


    //删除course2.dat里的课程
    KVpair<string,Course>* find;
    find = tcourse2.search(tcname);
    if(!find){//course2中找不到课程
        QMessageBox::critical(this,tr("错误"),tr("没有找到该课程"),QMessageBox::YesAll);
    }
    else{
        flag = 1;

        find->setTombstone();

        QMessageBox::information(this,tr("提示"),tr("删除课程成功"),QMessageBox::Ok);

        writecourse2();
    }


    if(flag == 1){//course2中找到课程
        //删除course.dat里的课程
        find = tcourse.search(tcname);
        if(!find){//找不到课程
            //QMessageBox::critical(this,tr("错误"),tr("没有找到该课程"),QMessageBox::YesAll);
        }
        else{//找到课程
            find->setTombstone();
            //QMessageBox::information(this,tr("提示"),tr("删除课程成功"),QMessageBox::Ok);

            writecourse1();


        }
    }


}


//添加功能界面按钮
void TeacherInterface::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//添加功能按钮
void TeacherInterface::on_pushButton_9_clicked()
{
    string tcname = qstr2str(ui->lineEdit_15->text());
    KVpair<string,Course>* find;
    find = tcourse2.search(tcname);
    if(find){
        QMessageBox::critical(this,tr("错误"),tr("已有该课程"),QMessageBox::YesAll);
    }
    else{

         char cno[20];
         char cname[50];
         float credit;
         char sno[20];
         char tno[20];
         float grade;

         int flag = 0;//立旗，判断是否有重复编号
         string checkcno;
         ifstream inf("course2.dat",ios::in);
         Course tc;
         do{
             inf.read((char*)&tc, sizeof(Course));
             if("mark"!=QString::fromLocal8Bit(tc.getcno())){
                 checkcno = tc.getcno();
                 if(!checkcno.compare(qstr2str(ui->lineEdit_14->text()).c_str())){//判断是否是有重复编号的课程
                     flag = 1;
                     break;
                 }
             }

         }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getcno()));
         inf.close();

         if(flag){
             QMessageBox::critical(this,tr("错误"),tr("此课程编号与已知课程编号重复"),QMessageBox::YesAll);
         }
         else{
            strcpy_s(cno,qstr2str(ui->lineEdit_14->text()).c_str());
            strcpy_s(cname,qstr2str(ui->lineEdit_15->text()).c_str());
            credit = ui->lineEdit_16->text().toFloat();
            strcpy_s(sno,"mark");
            strcpy_s(tno,extern_zhanghao.c_str());
            grade = -1;
            Course newcourse(cno,cname,credit,sno,tno,grade);
            KVpair<string,Course>* kt = new KVpair<string,Course>(tcname,newcourse);
            tcourse2.insert(kt);
            QMessageBox::information(this,tr("提示"),tr("添加课程成功"),QMessageBox::Ok);

            //写入文件
            writecourse2();
         }

    }

}



//删除学生成绩页面按钮
void TeacherInterface::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

//删除学生成绩按钮
void TeacherInterface::on_pushButton_11_clicked()
{
    string tcname = qstr2str(ui->lineEdit_4->text());
    string tsno = qstr2str(ui->lineEdit_19->text());
    KVpair<string,Course>* find;
    find = tcourse.search(tcname);
    if(find){
        int flag = 0;//判断有没有要删除的学生成绩
        if(!tsno.compare(find->getElem().getsno())){//如果链表最开始就是那个要删除的学生成绩
            flag = 1;//有要删除的学生成绩
            int i;
            for(i = 0 ; i < tcourse.getMaximum();i++){
                if(tcourse.getPlace(i)&&!tsno.compare(tcourse.getPlace(i)->getElem().getsno()))
                    break;
            }
            tcourse.HT[i] = find->next;
            if(!tcourse.HT[i]){
                Course tc("mark","mark",-1,"mark","mark");
                tcourse.HT[i] = new KVpair<string,Course>("-1",tc);
                tcourse.HT[i]->setTombstone();
            }
            delete find;
        }
        else{//查看剩余的链表有没有要删除的学生成绩
            while(find->next){
                if(!tsno.compare(find->next->getElem().getsno())){
                    flag = 1;//有要删除的学生成绩
                    delete find->next;//删除学生成绩
                    find->next = find->next->next;//删除学生成绩
                    break;
                }
                find = find->next;
            }
        }
        if(flag == 0){//没有该学生成绩
            QMessageBox::critical(this,tr("错误"),tr("该课程没有该学生成绩"),QMessageBox::YesAll);
        }
        if(flag == 1){
            QMessageBox::information(this,tr("提示"),tr("删除学生成绩成功"),QMessageBox::Ok);
            writecourse1();

        }

    }
    else{
        find = tcourse2.search(tcname);
        if(find){
             QMessageBox::critical(this,tr("错误"),tr("该课程没有该学生成绩"),QMessageBox::YesAll);
        }
        else{
            QMessageBox::critical(this,tr("错误"),tr("没有该课程"),QMessageBox::YesAll);
        }
    }


}

void TeacherInterface::on_pushButton_12_clicked()//修改密码界面按钮
{
    ui->stackedWidget->setCurrentIndex(5);
}


void TeacherInterface::on_pushButton_13_clicked()//修改密码按钮
{
    fstream passchange;
    passchange.open("teacher.dat",ios::in|ios::out);
    Teacher tc;
    int flag = 0; //判断有无此账号
    do{
        passchange.read((char*)&tc,sizeof(Teacher));
        if("mark"!=QString::fromLocal8Bit(tc.getnumber())){
            if(!extern_zhanghao.compare(tc.getnumber())){//找到了当前账号
                flag = 1;
                string oldpassword = qstr2str(ui->lineEdit_20->text());
                if(!oldpassword.compare(tc.getpassword())){//旧密码输入正确
                    string newpassword_1 = qstr2str(ui->lineEdit_21->text());
                    string newpassword_2 = qstr2str(ui->lineEdit_22->text());
                    if(!newpassword_1.compare(newpassword_2)){//新密码输入正确
                        char newpassword_3[20];
                        strcpy_s(newpassword_3,newpassword_1.c_str());
                        tc.setpassword(newpassword_3);
                        passchange.seekp(-long(sizeof(Teacher)),ios::cur);
                        passchange.write((char*)&tc, sizeof(Teacher));
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



//测试(重置)按钮功能
void TeacherInterface::on_pushButton_5_clicked()
{
    qDebug()<<"reset";
    char cno[20];
    char cname[50];
    float credit;
    char sno[20];
    char tno[20];
    float grade;
    Course* next;
    char ne[20];

    ifstream inf;
    ofstream outf;
    //course
    inf.open("course.txt",ios::in);
    outf.open("course.dat",ios::out|ios::binary);
    while(inf>>cno>>cname>>credit>>sno>>tno>>grade){
        //inf>>ne;
        Course inc(cno,cname,credit,sno,tno,grade);
        outf.write((char*)&inc,sizeof(Course));
    }
    inf.close();
    outf.close();

    //course2
    inf.open("course2.txt",ios::in);
    outf.open("course2.dat",ios::out|ios::binary);
    while(inf>>cno>>cname>>credit>>sno>>tno>>grade){
        //inf>>ne;
        Course inc(cno,cname,credit,sno,tno,grade);
        outf.write((char*)&inc,sizeof(Course));
    }
    inf.close();
    outf.close();


    char number[20];
    char name[20];
    char password[20];
    char sex[5];
    char institute[20];


    inf.open("student.txt",ios::in);
    outf.open("student.dat",ios::out|ios::binary);
    char telephone[20];
    while(inf>>number>>name>>password>>sex>>institute>>telephone){
        //inf>>ne;
        Student stu(number,name,password,sex,institute,telephone);
        outf.write((char*)&stu,sizeof(Student));
    }
    inf.close();
    outf.close();


    inf.open("teachingmanager.txt",ios::in);
    outf.open("teachingmanager.dat",ios::out|ios::binary);
    int workingtime;
    char education[20];
    while(inf>>number>>name>>password>>sex>>institute>>workingtime>>education){
        TeachingManager tmr(number,name,password,sex,institute,workingtime,education);
        outf.write((char*)&tmr,sizeof(TeachingManager));
    }
    inf.close();
    outf.close();


    inf.open("teacher.txt",ios::in);
    outf.open("teacher.dat",ios::out|ios::binary);
    while(inf>>number>>name>>password>>sex>>institute>>workingtime>>education){
        //inf>>ne;
        Teacher te(number,name,password,sex,institute,workingtime,education);
        outf.write((char*)&te,sizeof(Teacher));
    }

}

