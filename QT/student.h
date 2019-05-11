#ifndef STUDENT_H
#define STUDENT_H
#include "SchoolStaff.h"
#include"Course.h"
class Student :public SchoolStaff
{
protected:
    char telephone[20];



public:
    Course* studentCourse;

    Student(char* number="mark", char* name="mark", char* password = "mark", char* sex = "mark",
            char* institute = "mark",char* telephone = "null", Course* studentcourse = 0 );

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

    friend ostream & operator <<(ostream& out, Student& s)
    {
        out << s.number << ' ' << s.name << ' ' << s.password << ' ' << s.sex << ' '
            << s.institute << ' ' << s.telephone << endl;
        return out;
    }

void settelephone(char*s);

    void add(Course* c) {


        if (studentCourse == NULL)
        {

            studentCourse = new Course;
        }
        Course *t = studentCourse;
        while (t->next)
        {
            t = t->next;
        }
        t->next = c;
    }

};



#endif // STUDENT_H
