#include "teachingstaff.h"

TeachingStaff::TeachingStaff()
{

}

TeachingStaff::TeachingStaff(char *number, char *name, char *password, char *sex, char *institute, int workingtime, char *education):SchoolStaff(number,name,password,sex,institute)
{
    this->workingtime = workingtime;
    strcpy_s(this->education, strlen(education)+1, education);
}

int TeachingStaff::getworkingtime()
{
    return workingtime;
}

char *TeachingStaff::geteducation()
{
    return education;
}
