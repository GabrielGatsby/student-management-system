#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<cstring>
using namespace std;

class Course
{

private:
    char cno[20];
    char cname[50];
    float credit;
    char sno[20];
    char tno[20];
    float grade;

public:
    Course* next;

    Course(char* cno="mark", char *cname="mark", float credit=0,
           char* sno="mark", char* tno="mark", float grade = -1, Course* next = 0);
    char *getcno();
    char *getcname();
    float getcredit();
    char *getsno();
    char *gettno();
    float getgrade();
    Course *getnext();

    void setcno(char *cno);
    void setcname(char *cname);
    void setcredit(float credit);
    void setsno(char *sno);
    void settno(char *tno);
    void setgrade(float grade);

};

#endif // COURSE_H
