#ifndef TEACHINGMANAGER_H
#define TEACHINGMANAGER_H
#include "teachingstaff.h"

class TeachingManager:public TeachingStaff
{
public:
    TeachingManager();
    TeachingManager(char* number, char* name, char* password, char* sex,
                    char* institute, int workingtime = 0, char* education = "null");

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

#endif // TEACHINGMANAGER_H
