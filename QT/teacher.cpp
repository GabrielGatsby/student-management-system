#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(char *number, char *name, char *password, char *sex, char *institute, int workingtime, char *education, Course* teachercourse):
    TeachingStaff(number,name,password,sex,institute,workingtime,education)
{
    this->teachercourse = teachercourse;
}
char *Teacher::getname()
{
    return name;
}

char *Teacher::getnumber()
{
    return number;
}

char *Teacher::getpassword()
{
    return password;
}

char *Teacher::getsex()
{
    return sex;
}

char *Teacher::getinstitute()
{
    return institute;
}

void Teacher::setnumber(char *number)
{
    strcpy_s(this->number, strlen(number)+1, number);
}

void Teacher::setpassword(char *password)
{
    strcpy_s(this->password,strlen(password)+1, password);
}

void Teacher::setname(char *name)
{
     strcpy_s(this->name, strlen(name)+1, name);
}

void Teacher::setsex(char* sex)
{
     strcpy_s(this->sex, strlen(sex)+1, sex);
}
void Teacher::setinstitute(char* institute)
{
     strcpy_s(this->institute, strlen(institute)+1,institute);
}

