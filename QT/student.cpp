#include "student.h"
#include <string>

Student::Student(char* number, char* name, char* password, char* sex,
                 char *institute, char* telephone, Course *studentcourse):SchoolStaff(number,name,password,sex,institute)
{
    strcpy_s(this->telephone, strlen(telephone)+1, telephone);
    this->studentCourse = studentcourse;

}

char* Student::gettelephone()
{
    return telephone;

}
void Student::settelephone(char*s)
{
    strcpy_s(this->telephone,s);
}
char *Student::getname()
{
    return name;
}

char *Student::getnumber()
{
    return number;
}

char *Student::getpassword()
{
    return password;
}

char *Student::getsex()
{
    return sex;
}

char *Student::getinstitute()
{
    return institute;
}

void Student::setnumber(char *number)
{
    strcpy_s(this->number, strlen(number)+1, number);
}

void Student::setpassword(char *password)
{
    strcpy_s(this->password,strlen(password)+1, password);
}

void Student::setname(char *name)
{
     strcpy_s(this->name, strlen(name)+1, name);
}

void Student::setsex(char* sex)
{
     strcpy_s(this->sex, strlen(sex)+1, sex);
}
void Student::setinstitute(char* institute)
{
     strcpy_s(this->institute, strlen(institute)+1,institute);
}
