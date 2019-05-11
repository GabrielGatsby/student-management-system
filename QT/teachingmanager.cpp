#include "teachingmanager.h"

TeachingManager::TeachingManager()
{

}

TeachingManager::TeachingManager(char *number, char *name, char *password, char *sex, char *institute, int workingtime, char *education):
    TeachingStaff(number,name,password,sex,institute,workingtime,education)
{


}

char *TeachingManager::getname()
{
    return name;
}

char *TeachingManager::getnumber()
{
    return number;
}

char *TeachingManager::getpassword()
{
    return password;
}

char *TeachingManager::getsex()
{
    return sex;
}

char *TeachingManager::getinstitute()
{
    return institute;
}

void TeachingManager::setnumber(char *number)
{
    strcpy_s(this->number, strlen(number)+1, number);
}

void TeachingManager::setpassword(char *password)
{
    strcpy_s(this->password,strlen(password)+1, password);
}

void TeachingManager::setname(char *name)
{
     strcpy_s(this->name, strlen(name)+1, name);
}

void TeachingManager::setsex(char* sex)
{
     strcpy_s(this->sex, strlen(sex)+1, sex);
}
void TeachingManager::setinstitute(char* institute)
{
     strcpy_s(this->institute, strlen(institute)+1,institute);
}
