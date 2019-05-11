#include "schoolstaff.h"
#include <string>
#include<QString>
using namespace std;

SchoolStaff::SchoolStaff()
{

}

SchoolStaff::SchoolStaff(char* number, char* name, char* password, char* sex, char* institute)
{
    strcpy_s(this->number, strlen(number)+1, number);

    strcpy_s(this->name, strlen(name)+1, name);
    strcpy_s(this->password, strlen(password)+1, password);
    strcpy_s(this->sex, strlen(sex)+1, sex);
    strcpy_s(this->institute, strlen(institute)+1, institute);

}

