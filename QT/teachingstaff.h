#ifndef TEACHINGSTAFF_H
#define TEACHINGSTAFF_H
#include "schoolstaff.h"

class TeachingStaff :public SchoolStaff
{

protected:
    int workingtime;
    char education[20];

public:
    TeachingStaff();
    TeachingStaff(char* number, char* name, char* password, char* sex, char* institute, int workingtime = 0, char* education = "null");
    int getworkingtime();
    char* geteducation();
};

#endif // TEACHINGSTAFF_H
