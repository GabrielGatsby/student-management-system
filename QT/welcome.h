#ifndef WELCOME_H
#define WELCOME_H
#include <string>
#include<QString>
#include"student.h"
#include"course.h"
#include<fstream>
#include"hashtable.h"
#include <QWidget>
#include <QDialog>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();
    static hashdict<Student> studentHash;
    static hashdict<Course>CourseHash;
    static hashdict<Course>CourseHash2;
    static char userid[20];
    static bool judge;
private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Welcome_rejected();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Welcome *ui;
};
bool endStudent(Student& s);
bool endCourse(Course& s) ;
void addcourse();

void  makeCourse() ;
void  makeCourse2();
void initials();
void initialc();
void inc();
#endif // WELCOME_H
