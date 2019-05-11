#include "testcode.h"

testcode::testcode()
{

}

/*txt输入到dat中（Course)
    char cno[20];
    char cname[50];
    float credit;
    char sno[20];
    char tno[20];
    float grade;
    Course* next;
    char ne[20];

    ifstream inf("course.txt",ios::in);
    ofstream outf("course.dat",ios::out|ios::binary);
    while(inf>>cno>>cname>>credit>>sno>>tno>>grade){
        inf>>ne;
        Course inc(cno,cname,credit,sno,tno,grade);
        outf.write((char*)&inc,sizeof(Course));
    }
    inf.close();
    outf.close();
*/


/*没鬼用1
    ifstream inf("course.dat",ios::in);
    Course tc;
    inf.read((char*)&tc,sizeof(Course));
    inf.read((char*)&tc,sizeof(Course));
    //inf.read((char*)&tc,sizeof(Course));

    //ui->lineEdit->setText(QString::fromLocal8Bit(tc.getcname()));

    qDebug()<<QString::fromLocal8Bit(tc.getcno());
    qDebug()<<QString::fromLocal8Bit(tc.getcname());
    qDebug()<<tc.getcredit();
    qDebug()<<QString::fromLocal8Bit(tc.getsno());
    qDebug()<<QString::fromLocal8Bit(tc.gettno());
    qDebug()<<tc.getgrade();

    if(ui->lineEdit->text()==QString::fromLocal8Bit(tc.getcno()))
            qDebug()<<"yes;";

    inf.close();
*/

/*没鬼用2
     KVpair<string,Course>* k;
    k = changegrade.search(qstr2str(ui->lineEdit->text()));
    if(k)
        qDebug()<<QString::fromLocal8Bit(k->getElem().getcname());
*/

/*搞错：只支持修改或添加所有课程的某个课程的某个学生的成绩

void TeacherInterface::on_pushButton_2_clicked()
{
    myhashmap<string,Course> changegrade;
            KVpair<string,Course>* kt;

    //把信息输入哈希表
    ifstream inf("course.dat",ios::in);
    Course tc;
    do{
        inf.read((char*)&tc, sizeof(tc));
        if("mark"!=QString::fromLocal8Bit(tc.getcno())){
            string st = tc.getcname();
            kt = new KVpair<string,Course>(st,tc);
            changegrade.insert(kt);
        }

    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getcno()));
    inf.close();

    string tsno;
    string tcname;
    float tgrade;

    tsno = qstr2str(ui->lineEdit->text());
    tcname = qstr2str(ui->lineEdit_2->text());
    tgrade = ui->lineEdit_3->text().toFloat();

    KVpair<string,Course>* find;
    find = changegrade.search(tcname);

    int flag = 0;//立旗

    if(find){
        while(find){
            if(!tsno.compare(find->getElem().getsno())){
                flag = 1;//有此课程，有此学号
                qDebug()<<"flag = 1";
                break;
            }

            find=find->getNext();
        }

        if(flag == 0){
            flag = 2;//有此课程，无此学号
            qDebug()<<"flag = 2";
        }

    }
    else{
        flag = 3;//没有此课程
        qDebug()<<"flag = 3";
    }




}
*/

/*备用

void TeacherInterface::on_pushButton_2_clicked()
{
    myhashmap<string,Course> changegrade;
            KVpair<string,Course>* kt;

    //把信息输入哈希表
    ifstream inf("course.dat",ios::in);
    Course tc;
    do{
        inf.read((char*)&tc, sizeof(tc));
        if("mark"!=QString::fromLocal8Bit(tc.getcno())){
            string ttno = tc.gettno();
            if(!ttno.compare(qstr2str(ui->lineEdit_4->text()))){//判断是否是本教师课程
                string st = tc.getcname();
                kt = new KVpair<string,Course>(st,tc);
                changegrade.insert(kt);
            }
        }

    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getcno()));
    inf.close();

    string tsno;
    string tcname;
    float tgrade;

    tsno = qstr2str(ui->lineEdit->text());
    tcname = qstr2str(ui->lineEdit_2->text());
    tgrade = ui->lineEdit_3->text().toFloat();

    KVpair<string,Course>* find;
    find = changegrade.search(tcname);

    int flag = 0;//立旗

    if(find&&(!find->isTombstone())){
        while(find){
            if(!tsno.compare(find->getElem().getsno())){
                flag = 1;//有此课程，有此学号
                qDebug()<<"flag = 1";
                find->getElem().setgrade(tgrade);
                QMessageBox::information(this,tr("提示"),tr("修改学生成绩成功"),QMessageBox::Ok);
                break;
            }

            find=find->getNext();
        }

        if(flag == 0){
            flag = 2;//有此课程，无此学号
            qDebug()<<"flag = 2";
            KVpair<string,Course>* temp = changegrade.search(tcname);
            char ttsno[20];
            strcpy(ttsno,tsno.c_str());
            Course ic(temp->getElem().getcno(),temp->getElem().getcname(),temp->getElem().getcredit(),ttsno,temp->getElem().gettno(),tgrade);
            QMessageBox::information(this,tr("提示"),tr("添加学生成绩成功"),QMessageBox::Ok);
        }

    }
    else{
        flag = 3;//没有此课程
        qDebug()<<"flag = 3";
        QMessageBox::critical(this,tr("错误"),tr("没有找到该课程"),QMessageBox::YesAll);
    }








}

void TeacherInterface::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void TeacherInterface::on_pushButton_4_clicked()
{
    myhashmap<string,Course> seecourse;
            KVpair<string,Course>* kt;

    //把信息输入哈希表
    ifstream inf("course.dat",ios::in);
    Course tc;
    do{
        inf.read((char*)&tc, sizeof(tc));
        if("mark"!=QString::fromLocal8Bit(tc.getcno())){
            string ttno = tc.gettno();
            if(!ttno.compare("201033009944")){//判断是否是本教师课程
                string st = tc.getcname();
                kt = new KVpair<string,Course>(st,tc);
                seecourse.insert(kt);
            }
        }

    }while(inf&&"mark"!=QString::fromLocal8Bit(tc.getcno()));
    inf.close();

    string tcname;
    tcname = qstr2str(ui->lineEdit_5->text());

    //统计平均分数，最低分，最高分
    float min = 1000;
    float max = 0;
    float sum = 0;
    float count = 0;
    float avg = 0;

    KVpair<string,Course>* find;
    find = seecourse.search(tcname);
    if(find&&(!find->isTombstone())){
        while(find){
            if(find->getElem().getgrade()<min){
                min = find->getElem().getgrade();
            }
            if(find->getElem().getgrade() > max){
                max = find->getElem().getgrade();
            }

            sum+=find->getElem().getgrade();
            count++;



            find=find->getNext();
        }

        avg = sum/count;

        stringstream strsum;
        strsum<<sum;
        string ssum = strsum.str();

        stringstream strcount;
        strcount<<count;
        string scount = strcount.str();

        ui->lineEdit_6->setText(str2qstr(ssum));
        ui->lineEdit_7->setText(str2qstr(scount));
    }



}
*/
