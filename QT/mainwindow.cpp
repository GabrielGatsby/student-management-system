#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "function.h"
#include "schoolstaff.h"
#include "student.h"
#include "teacher.h"
#include<iostream>
#include<fstream>
#include <QDebug>
#include "welcome.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Welcome *w=new Welcome;
    w->show();
}


void MainWindow::on_pushButton_2_clicked()
{
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
