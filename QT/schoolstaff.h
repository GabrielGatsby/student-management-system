#ifndef SCHOOLSTAFF_H
#define SCHOOLSTAFF_H
#include "course.h"

class SchoolStaff
{
protected:

    char number[20];
    char name[20];
    char password[20];
    char sex[5];
    char institute[20];


public:
    SchoolStaff();
    SchoolStaff(char* number, char* name, char* password, char* sex, char* institute);

    virtual char* getname()=0;
    virtual char* getnumber()=0;
    virtual char* getpassword()=0;
    virtual char* getsex()=0;
    virtual char* getinstitute()=0;
    virtual void setnumber(char* number)=0;
    virtual void setpassword(char* password)=0;
    virtual void setname(char *name)=0;
    virtual void setsex(char* sex)=0;
    virtual void setinstitute(char* institute)=0;
};

#endif // SCHOOLSTAFF_H
