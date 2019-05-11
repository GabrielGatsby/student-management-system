#ifndef TEACHER_H
#define TEACHER_H
#include "teachingstaff.h"

class Teacher:public TeachingStaff
{
protected:


public:
    Course* teachercourse;
    Teacher();
    Teacher(char* number, char* name, char* password, char* sex, char* institute, int workingtime = 0,
            char* education = "null", Course* teachercourse = 0);

    char* gettelephone();
    char* getname();
    char* getnumber();
    char* getpassword();
    char* getsex();
    char* getinstitute();
   void setnumber(char* number);
    void setpassword(char* password);
    void setname(char *name);
    void setsex(char* sex);
    void setinstitute(char* institute);
};

#endif // TEACHER_H
