#include "course.h"


Course::Course(char* cno, char *cname, float credit, char* sno, char* tno, float grade, Course *next)
{
    strcpy_s(this->cno, strlen(cno)+1, cno);
    strcpy_s(this->cname, strlen(cname)+1, cname);
    this->credit = credit;
    strcpy_s(this->sno, strlen(sno)+1, sno);
    strcpy_s(this->tno, strlen(tno)+1, tno);
    this->grade = grade;
    this->next = next;


}

char *Course::getcno()
{
    return cno;

}

char *Course::getcname()
{
    return cname;
}

float Course::getcredit()
{
    return credit;
}

char *Course::gettno()
{
    return tno;
}

float Course::getgrade()
{
    return grade;
}

char *Course::getsno()
{
    return sno;
}

Course *Course::getnext()
{
    return next;
}

void Course::setcno(char *cno)
{
    strcpy_s(this->cno, strlen(cno)+1, cno);
}

void Course::setcname(char *cname)
{
    strcpy_s(this->cname, strlen(cname)+1, cname);
}

void Course::setcredit(float credit)
{
    this->credit = credit;
}

void Course::setsno(char *sno)
{
    strcpy_s(this->sno, strlen(sno)+1, sno);
}

void Course::settno(char *tno)
{
    strcpy_s(this->tno, strlen(tno)+1, tno);
}

void Course::setgrade(float grade)
{
        this->grade = grade;
}
